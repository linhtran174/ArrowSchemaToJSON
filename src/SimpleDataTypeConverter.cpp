#include <iostream>
#include "DataTypeConverter.cpp"
#include <arrow/api.h>
#include <nlohmann/json.hpp>


#ifndef SIMPLEDATATYPECONVERTER
#define SIMPLEDATATYPECONVERTER

// using namespace std;
using namespace arrow;

class SimpleDataTypeConverter : DataTypeConverter{
    public: 
        SimpleDataTypeConverter(){

        }
        string serialize(shared_ptr<DataType> dataType){
            nlohmann::json j;
            j["_type"]  = "dataType";
            j["dt_name"] = dataType->name();
            j["dt_id"] = dataType->id();

            return j.dump();
        };

        shared_ptr<DataType> parse(string JSON){
            // cout << "String: " << JSON << endl;
            nlohmann::json j = nlohmann::json::parse(JSON);

            // cout << "JSON" << j.dump() << endl;
            // j["dt_id"]
            std::map<Type::type, shared_ptr<DataType>> typeIdToDataType = {
                {Type::NA, null()},
                {Type::BOOL, boolean()},
                {Type::INT8, int8()},
                {Type::INT16, int16()},
                {Type::INT32, int32()},
                {Type::INT64, int64()},
                {Type::UINT8, uint8()},
                {Type::UINT16, uint16()},
                {Type::UINT32, uint32()},
                {Type::UINT64, uint64()},
                {Type::HALF_FLOAT, float16()},
                {Type::FLOAT, float32()},
                {Type::DOUBLE, float64()},
                {Type::STRING, utf8()},
                {Type::LARGE_STRING, large_utf8()},
                {Type::BINARY, binary()},
                {Type::LARGE_BINARY, large_binary()},
                {Type::DATE32, date32()},
                {Type::DATE64, date64()},
                // {Type::TIMESTAMP, timestamp()},
                // {Type::TIME32, time32()},
                // {Type::TIME64, time64()},
                {Type::INTERVAL_MONTHS, month_interval()},
                {Type::INTERVAL_MONTH_DAY_NANO, month_day_nano_interval()},
                // {Type::DECIMAL128,},
            };
            
            // (Type::type)j["dt_id"];
            shared_ptr<DataType> dtObj = typeIdToDataType[(Type::type)j["dt_id"]];
            
            return dtObj;
        };
        
    private:

        // number of child fields
        int num_child;
    
};

#endif