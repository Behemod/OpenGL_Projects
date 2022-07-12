#include "primitives.h"

void Cube::set_model(const std::string path)
{
    this->model->meshes.push_back(new Mesh(this->vertices));
}

void Pyramid::set_model(const std::string path)
{
    this->model->meshes.push_back(new Mesh(this->vertices));
}

Sphere::Sphere(std::string obj_name, std::string texture_path, std::string normal_path)
{
    this->set_name(obj_name);
    this->position = glm::vec3(0.0f);
    this->scale = glm::vec3(1.0f);
    this->spin = {glm::vec3(0.0f), 0.0f};
    this->model = std::make_shared<Model>();

    if (texture_path != "")
        this->set_texture(texture_path);
    //генерим вершины для сферы с такими параметрами(на ней не работают текстурки)
    int stacks = 20;
    int slices = 20;
    const float PI = 3.14f;

    for (int i = 0; i <= stacks; ++i)
    {
        float V = (float)i / (float)stacks;
        float phi = V * PI;

        for (int j = 0; j <= slices; ++j)
        {

            float U = (float)j / (float)slices;
            float theta = U * (PI * 2);

            float x = cos(theta) * sin(phi);
            float y = cos(phi);
            float z = sin(theta) * sin(phi);
            vertices.push_back({glm::vec3{x, y, z}});
        }
        for (int i = 0; i < slices * stacks + slices; ++i)
        {
            indices.push_back(GLuint(i));
            indices.push_back(GLuint(i + slices + 1));
            indices.push_back(GLuint(i + slices));

            indices.push_back(GLuint(i + slices + 1));
            indices.push_back(GLuint(i));
            indices.push_back(GLuint(i + 1));
        }
    }
    this->set_model("");
}

void Sphere::set_model(const std::string path)
{
    this->model->meshes.push_back(new Mesh(this->vertices, this->indices, 0));
}