#include <arrow/api.h>
#include <arrow/compute/api_aggregate.h>
#include <arrow/csv/api.h>
#include <arrow/csv/writer.h>
#include <arrow/io/api.h>
#include <arrow/result.h>
#include <arrow/status.h>
#include <arrow/type.h>

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

#include <nlohmann/json.hpp>
#include <SchemaConverter.hpp>

using namespace std;
using namespace arrow;

int main(){
    shared_ptr<Field> a, b;
    a = field("A", arrow::int32());
    b = field("B", arrow::utf8());
    shared_ptr<Schema> inputSchema = arrow::schema({a, b});
    shared_ptr<Schema> inputSchema_dup = arrow::schema({a, b});

    SchemaConverter converter;
    string json = converter.serialize(inputSchema);
    cout << "JSON String: " << json << endl;

    shared_ptr<Schema> reconstructedSchema = converter.parse(json);
    cout << "inputSchema equals reconstructedSchema: " << inputSchema->Equals(*reconstructedSchema) << endl;

    // cout << "resSchema JSON: " << converter.serialize(reconstructedSchema)   << endl;
}

