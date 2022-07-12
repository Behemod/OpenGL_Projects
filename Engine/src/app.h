#include <string>
#include <SFML/Graphics.hpp>

#include "render.h"

class App
{
public:
    App(const std::string &app_name);

    void loop();

    void event();

private:

    std::shared_ptr<sf::RenderWindow> window; //дефолтное окошко из sfml

    std::shared_ptr<Render> render; //рендерит объекты в цикле
};