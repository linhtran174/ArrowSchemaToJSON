cmake_minimum_required(VERSION 3.11)

# set(CMAKE_GENERATOR "Ninja")
# set(CMAKE_MAKE_PROGRAM "ninja")

message("generator is set to ${CMAKE_GENERATOR}")

# C++ 20 modules support 
# set(CXX_MODULES_CHECK -fmodules-ts)
# set(CXX_MODULES_FLAGS -fmodules-ts)
# set(CMAKE_CXX_FLAGS -fmodules-ts)

# target_compile_options(${TARGET} PRIVATE ${CXX_MODULES_FLAGS})


set(CMAKE_LIBRARY_PATH libs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include(FetchContent)
# FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)
# FetchContent_MakeAvailable(json)

project(arrowSchemaToJSON)
set(PROJECT_SRC_DIR src)

find_package(Arrow REQUIRED)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(libs/nlohmann_json)

# enable_testing()
include_directories(src)
include_directories(libs/nlohmann_json/single_include)
add_subdirectory(tests)
add_subdirectory(src)

add_executable(main test.cpp)
target_include_directories(main PRIVATE libs/nlohmann_json)
target_link_libraries(main PRIVATE arrow_shared)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)