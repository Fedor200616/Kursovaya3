#pragma once
#include <filesystem>
#include <iostream>
#include <vector>

#include "Student.h"
#include "Main.h"

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
    bool is_modified = false; // Был ли модифицирован файл
public:
    bool loadFromFile(std::vector<StudentInfo>& Info);
    bool saveToFile(const std::vector<StudentInfo>& Info);
    bool createBackup(const fs::path& main_path, const std::vector<StudentInfo>& Info);
    bool removeBackup(const fs::path& main_path);

    bool isModified() const {
        return is_modified;
    }
};

