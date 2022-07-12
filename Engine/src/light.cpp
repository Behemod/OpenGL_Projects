#include "light.h"

Light::Light()
{
    lightPos = glm::vec3(0.0f, 0.0f, 5.0f);
    lightAmb = glm::vec3(0.2f, 0.2f, 0.2f);
    lightDiff = glm::vec3(0.5f, 0.5f, 0.5f);
    lightSpec = glm::vec3(1.0f, 1.0f, 1.0f);

    materialSpec = glm::vec3(0.5f, 0.5f, 0.5f);
    materialShine = 32.0f;
}

void Light::set_pos(glm::vec3 pos)
{
    lightPos = pos;
}

void Light::render(std::shared_ptr<Shader>* shaderProgram)
{
    auto temp = *shaderProgram; //перекидываем свет в шейдер
    
    temp->setUniformInt("material.diffuse", 0);
    temp->setUniformInt("material.normalMap", 1);
    temp->setUniformVec3("material.specular", materialSpec);
    temp->setUniformFloat("material.shininess", materialShine);

    temp->setUniformVec3("light.ambient", lightAmb);
    temp->setUniformVec3("light.diffuse", lightDiff);
    temp->setUniformVec3("light.specular", lightSpec);
    temp->setUniformVec3("light.position", lightPos);
}