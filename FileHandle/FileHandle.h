#pragma once
#include <fstream>
#include <string>

class FileHandle {
private:
    std::fstream file;

public:
    FileHandle() = default;
    ~FileHandle();

    bool open(const std::string& filename, std::ios::openmode mode);
    void close();

    friend FileHandle& operator<<(FileHandle& fh, const std::string& data);
    friend FileHandle& operator>>(FileHandle& fh, std::string& data);
};
