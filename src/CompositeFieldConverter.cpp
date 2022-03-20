#include <iostream>
#include "FieldConverter.cpp"
#include <arrow/api.h>

using namespace std;
using namespace arrow;

class CompositeFieldConverter : FieldConverter{
    public: 
        CompositeFieldConverter(){

        }
        virtual string serialize(Field) = 0;
        virtual Field parse(string JSON) = 0;
        
    private:
        // number of child fields
        int num_child;
    
}