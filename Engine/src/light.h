#pragma once

#include "render/ew.h"
#include "render/shader.h"

class Light
{
public:
    Light();
    void render(std::shared_ptr<Shader>* shaderProgram);
    void set_pos(glm::vec3 pos);
    void set_shine(float shine)
    {
        materialShine = shine;
    }
    float get_shine()
    {
        return materialShine;
    }
private:
    glm::vec3 lightPos; //параметры света в ините они лежат
	glm::vec3 lightAmb;
	glm::vec3 lightDiff;
	glm::vec3 lightSpec;

    glm::vec3 materialSpec;
    float materialShine;
};