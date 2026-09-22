#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

enum class fileType{
    TXT,
    CSV
}

namespace FileStorage {
    bool loadFromFile (const fs::path& path, std::vector<StudentInfo>& Info); 
    bool saveToFile (const fs::path& path, std::vector<StudentInfo>& Info);

    bool createBackup(const fs::path& main_path, const std::vector<StudentInfo>& Info);
    bool removeBackup(const std::string& main_path);
}

class FileExplorer{
public:
    fs::path ExplorerUI(fs::path directory);

private:
    fs::path TurnBack(fs::path directory);
    fs::path OpenFolder(fs::path directory, std::string name);
    fs::path FileOpen(fs::path directory, std::string name);
}