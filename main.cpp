#include <SFML/Graphics.hpp>
#include "settings.h"

using namespace sf;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Window with border");
	sf::Color borderColor(sf::Color::Red);
	float borderWidth = 10.f;
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();

		}
		window.clear(sf::Color::Black);
		sf::RectangleShape border(Vector2f(WINDOW_WIDTH - 10, WINDOW_HEIGHT - 10));
		border.setOutlineThickness(borderWidth);
		border.setOutlineColor(borderColor);
		window.draw(border);
		// Отрисовка окна 
		window.display();
	}

	return 0;
}