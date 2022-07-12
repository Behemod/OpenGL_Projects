#pragma once

#include "render/ew.h"
#include "render/shader.h"

class Camera
{
public:

    Camera(glm::vec3 pos, glm::vec3 dir);

    void set_position(glm::vec3 pos);
    void set_direction(glm::vec3 dir);

    glm::vec3 get_position();
    glm::vec3 get_direction();

    void render(std::shared_ptr<Shader>* shaderProgram);

private:

    glm::vec3 position;//от куда смотрит
    glm::vec3 direction;//куда смотрит
};