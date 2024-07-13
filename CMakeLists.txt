cmake_minimum_required(VERSION 3.28)
project(C++_University_Code)

set(CMAKE_CXX_STANDARD 17)

# Add executable and sources
add_executable(C++_University_Code
        src/main.cpp
        src/ClassworkOrganiser.cpp
        src/SubjectManager.cpp
        src/DirectoryManager.cpp
)

# Set the output directory for the executable
set_target_properties(C++_University_Code PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
        # Optionally, specify other directories like LIBRARY_OUTPUT_DIRECTORY, ARCHIVE_OUTPUT_DIRECTORY, etc.
)
