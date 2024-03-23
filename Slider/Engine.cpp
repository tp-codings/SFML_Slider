#include "Engine.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <sstream>
#include <iomanip>

Engine::Engine()
{
	this->initWindow();
	this->initGUI();
	this->initVariables();
	this->initSlider();
}

Engine::~Engine()
{
	delete this->window;
}

void Engine::run()
{
	while (this->running())
	{
		this->update();
		this->render();
	}
}

const bool Engine::running()
{
	return this->window->isOpen();
}

void Engine::update()
{
	this->updateGUI();
	this->updateMousePosition();
	this->slider->update();
	this->updateInput();
	this->pollEvent();
}

void Engine::updateGUI()
{
	std::stringstream ss;
	ss << "Slider... you stink";
	this->GUI.setString(ss.str());
}

void Engine::updateMousePosition()
{
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Engine::updateInput()
{
}

void Engine::render()
{
	this->window->clear(Color::White);
	this->renderGUI(this->window);
	this->slider->render(this->window);
	this->window->display();
}

void Engine::renderGUI(RenderTarget* target)
{
	target->draw(this->GUI);
}

void Engine::initWindow()
{
	this->videomode.height = 700;
	this->videomode.width = 1500;
	this->window = new RenderWindow(this->videomode, "Slider", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Engine::initGUI()
{
	if (!this->font.loadFromFile("Fonts/Silkscreen-Bold.ttf")) std::cout << "fuck it";
	this->GUI.setFont(this->font);
	this->GUI.setCharacterSize(20);
	this->GUI.setString("NONE");
	this->GUI.setFillColor(Color::Black);
	this->GUI.setPosition(0.5 * this->window->getSize().x - 0.5 * this->GUI.getGlobalBounds().width, 0.24 * this->window->getSize().y);
}

void Engine::initVariables()
{
	this->slider = new Slider(this->window);
}

void Engine::initSlider()
{
	this->slider->setFillColorRect(Color(153, 205, 178));
	this->slider->setSize(Vector2f(400, 50));
	this->slider->setPos(Vector2f(300, 300));
	this->slider->setTitle("Testslider");
	this->slider->setRange(Vector2f(-100, 100));
	this->slider->setTextColorRect(Color::White);
}

void Engine::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->ev.key.code == Keyboard::F) this->window->close();
			break;
		}
	}
}

