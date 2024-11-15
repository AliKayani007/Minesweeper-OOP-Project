#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"SFML/Audio.hpp"
#include<time.h>
#include<string>
#include<vector>
#include<fstream>
#include"Difficulty.h"
#include"Easy_grid.h"
#include"medium_grid.h"
#include"hard_grid.h"

class Game:public Easy_grid

{
private:

	Easy_grid e;
	Medium_grid m;
	Hard_grid h;

public:

	Game(string level)

	{
		
		if (level == "Easy" || level == "easy")
		{
			e.print_grid();
		}
		if (level == "Medium" || level == "medium")
		{
			m.print_grid();
		}
		if (level == "Hard" || level == "hard")
		{
			h.print_grid();
		}
	}
};
