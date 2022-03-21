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
            j["name"] = field->name();

            SimpleDataTypeConverter c;
            nlohmann::json dtJson = nlohmann::json::parse(
                c.serialize(field->type())
            );
            j["dataType"] = dtJson;

            if (field->HasMetadata()){
                MetadataConverter c2;
            
                // cout << "Null metadata:" << c2.serialize(field->metadata()->Copy()) << endl;
                nlohmann::json metaDataJson = nlohmann::json::parse(
                    c2.serialize(field->metadata()->Copy())
                );

                // cout << field->metadata()->Copy() << endl;
                j["metadata"] = metaDataJson;
            }

            return j.dump();
        }
        
        shared_ptr<Field> parse(string JSON){
            nlohmann::json j = nlohmann::json::parse(JSON);

            // cout << "DUMP JSON: " << j["metadata"].dump() << endl;

            shared_ptr<KeyValueMetadata> kvMeta(new KeyValueMetadata());
            if(j.contains("metadata")){
                MetadataConverter mc;
                kvMeta = mc.parse((string)j["metadata"].dump());
            }

            SimpleDataTypeConverter dtc;
            shared_ptr<DataType> dataType = dtc.parse((string)j["dataType"].dump());

            shared_ptr<Field> returnVal = field(
                j["name"],
                dataType,
                kvMeta
            );
            
            // return void;
            return returnVal;
        }
        
    private:
        // number of child fields
        int num_child;
    
};

#endif