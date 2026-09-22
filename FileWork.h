#pragma once
#include <filesystem>
#include <iostream>
#include <vector>

#include "Status.h"

namespace fs = std::filesystem;

enum class fileType {
    NONE,
    TXT,
    CSV
};

class File {
private:
    fs::path filePath = ""; // путь к файлу
    fileType type = fileType::NONE; // тип файла
    bool is_modified = 0; // Был ли модифицирован файл
public:
    bool loadFromFile(std::vector<StudentInfo>& Info);
    bool saveToFile(std::vector<StudentInfo>& Info);
    bool createBackup(fs::path& main_path, const std::vector<StudentInfo>& Info);
    bool removeBackup(const fs::path& main_path);

    bool isModified() {
        return is_modified;
    }
};

class FileExplorer {
public:
    fs::path ExplorerUI(fs::path directory);

private:
    fs::path TurnBack(fs::path directory);
    fs::path OpenFolder(fs::path directory, std::string name);
    fs::path FileOpen(fs::path directory, std::string name);
};