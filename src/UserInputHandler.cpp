#include <cctype>

#include "../headers/UserInputHandler.h"

void UserInputHandler::signal_callback_handler(int signum) {
    std::cout << "\nCaught signal " << signum << ". Exiting program." << std::endl;
    exit(signum);
}

std::string UserInputHandler::getValidYearInput() {
    std::string input_year;
    while (true) {
        std::cout << "Enter what year this will be completed in (1, 2, 3, etc.), or 'done' to exit: ";
        std::getline(std::cin, input_year);

        if (std::cin.eof()) {
            UserInputHandler::signal_callback_handler(SIGINT);
            exit(SIGINT);
        }

        trimWhitespace(input_year);

        if (input_year == "done") {
            std::cout << "Exiting program." << std::endl;
            exit(EXIT_SUCCESS);
        }

        if (input_year.empty()) {
            std::cout << "Completion year cannot be empty." << std::endl;
        } else if (!std::all_of(input_year.begin(), input_year.end(), ::isdigit)) {
            std::cout << "Completion year must be a valid number." << std::endl;
        } else {
            break;
        }
    }
    return input_year;
}

std::map<std::string, std::vector<std::pair<std::string, std::string>>> UserInputHandler::getInputForSemestersAndSubjects() {
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> semester_subjects;

    while (true) {
        std::string input_semester;
        std::cout << "Enter the semester term (Autumn, Spring, Annual, or 'done' to finish): ";
        std::getline(std::cin, input_semester);
        std::transform(input_semester.begin(), input_semester.end(), input_semester.begin(), ::tolower);

        if (input_semester == "done") {
            break;
        }

        if (std::cin.eof()) {
            UserInputHandler::signal_callback_handler(SIGINT);
            exit(SIGINT);
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

    return semester_subjects;
}

void UserInputHandler::trimWhitespace(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}
