cmake_minimum_required(VERSION 3.10)

project(WebLinkExplorer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)
