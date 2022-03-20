# set(CMAKE_GENERATOR "Ninja")
# set(CMAKE_MAKE_PROGRAM "ninja")

# C++ 20 modules support 
# set(CXX_MODULES_CHECK -fmodules-ts)
# set(CXX_MODULES_FLAGS -fmodules-ts)
# set(CMAKE_CXX_FLAGS -fmodules-ts)

# target_compile_options(${TARGET} PRIVATE ${CXX_MODULES_FLAGS})

set(PROJECT_SRC_DIR src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(arrowSchemaToJSON)

message("generator is set to ${CMAKE_GENERATOR}")

find_package(Arrow REQUIRED)

add_executable(test test.cpp)
target_link_libraries(test PRIVATE arrow_shared)