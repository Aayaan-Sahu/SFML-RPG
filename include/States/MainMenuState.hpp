#ifndef _MAIN_MENU_STATE
#define _MAIN_MENU_STATE

#include "../State.hpp"
#include "../Button.hpp"

#include <map>

class MainMenuState : public State {

	private:
		/* Initializer Functions */
		void initFonts();
		void initKeybinds();
		void initButtons();

	public:
		/* Constructor / Destructor */
		MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
		~MainMenuState();

		/* Functions */
		void endState();
		void updateInput(const float& deltaTime);
		void updateButtons();
		void update(const float& deltaTime);
		void renderButtons(sf::RenderTarget* target=nullptr);
		void render(sf::RenderTarget* target=nullptr);

	private:
		/* Variables */
		sf::RectangleShape background;
		sf::Font font;

		std::map<std::string, Button*> buttons;

};

#endif
