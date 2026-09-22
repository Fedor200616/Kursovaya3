#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

namespace FileStorage {
    bool loadFromFile (const fs::path& path, std::vector<StudentInfo>& Info); 
    bool saveToFile (const fs::path& path, std::vector<StudentInfo>& Info);

    bool createBackup(const fs::path& main_path, const std::vector<StudentInfo>& Info);
    bool removeBackup(const std::string& main_path);
}
