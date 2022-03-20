#include <iostream>
#include <arrow/api.h>

using namespace std;
using namespace arrow;

class FieldConverter{
    public: 
        FieldConverter(){

        }
        virtual string serialize(Field) = 0;
        virtual Field parse(string JSON) = 0;
        
    private:
        // number of child fields
        int num_child;

}