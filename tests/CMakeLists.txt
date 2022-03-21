include_directories(libs/nlohmann_json)

add_executable(test unit_MetaDataConverter.cpp)

target_include_directories(test PRIVATE libs/nlohmann_json)