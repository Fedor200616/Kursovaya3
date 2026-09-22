#pragma once
#include <string>
#include <filesystem>
#include <vector>
#include "FileWork.h"


enum class StateType {
    MainMenu,
    Explorer,
    SaveDialog,
    ExitDialog,
    
    EditorView,
    EditorMenu,
};



/*ѕлавность: „тобы консоль не мерцала при посто€нной перерисовке в фазе Show UI, очищайте экран не через system("cls"), а перемеща€ каретку в начало (0,0) через ANSI-последовательность \033[H или SetConsoleCursorPosition.*/