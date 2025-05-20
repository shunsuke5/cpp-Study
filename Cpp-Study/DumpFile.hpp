#pragma once
#include <iostream>
#include <fstream>

class DumpFile {
public:
    bool Run();

private:
    bool Open();
    void Close();
    void Dump();
    bool Control();

private:
    std::fstream m_file;
    int m_page;
};