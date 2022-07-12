#pragma once

#include "ew.h"
#include "model.h"
#include "texture.h"

class Object//объектики на нашей сцене
{
    struct Spin
    {
        glm::vec3 spin_vec;
        float spin_deg;
    };

public:
    Object() {}

    Object(std::string obj_name, std::string model_path, std::string texture_path = "", std::string normal_path = "")
    {
        this->set_name(obj_name);//создаем с такими параметрами
        this->position = glm::vec3(0.0f);
        this->scale = glm::vec3(1.0f);
        this->spin = {glm::vec3(0.0f), 0.0f};
        this->model = std::make_shared<Model>();
        this->set_model(model_path);//устанавливаем модель
        if (texture_path != "")
            this->set_texture(texture_path);//текстуру
        if (normal_path != "")
            this->set_texture_norm(normal_path);//и нормали
    }

    virtual void draw()
    {
        for (auto &m : this->model->meshes)//рисуем каждую вершинку
            glDrawElements(GL_TRIANGLES, m->getIndexCount(), GL_UNSIGNED_INT, 0);
    }

    void bind()
    {
        if (this->texture != 0x0)//загружаем текстурку токо если она есть
        {
            this->texture->bind(0);
        }
        if (this->textureNorm != 0x0)
        {
            this->textureNorm->bind(1);
        }
        for (auto &m : this->model->meshes)
            m->bind();
    }

    void unbind()
    {
        this->texture->unbind(0);
        this->textureNorm->unbind(1);
        for (auto &m : this->model->meshes)
            m->unbind();
    }

    void set_name(std::string name)//далее методы для получения и установки параметров у объекта, по названию должно быть очевидно что и где
    {
        this->name = name;
    }

    std::string get_name()
    {
        return this->name;
    }

    virtual void set_model(const std::string path);

    void set_texture(std::string path)
    {
        this->texture = TextureLoader::getInstance().load(path);
    }

    void set_texture_norm(std::string path)
    {
        this->textureNorm = TextureLoader::getInstance().load(path);
    }

    void set_position(glm::vec3 pos)
    {
        this->position = pos;
    }

    glm::vec3 get_position()
    {
        return this->position;
    }

    void set_scale(glm::vec3 scale)
    {
        this->scale = scale;
    }

    glm::vec3 get_scale()
    {
        return this->scale;
    }

    void set_rotation(glm::vec3 spin_vec, float spin_deg)
    {
        if (spin_deg > 360)
            spin_deg = 360;
        else if (spin_deg < -360)
            spin_deg = -360;
        this->spin = {spin_vec, spin_deg};
    }

    Spin get_rotation()
    {
        return this->spin;
    }

protected:
    ew::Id<Object> id;
    std::string name;
    std::shared_ptr<Model> model;
    std::shared_ptr<Texture> texture;
    std::shared_ptr<Texture> textureNorm;
    glm::vec3 position;
    glm::vec3 scale;
    Spin spin;
    int rotationX;
    int rotationY;
    int rotationZ;
};