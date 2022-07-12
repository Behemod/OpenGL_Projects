#include "app.h"

int main()
{
	auto app = std::make_unique<App>("OpenGL Engine"); //инит приложухи(тут вся магия)

	app->loop(); //основной цикл

	return 0;
}
