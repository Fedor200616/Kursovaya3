#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <conio.h>
#include "FileWork.h"

namespace input {
    enum class key
    {
        Up = 72,
        Down = 80,
        Left = 75,
        Right = 77,

        Enter = 13,
        Esc = 27,

        Tab = 9,

        Utility = 224,
        Null = 0
    };

    key getKey() {
        int ch = _getch();

        // Если считн служебный байт стрелок/расширенных клавиш (0 или 224)
        if (ch == 0 || ch == static_cast<int>(key::Utility)) {
            ch = _getch(); // Читаем второй байт с реальным кодом стрелки
        }

        // Преобразуем код в enum
        switch (ch) {
        case static_cast<int>(key::Up):    return key::Up;
        case static_cast<int>(key::Down):  return key::Down;
        case static_cast<int>(key::Left):  return key::Left;
        case static_cast<int>(key::Right): return key::Right;
        case static_cast<int>(key::Enter): return key::Enter;
        case static_cast<int>(key::Esc):   return key::Esc;
        case static_cast<int>(key::Tab):   return key::Tab;
        default:                           return key::Null;
        }
    }
}


struct MenuOut {
    int total_row;
    std::vector<int> set_row;
    std::vector<int> show_row;
    int act_row;

    std::string before_show = "";
    std::vector<std::string> menu;
    std::vector<std::function<std::string()>> MenuParam;
    std::string post_show = "";

    std::string ActMark = "->";
    std::string InactMark = "  ";

    

};

enum class MenuNav {
    Left,
    Right,
    Up,
    Down,

    Enter,

    Add1,
};

/// <summary>
/// Базовый абстрактный класс - родитель для любого меню
/// </summary>
class MenuLogic {
public:
    virtual ~MenuLogic() = default;
    
    virtual void beforeShow(MenuOut& menu) {};
    virtual bool showUI(const MenuOut& menu);
    virtual void handleNav(MenuNav nav) = 0;

protected:
    bool windowSize();
    MenuNav GetAction(input::key key_code) const;
    virtual std::string menuString() {};
    
};

class MainMenu : public MenuLogic {

};

class ExplorerMenu : public MenuLogic, public FileExplorer {

};