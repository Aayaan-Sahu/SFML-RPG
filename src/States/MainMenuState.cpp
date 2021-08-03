#include "../../include/States/MainMenuState.hpp"

#include <fstream>
#include <iostream>

/* Initializer Functions */
void MainMenuState::initFonts() {
	if (!this->font.loadFromFile("fonts/Dosis-Light.ttf")) {
		throw("ERROR::MAINMENUSTATE::COULD_NOT_LOAD_FONT");
	}
}

void MainMenuState::initKeybinds() {
	// Give each of the supported keys a function (how they will be used in the current state)
	std::ifstream fin( "config/MainMenuStateKeybinds.conf" );
	if (fin.is_open()) {
		std::string key = "";
		std::string keyValue = "";
		while (fin >> key >> keyValue) {
			this->keybinds[key] = this->supportedKeys->at(keyValue);
		}
	}
	fin.close();
}

void MainMenuState::initButtons() {
	this->buttons["GAME_STATE"] = new Button(
		100, 100,
		150, 50,
		&this->font, "New Game",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)
	);

	this->buttons["EXIT_STATE"] = new Button(
		100, 300,
		150, 50,
		&this->font, "Quit",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)
	);
}

/* Constructor / Destructor */
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys) {
	this->initFonts();
	this->initKeybinds();
	this->initButtons();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState() {
	for (auto button : buttons) {
		delete button.second;
	}
}

/* Functions */
void MainMenuState::endState() {
	std::cout << "Ending main menu state!\n";
}

void MainMenuState::updateInput(const float& deltaTime) {
	// Update mouse positions
	this->updateMousePositions();

	// Defined in State class
	this->checkForQuit();
}

void MainMenuState::updateButtons() {
	for (const auto& button : this->buttons) {
		button.second->update(this->mousePosView);
	}

	// New game
	if (this->buttons["GAME_STATE"]->isPressed() == true) {
		std::cout << "New Game!\n";
	}

	// Quit the state
	if (this->buttons["EXIT_STATE"]->isPressed() == true) {
		this->quit = true;
	}
}

void MainMenuState::update(const float& deltaTime) {
	this->updateInput(deltaTime);
	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target) {
	for (const auto& button : this->buttons) {
		button.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target) {
	// Make sure target is not nullptr
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);
	this->renderButtons(target);
}
