#include<SFML/Graphics.hpp>
#include<time.h>
#include<string>
#include "../include/color.hpp"
#include <iostream>
#include "Difficulty.h"
#include"Smthing.h"
#include"Grid.h"
#include"Game.h"

#include"Easy_grid.h"

using namespace sf;
using namespace std;



int main()
{
	int num = -1;
	while (num != 0)

	{
		std::cout << dye::purple_on_light_green(" C- H- O- O- S- E   D- I- F- F- I- U- C- L- T- Y   L- E- V- E- L ") << endl;
		cout << endl;
		std::cout << dye::white("\t 1.   E A S Y   ") << endl;
		cout << dye::white("\t 2.   M E D I U M ") << endl;
		cout << dye::white("\t 2.   H A R D ") << endl;
		cout << endl;
		cout << dye::purple_on_white("\t S E L E C T    D I F F I C U L T Y : ");
		cout << "  ";

		Music m1;

		m1.openFromFile("audio/F5.wav");

		m1.setVolume(50);

		m1.play();

		grid* g[3] = { nullptr };

		fox f;

		int gme = f.printdifficulty();

		if (gme == 0)
		{
			g[0] = new Easy_grid();
			g[0]->print_grid();
		}
		else if (gme == 1)
		{
			g[1] = new Medium_grid();
			g[1]->print_grid();
		}
		else if (gme == 2)
		{
			g[2] = new Hard_grid();
			g[2]->print_grid();
		}
		system("cls");
		cout << " Input any number to play again ::::: ";
		cout << " Input 0 to exit the game " << endl;
		cin >> num;
	}
	system("pause");
	return 0;
}
//int main()
//{
//
//	
//	fox f;
//
//
//	sf::Text text;
//	
//	int num=1;
//	
//	while (num != 0)
//	{
//		std::cout << dye::purple_on_light_green(" C- H- O- O- S- E   D- I- F- F- I- U- C- L- T- Y   L- E- V- E- L ") << endl;
//		cout << endl;
//		std::cout << dye::white("\t 1.   E A S Y   ") << endl;
//		cout << dye::white("\t 2.   M E D I U M ") << endl;
//		cout << dye::white("\t 2.   H A R D ") << endl;
//		cout << endl;
//		cout << dye::purple_on_white("\t S E L E C T    D I F F I C U L T Y : ");
//		cout << "  ";
//
//		Music m1;
//
//		m1.openFromFile("audio/abc.wav");
//
//		m1.setVolume( 50);
//
//		m1.play();
//
//		if (f.printdifficulty() == 0)
//		{
//			
//			std::cout << dye::green("\t S E L E C T E D   D I F F I C U L T Y: ") << std::endl;
//			
//			std::cout << dye::white_on_aqua("\t E A S Y ") << std::endl;
//
//			string level = "easy";
//
//			Difficulty g1(level);
//		}
//		else if (f.printdifficulty()==1)
//		{
//			
//			std::cout << dye::green("\t S E L E C T E D   D I F F I C U L T Y: ") << std::endl;
//			
//			std::cout << dye::white_on_aqua("\t M E D I U M ") << std::endl;
//
//			string level = "medium";
//
//			Difficulty g1(level);
//		}
//		else if (f.printdifficulty()==2)
//		{
//			
//			std::cout << dye::green("\t S E L E C T E D   D I F F I C U L T Y: ") << std::endl;
//			
//			std::cout << dye::white_on_aqua("\t H A R D ") << std::endl;
//			
//			srand(time(0));
//
//			string level = "hard";
//			
//			Difficulty g1(level);
//		}
//		
//		cout << "                        ";
//		cout << endl;
//		cout << endl;
//		cout << endl;
//		cout << endl;
//		cout << dye::yellow_on_light_purple(" !!!!!!!!!!T H A N K S  F O R  P L A Y I N G !!!!!!!!!!!!");
//		system("cls");
//		cout << " Input any number to play again ::::: ";
//		cout << " Input 0 to exit the game " << endl;
//		cin >> num;
//	}
//	
//	
//
//}
