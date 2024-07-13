#ifndef SUBJECT_MANAGER_H
#define SUBJECT_MANAGER_H

#include <string>
#include <vector>
#include "DirectoryManager.h"

class SubjectManager {
public:
    static void create_subject_directories(const std::string& semester_dir,
                                           const std::vector<std::pair<std::string, std::string>>& subjects,
                                           const WeekDirectoryManager& week_directory_manager);
private:
    static void create_subject_subdirectories(const std::string& subject_dir,
                                              const WeekDirectoryManager& week_directory_manager);
};

#endif // SUBJECT_MANAGER_H