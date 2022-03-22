#ifndef COMPOSITEFIELDCONVERTER
#define COMPOSITEFIELDCONVERTER

#include <iostream>
#include <CompositeFieldConverter.hpp>
#include <SimpleFieldConverter.hpp>
#include <CompositeDataTypeConverter.hpp>
#include <MetadataConverter.hpp>
#include <arrow/api.h>
#include <set>
#include <nlohmann/json.hpp>

using namespace std;
using namespace arrow;

// Forward declaration hack - to bypass circular dependency without header files/linking

CompositeFieldConverter::CompositeFieldConverter(){}

string CompositeFieldConverter::serialize(shared_ptr<Field> field){
    if(this->isCompositeField(field)){
        // Map type
        // if(field->dtType->id() == Type::type::MAP){
        //     // return this->serializeMap(dtType);
        //     throw "Error: MapType field is not supported yet.";
        // }

        // // List type 
        // if(field->dtType->id() == Type::type::LIST){
        //     return this->serializeList(field);
        // }
        nlohmann::json j;
        j["_type"] = "field";

        if(field->HasMetadata()){
            MetadataConverter c;
            j["metadata"] = nlohmann::json::parse(
                c.serialize(field->metadata()->Copy())
            );
        }

        CompositeDataTypeConverter c;
        j["dataType"] = nlohmann::json::parse(
            c.serialize(field->type())
        );

        return j.dump();
    }
    else{
        SimpleFieldConverter c;
        return c.serialize(field);
    }
}

shared_ptr<Field> CompositeFieldConverter::parse(string JSON){
    nlohmann::json j;
    try {
        j = nlohmann::json::parse(JSON);
    }
    catch(nlohmann::json::parse_error& e){
        cout << "Error parsing JSON";
    }

    if(j["_type"] != "field"){
        throw "Not a field type JSON";
    }

    if(!j.contains("name")){
        throw "Field name cannot be empty";
    }

    shared_ptr<KeyValueMetadata> meta(new KeyValueMetadata());
    if(j.contains("metadata")){
        MetadataConverter c;
        meta = c.parse((string)j["metadata"].dump());
    }

    if(!j.contains("dataType")){
        throw "Error: Field does not contain datatype";
    }
    CompositeDataTypeConverter c;
    shared_ptr<DataType> dtType = c.parse(j["dataType"]);

    return field((string)j["name"], dtType, meta);
}


bool CompositeFieldConverter::isCompositeField(shared_ptr<Field> field){
    if( this->compositeFieldTypeId.find(field->type()->id()) != this->compositeFieldTypeId.end() ) return true;
    else return false;
}


#endif