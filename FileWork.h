#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

enum class fileType{
    TXT,
    CSV
}

class File {
public:
    fs::path filePath;
    fileType type;

    bool loadFromFile (std::vector<StudentInfo>& Info); 
    bool saveToFile (std::vector<StudentInfo>& Info);

    bool createBackup(fs::path& main_path, const std::vector<StudentInfo>& Info);
    bool removeBackup(const fs::path& main_path);

private:
    fs::path GetPath(){ 
        return filePath;
    }
    fileType GetType(){
        return type;
    }


}

class FileExplorer{
public:
    fs::path ExplorerUI(fs::path directory);

private:
    fs::path TurnBack(fs::path directory);
    fs::path OpenFolder(fs::path directory, std::string name);
    fs::path FileOpen(fs::path directory, std::string name);
}