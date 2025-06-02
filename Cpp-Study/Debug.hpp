#ifndef DEBUG_H_
#define DEBUG_H_

#ifdef NDEBUG
#define ASSERT(b)
#else   // デバッグ時

#define ASSERT(b) Debug::Assert((b), __FILE__, __LINE__)
namespace Debug
{
    void Assert(bool b, const char* file, int line);
}

#endif  // #ifdef NDEBUG
#endif  // #ifndef DEBUG_H_