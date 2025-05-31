#include "FileHandle.h"

bool FileHandle::open(const std::string& filename, std::ios::openmode mode) {
    file.open(filename, mode);
    return file.is_open();
}

void FileHandle::close() {
    if (file.is_open()) {
        file.close();
    }
}

FileHandle::~FileHandle() {
    close();
}

FileHandle& operator<<(FileHandle& fh, const std::string& data) {
    if (fh.file.is_open()) {
        fh.file << data;
    }
    return fh;
}

FileHandle& operator>>(FileHandle& fh, std::string& data) {
    if (fh.file.is_open()) {
        std::getline(fh.file, data);
    }
    return fh;
}
