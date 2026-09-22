#pragma once
#include <iostream>
#include <vector>

struct MenuOut {
    int total_row;
    std::vector<int> show_row;
    int act_row;



};

class MenuLogic {
public:
    bool showUI();

    bool windowSize();
protected:
    virtual std::string menuString() {};
};

class MainMenu : public MenuLogic {

};

class Editor : public MenuLogic {

};
