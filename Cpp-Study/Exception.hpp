#pragma once

class Exception {
public:
    virtual ~Exception();

public:
    virtual const char* What() const = 0;
};