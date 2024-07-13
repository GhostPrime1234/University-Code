#include <filesystem>
#include <iostream>
#include "../headers/DirectoryManager.h"

namespace fs = std::filesystem;

DirectoryManager::DirectoryManager(const std::string &base_directory) {
    this->base_directory = base_directory;
        create_directory(this->base_directory);
    }

 void DirectoryManager::create_directory(const std::string& directory_path) {
    try {
        if (fs::create_directories(directory_path)) {
            std::cout << "Directory '" << directory_path << "' created" << std::endl;
        } else {
            std::cout << "Directory '" << directory_path << "' already exists" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error creating directory: " << e.what() << std::endl;
    }
}

std::vector<std::string> DirectoryManager::create_subdirectories(const std::string& m_base_directory, const std::vector<std::string>& m_subdirectories) {
    std::vector<std::string> created_dirs;
    for (const auto& subdir : m_subdirectories) {
        std::string subdir_path = m_base_directory + "\\" += subdir;
        DirectoryManager::create_directory(subdir_path);
        created_dirs.push_back(subdir_path);
    }
    return created_dirs;
}



void WeekDirectoryManager::create_weekly_directories(const std::string& classwork_dir) const {
    for (int week = 1; week <= total_weeks; ++week) {
        std::string week_dir = create_week_directory(classwork_dir, week);
        create_week_subdirectories(week_dir, week);
    }
}

std::string WeekDirectoryManager::create_week_directory(const std::string& classwork_dir, int week) {
    std::string week_dir = classwork_dir + "/Week " + std::to_string(week);
    DirectoryManager::create_directory(week_dir);
    return week_dir;
}

void WeekDirectoryManager::create_week_subdirectories(const std::string& week_dir, int week) {
    DirectoryManager::create_directory(week_dir + "/Lecture");
    if (2 <= week && week <= 12) {
        DirectoryManager::create_directory(week_dir + "/Lab");
    }
}