#ifndef DIRECTORY_MANAGER_H
#define DIRECTORY_MANAGER_H

#include <string>
#include <vector>

class DirectoryManager {
public:
    explicit DirectoryManager(const std::string& base_directory);

    static void create_directory(const std::string& directory_path);

    static std::vector<std::string> create_subdirectories(const std::string& m_base_directory, const std::vector<std::string>& m_subdirectories);

private:
    std::string base_directory;
};
#endif // DIRECTORY_MANAGER_H

#ifndef WEEK_DIRECTORY_MANAGER_H
#define WEEK_DIRECTORY_MANAGER_H
class WeekDirectoryManager {
public:
    explicit WeekDirectoryManager(int total_weeks = 13) : total_weeks(total_weeks) {}

    void create_weekly_directories(const std::string& classwork_dir) const;

private:
    int total_weeks;

    static std::string create_week_directory(const std::string& classwork_dir, int week);

    static void create_week_subdirectories(const std::string& week_dir, int week);
};

#endif // WEEK_DIRECTORY_MANAGER_H
