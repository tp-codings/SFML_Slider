#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Slider.h"
using namespace sf;

class Engine
{
public:
	Engine();
	virtual ~Engine();

	void run();

	const bool running();

private:

	//window
	RenderWindow* window;
	VideoMode videomode;
	Event ev;


	//GUI
	Font font;
	Text GUI;
	Slider* slider;


	//Mouse positions
	Vector2i mousePosWindow;
	Vector2f mousePosView;
	bool mouseheld = false;

	//Game logic

	void update();
	void updateGUI();
	void updateMousePosition();
	void updateInput();

	void render();
	void renderGUI(RenderTarget*);

	void initWindow();
	void initGUI();
	void initVariables();
	void initSlider();

	void pollEvent();

};



