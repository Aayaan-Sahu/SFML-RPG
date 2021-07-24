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
		sf::RenderWindow* window;
		std::vector<sf::Texture*> textures;

	public:
		/* Constructor / Destructor */
		State(sf::RenderWindow* window);
		virtual ~State();

		/* Functions */
		virtual void endState() = 0;
		virtual void update(const float deltaTime) = 0;
		virtual void render(sf::RenderTarget* target=nullptr) = 0;

	private:

};

#endif
