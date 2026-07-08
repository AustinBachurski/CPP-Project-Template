cmake_minimum_required(VERSION 3.25...4.3)

project(CPP_TEMPLATE LANGUAGES CXX)

option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors." ON)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerWarnings.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Sanitizers.cmake")

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.15.1
)

FetchContent_MakeAvailable(Catch2)

# When using FetchContent, include(Catch) will fail unless CMAKE_MODULE_PATH
# is explicitly updated to include the extras directory.
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

add_subdirectory(src)
add_subdirectory(tests)
