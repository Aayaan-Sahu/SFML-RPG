#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#include "./State.hpp"
#include "./Defines.hpp"

#define BASE_WIDTH 					800
#define BASE_HEIGHT 				600
#define BASE_FRAME_RATE_LIMIT 		120
#define BASE_VERTICAL_SYNC_ENABLED 	false
#define BASE_TITLE 					"None"

class Game {

	private:
		/* Initializer Functions */
		void initVariables();
		void initWindow();
		void initKeys();
		void initStates();

	public:
		/* Constructor / Destructor */
		Game();
		~Game();

		/* Functions */
		void endApplication();
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
		int WIDTH 						= BASE_WIDTH;
		int HEIGHT 						= BASE_HEIGHT;
		int FRAME_RATE_LIMIT 			= BASE_FRAME_RATE_LIMIT;
		bool VERTICAL_SYNC_ENABLED 		= BASE_VERTICAL_SYNC_ENABLED;
		std::string TITLE 				= BASE_TITLE;

		// Delta time
		sf::Clock deltaTimeClock;
		float deltaTime;

		// State management
		std::stack<State*> states;

		// Keybind Management
		std::map<std::string, int> supportedKeys;

};

#endif
