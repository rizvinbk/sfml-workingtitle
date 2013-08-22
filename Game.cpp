#include "Game.h"

Game::Game()
{
	gameWindow.create(sf::VideoMode(windowX, windowY), "workingtitle");
	currentlevel = new Level();
	currentlevel->setLevel(Stage1);
	deltatime = 0;
}

void Game::start()
{
	//gameWindow.setFramerateLimit(60);
	while(gameWindow.isOpen())
	{
		gameloop();
	}
}

void Game::gameloop()
{
	std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
	gameWindow.clear(sf::Color(255,255,255));

	sf::Event evt;
	gameWindow.pollEvent(evt);
	if(evt.type == sf::Event::Closed) gameWindow.close();

	currentlevel->checkInput(evt);
	currentlevel->update(deltatime);
	currentlevel->draw(gameWindow);
	
	gameWindow.display();

	//calculate deltatime for one iteration of gameloop
	std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
	deltatime = time_span.count()*1000;;
	//deltatime = 1/60;
}
