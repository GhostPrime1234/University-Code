#include "../headers/ClassworkOrganiser.h"

ClassworkOrganiser::ClassworkOrganiser(const std::string& base_directory, std::string year, const std::map<std::string, std::vector<std::pair<std::string, std::string>>>& semester_subjects)
        : base_directory(base_directory), year(std::move(year)), semester_subjects(semester_subjects), directory_manager(base_directory), week_directory_manager(), subject_manager() {}

void ClassworkOrganiser::create_year_and_subject_dirs() {
    std::string year_dir = base_directory + "/Year" + year;
    DirectoryManager::create_directory(year_dir);

    for (const auto& semester : semester_subjects) {
        std::string semester_dir = year_dir + "/" + semester.first;
        DirectoryManager::create_directory(semester_dir);
        SubjectManager::create_subject_directories(semester_dir, semester.second, week_directory_manager);
    }
}
