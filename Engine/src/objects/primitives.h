#pragma once

#include "ew.h"
#include "object.h"

class Cube : public Object//тут примитивы, это обекты без моделек с уже предзагруженными мешами по факту всё тоже самое, токо для них не грузим модель из вне
{
public:
    Cube(std::string obj_name, std::string texture_path = "", std::string normal_path = "")
    {
        this->set_name(obj_name);
        this->position = glm::vec3(0.0f);
        this->scale = glm::vec3(1.0f);
        this->spin = {glm::vec3(0.0f), 0.0f};
        this->model = std::make_shared<Model>();
        this->set_model("");
        if (texture_path != "")
            this->set_texture(texture_path);
        if (normal_path != "")
            this->set_texture_norm(normal_path);
    }

    void set_model(const std::string path) override;
    void draw() override
    {
        for (auto &m : this->model->meshes)
            glDrawArrays(GL_TRIANGLES, 0, m->getVertexCount());
    }

private:
    std::vector<ew::Vertex> vertices = {
        // координаты       				 // текстурные координаты
        ew::Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
        ew::Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
        ew::Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
        ew::Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
        ew::Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
        ew::Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)},

        ew::Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
        ew::Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
        ew::Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
        ew::Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
        ew::Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
        ew::Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},

        ew::Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},

        ew::Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},

        ew::Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
        ew::Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
        ew::Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)},

        ew::Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
        ew::Vertex{glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
        ew::Vertex{glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
    };
};

class Pyramid : public Object
{
public:
    Pyramid(std::string obj_name, std::string texture_path = "", std::string normal_path = "")
    {
        this->set_name(obj_name);
        this->position = glm::vec3(0.0f);
        this->scale = glm::vec3(1.0f);
        this->spin = {glm::vec3(0.0f), 0.0f};
        this->model = std::make_shared<Model>();
        this->set_model("");
        if (texture_path != "")
            this->set_texture(texture_path);
        // if (normal_path != "")
        //     this->set_texture_norm(normal_path);
    }

    void set_model(const std::string path) override;
    void draw() override
    {
        for (auto &m : this->model->meshes)
            glDrawArrays(GL_TRIANGLES, 0, m->getVertexCount());
    }

private:
    std::vector<ew::Vertex> vertices = {
        ew::Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
        ew::Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
        ew::Vertex{glm::vec3(0.0f, 0.5f, 0.0f), glm::vec2(0.5f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)},

        ew::Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
        ew::Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
        ew::Vertex{glm::vec3(0.0f, 0.5f, 0.0f), glm::vec2(0.5f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)},

        ew::Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.0f, 0.5f, 0.0f), glm::vec2(0.5f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},

        ew::Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.0f, 0.5f, 0.0f), glm::vec2(0.5f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},

        ew::Vertex{glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.0f, 0.5f, 0.0f), glm::vec2(0.5f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)},

        ew::Vertex{glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
        ew::Vertex{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
        ew::Vertex{glm::vec3(0.0f, 0.5f, 0.0f), glm::vec2(0.5f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)}};
};

class Sphere : public Object
{
public:
    Sphere(std::string obj_name, std::string texture_path = "", std::string normal_path = "");

    void set_model(const std::string path) override;
    void draw() override
    {
        for (auto &m : this->model->meshes)
            glDrawElements(GL_TRIANGLES, m->getIndexCount(), GL_UNSIGNED_INT, 0);
    }
private:
    std::vector<ew::Vertex> vertices;
    std::vector<unsigned> indices;
};