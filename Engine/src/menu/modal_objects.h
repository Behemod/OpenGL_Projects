#include "toggle_button.h"
#include "menu.h"

void Menu::objects_tab(std::shared_ptr<std::vector<Object *>> objects)
{

	static char selectedItem[255];//нада для понимания какой объект мы измением
	static int selected_ind = -1;
	bool selected[objects->size()];

	static float scaleV[3];//нада для изменения объектов
	static float spinV[3];
	static float deg;
	static float transV[3];

	if (selected_ind != -1)//если выбран объект показываем имя
	{
		selected[selected_ind] = true;
		strcpy(selectedItem, (*objects)[selected_ind]->get_name().c_str());
	}

	if (ImGui::BeginCombo("ObjectList", selectedItem))//выводим все объекты и грузим параматры из них
	{

		for (int i = 0; i < objects->size(); i++)
		{
			if (ImGui::Selectable((*objects)[i]->get_name().c_str(), &selected[i]))
			{
				selected_ind = i;

				strcpy(selectedItem, (*objects)[selected_ind]->get_name().c_str());

				{
					auto temp = (*objects)[selected_ind]->get_scale();
					scaleV[0] = temp.x;
					scaleV[1] = temp.y;
					scaleV[2] = temp.z;
				}

				{
					auto temp = (*objects)[selected_ind]->get_rotation();
					spinV[0] = temp.spin_vec.x;
					spinV[1] = temp.spin_vec.y;
					spinV[2] = temp.spin_vec.z;
					deg = temp.spin_deg;
				}

				{
					auto temp = (*objects)[selected_ind]->get_position();
					transV[0] = temp.x;
					transV[1] = temp.y;
					transV[2] = temp.z;
				}
			}
		}
		ImGui::EndCombo();
	}
	ImGui::SameLine();
	if (ImGui::Button("Add", ImVec2(125, 25)))//создание объекта
	{
		ImGui::OpenPopup("Create object");
	}

	bool open = true;
	if (ImGui::BeginPopupModal("Create object", &open))
	{
		static std::string obj_name;//его имя путь до модели и тд
		static path_name model;
		static path_name texture;
		static path_name normal;

		static char obj_name_[255];
		if (ImGui::InputText("Object name", obj_name_, sizeof(obj_name_)))
			obj_name = obj_name_;

		static bool is_primitive;
		ToggleButton("Toggle", &is_primitive);//крутая кнопка для модели/примитивов
		ImGui::SameLine();
		ImGui::BulletText("model/primitive");
		if (!is_primitive)
		{

			if (ImGui::Button("Choose Model"))//юзаем либу ImGuiFileDialog для открытия файлов
			{
				ImGuiFileDialog::Instance()->OpenModal("ChooseModel", "Choose File", "Model files (*.fbx *.obj){.fbx,.obj}", ".\\res\\");
			}
			if (model.name != "")//шобы сбросить выбранную модель
			{
				ImGui::SameLine();
				ImGui::BulletText(model.name.c_str());
				ImGui::SameLine();
				if (ImGui::Button("X"))
				{
					model.name = "";
					model.path = "";
				}
			}
			model = OpenFile("ChooseModel", model);
		}
		if (is_primitive)//если примитив не грузим модель а делаем вот так
		{
			static int curItem = 0;
			const char *primitives[3] = {"Cube", "Pyramid", "Sphere"};
			ImGui::Combo("Primitives", &curItem, primitives, 3, -1);
			if (curItem == 0)
			{
				model.name = "Cube";
			}
			if (curItem == 1)
			{
				model.name = "Pyramid";
			}
			if (curItem == 2)
			{
				model.name = "Sphere";
			}
		}

		if (ImGui::Button("Choose Texture"))//аналогично загрузке модели
		{
			ImGuiFileDialog::Instance()->OpenModal("ChooseTexture", "Choose File", "Image files (*.png *.gif *.jpg *.jpeg){.png,.gif,.jpg,.jpeg}", ".\\res\\");
		}
		if (texture.name != "")
		{
			ImGui::SameLine();
			ImGui::BulletText(texture.name.c_str());
			ImGui::SameLine();
			if (ImGui::Button("X"))
			{
				texture.name = "";
				texture.path = "";
			}
		}
		texture = OpenFile("ChooseTexture", texture);

		if (ImGui::Button("Choose Normal Texture"))//аналогично загрузке модели
		{
			ImGuiFileDialog::Instance()->OpenModal("ChooseNormal", "Choose File", "Image files (*.png *.gif *.jpg *.jpeg){.png,.gif,.jpg,.jpeg}", ".\\res\\");
		}

		if (normal.name != "")
		{
			ImGui::SameLine();
			ImGui::BulletText(normal.name.c_str());
			ImGui::SameLine();
			if (ImGui::Button("X"))
			{
				normal.name = "";
				normal.path = "";
			}
		}
		normal = OpenFile("ChooseNormal", normal);
		//если объект без имени и без модели мы его не создадим, если примитив без имени, то тоже кароче нужно имя
		if (ImGui::Button("Create") && obj_name != "" && ((model.name != "" && !is_primitive) || is_primitive))
		{
			if (is_primitive)//если примитив и ниже пихаем в объект примитив выбранный
			{
				if (model.name == "Cube")
					objects->push_back(new Cube(obj_name, texture.path, normal.path));
				if (model.name == "Pyramid")
					objects->push_back(new Pyramid(obj_name, texture.path, normal.path));
				if (model.name == "Sphere")
					objects->push_back(new Sphere(obj_name, texture.path, normal.path));
			}
			else//обычная модель
				objects->push_back(new Object(obj_name, model.path, texture.path, normal.path));

			is_primitive = false;//обнуляем переменные
			model = {"", ""};
			texture = {"", ""};
			normal = {"", ""};
			obj_name = "";
			strcpy(obj_name_, "");
			ImGui::CloseCurrentPopup();
		}
		ImGui::SameLine();
		if (ImGui::Button("Close"))
		{

			model = {"", ""};
			texture = {"", ""};
			normal = {"", ""};
			obj_name = "";
			strcpy(obj_name_, "");
			ImGui::CloseCurrentPopup();
		}

		ImGui::EndPopup();
	}

	if (selected_ind != -1)//если выбрали объект из списка у нас появляется 3 вкладки и пару полей
	{

		if (ImGui::InputText("Change name", &selectedItem[0], sizeof(selectedItem)))
		{
			(*objects)[selected_ind]->set_name(selectedItem);//меняем имя модели
		}

		if (ImGui::Button("Change Texture"))//меняем текстуру, загружаем как модели выще^
		{
			ImGuiFileDialog::Instance()->OpenModal("ChangeTexture", "Choose File", "Image files (*.png *.gif *.jpg *.jpeg){.png,.gif,.jpg,.jpeg}", ".\\res\\");
		}
		{
			path_name temp_path = {"", ""};
			temp_path = OpenFile("ChangeTexture", temp_path);
			if (temp_path.name != "")
				(*objects)[selected_ind]->set_texture(temp_path.path);
		}

		static int cur_tab = 0;//в замисимости от нажатой кнопки рисуются 3 разных таба для скейла кручения и перемещения
		if (ImGui::Button("Scale", ImVec2(150, 25)))
			cur_tab = 0;
		ImGui::SameLine();
		if (ImGui::Button("Rotate", ImVec2(150, 25)))
			cur_tab = 1;
		ImGui::SameLine();
		if (ImGui::Button("Translate", ImVec2(150, 25)))
			cur_tab = 2;

		if (cur_tab == 0)
		{
			ImGui::LabelText("", "Scale obj");
			{
				if (ImGui::SliderFloat("Scale prop", &scaleV[0], -10.0f, 10.0f))
				{
					scaleV[1] = scaleV[0];
					scaleV[2] = scaleV[0];
					(*objects)[selected_ind]->set_scale(glm::vec3(scaleV[0], scaleV[1], scaleV[2]));
				}
				if (ImGui::SliderFloat3("Scale", scaleV, -10.0f, 10.0f))
				{
					(*objects)[selected_ind]->set_scale(glm::vec3(scaleV[0], scaleV[1], scaleV[2]));
				}
			}
		}

		if (cur_tab == 1)
		{
			ImGui::LabelText("", "Spin obj");
			{
				if (ImGui::SliderFloat3("Spin vector", spinV, -10.0f, 10.0f) || ImGui::SliderFloat("Degree", &deg, -360.0f, 360.0f))
				{
					(*objects)[selected_ind]->set_rotation(glm::vec3(spinV[0], spinV[1], spinV[2]), deg);
				}
			}
		}

		if (cur_tab == 2)
		{
			ImGui::LabelText("", "Translate obj");
			{
				if (ImGui::SliderFloat3("Translate vector", transV, -10.0f, 10.0f))
				{
					(*objects)[selected_ind]->set_position(glm::vec3(transV[0], transV[1], transV[2]));
				}
			}
		}
		if (ImGui::Button("Delete obj"))//удаляем объект
		{
			objects->erase(objects->begin() + selected_ind);
			selected_ind = -1;
			strcpy(selectedItem, "");
		}
	}
}
