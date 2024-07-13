#include <iostream>
#include <filesystem>
#include <algorithm>
#include <csignal>
#include "../headers/ClassworkOrganiser.h"

namespace fs = std::filesystem;

// Signal handler function
void signal_callback_handler(int signum) {
    std::cout << "\nCaught signal " << signum << ".\nExiting program." << std::endl;
    exit(signum);
}

class UserInputHandler {
public:
    static std::string getValidYearInput() {
        std::string input_year;

        // Define a temporary signal handler that will reset to default after use
        auto previous_handler = signal(SIGINT, [](int signum) {
            std::cout << "\nCaught signal " << signum << ".\nExiting program." << std::endl;
            exit(signum);
        });

        while (true) {
            std::cout << "Enter what year this will be completed in (1, 2, 3, etc.), or 'done' to exit: ";
            std::getline(std::cin, input_year);

            // Reset the signal handler to the previous one after getting input
            signal(SIGINT, previous_handler);

            // Check if input was interrupted (Ctrl+C)
            if (std::cin.eof()) {
                std::cout << "\nInput interrupted. Exiting program." << std::endl;
                exit(EXIT_SUCCESS);
            }

            // Trim leading and trailing whitespace
            input_year.erase(0, input_year.find_first_not_of(' '));
            input_year.erase(input_year.find_last_not_of(' ') + 1);

            // Check if input is 'done' to exit early
            if (input_year == "done") {
                std::cout << "Exiting program." << std::endl;
                exit(EXIT_SUCCESS); // Or handle program termination as needed
            }

            // Check if input is empty or contains non-digit characters
            if (input_year.empty()) {
                std::cout << "Completion year cannot be empty." << std::endl;
            } else if (!std::all_of(input_year.begin(), input_year.end(), ::isdigit)) {
                std::cout << "Completion year must be a valid number." << std::endl;
            } else {
                break; // Valid input, exit the loop
            }
        }
        return input_year;
    }

    static void getInputForSemestersAndSubjects(std::map<std::string, std::vector<std::pair<std::string, std::string>>>& semester_subjects) {
        while (true) {
            std::string input_semester;
            std::cout << "Enter the semester term (Autumn, Spring, Annual, or 'done' to finish): ";
            std::getline(std::cin, input_semester);
            std::transform(input_semester.begin(), input_semester.end(), input_semester.begin(), ::tolower);

            if (input_semester == "done") {
                break;
            }

            input_semester[0] = static_cast<char>(toupper(input_semester[0]));

            if (input_semester == "Autumn" || input_semester == "Spring" || input_semester == "Annual") {
                std::vector<std::pair<std::string, std::string>> subjects;
                while (true) {
                    std::string input_subject_code;
                    std::cout << "Enter the subject code (or 'done' to finish this semester): ";
                    std::getline(std::cin, input_subject_code);
                    if (input_subject_code == "done") {
                        break;
                    }

                    std::string input_subject_name;
                    std::cout << "Enter the subject name for " << input_subject_code << ": ";
                    std::getline(std::cin, input_subject_name);
                    if (input_subject_name.empty()) {
                        std::cout << "Subject name cannot be empty." << std::endl;
                    } else {
                        subjects.emplace_back(input_subject_code, input_subject_name);
                    }
                }

                if (!subjects.empty()) {
                    semester_subjects[input_semester] = subjects;
                } else {
                    std::cout << "At least one subject must be entered for the semester." << std::endl;
                }
            } else {
                std::cout << "Semester must be 'Autumn', 'Spring', or 'Annual'." << std::endl;
            }
        }
    }
};

int main() {
    // Register global signal handler for interrupt (Ctrl+C)
    signal(SIGINT, signal_callback_handler);

    while (true) {
        std::string script_dir = fs::absolute(__FILE__).parent_path().string();
        std::cout << "Script directory: '" << script_dir << "'\n";

        int levels_to_remove = 3;
        for (int i = 0; i < levels_to_remove; ++i) {
            script_dir = fs::path(script_dir).parent_path().string();
        }
        std::string base_directory = script_dir + "/Bachelor of Computer Science";
        std::cout << "Base directory: '" << base_directory << "'\n";

        std::string input_year = UserInputHandler::getValidYearInput();

        std::map<std::string, std::vector<std::pair<std::string, std::string>>> semester_subjects;
        UserInputHandler::getInputForSemestersAndSubjects(semester_subjects);

        ClassworkOrganiser organiser(base_directory, input_year, semester_subjects);
        organiser.create_year_and_subject_dirs();

        std::cout << "Press enter to continue." << std::endl;
        std::cin.get();

        // Uncomment the next line if you want to exit after one iteration
        break;
    }

    return EXIT_SUCCESS;
}
