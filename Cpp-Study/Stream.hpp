#pragma once

class Stream {
public:
    Stream();
    Stream(double n);
    virtual ~Stream();
    double Get() const;
    bool Set();

protected:
    virtual void SetBase() = 0;
    double m_n;
};