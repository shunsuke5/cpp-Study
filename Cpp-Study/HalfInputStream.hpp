#include "InputStream.hpp"

class HalfInputStream : public InputStream {
public:
    HalfInputStream();
protected:
    void SetBase();
};