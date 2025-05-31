#include <iostream>
#include "FileHandle.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8); // ϳ������� UTF-8 � Windows-������

    FileHandle fh;

    // �����
    if (fh.open("output.txt", std::ios::out)) {
        fh << "Hello";
        fh.close();
    }

    // ����������
    std::string content;
    if (fh.open("output.txt", std::ios::in)) {
        fh >> content;
        fh.close();
    }

    std::cout << content << std::endl;
    return 0;
}
