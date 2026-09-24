#pragma once
#include <string>
#include <filesystem>
#include <vector>
#include "File.h"
#include "Main.h"


enum class StateType {
    MainMenu,
    Explorer,
    SaveDialog,
    ExitDialog,

    EditorView, //ћеню с данными студентов
    EditorMenu, //ћеню с изменением данных

    EXIT,
};

/// <summary>
/// три задачи: запуск приложени€, координацию компонентов и переключение состо€ний.  онкретную работу делегировать соответствующим классам.
/// </summary>
class Application {
private:
    StateType current_state = StateType::MainMenu;

    Info app_info;
    File file_manager;
    StudentDB students_info;

    bool start_with_path;

public:
    Application(int argc, char* argv[]) : app_info(argc, argv), file_manager(app_info.getStartPath()) {
        fs::path start_path = app_info.getStartPath();
        if (!start_path.empty()) {
            current_state = StateType::EditorView;
            start_with_path = true;
        }
        else {
            start_with_path = false;
        }
    }
};

/*ѕлавность: „тобы консоль не мерцала при посто€нной перерисовке в фазе Show UI, очищайте экран не через system("cls"), а перемеща€ каретку в начало (0,0) через ANSI-последовательность \033[H или SetConsoleCursorPosition.*/