
#pragma once

#include<SFML/Graphics.hpp>
#include<time.h>
#include<string>
#include<vector>
#include"Grid.h"
#include"Game.h"

using namespace sf;
using namespace std;

class Difficulty
{

private:

	string game_level;

public:

	Difficulty()

	{
		game_level = "0";
	}

     Difficulty(string user_level)

	{
		 game_level="0";

		game_level = user_level;

		Game game1(game_level);
	}
};
