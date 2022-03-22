#pragma once

#include "FieldConverter.hpp"
#include <arrow/api.h>
#include <string>
#include <set>

using namespace std;
using namespace arrow;

class CompositeFieldConverter : FieldConverter{
    public: 
        CompositeFieldConverter();
        string serialize(shared_ptr<Field> field);
        shared_ptr<Field> parse(string JSON);

    private:
        // number of child fields
        std::set<int> compositeFieldTypeId = {Type::type::MAP, Type::type::LIST};
        bool isCompositeField(shared_ptr<Field> field);
        bool isCompositeField(int dataTypeId);
};