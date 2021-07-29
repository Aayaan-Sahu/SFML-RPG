#include "../include/Entity.hpp"

/* Constructor / Destructor */
Entity::Entity() {
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->movementSpeed = 200.f;
}

Entity::~Entity() {}

/* Functions */
void Entity::move(const float& deltaTime, const float dirx, const float diry) {
	// Move in a certain direction at a defined speed multiplied by the delta time
	this->shape.move(
			dirx * this->movementSpeed * deltaTime,
			diry * this->movementSpeed * deltaTime
	);
}

void Entity::update(const float& deltaTime) {
}

void Entity::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
