#ifndef VOXENG_CLOCK_HPP
#define VOXENG_CLOCK_HPP

namespace VoxelEngine
{

using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

class Clock
{
public:
    Clock();

    void Resume();
    void Pause();

    inline bool IsRunning() const
    {
        return m_IsRunning;
    }

    std::chrono::duration<double> GetElapsedTime() const;

private:
    std::chrono::duration<double> m_PausedDuration;
    TimePoint m_PausePoint;
    bool m_IsRunning;

    TimePoint m_StartPoint;
};

} // namespace VoxelEngine

#endif
