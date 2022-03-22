include_directories(libs/nlohmann_json)

add_executable(unit_Metadata unit_MetadataConverter.cpp)

# add_dependencies()

add_executable(unit_SimpleField unit_SimpleFieldConverter.cpp)


add_executable(unit_CompositeField unit_CompositeFieldConverter.cpp)
