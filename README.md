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

## Usage
Use CMake to include all the source files in `src` folder. Static/Dynamic library object not yet available.
```
#include <SchemaConverter.cpp>

int main(){
    
}
```