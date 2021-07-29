#ifndef _GAME_STATE_HPP
#define _GAME_STATE_HPP

#include "../State.hpp"
#include "../Entity.hpp"

class GameState : public State {

	private:
		Entity player;

	public:
		/* Constructor / Destructor */
		GameState(sf::RenderWindow* window);
		~GameState();

		/* Functions */
		void endState();
		void updateKeybinds(const float& deltaTime);
		void update(const float& deltaTime);
		void render(sf::RenderTarget* target=nullptr);

	private:

};

#endif
