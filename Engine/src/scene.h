#pragma once

#include "ew.h"
#include "object.h"
#include "camera.h"
#include "shader.h"
#include "primitives.h"
#include "light.h"

class Scene
{
public:
    Scene();

    void render();

    std::shared_ptr<std::vector<Object *>> get_objects()
    {
        return objects;
    }

    std::shared_ptr<Light> get_light()
    {
        return light;
    }

    std::shared_ptr<Camera> get_camera()
    {
        return camera;
    }

private:
    std::shared_ptr<std::vector<Object *>> objects;//объекты сцены
    std::shared_ptr<Camera> camera;//камера
    std::shared_ptr<Shader> shaderProgram;//шейдер
    std::shared_ptr<Light> light;//свет
    // shader...
};