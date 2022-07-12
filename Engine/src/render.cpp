#include "render.h"

Render::Render(std::shared_ptr<sf::RenderWindow> window)
{
    glEnable(GL_DEPTH_TEST);//запускаем глю

    glewExperimental = GL_TRUE;

    if (GLEW_OK != glewInit())
    { // включить glew
        std::cout << "Error:: glew not init =(" << std::endl;//если чото пошло не так, но по идеи не должно
    }

    scene = std::make_shared<Scene>();
    menu = std::make_shared<Menu>(window, scene);
}

void Render::render()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);//удаляем объекты прошлого кадра и устанавливаем фоновый цвет
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    scene->render();//рендерим новый кадр
    menu->render();//рендерим меню
}