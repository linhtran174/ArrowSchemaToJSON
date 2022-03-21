#include <iostream>
#include <arrow/api.h>

#ifndef DATATYPECONVERTER
#define DATATYPECONVERTER

using namespace std;
using namespace arrow;

class DataTypeConverter{
    public: 
        DataTypeConverter(){
            
        }
        virtual string serialize(shared_ptr<DataType>) = 0;
        virtual shared_ptr<DataType> parse(string JSON) = 0;
        
    private:
        // number of child fields
        int num_child;

};

#endif