# project(metadataConverter)
add_library(schemaConverter STATIC
 CompositeDataTypeConverter.cpp CompositeFieldConverter.cpp DataTypeConverter.cpp
 MetadataConverter.cpp SchemaConverter.cpp SimpleDataTypeConverter.cpp SimpleFieldConverter.cpp)

