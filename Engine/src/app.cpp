#include "app.h"

App::App(const std::string &app_name)
{
    sf::ContextSettings settings; //настройки окошка
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.majorVersion = 4;
    settings.minorVersion = 3;

    window = std::make_shared<sf::RenderWindow>();

    window->create(sf::VideoMode(1920, 1080, 32), app_name, sf::Style::Titlebar | sf::Style::Close, settings);// создание окошка
    window->setActive();
    window->setFramerateLimit(60);

    render = std::make_shared<Render>(window);//инит рендера
}

void App::loop()
{
    while (window->isOpen())
    {
        event();//смотрим каждый кадр случился ли евент
        
        render->render();//рендерим сцену

        window->display();// отображаем чо получилось
    }
    
    // menu->~Menu();
    window->close();
}

void App::event()
{
    sf::Event windowEvent;

    while (window->pollEvent(windowEvent))
    {
        ImGui::SFML::ProcessEvent(windowEvent);

        switch (windowEvent.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        default:
            break;
        }
    }
}
