#pragma once

class Stream {
public:
    double Get() const;
    bool Set();

protected:
    virtual void SetBase();
    double m_n;
};