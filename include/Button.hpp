#ifndef _BUTTON_HPP
#define _BUTTON_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

enum BUTTON_STATES { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button {

	private:

	public:
		/* Contsructor / Destructor */
		Button(
			float x, float y,
			float width, float height,
			sf::Font* font, std::string text,
			sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor
		);
		virtual ~Button();

		/* Accessors */
		const bool isPressed() const;

		/* Funtions */
		void update(const sf::Vector2f mousePos);
		void render(sf::RenderTarget* target=nullptr);

	private:
		/* Variables */
		// Button functionality
		short unsigned buttonState;

		// Button properties
		sf::RectangleShape shape;
		sf::Font* font;
		sf::Text text;

		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color activeColor;
	
};

#endif
