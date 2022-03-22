# Arrow Schema To JSON
C++ library to convert Arrow Schema to JSON string

## Dependancies
- [Arrow](https://github.com/apache/arrow)
- [nlohmann JSON](https://github.com/nlohmann/json)

Use the bash script installDependencies.sh to install the libraries above
```
bash installDependancies.sh
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

Or manually include headers in `include` folder, and link with `libschemaConverter.a`
A minimum example is included in `example.cpp`
```
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

