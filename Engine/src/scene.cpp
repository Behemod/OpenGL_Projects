#include "scene.h"

#include "render/shader.h"

Scene::Scene()
{

    objects = std::make_shared<std::vector<Object *>>();//инитим всо
    
    camera = std::make_shared<Camera>(glm::vec3(3.0f), glm::vec3(0.0f));
    light = std::make_shared<Light>();
    shaderProgram = ShaderLoader::getInstance().load(".\\res\\shaders\\shader");
}

void Scene::render()
{
    shaderProgram->bind();

    glm::mat4 proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);//матрица проекции
    
    shaderProgram->setUniformMat4("projection", proj);//кидаем её в шейдеры

    light->render(&shaderProgram);//рисуем свет и камеру и их кидаем тож в шейдер
    camera->render(&shaderProgram);

    for (auto &obj_ : *objects)// рисуем объекты и кидаем в шейдер)
    {
        obj_->bind();
        glm::mat4 translation = glm::translate(glm::mat4(1.0f), obj_->get_position());
        glm::mat4 rotation = glm::rotate(glm::mat4(1.0f),glm::radians(obj_->get_rotation().spin_deg), obj_->get_rotation().spin_vec);
        glm::mat4 scale = glm::scale(glm::mat4(1.0f), obj_->get_scale());
        glm::mat4 model = translation * rotation * scale;
        shaderProgram->setUniformMat4("model", model);
        obj_->draw();
        obj_->unbind();
    }

    shaderProgram->unbind();
}