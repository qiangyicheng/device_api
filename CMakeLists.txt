# CMakeLists files in this project can
# refer to the root source directory of the project as ${PROJECT_SOURCE_DIR} and
# to the root binary directory of the project as ${PROJECT_BINARY_DIR}.

cmake_minimum_required(VERSION 3.14)
project (device_api)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include/)

include(FetchContent)

FetchContent_Declare(HIPIFY
    GIT_REPOSITORY    https://github.com/ROCm-Developer-Tools/HIPIFY.git
)

if(NOT HIPIFY_POPULATED)
    FetchContent_Populate(HIPIFY)
endif()

add_subdirectory(generator)

add_subdirectory(include)

enable_testing()
add_subdirectory(test)