#include <arrow/api.h>
#include <arrow/compute/api_aggregate.h>
#include <arrow/csv/api.h>
#include <arrow/csv/writer.h>
#include <arrow/io/api.h>
#include <arrow/result.h>
#include <arrow/status.h>

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){
    // arrow::DataType;
    
    std::shared_ptr<arrow::Schema> schema;
    std::shared_ptr<arrow::Field> field_a, field_b;
    
    // field_a = arrow::field("Name", arrow::);

    // arrow::KeyValueMetadata
    // arrow::schema({field_a, field_b});

    std::cout << field_a->ToString() << std::endl;

    
}

