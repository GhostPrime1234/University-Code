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
            break;
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
    return 0;
}
