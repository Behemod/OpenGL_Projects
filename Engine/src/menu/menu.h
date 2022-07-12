#pragma once

#include <string>
#include <memory>

#include "imgui.h"
#include "imgui-sfml.h"
#include "imgui_internal.h"
#include "ImGuiFileDialog/ImGuiFileDialog.h"

#include "../scene.h"

#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Scene> scene);

    void render();

    ~Menu(){ ImGui::SFML::Shutdown(); }

private:
    struct path_name//фиговина для хранения пути файла и его имени библиотеки
	{
		std::string path;
		std::string name;
	};

    void ToggleButton(const char *str_id, bool *v);
    path_name OpenFile(std::string id, path_name cur);

    void objects_tab(std::shared_ptr<std::vector<Object *>> objects);//методы для отрисовой 3х вкладок менюшки
    void light_tab(std::shared_ptr<Light> light);
    void camera_tab(std::shared_ptr<Camera> camera);

    std::shared_ptr<sf::Clock> deltaClock;
    std::shared_ptr<sf::RenderWindow> win_;//наше окошко и сцена
    std::shared_ptr<Scene> scene_;

};