#include <iostream>
#include "FieldConverter.cpp"
#include "SimpleDataTypeConverter.cpp"
#include "CompositeFieldConverter.cpp"
#include "SimpleDataTypeConverter.cpp"
#include "MetadataConverter.cpp"
#include <arrow/api.h>
#include <nlohmann/json.hpp>


#ifndef COMPOSITEDATATYPECONVERTER
#define COMPOSITEDATATYPECONVERTER

using namespace std;
using namespace arrow;

class CompositeDataTypeConverter : DataTypeConverter{
    public: 
        CompositeDataTypeConverter(){}
        string serialize(shared_ptr<DataType> dtType){
            if(isCompositeDataType(dtType)){
                // Map type
                if(dtType->id() == Type::type::MAP){
                    return this->serializeMap(dtType);
                }

                // List type 
                if(dtType->id() == Type::type::LIST){
                    return this->serializeList(dtType);
                }
            }
            else{
                SimpleDataTypeConverter c;
                return c.serialize(dtType);
            }
        }
        
        shared_ptr<Field> parse(string JSON){
            
        }
    private:
        string serializeMap(shared_ptr<DataType> dtType){
            
        }

        string serializeList(shared_ptr<DataType> dtType){

        }

        boolean isCompositeDataType(shared_ptr<DataType> dtType){
            if(dtType->num_fields() > 1) return true;
            else return false;
        }

        // number of child fields
        int num_child;
    
};

#endif