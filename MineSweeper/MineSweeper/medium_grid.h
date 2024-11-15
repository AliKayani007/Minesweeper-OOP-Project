#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"SFML/Audio.hpp"
#include<time.h>
#include<string>
#include<vector>
#include<fstream>
#include"Difficulty.h"

using namespace sf;
using namespace std;
class Medium_grid :public grid
{
private:
    int showmedium_grid[17][17];
    int medium_mines = 40;
    int medium_grid[17][17];
    int mine;
    int med_mines;
    Texture t, t1, t2;
    sf::Text txt, txt1, clock_txt;
    sf::Font f1;

public:
    Medium_grid()
    {
        mine = 40;
        showmedium_grid[17][17] = {};
        medium_grid[17][17] = {};
        med_mines = 40;
    }
    void print_grid()
    {
        RenderWindow app(VideoMode(600, 650), "Minesweeper OOP");

        srand(time(0));
        
        Clock clock;
        Clock clock1;
        mine = med_mines;
      
        int w = 32;
        
        

        t.loadFromFile("images/tiles.jpg");
        t1.loadFromFile("images/mine.jpg");
        t2.loadFromFile("images/clock.jpg");

        Sprite s(t);
        Sprite s1(t1);
        Sprite s2(t2);

        
        s1.setScale(0.2, 0.2);
        s1.setPosition(10, 550);
       
        s2.scale(0.1, 0.1);
        s2.setPosition(470, 550);

        f1.loadFromFile("font/ebrima.ttf");

        txt.setString(to_string(mine));  
        txt.setFont(f1);
        txt.setCharacterSize(70);
        txt.setPosition(120, 550);
        txt.setFillColor(Color::Red);
        
        txt1.setFont(f1);
        txt1.setCharacterSize(60);
        txt1.setPosition(390, 560);
        txt1.setFillColor(Color::Red);
        
        for (int i = 1; i <= 16; i++) // Place Closed Boxes
        {
            for (int j = 1; j <= 16; j++)
            {
                showmedium_grid[i][j] = 10;
            }
        }

        for (int i = 0; i <= medium_mines; i++) // Place Mines
        {
            int x, y;
            x = 1 + (rand() % 16);
            y = 1 + (rand() % 16);
            if (medium_grid[x][y] != 9)
            {
                medium_grid[x][y] = 9;
            }
        }

        for (int i = 1; i <= 16; i++) // Place 
        {
            for (int j = 1; j <= 16; j++)
            {
                if (medium_grid[i][j] != 9)
                    medium_grid[i][j] = 0;
            }
        }

        for (int i = 1; i <= 16; i++)
        {
            for (int j = 1; j <= 16; j++)
            {
                int n = 0;
                if (medium_grid[i][j] == 9)
                    continue;
                if (medium_grid[i + 1][j] == 9)
                    n++;
                if (medium_grid[i][j + 1] == 9)
                    n++;
                if (medium_grid[i - 1][j] == 9)
                    n++;
                if (medium_grid[i][j - 1] == 9)
                    n++;

                if (medium_grid[i + 1][j + 1] == 9)
                    n++;
                if (medium_grid[i - 1][j - 1] == 9)
                    n++;
                if (medium_grid[i - 1][j + 1] == 9)
                    n++;
                if (medium_grid[i + 1][j - 1] == 9)
                    n++;

                medium_grid[i][j] = n;
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
                        showmedium_grid[x][y] = medium_grid[x][y];
                        if (medium_grid[x][y] == 0)
                        {
                            for (int i = y; medium_grid[x][i] == 0 && i >= 0 && i <= 16; i++) // Right
                            {
                                expose_mediumzero_cell(medium_grid, showmedium_grid, x, i);
                            }
                            for (int i = y; medium_grid[x][i] == 0 && i >= 0 && i <= 16; i--) // Left
                            {
                                expose_mediumzero_cell(medium_grid, showmedium_grid, x, i);
                            }
                            for (int i = x; medium_grid[i][y] == 0 && i >= 0 && i <= 16; i++) // Up
                            {
                                expose_mediumzero_cell(medium_grid, showmedium_grid, i, y);
                            }
                            for (int i = x; medium_grid[i][y] == 0 && i >= 0 && i <= 16; i--) // Down
                            {
                                expose_mediumzero_cell(medium_grid, showmedium_grid, i, y);
                            }
                            int j = y;
                            for (int i = x; medium_grid[i][j] == 0 && i >= 0 && i <= 16 && j >= 0 && j <= 16; i--) // Top Left Diagnol 
                            {
                                expose_mediumzero_cell(medium_grid, showmedium_grid, i, j);
                                j--;
                            }
                            j = y;
                            for (int i = x; medium_grid[i][j] == 0 && i >= 0 && i <= 16 && j >= 0 && j <= 16; i--) // Top Right Diagnol 
                            {
                                expose_mediumzero_cell(medium_grid, showmedium_grid, i, j);
                                j++;
                            }
                            j = y;
                            for (int i = x; medium_grid[i][j] == 0 && i >= 0 && i <= 16 && j >= 0 && j <= 16; i++) // Bottom Right Diagnol 
                            {
                                expose_mediumzero_cell(medium_grid, showmedium_grid, i, j);
                                j++;
                            }
                            j = y;
                            for (int i = x; medium_grid[i][j] == 0 && i >= 0 && i <= 16 && j >= 0 && j <= 16; i++) // Bottom Left Diagnol 
                            {
                                expose_mediumzero_cell(medium_grid, showmedium_grid, i, j);
                                j--;
                            }
                        }
                    }


                    else if (e.key.code == Mouse::Right)
                    {
                        
                        showmedium_grid[x][y] = 11;
                        mine = med_mines--;
                        if (showmedium_grid[x][y] == 11)
                        {
                            mine = med_mines--;
                            txt.setString(to_string(mine));
                            
                        }
                        

                    }

            }

            app.clear(Color::White);
            
            for (int i = 1; i <= 16; i++)
                for (int j = 1; j <= 16; j++)
                {
                    if (showmedium_grid[x][y] == 9)
                    {
                        showmedium_grid[i][j] = medium_grid[i][j];
                       
                    }
                    s.setTextureRect(IntRect(showmedium_grid[i][j] * w, 0, w, w));
                    s.setPosition(i * w, j * w);
                   
                    app.draw(s);
                }
            for (int i = 1; i <= 16; i++)
                for (int j = 1; j <= 16; j++)
                    if (showmedium_grid[i][j] == 9)
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

            app.draw(txt);

            app.display();
            
            int count = 0;
            for (int i = 1; i <= 16; i++)
            {
                for (int j = 1; j <= 16; j++)
                {
                    if (showmedium_grid[i][j] != 9 && showmedium_grid[i][j] != 10)
                    {
                        count++;
                    }
                }
            }
            if (count == 216)
            {
                cout << "Winner!" << endl;
            }
        }

