#include <random>
#include <Operations.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

template <typename T, typename Ti>
bool vec_eq(T my_vec, Ti glm_vec, int size)
{
    bool eq = true;
    for (int i = 0; i < size; i++)
    {
        if (my_vec[i] - remainderf(my_vec[i], pow(10, -4)) != glm_vec[i] - remainderf(glm_vec[i], pow(10, -4)))
        {
            eq = false;
            return eq;
        }
    }
    return eq;
}

template <typename T, typename Ti>
bool mat_eq(T my_mat, Ti glm_mat, int size)
{
    bool eq = true;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (my_mat[i][j] - remainderf(my_mat[i][j], pow(10, -3)) != glm_mat[i][j] - remainderf(glm_mat[i][j], pow(10, -3)))
            {
                eq = false;
                return eq;
            }
        }
    }
    return eq;
}

void vector_test()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-1000, 1000);

    { 
        glm::vec2 glm_vec1;
        glm::vec2 glm_vec2;
        Vector2 my_vec1;
        Vector2 my_vec2;

        for (int i = 0; i < 2; i++)
        {
            float temp = dist(gen);
            glm_vec1[i] = temp;
            my_vec1[i] = temp;
            temp = dist(gen);
            glm_vec2[i] = temp;
            my_vec2[i] = temp;
        }
        
        assert(vec_eq(my_vec1, glm_vec1, 2));
        assert(vec_eq(my_vec2, glm_vec2, 2));
        assert(vec_eq(my_vec1 + my_vec2, glm_vec1 + glm_vec2, 2));
        assert(vec_eq(my_vec1 - my_vec2, glm_vec1 - glm_vec2, 2));
        {
            int temp = dist(gen);
            auto temp_glm_vec = glm_vec1;
            assert(vec_eq(my_vec1 * temp, temp_glm_vec.operator*=(temp), 2));
            temp = dist(gen);
            temp_glm_vec = glm_vec2;
            assert(vec_eq(my_vec2 * temp, temp_glm_vec.operator*=(temp), 2));
        }
        assert(vec_eq(my_vec1 * my_vec2, glm_vec1 * glm_vec2, 2));
        assert(length(my_vec1) == glm::length(glm_vec1));
        assert(length(my_vec2) == glm::length(glm_vec2));
        assert(vec_eq(normalize(my_vec1), glm::normalize(glm_vec1), 2));
        assert(vec_eq(normalize(my_vec2), glm::normalize(glm_vec2), 2));
        assert(vec_eq(reverse(my_vec1), -glm_vec1, 2));
        assert(vec_eq(reverse(my_vec2), -glm_vec2, 2));
        assert(dot_product(my_vec1, my_vec2) == glm::dot(glm_vec1, glm_vec2));
    }

    {
        glm::vec3 glm_vec1;
        glm::vec3 glm_vec2;
        Vector3 my_vec1;
        Vector3 my_vec2;

        for (int i = 0; i < 3; i++)
        {
            float temp = dist(gen);
            glm_vec1[i] = temp;
            my_vec1[i] = temp;
            temp = dist(gen);
            glm_vec2[i] = temp;
            my_vec2[i] = temp;
        }
        assert(vec_eq(my_vec1, glm_vec1, 3));
        assert(vec_eq(my_vec2, glm_vec2, 3));
        assert(vec_eq(my_vec1 + my_vec2, glm_vec1 + glm_vec2, 3));
        assert(vec_eq(my_vec1 - my_vec2, glm_vec1 - glm_vec2, 3));
        {
            int temp = dist(gen);
            auto temp_glm_vec = glm_vec1;
            assert(vec_eq(my_vec1 * temp, temp_glm_vec.operator*=(temp), 3));
            temp = dist(gen);
            temp_glm_vec = glm_vec2;
            assert(vec_eq(my_vec2 * temp, temp_glm_vec.operator*=(temp), 3));
        }
        assert(vec_eq(my_vec1 * my_vec2, glm_vec1 * glm_vec2, 3));
        assert(length(my_vec1) == glm::length(glm_vec1));
        assert(length(my_vec2) == glm::length(glm_vec2));
        assert(vec_eq(normalize(my_vec1), glm::normalize(glm_vec1), 3));
        assert(vec_eq(normalize(my_vec2), glm::normalize(glm_vec2), 3));
        assert(vec_eq(reverse(my_vec1), -glm_vec1, 3));
        assert(vec_eq(reverse(my_vec2), -glm_vec2, 3));
        assert(dot_product(my_vec1, my_vec2) == glm::dot(glm_vec1, glm_vec2));
        assert(vec_eq(cross_product(my_vec1, my_vec2), glm::cross(glm_vec1, glm_vec2), 3));
    }

    {
        glm::vec4 glm_vec1;
        glm::vec4 glm_vec2;
        Vector4 my_vec1;
        Vector4 my_vec2;

        for (int i = 0; i < 4; i++)
        {
            float temp = dist(gen);
            glm_vec1[i] = temp;
            my_vec1[i] = temp;
            temp = dist(gen);
            glm_vec2[i] = temp;
            my_vec2[i] = temp;
        }
        assert(vec_eq(my_vec1, glm_vec1, 4));
        assert(vec_eq(my_vec2, glm_vec2, 3));
        assert(vec_eq(my_vec1 + my_vec2, glm_vec1 + glm_vec2, 4));
        assert(vec_eq(my_vec1 - my_vec2, glm_vec1 - glm_vec2, 4));
        {
            int temp = dist(gen);
            auto temp_glm_vec = glm_vec1;
            assert(vec_eq(my_vec1 * temp, temp_glm_vec.operator*=(temp), 4));
            temp = dist(gen);
            temp_glm_vec = glm_vec2;
            assert(vec_eq(my_vec2 * temp, temp_glm_vec.operator*=(temp), 4));
        }
        assert(vec_eq(my_vec1 * my_vec2, glm_vec1 * glm_vec2, 4));
        assert(length(my_vec1) == glm::length(glm_vec1));
        assert(length(my_vec2) == glm::length(glm_vec2));
        assert(vec_eq(normalize(my_vec1), glm::normalize(glm_vec1), 4));
        assert(vec_eq(normalize(my_vec2), glm::normalize(glm_vec2), 4));
        assert(vec_eq(reverse(my_vec1), -glm_vec1, 4));
        assert(vec_eq(reverse(my_vec2), -glm_vec2, 4));
        assert(dot_product(my_vec1, my_vec2) == glm::dot(glm_vec1, glm_vec2));
    }

    std::cout << "Vector math: OK" << std::endl;
}

