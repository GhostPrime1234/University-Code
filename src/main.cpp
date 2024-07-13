#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <filesystem>
#include <algorithm>
#include "../headers/ClassworkOrganiser.h"

namespace fs = std::filesystem;

int main() {
    std::string script_dir = fs::absolute(__FILE__).parent_path().string(); // Determine the directory where the script is located

    // Go up multiple parent directories from the path
    std::cout << "Script directory: '" << script_dir << "'\n";
    int levels_to_remove = 3;
    for (int i = 0; i < levels_to_remove; ++i) {
        script_dir = fs::path(script_dir).parent_path().string();
    }
    std::string base_directory = script_dir + "/Bachelor of Computer Science";
    std::cout << "Base directory: '" << base_directory << "'\n";

    std::string input_year;
    while (true) {
        std::cout << "Enter what year this will be completed in (1, 2, 3 etc): ";
        std::getline(std::cin, input_year);
        if (!input_year.empty() && std::all_of(input_year.begin(), input_year.end(), ::isdigit)) {
            break;
        } else {
            std::cout << "Completion year must be a valid number." << std::endl;
        }
    }

    std::map<std::string, std::vector<std::pair<std::string, std::string>>> semester_subjects;

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

    ClassworkOrganiser organiser(base_directory, input_year, semester_subjects);
    organiser.create_year_and_subject_dirs();
    std::cout << "Press enter to continue." << std::endl;
    std::cin.get();
    return 0;
}
