
#pragma once
#include<SFML/Graphics.hpp>
#include<time.h>
#include<string>
#include<vector>
#include"Grid.h"
using namespace sf;
using namespace std;

class fox
{
private:

public:

	int printdifficulty()
	{
		
		RenderWindow fo(VideoMode(400, 400), " SELECT DIFFICULTY ");
		int w = 32;
		int arr[4][1];
		arr[0][0] = 0;
		arr[1][0] = 1;
		arr[2][0] = 2;
		arr[3][0] = 3;
		while (fo.isOpen())
		{
			Text t,t1,t2,t3;
			sf::Font font1,font2;

			font1.loadFromFile("font/LCALLIG.ttf");

			t1.setFont(font1);
			t1.setString("EASY");
			t1.setCharacterSize(35);
			t1.setOutlineColor(Color::White);
			t1.setFillColor(sf::Color::White);
			t1.setPosition(80, 100);

			t2.setFont(font1);
			t2.setString("MEDIUM");
			t2.setCharacterSize(35);
			t2.setOutlineColor(Color::White);
			t2.setFillColor(sf::Color::White);
			t2.setPosition(80, 190);

			t3.setFont(font1);
			t3.setString("HARD");
			t3.setCharacterSize(35);
			t3.setOutlineColor(Color::White);
			t3.setFillColor(sf::Color::White);
			t3.setPosition(100, 350);

			fo.draw(t1);
			fo.draw(t2);
			fo.draw(t3);
			
			Vector2i pos = Mouse::getPosition(fo);
			
			Event e;
			int x = pos.x / 128;
			
			int y = pos.y / 128;
			
			
			while (fo.pollEvent(e))
			{
				
				if (e.type == Event::Closed)
					fo.close();

				if (e.type == Event::MouseButtonPressed)
					if (e.key.code == Mouse::Left)
					{
						
						if (arr[x][y] ==  0 || arr[x][y] == 1 )
						{
						
							return 0;
						}
						else if (arr[x][y] == 2)
						{
							return 1;
						}
						else if (arr[x][y] == 3)
						{
							return 2;
						}
						
					}
				fo.display();
			}
			
		}
		
	}
};

