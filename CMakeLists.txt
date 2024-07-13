cmake_minimum_required(VERSION 3.28)
project(Cpp_University_Code)

set(CMAKE_CXX_STANDARD 17)

# Add executable and sources
add_executable(Cpp_University_Code
        src/main.cpp
        src/ClassworkOrganiser.cpp
        src/SubjectManager.cpp
        src/DirectoryManager.cpp
        src/UserInputHandler.cpp
)

# Set the output directory for the executable
set_target_properties(Cpp_University_Code PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin/Debug"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin/Release"
)
