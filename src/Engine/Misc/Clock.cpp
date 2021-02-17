#include "Clock.hpp"

namespace VoxelEngine
{

Clock::Clock()
    : m_PausedDuration(0.0)
    , m_StartPoint(std::chrono::system_clock::now())
    , m_IsRunning(true)
{
}

void Clock::Resume()
{
    if (m_IsRunning)
    {
        TimePoint now = std::chrono::system_clock::now();
        m_PausedDuration += (now - m_PausePoint);
        m_IsRunning = true;
    }
    else
    {
        VOXENG_WARN_LOG("The clock is already running");
    }
}

void Clock::Pause()
{
    if (!m_IsRunning)
    {
        m_PausePoint = std::chrono::system_clock::now();
        m_IsRunning = false;
    }
    else
    {
        VOXENG_WARN_LOG("The clock is already paused");
    }
}

std::chrono::duration<double> Clock::GetElapsedTime() const
{
    TimePoint now = std::chrono::system_clock::now();
    return std::chrono::duration<double>(now - m_StartPoint);
}

} // namespace VoxelEngine
