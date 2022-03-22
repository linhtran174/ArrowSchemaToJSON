#include <iostream>
#include <arrow/api.h>
#include <nlohmann/json.hpp>
#include <CompositeFieldConverter.hpp>
#include <MetadataConverter.hpp>
#include <SchemaConverter.hpp>

using namespace std;
using namespace arrow;

SchemaConverter::SchemaConverter(){}

string SchemaConverter::serialize(shared_ptr<Schema> sch){
    
    nlohmann::json j;
    j["_type"] = "schema";

    j["fields"] = nlohmann::json::array();
    CompositeFieldConverter c;
    for(auto &f : sch->fields()){
        j["fields"].push_back(
            nlohmann::json::parse(
                c.serialize(f)
        ));
    }

    if(sch->HasMetadata()){
        MetadataConverter c;
        j["metadata"] = nlohmann::json::parse(
            c.serialize(sch->metadata()->Copy())
        );
    }

    return j.dump();
}

shared_ptr<Schema> SchemaConverter::parse(string JSON){
    nlohmann::json j;
    try{
        j = nlohmann::json::parse(JSON);
    }
    catch(nlohmann::json::parse_error& e){
        throw "Error while parsing JSON";
    }

    if(j["_type"] != "schema"){
        throw "JSON object is not of type schema";
    }

    if(!j.contains("fields")){
        throw "schema's fields cannot be empty";
    }

    CompositeFieldConverter c;
    std::vector<shared_ptr<Field>> fields;
    for(auto &f : j["fields"]){
        // cout << "FDUMP:" << c.parse( f.dump() )->ToString() << endl;
        fields.push_back( c.parse( f.dump() ) );
    }

    shared_ptr<KeyValueMetadata> meta(new KeyValueMetadata());
    if(j.contains("metadata")){
        MetadataConverter c;
        meta = c.parse(
            j["metadata"].dump()
        );
    }

    return schema(fields, meta);
    // return schema({field("A", int32()), field("B", utf8())});
}
