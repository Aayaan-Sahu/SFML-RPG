#include "../include/Button.hpp"

/* Contsructor / Destructor */
Button::Button(
		float x, float y,
		float width, float height,
		sf::Font* font, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor
	) {
	// Default button state
	this->buttonState = BTN_IDLE;

	// Physical properties
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));

	// Text properties
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(16);

	// Text position properties
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	// Color properties
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);
}

Button::~Button() {}

/* Accessors */
const bool Button::isPressed() const {
	return (this->buttonState == BTN_ACTIVE);
}

/* Funtions */
void Button::update(const sf::Vector2f mousePos) {
	/* Update the booleans for hover and pressed */

	// Idle
	this->buttonState = BTN_IDLE;

	// Hover
	if (this->shape.getGlobalBounds().contains(mousePos)) {
		this->buttonState = BTN_HOVER;

		// Active / Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->buttonState = BTN_ACTIVE;
		}
	}

	/* Change the color depending on the state */
	switch (this->buttonState) {
		case (BTN_IDLE):
			this->shape.setFillColor(this->idleColor);
			break;
		case (BTN_HOVER):
			this->shape.setFillColor(this->hoverColor);
			break;
		case (BTN_ACTIVE):
			this->shape.setFillColor(this->activeColor);
			break;
		default:
			this->shape.setFillColor(sf::Color::Red);
			break;
	}
}

void Button::render(sf::RenderTarget* target) {
	target->draw(this->shape);
	target->draw(this->text);
}
