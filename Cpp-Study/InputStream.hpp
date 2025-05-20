#pragma once
#include "Stream.hpp"

class InputStream : public Stream {
public:
    InputStream(double n);
    void SetBase();
};