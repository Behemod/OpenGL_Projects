#include "camera.h"

Camera::Camera(glm::vec3 pos = {}, glm::vec3 dir = {})
{
    set_position(pos);
    set_direction(dir);
}

void Camera::set_position(glm::vec3 pos)
{
    this->position = pos;
}

void Camera::set_direction(glm::vec3 dir)
{
    this->direction = dir;
}

glm::vec3 Camera::get_position()
{
    return this->position;
}

glm::vec3 Camera::get_direction()
{
    return this->direction;
}

void Camera::render(std::shared_ptr<Shader>* shaderProgram)
{
    auto temp = *shaderProgram;
    glm::mat4 view = glm::lookAt(position, direction, glm::vec3(0.0f, 1.0f, 0.0f));//видовая матрица помещается в шейдер
    temp->setUniformVec3("viewPos", position);
    temp->setUniformMat4("view", view);
}


