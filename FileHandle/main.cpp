#include <iostream>
#include "FileHandle.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8); // Підтримка UTF-8 у Windows-консолі

    FileHandle fh;

    // Запис
    if (fh.open("output.txt", std::ios::out)) {
        fh << "Hello";
        fh.close();
    }

    // Зчитування
    std::string content;
    if (fh.open("output.txt", std::ios::in)) {
        fh >> content;
        fh.close();
    }

    std::cout << content << std::endl;
    return 0;
}
