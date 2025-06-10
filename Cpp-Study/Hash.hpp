#ifndef HASH_H
#define HASH_H

#include "HashFn.hpp"
#include <map>
#include <stdexcept>

template <
    typename KEY,
    typename VALUE,
    typename HASH_FN = HashFn<KEY>
>
class Hash
{
private:
    typedef std::map<KEY, VALUE> Map;
    typedef typename Map::const_iterator CIterator;

public:
    VALUE& operator[](const KEY& key)
    {
        size_t hashValue = HASH_FN::Get(key);
        return m_hashTable[hashValue][key];
    }

    const VALUE& operator[](const KEY& key) const
    {
        size_t hashValue = HASH_FN::Get(key);
        const Map& map = m_hashTable[hashValue];
        CIterator it = map.find(key);
        if (it == map.end()) {
            throw std::out_of_range("見つかりませんでした");
        }
        return it->second;
    }

private:
    Map m_hashTable[HASH_FN::SIZE];
};

#endif // !HASH_H
