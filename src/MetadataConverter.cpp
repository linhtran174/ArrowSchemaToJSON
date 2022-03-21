#include <iostream>
#include <arrow/api.h>
#include <nlohmann/json.hpp>

using namespace std;
using namespace arrow;

class MetadataConverter{
    public: 
        MetadataConverter(){

        }
        string serialize(KeyValueMetadata kvMeta){
            unordered_map<string, string> map;
            kvMeta.ToUnorderedMap(&map);

            // for(auto it : map){
            //     nlohmann::json
            // }
            
        }

        KeyValueMetadata parse(string JSON){

        }
    private:
        // number of child fields
        int num_child;

};