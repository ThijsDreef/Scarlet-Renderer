#include <chrono>

class Timer {
public:
    Timer();
    ~Timer();
    void reset();
    double getElapsed();
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};