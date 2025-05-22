#include "DumpFile.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

const int PAGE_WIDTH = 16;
const int PAGE_HEIGHT = 16;
const int PAGE_SIZE = PAGE_WIDTH * PAGE_HEIGHT;

bool DumpFile::Run() {
    if (!Open()) {
        return false;
    }

    do {
        Dump();
    } while (Control());

    Close();

    return true;
}

bool DumpFile::Open() {
    string filename;

    cout << "ファイル名 > " << flush;
    getline(cin, filename);

    m_file.open(filename.c_str(), ios::in | ios::binary);
    m_page = 0;

    return m_file.is_open();
}

void DumpFile::Close() {
    m_file.close();
}

void DumpFile::Dump() {
    cout << endl;

    m_file.clear();
    m_file.seekg(m_page * PAGE_SIZE);

    for (int h = 0; h < PAGE_HEIGHT; h++) {
        unsigned char buf[PAGE_WIDTH];

        m_file.read((char*)buf, sizeof buf);

        ios::fmtflags flags = cout.flags();
        char fill = cout.fill();

        cout << setfill('0') << hex << uppercase;

        for (int w = 0, size = m_file.gcount(); w < size; w++) {
            cout << setw(2) << (int)buf[w] << ' ';
        }
        cout << endl;

        cout << setiosflags(flags) << setfill(fill);
    }
}

bool DumpFile::Control() {
    while (true) {
        string command;

        cout << "コマンド？ (n: 次 / p: 前 / q: 終了) > " << flush;
        getline(cin, command);

        if (command == "n") {
            if (!m_file.eof()) {
                ++m_page;
                return true;
            } else {
                // コマンドを再入力
            }
        } else if (command == "p") {
            if (m_page > 0) {
                --m_page;
                return true;
            } else {
                // コマンドを再入力
            }
        } else if (command == "q") {
            return false;
        }

    }
}