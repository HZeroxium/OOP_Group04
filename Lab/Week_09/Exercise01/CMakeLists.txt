cmake_minimum_required(VERSION 3.16)

project(MyProject)

# Get all .cpp and .h files in the current directory.
file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h)

# Add the source files to the project.
add_executable(MyProject ${SOURCE_FILES})

