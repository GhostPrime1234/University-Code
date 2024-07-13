# C++ University Code

## Overview
This C++ program organizes coursework files based on the user's input for academic year and semester subjects. It creates directories for each subject under specified base directories.

## Requirements
- C++ compiler that supports C++17
- CMake version 3.28 or higher
- Standard Library: iostream, filesystem

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
     ./C++_University_Code
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

---

### main.cpp

```cpp
#include <iostream>
#include <filesystem>
#include <csignal>
#include "../headers/UserInputHandler.h"
#include "../headers/ClassworkOrganiser.h"

namespace fs = std::filesystem;

class Application {
public:
    Application() {
        signal(SIGINT, UserInputHandler::signal_callback_handler);
    }

    static void run() {
        while (true) {
            std::string script_dir = getScriptDirectory();
            std::cout << "Script directory: '" << script_dir << "'\n";

            std::string base_directory = getBaseDirectory(script_dir);
            std::cout << "Base directory: '" << base_directory << "'\n";

            std::string input_year = UserInputHandler::getValidYearInput();
            auto semester_subjects = UserInputHandler::getInputForSemestersAndSubjects();

            ClassworkOrganiser organiser(base_directory, input_year, semester_subjects);
            organiser.create_year_and_subject_dirs(); // Ensure this method is accessible

            std::cout << "Press enter to continue." << std::endl;
            std::cin.get();

            // Uncomment the next line if you want to exit after one iteration
            // break;
        }
    }

private:
    static std::string getScriptDirectory() {
        return fs::absolute(__FILE__).parent_path().string();
    }

    static std::string getBaseDirectory(const std::string& script_dir) {
        fs::path base_dir = script_dir;
        for (int i = 0; i < 3; ++i) {
            base_dir = base_dir.parent_path();
        }
        return base_dir.string() + "/Bachelor of Computer Science";
    }
};

int main() {
    Application::run();
    return EXIT_SUCCESS;
}
