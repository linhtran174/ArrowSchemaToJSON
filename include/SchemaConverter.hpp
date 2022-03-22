#pragma once 

#include <arrow/api.h>
#include <string>

using namespace std;
using namespace arrow;

class SchemaConverter{
    public: 
        SchemaConverter(){}
        string serialize(shared_ptr<Schema> sch);
        shared_ptr<Schema> parse(string JSON);
};
