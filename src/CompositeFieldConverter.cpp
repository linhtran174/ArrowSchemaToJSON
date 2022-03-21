#include <iostream>
#include "FieldConverter.cpp"
#include <arrow/api.h>


#ifndef COMPOSITEFIELDCONVERTER
#define COMPOSITEFIELDCONVERTER


using namespace std;
using namespace arrow;

class CompositeFieldConverter : FieldConverter{
    public: 
        CompositeFieldConverter(){}
        string serialize(shared_ptr<Field>){

        }
        shared_ptr<Field> parse(string JSON){

        }
        
    private:
        // number of child fields
        int num_child;
    
};

#endif