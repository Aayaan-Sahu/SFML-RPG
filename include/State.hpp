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

	protected:
		/* Initializer Functions */
		virtual void initKeybinds() = 0;

	public:
		/* Constructor / Destructor */
		State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
		virtual ~State();

		/* Functions */
		const bool& getQuit() const;

		virtual void checkForQuit();

		virtual void endState() = 0;
		virtual void updateInput(const float& deltaTime) = 0;
		virtual void update(const float& deltaTime) = 0;
		virtual void render(sf::RenderTarget* target=nullptr) = 0;

	protected:
		/* Variables */
		sf::RenderWindow* window;
		std::map<std::string, int>* supportedKeys;
		std::map<std::string, int> keybinds;

		// Resources
		std::vector<sf::Texture*> textures;

		// Quitting
		bool quit;

	private:

};

#endif
