include(FetchContent)

FetchContent_Declare(wolfram_script_cmake
    GIT_REPOSITORY    git@github.com:qiangyicheng/wolfram_script_cmake.git
)

FetchContent_GetProperties(wolfram_script_cmake)
if(NOT wolfram_script_cmake_POPULATED)
    FetchContent_Populate(wolfram_script_cmake)
    include(${wolfram_script_cmake_SOURCE_DIR}/CMakeLists.txt)
endif()