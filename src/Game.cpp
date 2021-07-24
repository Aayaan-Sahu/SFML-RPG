#include "../include/Game.hpp"

#include <fstream>
#include <iostream>

/* Initializer Functions */
void Game::initWindow() {
	this->WINDOW = new sf::RenderWindow(
		sf::VideoMode(this->WIDTH, this->HEIGHT),
		this->TITLE,
		sf::Style::Close | sf::Style::Titlebar
	);

	this->WINDOW->setFramerateLimit(this->FRAME_RATE_LIMIT);
	this->WINDOW->setVerticalSyncEnabled(this->VERTICAL_SYNC_ENABLED);

	std::cout << "Frame rate limit: " << this->FRAME_RATE_LIMIT << "\n";
	std::cout << "Vertical sync enabled: " << this->VERTICAL_SYNC_ENABLED << "\n";
}

void Game::initVariables() {
	/* Read Window Properties */
	std::ifstream fin( "Config/WindowProperties.conf" );

	std::string title;
	std::string stringWidth;
	std::string stringHeight;
	std::string stringFrameRateLimit;
	std::string stringVerticalSyncEnabled;

	std::getline(fin, title);
	std::getline(fin, stringWidth);
	std::getline(fin, stringHeight);
	std::getline(fin, stringFrameRateLimit);
	std::getline(fin, stringVerticalSyncEnabled);

	this->TITLE = title.substr(title.find("=") + 1);
	stringWidth = stringWidth.substr(stringWidth.find("=") + 1);
	stringHeight = stringHeight.substr(stringHeight.find("=") + 1);
	stringFrameRateLimit = stringFrameRateLimit.substr(stringFrameRateLimit.find("=") + 1);
	stringVerticalSyncEnabled = stringVerticalSyncEnabled.substr(stringVerticalSyncEnabled.find("=") + 1);

	this->WIDTH = std::stoi(stringWidth);
	this->HEIGHT = std::stoi(stringHeight);
	this->FRAME_RATE_LIMIT = std::stoi(stringFrameRateLimit);
	this->VERTICAL_SYNC_ENABLED = (stringVerticalSyncEnabled == "1") ? true : false;

	fin.close();
}

/* Constructor / Destructor */
Game::Game() {
	// Initialize variables before initializing window
	this->initVariables();
	this->initWindow();
}

Game::~Game() {
	delete this->WINDOW;
}

/* Functions */
void Game::updateDeltaTime() {
	// Updates delta time with the time it takes from one frame to the next
	this->deltaTime = this->deltaTimeClock.restart().asSeconds();
}

void Game::updateSFMLEvents() {
	// Go through all the events that are happening
	// within the window
	while (this->WINDOW->pollEvent(this->event)) {
		// Check for the window closed
		if (this->event.type == sf::Event::Closed) {
			this->WINDOW->close();
		}
	}
}

void Game::update() {
	this->updateSFMLEvents();
}

void Game::render() {
	// Clear the screen with a color
	this->WINDOW->clear(sf::Color(51, 51, 51, 100));

	// Render everything on the back buffer
	this->WINDOW->display();
}

void Game::run() {
	while (this->WINDOW->isOpen()) {
		this->updateDeltaTime();
		this->update();
		this->render();
	}
}
