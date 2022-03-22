#pragma once

#include <arrow/api.h>
#include <string>

using namespace std;
using namespace arrow;

class MetadataConverter{
    public: 
        MetadataConverter();
        string serialize(shared_ptr<KeyValueMetadata> kvMeta);
        shared_ptr<KeyValueMetadata> parse(string JSON);
};