#pragma once
#include <filesystem>
#include <iostream>
#include "Student.h"

namespace fs = std::filesystem;

enum class StateType {
    MainMenu,
    Explorer,
    SaveDialog,
    ExitDialog,

    EditorView,
    EditorMenu,
};

class Info {
private:
    fs::path exe_filepath; //Путь к exe файлу программы
    bool initExePath(int argc, char* argv[]) {
        if (argc > 0 && argv && argv[0]) {
            exe_filepath = fs::absolute(argv[0]);
            return true;
        }
        return false;
    }

public:
    Info(int argc, char* argv[]) {
        if (!initExePath(argc, argv)) {
            exe_filepath = fs::current_path();
        }
    }

    fs::path getExe() const {
        return exe_filepath;
    }
    fs::path getExeDirectory() const {
        return exe_filepath.parent_path();
    }

};