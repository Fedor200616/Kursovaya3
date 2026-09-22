#include <string>
#include <filesystem>
#include <vector>
#include "FileWork"

//Запись о студенте
struct StudentInfo {
    unsigned int num;
    std::string name;
    std::string group;
    std::string pass;
    std::string num;
}

struct WorkState {
    std::vector<StudentInfo> info; //Массив данных об учениках
    filesystem::path exe_filepath; //Путь к exe файлу программы
    bool is_modified; // Был ли модифицирован файл

    size_t sel_row = 0; // Выбранная строка
    StudentInfo sel_inf = 0; //выбранная информация
    size_t page_top = 0; // Первая видимая строка в отображении
}
