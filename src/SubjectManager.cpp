#include "../headers/SubjectManager.h"

void SubjectManager::create_subject_directories(const std::string& semester_dir, const std::vector<std::pair<std::string, std::string>>& subjects, const WeekDirectoryManager& week_directory_manager) {
    for (const auto& subject : subjects) {
        std::string subject_dir = semester_dir + "/" + subject.first + " - " + subject.second;
        DirectoryManager::create_directory(subject_dir);
        create_subject_subdirectories(subject_dir, week_directory_manager);
    }
}

void SubjectManager::create_subject_subdirectories(const std::string& subject_dir, const WeekDirectoryManager& week_directory_manager) {
    std::vector<std::string> subdirectories = { "Assessments", "Lectures", "Classwork" };
    auto created_subdirectories = DirectoryManager::create_subdirectories(subject_dir, subdirectories);
    std::string classwork_dir = created_subdirectories[2]; // Classwork directory is the third in the list
    week_directory_manager.create_weekly_directories(classwork_dir);
}