#include <arrow/api.h>
#include <arrow/compute/api_aggregate.h>
#include <arrow/csv/api.h>
#include <arrow/csv/writer.h>
#include <arrow/io/api.h>
#include <arrow/result.h>
#include <arrow/status.h>
#include <arrow/type.h>

#include <iostream>
#include <vector>
#include <string>

#include <nlohmann/json.hpp>

using namespace std;
using namespace arrow;



int main(){
  // arrow::DataType;
  
  shared_ptr<Schema> schema;
  shared_ptr<Field> field_person, field_p_name, field_p_age, field_p_profession;
  
  field_p_name = field("Name", utf8());
  field_p_age = field("Age", int8());
  field_p_profession = field("Name", utf8());

  // shared_ptr<DataType> pmap = arrow::map(utf8(), );

  field_person = field("Person", utf8());



  // arrow::KeyValueMetadata
  // arrow::schema({field_a, field_b});

  // std::cout << field_a->ToString() << std::endl;

  // tentative schemas
  // nlohmann::json tentativeSchemas = {
  //   {"type", "schema"},
  //   {"endianess", ""},
  //   {"fields", {
  //     {"type", "fields"}
  //   }}
  // };



  nlohmann::json j2 = {
    {"pi", 3.141},
    {"happy", true},
    {"name", "Niels"},
    {"nothing", nullptr},
    {"answer", {
      {"everything", 42}
    }},
    {"list", {1, 0, 2}},
    {"object", {
      {"currency", "USD"},
      {"value", 42.99}
    }}
  };

  std::cout << j2.dump() << endl;
}

