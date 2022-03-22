#ifndef COMPOSITEDATATYPECONVERTER
#define COMPOSITEDATATYPECONVERTER

#include <iostream>
#include <SimpleDataTypeConverter.hpp>
#include <CompositeFieldConverter.hpp>
#include <CompositeDataTypeConverter.hpp>
#include <SimpleDataTypeConverter.hpp>
#include <arrow/api.h>
#include <nlohmann/json.hpp>
#include <set>

using namespace std;
using namespace arrow;

CompositeDataTypeConverter::CompositeDataTypeConverter(){}
string CompositeDataTypeConverter::serialize(shared_ptr<DataType> dtType){
    if(this->isCompositeDataType(dtType)){
        // Map type
        if(dtType->id() == Type::type::MAP){
            return this->serializeMap(dtType);
        }

        // List type 
        if(dtType->id() == Type::type::LIST){
            return this->serializeList(dtType);
        }
    }
    else{
        SimpleDataTypeConverter c;
        return c.serialize(dtType);
    }
    return "";
}
        
shared_ptr<DataType> CompositeDataTypeConverter::parse(string JSON){
    // check empty dt_id 
    nlohmann::json j;
    try{
        j = nlohmann::json::parse(JSON);
    }
    catch(nlohmann::json::parse_error& e){
        throw "Error while parsing JSON";
    }

    if(!j.contains("dt_id")){
        throw "Error: DataType JSON string without dt_id";
    }

    if(this->isCompositeDataType(j["dt_id"])){
        // Q: Multiple fields in a dataType, no factory function for that??!
        if(j["dt_id"] == (int) Type::type::MAP){
            // Cannot retrive key from MapType
            throw "Error MapType not supported.";
        }
        else if(j["dt_id"] == (int) Type::type::LIST){    
            throw "Error MapType not supported.";
            CompositeFieldConverter c;
            shared_ptr<Field> child_field = c.parse(
                j["list"].dump()
            );

            return list(child_field);
        }
    }
}

string CompositeDataTypeConverter::serializeMap(shared_ptr<DataType> dtType){
    // Q: How to retrive the key from a MapType
    throw "Error: MapType not supported.";

    // nlohmann::json j;
    // j["dt_type"] = "map";
    // j["dt_id"] = dtType->id();
    // j["key"] = dtType->
    // MapType
}

string CompositeDataTypeConverter::serializeList(shared_ptr<DataType> dtType){
    nlohmann::json j;
    j["dt_type"] = "list";
    j["dt_id"] = dtType->id();

    ////ABORTED_CODE: ListType may not contains multiple different Fields 
    // j["list"] = nlohmann::json::array();
    // CompositeFieldConverter c;
    // for(auto &f : dtType->fields()){
    //     j["list"].push_back(
    //         nlohmann::json::parse(
    //             c.serialize(f)
    //         )
    //     );
    // }

    // Q: how to retrieve child Fields from ListType ? 
    throw "Error: Not implemented";

    return j.dump();
} 

bool CompositeDataTypeConverter::isCompositeDataType(shared_ptr<DataType> dtType){
    // Q: Where is the factory function for DataType with multiple child fields?

    return this->isCompositeDataType(dtType->id())
    // if(dtType->num_fields() > 1) return true;
    // else return false;
}

bool CompositeDataTypeConverter::isCompositeDataType(int dataTypeId){
    if( this->compositeFieldTypeId.find(dataTypeId) != this->compositeFieldTypeId.end() ) return true;
    else return false;
}


#endif