#ifndef _GAME_STATE_HPP
#define _GAME_STATE_HPP

#include "../State.hpp"

class GameState : public State {

	private:

	public:
		/* Construct / Destructor */
		GameState(sf::RenderWindow* window);
		~GameState();

		/* Functions */
		void endState();
		void update(const float deltaTime);
		void render(sf::RenderTarget* target=nullptr);

	private:

};

#endif
