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

enum class State {
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
    State user_state;
    bool initExePath(int argc, char* argv[]) {
        if (argc > 0 && argv && argv[0]) {
            exe_filepath = std::filesystem::absolute(argv[0]);
            return true;
        }
        return false;
    }

public:
    MainState(int argc, char* argv[]) {
        if (!initExePath(argc, argv)) {
            std::cerr << "Внутренняя ошибка получения пути к EXE.";
            exe_filepath = fs::current_path();
        }
    }
    
    fs::path getExe() {
        return exe_filepath;
    }
    fs::path getExeDirectory() {
        return exe_filepath.parent_path();
    }

    bool changeState(State new_state);

};
