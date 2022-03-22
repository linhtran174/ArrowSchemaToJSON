#pragma once 

#include <arrow/api.h>
#include <string>
#include "DataTypeConverter.hpp"

using namespace std;
using namespace arrow;

class SimpleDataTypeConverter : DataTypeConverter{
    public: 
        SimpleDataTypeConverter(){};
        string serialize(shared_ptr<DataType> dataType);
        shared_ptr<DataType> parse(string JSON);
        
};