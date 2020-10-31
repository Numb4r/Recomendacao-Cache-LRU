#include <chrono>
#include <string_view>
#include <iostream>
class Timer
{
private:
    std::chrono::steady_clock::time_point m_start;
public:
    Timer() : m_start(std::chrono::steady_clock::now()){}
    
    void ShowResult(std::string_view message =""){
        auto end = std::chrono::steady_clock::now();
        auto diferrence = end-m_start;
        std::cout<< message 
        <<":"
        << std::chrono::duration_cast<std::chrono::milliseconds>(diferrence).count()
        <<" miliseconds"
        <<std::endl;
    }
    void Reset(){
        m_start = std::chrono::steady_clock::now();
    }
};
