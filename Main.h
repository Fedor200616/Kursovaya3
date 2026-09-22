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

class MainState {
private:
    std::vector<StudentInfo> info; //Массив данных об учениках
    fs::path exe_filepath; //Путь к exe файлу программы
    StateType user_state = StateType::MainMenu;


public:
    bool initExePath(int argc, char* argv[]) {
        if (argc > 0 && argv && argv[0]) {
            exe_filepath = fs::absolute(argv[0]);
            return true;
        }
        return false;
    }

    fs::path getExe() const {
        return exe_filepath;
    }
    fs::path getExeDirectory() const {
        return exe_filepath.parent_path();
    }

    bool changeState(StateType new_state);

};

inline MainState MainInfo;