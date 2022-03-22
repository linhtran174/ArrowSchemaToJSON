#pragma once

#include <arrow/api.h>
#include <string>
#include <set>
#include "DataTypeConverter.hpp"

using namespace std;
using namespace arrow;

class CompositeDataTypeConverter : DataTypeConverter{
    public: 
        CompositeDataTypeConverter();
        string serialize(shared_ptr<DataType> field);
        shared_ptr<DataType> parse(string JSON);
    
    private:
        string serializeMap(shared_ptr<DataType> dtType);
        string serializeList(shared_ptr<DataType> dtType);
        std::set<int> compositeFieldTypeId = {Type::type::MAP, Type::type::LIST};
        bool isCompositeDataType(shared_ptr<DataType> dtType);
        bool isCompositeDataType(int dataTypeId);

};