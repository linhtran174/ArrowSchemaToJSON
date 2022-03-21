#include <iostream>
#include <arrow/api.h>
#include <nlohmann/json.hpp>

#ifndef METADATACONVERTER
#define METADATACONVERTER

using namespace std;
using namespace arrow;

class MetadataConverter{
    public: 
        MetadataConverter(){

        }
        string serialize(shared_ptr<KeyValueMetadata> kvMeta){
            // cout << kvMeta->ToString();
            // cout << "SIZE: " << kvMeta->size() << endl;

            unordered_map<string, string> map;
            kvMeta->ToUnorderedMap(&map);

            // kvMeta->keys();

            nlohmann::json j;
            j["_type"] = "metadata";
            for (auto it : map){                
                j[it.first] = it.second;
            }

            // for(auto &key : kvMeta->keys()){
            //     cout << "doing key: " << (key);
            //     // Result<string> res = kvMeta->Get(key);
            //     // if(!res.ok()){
            //     //     cout << "Failed";
            //     //     throw "Error when serializing metadata: " + kvMeta->ToString();
            //     // }
            //     // j[key] = res.ValueOrDie();
            // }
            
            return j.dump();
            // return "";
        }

        shared_ptr<KeyValueMetadata> parse(string JSON){
            shared_ptr<KeyValueMetadata> returnVal(new KeyValueMetadata());
            nlohmann::json j = nlohmann::json::parse(JSON);

            // cout << JSON;
            unordered_map<string, string> map = j.get<unordered_map<string, string>>();
            if (map["_type"] != "metadata"){
                throw "Object is not metadata";
            }
            map.erase("_type");

            for(auto& [key, value] : map){
                // if(it.value() != it.)
                returnVal->Append(key, value);
            }

            // return arrow::key_value_metadata(&map);
            return returnVal;
        }

        
    private:
        // number of child fields
        int num_child;

};

#endif