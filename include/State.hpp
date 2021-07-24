#ifndef _STATE_HPP
#define _STATE_HPP

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#include <map>
#include <stack>
#include <vector>

class State {

	private:
		/* Variables */
		std::vector<sf::Texture*> textures;

	public:
		/* Constructor / Destructor */
		State();
		virtual ~State();

		/* Functions */
		virtual void update() = 0;
		virtual void render() = 0;

	private:

};

#endif
