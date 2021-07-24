#ifndef _GAME_STATE_HPP
#define _GAME_STATE_HPP

#include "../State.hpp"

class GameState : public State {

	private:

	public:
		/* Construct / Destructor */
		GameState();
		~GameState();

		/* Functions */
		void update();
		void render();

	private:

};

#endif
