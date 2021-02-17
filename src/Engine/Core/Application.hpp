#ifndef VOXENG_APPLICATION_HPP
#define VOXENG_APPLICATION_HPP

namespace VoxelEngine
{

class Application
{
protected:
    Application();

    virtual void OnStart() {}
    virtual void OnUpdate() {}
    virtual void OnRender() {}
    virtual void OnDestroy() {}
};

}

#endif
