//----------------------------------------------------------------------------------------------------
// PerformanceTimer.cpp
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
#include "Game/PerformanceTimer.hpp"

//----------------------------------------------------------------------------------------------------
void PerformanceTimer::Start()
{
    start = std::chrono::high_resolution_clock::now();
}

//----------------------------------------------------------------------------------------------------
void PerformanceTimer::Stop()
{
    end = std::chrono::high_resolution_clock::now();
}

//----------------------------------------------------------------------------------------------------
double PerformanceTimer::GetElapsedMilliseconds() const
{
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return duration.count() / 1000000.0; // Convert to milliseconds
}

//----------------------------------------------------------------------------------------------------
double PerformanceTimer::GetElapsedMicroseconds() const
{
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    return duration.count() / 1000.0; // Convert to microseconds
}