        sf::Time elapsed = clock.getElapsedTime();

        txt1.setString(to_string((int)elapsed.asSeconds()));
        
        sf::RenderWindow app1(sf::VideoMode(600, 600), " TIMER");
        
        while (app1.isOpen())
        {
            sf::Texture image1;
            sf::Texture image2;
            
            image1.loadFromFile("images/mine.jpg");
            image2.loadFromFile("images/123.jpg");
            
            sf::Sprite images1;
            sf::Sprite images2;

            sf::Text text, text1;
            
            images1.setTexture(image1);
            images2.setTexture(image2);
            
            sf::Font font;
            sf::Font font1;
            
            font1.loadFromFile("font/LCALLIG.ttf");

            text.setFont(font);
            clock_txt.setFont(font1);
            text1.setFont(font1);
            
            string ax = "Time Played:";
            string bx = "seconds";

            text.setString(ax);
            text1.setString(bx);
           
            clock_txt.setPosition(250, 250);
           
            text1.setPosition(290, 250);
            text.setPosition(10, 200);
            
            text.setCharacterSize(40);
            text1.setCharacterSize(30);
            clock_txt.setCharacterSize(40);
            
            text.setFillColor(sf::Color::Red);
            clock_txt.setFillColor(sf::Color::Blue);
            text1.setFillColor(sf::Color::Green);

            sf::Texture image3;
            image3.loadFromFile("images/ABC.jpg");
            sf::Sprite images3;
            images3.setTexture(image3);
            images3.setScale(0.3, 0.3);
            images3.setPosition(150, 150);
            app1.draw(images3);
            
            text.setStyle(sf::Text::Underlined);
            clock_txt.setStyle(sf::Text::Bold);
            
            images1.setScale(1.3, 1.2);
            images2.setScale(0.5, 0.5);
            
            app1.draw(images1);
            
            app1.draw(images2);
            
            app1.draw(text);
            
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
