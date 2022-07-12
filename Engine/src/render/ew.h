#pragma once

// std includes
#include <string>
#include <vector>
#include <iostream>
#include <memory>

// 3d includes
#include "GL/glew.h"
#include "utils/shaderLoader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"

namespace ew
{
    template <typename T>
    struct Id
    {
        Id(size_t id_ = 0) : id(id_) {}
        unsigned id = 0;
    };

    struct Vertex
    {
        glm::vec3 pos;
        glm::vec2 uv;
        glm::vec3 norm;
        glm::vec3 tangent;
        glm::vec3 bitangent;
    };
}