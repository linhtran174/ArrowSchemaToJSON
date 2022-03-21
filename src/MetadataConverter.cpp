#include <iostream>
#include <arrow/api.h>
#include <nlohmann/json.hpp>

using namespace std;
using namespace arrow;


class MetadataConverter{
    public: 
        MetadataConverter(){

        }
        string serialize(shared_ptr<KeyValueMetadata> kvMeta){
            unordered_map<string, string> map;
            kvMeta->ToUnorderedMap(&map);

            nlohmann::json j;
            j["_type"] = "metadata";
            for (auto it : map){                
                j[it.first] = it.second;
            }
            
            return j.dump();
        }

        shared_ptr<KeyValueMetadata> parse(string JSON){
            shared_ptr<KeyValueMetadata> returnVal(new KeyValueMetadata());
            nlohmann::json j = nlohmann::json::parse(JSON);

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