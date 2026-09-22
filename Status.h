#pragma once
#include <string>
#include <filesystem>
#include <vector>
#include "FileWork.h"

//Запись о студенте
struct StudentInfo {
    unsigned int i;
    std::string name;
    std::string group;
    std::string pass;
    std::string num;
};

enum class Inf {
    num,
    name,
    group,
    pass,
    digit
};

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
    StateType user_state;
   

public:
    bool initExePath(int argc, char* argv[]) {
        if (argc > 0 && argv && argv[0]) {
            exe_filepath = std::filesystem::absolute(argv[0]);
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
