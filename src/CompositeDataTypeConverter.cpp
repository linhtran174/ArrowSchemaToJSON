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

    if(this->isCompositeDataType(JSON)){
        if(j["dt_id"] == (int) Type::type::MAP){
            throw "Error MapType not supported.";
        }
        else if(j["dt_id"] == (int) Type::type::LIST){

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
    j["list"] = nlohmann::json::array();

    CompositeFieldConverter c;
    for(auto &f : dtType->fields()){
        j["list"].push_back(
            nlohmann::json::parse(
                c.serialize(f)
            )
        );
    }

    return j.dump();
} 

bool CompositeDataTypeConverter::isCompositeDataType(shared_ptr<DataType> dtType){
    // Q: Where is the factory function for DataType with multiple child fields?

    if( this->compositeFieldTypeId.find(dtType->id()) != this->compositeFieldTypeId.end() ) return true;
    else return false;
    // if(dtType->num_fields() > 1) return true;
    // else return false;
}

bool CompositeDataTypeConverter::isCompositeDataType(string JSON){
    nlohmann::json j = nlohmann::json::parse(JSON);

    if( this->compositeFieldTypeId.find(j["dt_id"]) != this->compositeFieldTypeId.end() ) return true;
    else return false;
}


#endif