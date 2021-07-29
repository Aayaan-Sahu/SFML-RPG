#include "../include/Entity.hpp"

/* Constructor / Destructor */
Entity::Entity() {
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->movementSpeed = 100.f;
}

Entity::~Entity() {}

/* Functions */
void Entity::move(const float& deltaTime, const float dirx, const float diry) {
	this->shape.move(
			dirx * this->movementSpeed * deltaTime,
			diry * this->movementSpeed * deltaTime
	);
}

void Entity::update(const float& deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->move(deltaTime, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->move(deltaTime, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->move(deltaTime, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->move(deltaTime, 0.f, 1.f);
	}
}

void Entity::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
