#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#define BASE_WIDTH 		800
#define BASE_HEIGHT 	600
#define BASE_TITLE 		"Explorer"

class Game {

	private:
		/* Initializer Functions */
		void initVariables();
		void initWindow();

	public:
		/* Constructor / Destructor */
		Game();
		~Game();

		/* Functions */
		void updateDeltaTime();
		void updateSFMLEvents();
		void update();
		void render();
		void run();

	private:
		/* Variables */
		sf::RenderWindow* WINDOW;
		sf::Event event;

		// Window Variables
		int WIDTH 			= BASE_WIDTH;
		int HEIGHT 			= BASE_HEIGHT;
		std::string TITLE 	= BASE_TITLE;

		// Delta time
		sf::Clock deltaTimeClock;
		float deltaTime;

};

#endif
