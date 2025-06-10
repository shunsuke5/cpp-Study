#ifndef HASH_FN_
#define HASH_FN_

#include <cstddef>

template <typename TYPE>
class HashFn
{
public:
    static size_t Get(const TYPE& value);
    static const size_t SIZE = 23;
};

#endif // !HASH_FN_

