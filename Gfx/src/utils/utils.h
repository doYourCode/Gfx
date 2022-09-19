#include <vector>
#include <sstream>
#include <SDL.h>
#include <iostream>

/*
std::vector<std::string> Split(const std::string& s, char delim)
{
    std::vector<std::string> elems;

    const char* cstr = s.c_str();
    unsigned int strLength = s.length();
    unsigned int start = 0;
    unsigned int end = 0;

    while (end <= strLength)
    {
        while (end <= strLength)
        {
            if (cstr[end] == delim)
                break;
            end++;
        }

        elems.push_back(s.substr(start, end - start));
        start = end + 1;
        end = start;
    }

    return elems;
}*/

namespace Gfx
{

    class DebugTimer
    {
    public:
        void Start()
        {
            startTime = SDL_GetTicks();
        }

        void End(const std::string& message)
        {
            unsigned int endTime = SDL_GetTicks();
            std::cout << message << (endTime - startTime) << "ms" << std::endl;
        }

    protected:
    private:
        unsigned int startTime;
    };

}