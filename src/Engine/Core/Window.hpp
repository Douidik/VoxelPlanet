#ifndef VOXENG_WINDOW_HPP
#define VOXENG_WINDOW_HPP

#include "Misc/Serialization.hpp"

namespace VoxelEngine
{

class SERIALIZABLE(Window, Core)
{
public:
    Window();
    ~Window();

private:
    GLFWwindow *m_GLFWwindow;
};

} // namespace VoxelEngine

#endif
