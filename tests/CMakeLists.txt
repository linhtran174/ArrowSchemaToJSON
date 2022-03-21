include_directories(libs/nlohmann_json)

add_executable(unit_Metadata unit_MetaDataConverter.cpp)
target_link_libraries(unit_Metadata PRIVATE arrow_shared)
target_link_libraries(unit_Metadata PRIVATE nlohmann_json::nlohmann_json)
# add_dependencies()