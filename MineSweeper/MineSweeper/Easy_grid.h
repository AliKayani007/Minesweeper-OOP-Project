#pragma once
#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include"SFML/Audio.hpp"
#include<time.h>
#include<string>
#include<vector>
#include<fstream>


#include"Grid.h"

using namespace sf;
using namespace std;

class Easy_grid : public grid 



{

    private:
	
    int showeasy_grid[10][10];
	int easy_mines=10;
    int easy_grid[10][10];
	int mine;
	int ez_mines;

    sf::Text mine_txt;
    sf::Text txt1;
    Text clock_txt;
    Texture t, t1, t2;
    sf::Font f1;
    

    public:

    Easy_grid()
	
    {
		mine = 10;
		ez_mines = 10;
        showeasy_grid[11][11] = {};
        easy_grid[11][11] = {};
	}

    void print_grid()
    {
        srand(time(0));
        Clock clock;
        Clock clock1;


        mine = ez_mines;

        RenderWindow app(VideoMode(400, 400), "Minesweeper OOP");



        t.loadFromFile("images/tiles.jpg");
        t1.loadFromFile("images/mine.jpg");
        t2.loadFromFile("images/clock.jpg");

        Sprite s(t);
        Sprite s1(t1);
        Sprite s2(t2);

        int w = 32;

        s2.setPosition(270, 330);
        s2.setScale(0.08, 0.08);
        s1.setPosition(10, 350);
        s1.setScale(0.1, 0.1);



        f1.loadFromFile("font/ebrima.ttf");

        mine_txt.setString(to_string(mine));
        mine_txt.setFont(f1);
        mine_txt.setCharacterSize(60);
        mine_txt.setPosition(70, 320);
        mine_txt.setFillColor(Color::Red);

        txt1.setFont(f1);
        txt1.setCharacterSize(60);
        txt1.setPosition(335, 320);
        txt1.setFillColor(Color::Red);


        for (int i = 1; i <= 9; i++) // Place Closed Boxes
        {
            for (int j = 1; j <= 9; j++)
            {
                showeasy_grid[i][j] = 10;
            }
        }

        for (int i = 1; i <= 9; i++) // Place Mines
        {
            int x, y;
            x = 1 + (rand() % 9);
            y = 1 + (rand() % 9);
            if (easy_grid[x][y] != 9)
            {
                easy_grid[x][y] = 9;
            }
        }

        

        for (int i = 1; i <= 9; i++) // Place Empty
        {
            for (int j = 1; j <= 9; j++)
            {
                if (easy_grid[i][j] != 9)
                    easy_grid[i][j] = 0;
            }
        }

        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                int n = 0;
                if (easy_grid[i][j] == 9)
                    continue;
                if (easy_grid[i + 1][j] == 9)
                    n++;
                if (easy_grid[i][j + 1] == 9)
                    n++;
                if (easy_grid[i - 1][j] == 9)
                    n++;
                if (easy_grid[i][j - 1] == 9)
                    n++;

                if (easy_grid[i + 1][j + 1] == 9)
                    n++;
                if (easy_grid[i - 1][j - 1] == 9)
                    n++;
                if (easy_grid[i - 1][j + 1] == 9)
                    n++;
                if (easy_grid[i + 1][j - 1] == 9)
                    n++;

                easy_grid[i][j] = n;
            }
        }
        
        while (app.isOpen())
        {

            Vector2i pos = Mouse::getPosition(app);

            int x = pos.x / w;
            int y = pos.y / w;

            sf::Time elapsed = clock.getElapsedTime();

            txt1.setString(to_string((int)elapsed.asSeconds()));
            
            Event e;
            while (app.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    app.close();

                if (e.type == Event::MouseButtonPressed)
                    if (e.key.code == Mouse::Left)
                    {

                        showeasy_grid[x][y] = easy_grid[x][y];
                       
                        if (easy_grid[x][y] == 0)
                        {
                            for (int i = y; easy_grid[x][i] == 0 && i >= 0 && i <= 9; i++) // Right
                            {
                                expose_easyzero_cell(easy_grid, showeasy_grid, x, i);
                            }
                            for (int i = y; easy_grid[x][i] == 0 && i >= 0 && i <= 9; i--) // Left
                            {
                                expose_easyzero_cell(easy_grid, showeasy_grid, x, i);
                            }
                            for (int i = x; easy_grid[i][y] == 0 && i >= 0 && i <= 9; i++) // Up
                            {
                                expose_easyzero_cell(easy_grid, showeasy_grid, i, y);
                            }
                            for (int i = x; easy_grid[i][y] == 0 && i >= 0 && i <= 9; i--) // Down
                            {
                                expose_easyzero_cell(easy_grid, showeasy_grid, i, y);
                            }
                            int j = y;
                            for (int i = x; easy_grid[i][j] == 0 && i >= 0 && i <= 9 && j >= 0 && j <= 9; i--) // Top Left Diagnol 
                            {
                                expose_easyzero_cell(easy_grid, showeasy_grid, i, j);
                                j--;
                            }
                            j = y;
                            for (int i = x; easy_grid[i][j] == 0 && i >= 0 && i <= 9 && j >= 0 && j <= 9; i--) // Top Right Diagnol 
                            {
                                expose_easyzero_cell(easy_grid, showeasy_grid, i, j);
                                j++;
                            }
                            j = y;
                            for (int i = x; easy_grid[i][j] == 0 && i >= 0 && i <= 9 && j >= 0 && j <= 9; i++) // Bottom Right Diagnol 
                            {
                                expose_easyzero_cell(easy_grid, showeasy_grid, i, j);
                                j++;
                            }
                            j = y;
                            for (int i = x; easy_grid[i][j] == 0 && i >= 0 && i <= 9 && j >= 0 && j <= 9; i++) // Bottom Left Diagnol 
                            {
                                expose_easyzero_cell(easy_grid, showeasy_grid, i, j);
                                j--;
                            }
                        }
                    
                    }
                    else if (e.key.code == Mouse::Right)
                    {

                        showeasy_grid[x][y] = 11;
                        mine = ez_mines--;
                        if (showeasy_grid[x][y] == 11)
                        {
                            mine = ez_mines--;
                            mine_txt.setString(to_string(mine));

                        }


                    }

            }
            
            app.clear(Color::White);

            for (int i = 1; i <= 9; i++)
                for (int j = 1; j <= 9; j++)
                {
                    if (showeasy_grid[x][y] == 9)
                    {
                        showeasy_grid[i][j] = easy_grid[i][j];
                    }
                   
                    s.setTextureRect(IntRect(showeasy_grid[i][j] * w, 0, w, w));
                    s.setPosition(i * w, j * w);

                    app.draw(s);

                }
            int count = 0;
            for (int i = 1; i <= 9; i++)
            {
                for (int j = 1; j <= 9; j++)
                {
                    if (showeasy_grid[i][j] != 9 && showeasy_grid[i][j] != 10)
                    {
                        count++;
                    }
                }
            }

            

                for (int i = 1; i <= 9; i++)
                    for (int j = 1; j <= 9; j++)
                    if (showeasy_grid[i][j] == 9)
                    {
                        sf::Time elapsed1 = clock1.getElapsedTime();
                        clock_txt.setString(to_string((int)elapsed1.asSeconds()));
                        clock.restart();
                        sf::Time elapsed = clock.getElapsedTime();
                        txt1.setString(to_string((int)elapsed.asSeconds()));
                        app.draw(txt1);
                    }
                    else
                    {
                        app.draw(txt1);
                    }
                
        
                    
            app.draw(s2);
            app.draw(s1);
            app.draw(mine_txt);

            app.display();
            if (count == 71)
            {
                cout << "Winner!" << endl;
            }

        }

        
        sf::Time elapsed2 = clock1.getElapsedTime();

        txt1.setString(to_string((int)elapsed2.asSeconds()));

        sf::RenderWindow app1(sf::VideoMode(600, 600), " TIMER");

        while (app1.isOpen())
        {

            sf::Texture image1;
            sf::Texture image2;
            sf::Texture image3;


            image1.loadFromFile("images/mine.jpg");
            image2.loadFromFile("images/123.jpg");
            image3.loadFromFile("images/ABC.jpg");

            sf::Sprite images1;
            sf::Sprite images2;
            sf::Sprite images3;

            images1.setTexture(image1);
            images2.setTexture(image2);
            images3.setTexture(image3);

            sf::Font font;
            sf::Font font1;

            font1.loadFromFile("font/LCALLIG.ttf");

            sf::Text text, text1;

            text.setFont(font);
            clock_txt.setFont(font1);
            text1.setFont(font1);

            string ax = "Time Played:";
            string bx = "seconds";

            images1.setScale(1.3, 1.2);
            images3.setScale(0.3, 0.3);

            images3.setPosition(150, 150);

            text.setString(ax);

            text1.setString(bx);

            text.setPosition(20, 200);


            clock_txt.setPosition(250, 250);

            text1.setPosition(290, 250);
            text.setCharacterSize(40);

            text1.setCharacterSize(30);
            clock_txt.setCharacterSize(40);

            text.setFillColor(sf::Color::Blue);
            clock_txt.setFillColor(sf::Color::Blue);

            text1.setFillColor(sf::Color::Green);
            text.setStyle(sf::Text::Underlined);

            clock_txt.setStyle(sf::Text::Bold);
            images2.setScale(0.5, 0.5);

            app1.draw(images1);
            app1.draw(images2);

            app1.draw(text);
            app1.draw(images3);
            app1.draw(clock_txt);
            app1.draw(text1);



            sf::Event event;
            while (app1.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    app1.close();
            }

            app1.display();
        }
    }
        
	
};