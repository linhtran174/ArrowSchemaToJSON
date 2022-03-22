#pragma once 

#include <arrow/api.h>
#include <string>

using namespace std;
using namespace arrow;

class DataTypeConverter{
    public: 
        DataTypeConverter(){};
        virtual string serialize(shared_ptr<DataType>) = 0;
        virtual shared_ptr<DataType> parse(string JSON) = 0;
        
    private:
        // number of child fields
        int num_child;

};