#ifndef _MAIN_MENU_STATE
#define _MAIN_MENU_STATE

#include "../State.hpp"

class MainMenuState : public State {

	private:
		/* Initializer Functions */
		void initKeybinds();

	public:
		/* Constructor / Destructor */
		MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
		~MainMenuState();

		/* Functions */
		void endState();
		void updateInput(const float& deltaTime);
		void update(const float& deltaTime);
		void render(sf::RenderTarget* target=nullptr);

	private:
		/* Variables */
		sf::RectangleShape background;

};

#endif
