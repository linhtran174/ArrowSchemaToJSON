# Arrow Schema To JSON
C++ library to convert Arrow Schema to JSON string

## Dependencies
- [Arrow](https://github.com/apache/arrow)
- [nlohmann JSON](https://github.com/nlohmann/json)

Use the bash script `installDependencies.sh` to install the libraries above
```
bash installDependencies.sh
```

## Build
```
mkdir build
cd build
cmake ..
make
```

## Folder structure
- `include` : header files
- `src` : implementation files
- `test` : unit-tests

## Usage
Use CMake to include this folder
```
include_directories(arrowSchemaToJson)
```

Or manually include headers in `include` folder, and link with `libschemaConverter.a`.

A minimum example is included in `example.cpp`
```C++
#include <SchemaConverter.hpp>
#include <arrow/api.h>

int main(){
    shared_ptr<Field> a, b;
    a = field("A", arrow::int32());
    b = field("B", arrow::utf8());
    shared_ptr<Schema> inputSchema = arrow::schema({a, b});
    shared_ptr<Schema> inputSchema_dup = arrow::schema({a, b});

    SchemaConverter converter;
    shared_ptr<Schema> reconstructedSchema = converter.parse(converter.serialize(inputSchema));
    cout << "inputSchema equals reconstructedSchema: " << inputSchema->Equals(*reconstructedSchema) << endl;
}
```

## Limitations & Notes 
* The project was designed to work with nested dataType like `map(int8(), map(utf8(), list(int32())))`, but implementation is not yet available. I still have limited understanding about Apache Arrow/project requirements, and was stuck on the following points:
    * There is no way to get the key [DataType](https://arrow.apache.org/docs/cpp/api/datatype.html#_CPPv4N5arrow8DataTypeE) from a [MapType](https://arrow.apache.org/docs/cpp/api/datatype.html#classarrow_1_1_map_type). Digging in the source code is not a good option in my opinion.
    * A [DataType](https://arrow.apache.org/docs/cpp/api/datatype.html#classarrow_1_1_data_type) can contains multiple child [Fields](https://arrow.apache.org/docs/cpp/api/datatype.html#_CPPv4N5arrow5FieldE), but there is no factory function to reconstruct a DataType from multiple Fields. Again, using hidden API is out of the question.
    
* No linter is included, as I am not sure what is the requirement of the linter. Will study more abt similar projects & their linters later.
    * Building custom rules for a linter system like cpplint?
    * Writing a standalone minimal linter?


