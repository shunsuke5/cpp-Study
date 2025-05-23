#include "FileException.hpp"

FileException::FileException(const char* error) {
    m_error = error;
}

const char* FileException::What() const {
    return m_error.c_str();
}

OpenFileException::OpenFileException(const char* filename) 
    : FileException("ファイルを開けませんでした")
{
    m_error += "\nファイル名： ";
    m_error += filename;
}

ReadFileException::ReadFileException()
    : FileException("ファイルから読み込めませんでした") {}