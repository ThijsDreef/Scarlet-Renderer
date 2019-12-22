#include "Scarlet/Utils/Timer.h"

Timer::Timer() {
    startTime = std::chrono::high_resolution_clock::now();
}

Timer::~Timer() {

}

void Timer::reset() {
    startTime = std::chrono::high_resolution_clock::now();
}

double Timer::getElapsed() {
    return std::chrono::duration<double, std::ratio<1>>(std::chrono::high_resolution_clock::now() - startTime).count();
}