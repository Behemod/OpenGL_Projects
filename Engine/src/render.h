#include "scene.h"
#include "menu.h"

class Render
{
public:
    Render(std::shared_ptr<sf::RenderWindow> window);
    void render();

private:
    std::shared_ptr<Menu> menu;//имгуиха
    std::shared_ptr<Scene> scene;//остальное
};