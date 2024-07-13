# Classwork Organiser

## Overview
This C++ program helps organize coursework files based on the user's input for academic year and semester subjects. It creates directories for each subject under specified base directories.

## Requirements
- C++ compiler that supports C++17
- CMake version 3.28 or higher
- Standard Library: iostream, string, vector, map, filesystem, algorithm

## Compilation and Execution
1. **Setup**
    - Clone the repository or download the source files.

2. **Build with CMake**
    - Navigate to the root directory of the project in your terminal.
    - Create a build directory:
      ```bash
      mkdir build
      cd build
      ```
    - Generate the build system using CMake:
      ```bash
      cmake ..
      ```
    - Build the executable:
      ```bash
      cmake --build .
      ```

3. **Execution**
    - Run the executable:
      ```bash
      ./C++_Univesity_Code
      ```
    - Follow the prompts to enter the completion year and semester subjects.

4. **Output**
    - The program will create directories for each semester subject under the specified base directory.

## Example
Assume the base directory is set to `/Bachelor of Computer Science`:
- Enter the completion year (e.g., 1, 2, 3).
- Enter each semester (Autumn, Spring, Annual) and respective subjects.

## Notes
- Ensure directory permissions allow for directory creation.
- Input validation is implemented to ensure correct data entry.

## Author
- Michael McMillan

