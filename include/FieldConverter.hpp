#pragma once

#include <arrow/api.h>

using namespace std;
using namespace arrow;

class FieldConverter{
    public: 
        FieldConverter(){};
        virtual string serialize(shared_ptr<Field>) = 0;
        virtual shared_ptr<Field> parse(string JSON) = 0;
};