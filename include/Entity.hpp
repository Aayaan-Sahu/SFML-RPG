#ifndef _ENTITY_HPP
#define _ENTITY_HPP

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

class Entity {

	private:

	protected:
		sf::RectangleShape shape;
		float movementSpeed;

	public:
		/* Constructor / Destructor */
		Entity();
		virtual ~Entity();

		/* Functions */
		virtual void move(const float& deltaTime, const float dirx, const float diry);
		virtual void update(const float& deltaTime);
		virtual void render(sf::RenderTarget* target);

	private:

};

#endif
