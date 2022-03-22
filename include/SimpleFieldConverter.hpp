#pragma once

#include <arrow/api.h>
#include "FieldConverter.hpp"
#include <string>

using namespace std;
using namespace arrow;

class SimpleFieldConverter : FieldConverter{
    public: 
        SimpleFieldConverter(){};
        string serialize(shared_ptr<Field> field);
        shared_ptr<Field> parse(string JSON);
};