#include <iostream>
#include "FieldConverter.cpp"
#include "SimpleDataTypeConverter.cpp"
#include "MetadataConverter.cpp"
#include <arrow/api.h>
#include <nlohmann/json.hpp>


#ifndef SIMPLEFIELDCONVERTER
#define SIMPLEFIELDCONVERTER

using namespace std;
using namespace arrow;

class SimpleFieldConverter : FieldConverter{
    public: 
        SimpleFieldConverter(){

        }
        string serialize(shared_ptr<Field> field){
            nlohmann::json j;
            j["_type"] = "field";
            j["f_type"] = "simple";

            SimpleDataTypeConverter c;
            nlohmann::json dtJson = c.serialize(field->type());
            j["dataType"] = dtJson;

            // MetadataConverter c2 = new MetadataConverter();
            // nlohmann::json metaDataJson = c2.serialize(field->metadata());
            // j["metadata"] = metaDataJson;

            return j.dump();
        }
        
        shared_ptr<Field> parse(string JSON){

        }
        
    private:
        // number of child fields
        int num_child;
    
};

#endif