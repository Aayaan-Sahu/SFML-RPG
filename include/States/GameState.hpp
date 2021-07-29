#ifndef _GAME_STATE_HPP
#define _GAME_STATE_HPP

#include "../State.hpp"
#include "../Entity.hpp"

class GameState : public State {

	private:
		/* Initializer Functions */
		void initKeybinds();

	public:
		/* Constructor / Destructor */
		GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
		~GameState();

		/* Functions */
		void endState();
		void updateInput(const float& deltaTime);
		void update(const float& deltaTime);
		void render(sf::RenderTarget* target=nullptr);

	private:
		/* Variables */
		Entity player;

};

#endif
