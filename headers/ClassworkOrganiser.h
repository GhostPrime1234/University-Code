#ifndef CLASSWORK_ORGANISER_H
#define CLASSWORK_ORGANISER_H

#include <string>
#include <map>
#include <vector>
#include "DirectoryManager.h"
#include "SubjectManager.h"

class ClassworkOrganiser {
public:
    ClassworkOrganiser(const std::string& base_directory, std::string year, const std::map<std::string, std::vector<std::pair<std::string, std::string>>>& semester_subjects);

    void create_year_and_subject_dirs();

private:
    std::string base_directory;
    std::string year;
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> semester_subjects;
    DirectoryManager directory_manager;
    WeekDirectoryManager week_directory_manager;
    [[maybe_unused]] SubjectManager subject_manager;
};

#endif // CLASSWORK_ORGANISER_H
