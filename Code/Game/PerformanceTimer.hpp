//----------------------------------------------------------------------------------------------------
// PerformanceTimer.hpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#pragma once

#include <chrono>

//----------------------------------------------------------------------------------------------------
struct PerformanceTimer
{
    void   Start();
    void   Stop();
    double GetElapsedMilliseconds() const;
    double GetElapsedMicroseconds() const;

    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
};
