#include <iostream>
#include <arrow/api.h>


#ifndef FIELDCONVERTER
#define FIELDCONVERTER


using namespace std;
using namespace arrow;

class FieldConverter{
    public: 
        FieldConverter(){
            
        }
        virtual string serialize(shared_ptr<Field>) = 0;
        virtual shared_ptr<Field> parse(string JSON) = 0;
        
    private:
        // number of child fields
        int num_child;

};

#endif