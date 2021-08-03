#ifndef _MAIN_MENU_STATE
#define _MAIN_MENU_STATE

#include "../State.hpp"
#include "../Button.hpp"

class MainMenuState : public State {

	private:
		/* Initializer Functions */
		void initFonts();
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
		sf::Font font;

		Button* gameStateBtn;

};

#endif
