#include "menu.h"

#include "modal_light.h"
#include "modal_objects.h"
#include "open_file.h"
#include "modal_camera.h"

Menu::Menu(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Scene> scene)
{
	win_ = window;
	scene_ = scene;
	(void *)ImGui::SFML::Init(*win_);//инит менюшки
	ImGui::StyleColorsClassic();//темная тема)
	deltaClock = std::make_shared<sf::Clock>();
}

void Menu::render()
{
	ImGui::SFML::Update(*win_, deltaClock->restart());//создаём наше меню
	ImGui::Begin("Window title", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove);
	{
		if (ImGui::Button("Objects", ImVec2(100, 100)))//далее 3 кнопки, каждая открывает модалки, которые в других файлах
		{
			ImGui::OpenPopup("Object");
		}
		bool open = true;
		if (ImGui::BeginPopupModal("Object", &open))
		{
			objects_tab(scene_->get_objects());
			ImGui::EndPopup();
		}

		if (ImGui::Button("Light", ImVec2(100, 100)))
		{
			ImGui::OpenPopup("Light");
		}
		if (ImGui::BeginPopupModal("Light", &open))
		{
			light_tab(scene_->get_light());
			ImGui::EndPopup();
		}

		if (ImGui::Button("Camera", ImVec2(100, 100)))
		{
			ImGui::OpenPopup("Camera");
		}
		if (ImGui::BeginPopupModal("Camera", &open))
		{
			camera_tab(scene_->get_camera());
			ImGui::EndPopup();
		}
	}
	ImGui::End();

	ImGui::SFML::Render(*win_);
}