void matrix_test()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-1000, 1000);
    {
        Mat3 my_mat1;
        Mat3 my_mat2;
        glm::mat3 glm_mat1;
        glm::mat3 glm_mat2;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                float temp = dist(gen);
                my_mat1[i][j] = temp;
                glm_mat1[i][j] = temp;
                temp = dist(gen);
                my_mat2[i][j] = temp;
                glm_mat2[i][j] = temp;
            }
        }

        assert(mat_eq(my_mat1, glm_mat1, 3));
        assert(mat_eq(my_mat2, glm_mat2, 3));
        assert(mat_eq(my_mat1 + my_mat2, glm_mat1 + glm_mat2, 3));
        assert(mat_eq(my_mat1 - my_mat2, glm_mat1 - glm_mat2, 3));
        {
            int temp = dist(gen);
            auto temp_glm_mat = glm_mat1;
            assert(mat_eq(my_mat1 * temp, temp_glm_mat.operator*=(temp), 3));
            temp = dist(gen);
            temp_glm_mat = glm_mat2;
            assert(mat_eq(my_mat2 * temp, temp_glm_mat.operator*=(temp), 3));
        }
        assert(mat_eq(my_mat1 * my_mat2, glm_mat1 * glm_mat2, 3));
        assert(mat_eq(my_mat2 * my_mat1, glm_mat2 * glm_mat1, 3));
        assert(mat_eq(transpose(my_mat1), glm::transpose(glm_mat1), 3));
        assert(mat_eq(transpose(my_mat2), glm::transpose(glm_mat2), 3));
        assert(mat_eq(inverse(my_mat1), glm::inverse(glm_mat1), 3));
        assert(mat_eq(inverse(my_mat2), glm::inverse(glm_mat2), 3));
    }
    {
        Mat4 my_mat1;
        Mat4 my_mat2;
        glm::mat4 glm_mat1;
        glm::mat4 glm_mat2;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                float temp = dist(gen);
                my_mat1[i][j] = temp;
                glm_mat1[i][j] = temp;
                temp = dist(gen);
                my_mat2[i][j] = temp;
                glm_mat2[i][j] = temp;
            }
        }

        assert(mat_eq(my_mat1, glm_mat1, 4));
        assert(mat_eq(my_mat2, glm_mat2, 4));
        assert(mat_eq(my_mat1 + my_mat2, glm_mat1 + glm_mat2, 4));
        assert(mat_eq(my_mat1 - my_mat2, glm_mat1 - glm_mat2, 4));
        {
            int temp = dist(gen);
            auto temp_glm_mat = glm_mat1;
            assert(mat_eq(my_mat1 * temp, temp_glm_mat.operator*=(temp), 4));
            temp = dist(gen);
            temp_glm_mat = glm_mat2;
            assert(mat_eq(my_mat2 * temp, temp_glm_mat.operator*=(temp), 4));
        }
        assert(mat_eq(my_mat1 * my_mat2, glm_mat1 * glm_mat2, 4));
        assert(mat_eq(my_mat2 * my_mat1, glm_mat2 * glm_mat1, 4));
        assert(mat_eq(transpose(my_mat1), glm::transpose(glm_mat1), 4));
        assert(mat_eq(transpose(my_mat2), glm::transpose(glm_mat2), 4));
        assert(mat_eq(inverse(my_mat1), glm::inverse(glm_mat1), 4));
        assert(mat_eq(inverse(my_mat2), glm::inverse(glm_mat2), 4));
        {
            Vector3 my_temp_vec(dist(gen), dist(gen), dist(gen));
            glm::vec3 glm_temp_vec(my_temp_vec[0], my_temp_vec[1], my_temp_vec[2]);
            assert(mat_eq(translationMat(my_temp_vec), glm::translate(glm::mat4(1.0f), glm_temp_vec), 4));
        }
        {
            Vector3 my_temp_vec(dist(gen), dist(gen), dist(gen));
            glm::vec3 glm_temp_vec(my_temp_vec[0], my_temp_vec[1], my_temp_vec[2]);
            assert(mat_eq(scaleMat(my_temp_vec), glm::scale(glm::mat4(1.0f), glm_temp_vec), 4));
        }
        {
            Vector3 my_temp_vec(dist(gen), dist(gen), dist(gen));
            glm::vec3 glm_temp_vec(my_temp_vec[0], my_temp_vec[1], my_temp_vec[2]);
            float angle = dist(gen);
            assert(mat_eq(rotateMat(my_temp_vec, radians(angle)), glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm_temp_vec), 4));
        }
        {
            Vector3 my_from_vec(dist(gen), dist(gen), dist(gen));
            Vector3 my_to_vec(dist(gen), dist(gen), dist(gen));
            glm::vec3 glm_from_vec(my_from_vec[0], my_from_vec[1], my_from_vec[2]);
            glm::vec3 glm_to_vec(my_to_vec[0], my_to_vec[1], my_to_vec[2]);
            assert(mat_eq(CreateViewMatrix(my_from_vec, my_to_vec, Vector3(0.0f, 1.0f, 0.0f)), glm::lookAt(glm_from_vec, glm_to_vec, glm::vec3(0.0f, 1.0f, 0.0f)), 4));
        }
        {
            float left = dist(gen);
            float right = dist(gen);
            if (left > right)
                std::swap(left, right);
            float bottom = dist(gen);
            float top = dist(gen);
            if (bottom > top)
                std::swap(bottom, top);
            float near = dist(gen);
            float far = dist(gen);
            if (near > far)
                std::swap(near, far);
            assert(mat_eq(ortho(left, right, bottom, top, near, far), glm::ortho(left, right, bottom, top, near, far), 4));
        }
        {
            float fov = dist(gen);
            float aspect = dist(gen);
            float near = dist(gen);
            float far = dist(gen);
            if (near > far)
                std::swap(near, far);
            assert(mat_eq(perspective(radians(fov), aspect, near, far), glm::perspective(radians(fov), aspect, near, far), 4));
        }

    }

    std::cout << "Matrix math: OK" << std::endl;
}