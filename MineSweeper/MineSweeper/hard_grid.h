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
class Hard_grid :public grid
{
private:
    int showhard_grid[31][17];
    int hard_mines = 99;
    int hard_grid[31][17];
    int mine;
    int h_mines;
    Texture t, t1, t2;

    sf::Text txt, txt1, clock_txt;
    sf::Font f1;

public:
    Hard_grid()
    {
        mine = 99;
        h_mines = 99;
        showhard_grid[31][17] = {};
        hard_grid[31][17] = {};
    }
    void print_grid()
    {
        srand(time(0));

        Clock clock;

        Clock clock1;
        
        RenderWindow app(VideoMode(1200, 800), "Minesweeper OOP");

        mine = h_mines;
        
        int w = 32;
        
        f1.loadFromFile("font/ebrima.ttf");

        txt.setString(to_string(mine));
        txt.setFont(f1);
        txt.setCharacterSize(180);
        txt.setPosition(300, 550);
        txt.setFillColor(Color::Red);

        txt1.setFont(f1);
        txt1.setCharacterSize(180);
        txt1.setPosition(750, 550);
        txt1.setFillColor(Color::Red);
       
        t.loadFromFile("images/tiles.jpg");
        t1.loadFromFile("images/mine.jpg");
        t2.loadFromFile("images/clock.jpg");
       
        Sprite s(t);
        Sprite s1(t1);
        Sprite s2(t2);
        
        s1.setScale(0.5, 0.5);
        s1.setPosition(30, 550);
        
        s2.setScale(0.3, 0.3);
        s2.setPosition(950, 550);

        for (int i = 1; i <= 30; i++) // Place Closed Boxes
        {
            for (int j = 1; j <= 16; j++)
            {
                showhard_grid[i][j] = 10;
            }
        }

        for (int i = 1; i <= hard_mines; i++) // Place Mines // Remeber to change it 
        {
            int x, y;
            x = 1 + (rand() % 30);
            y = 1 + (rand() % 16);
            if (hard_grid[x][y] != 9)
            {
                hard_grid[x][y] = 9;
            }
        }

        for (int i = 1; i <= 30; i++) // Place 
        {
            for (int j = 1; j <= 16; j++)
            {
                if (hard_grid[i][j] != 9)
                    hard_grid[i][j] = 0;
            }
        }

        for (int i = 1; i <= 30; i++)
        {
            for (int j = 1; j <= 16; j++)
            {
                int n = 0;
                if (hard_grid[i][j] == 9)
                    continue;
                if (hard_grid[i + 1][j] == 9)
                    n++;
                if (hard_grid[i][j + 1] == 9)
                    n++;
                if (hard_grid[i - 1][j] == 9)
                    n++;
                if (hard_grid[i][j - 1] == 9)
                    n++;

                if (hard_grid[i + 1][j + 1] == 9)
                    n++;
                if (hard_grid[i - 1][j - 1] == 9)
                    n++;
                if (hard_grid[i - 1][j + 1] == 9)
                    n++;
                if (hard_grid[i + 1][j - 1] == 9)
                    n++;

                hard_grid[i][j] = n;
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
                    if (e.key.code == Mouse::Left) {
                        showhard_grid[x][y] = hard_grid[x][y];
                        if (hard_grid[x][y] == 0)
                        {
                            for (int i = y; hard_grid[x][i] == 0 && i >= 0 && i <= 16; i++) // Right
                            {
                                expose_hardzero_cell(hard_grid, showhard_grid, x, i);
                            }
                            for (int i = y; hard_grid[x][i] == 0 && i >= 0 && i <= 16; i--) // Left
                            {
                                expose_hardzero_cell(hard_grid, showhard_grid, x, i);
                            }
                            for (int i = x; hard_grid[i][y] == 0 && i >= 0 && i <= 30; i++) // Up
                            {
                                expose_hardzero_cell(hard_grid, showhard_grid, i, y);
                            }
                            for (int i = x; hard_grid[i][y] == 0 && i >= 0 && i <= 30; i--) // Down
                            {
                                expose_hardzero_cell(hard_grid, showhard_grid, i, y);
                            }
                            int j = y;
                            for (int i = x; hard_grid[i][j] == 0 && i >= 0 && i <= 30 && j >= 0 && j <= 16; i--) // Top Left Diagnol 
                            {
                                expose_hardzero_cell(hard_grid, showhard_grid, i, j);
                                j--;
                            }
                            j = y;
                            for (int i = x; hard_grid[i][j] == 0 && i >= 0 && i <= 30 && j >= 0 && j <= 16; i--) // Top Right Diagnol 
                            {
                                expose_hardzero_cell(hard_grid, showhard_grid, i, j);
                                j++;
                            }
                            j = y;
                            for (int i = x; hard_grid[i][j] == 0 && i >= 0 && i <= 30 && j >= 0 && j <= 16; i++) // Bottom Right Diagnol 
                            {
                                expose_hardzero_cell(hard_grid, showhard_grid, i, j);
                                j++;
                            }
                            j = y;
                            for (int i = x; hard_grid[i][j] == 0 && i >= 0 && i <= 30 && j >= 0 && j <= 16; i++) // Bottom Left Diagnol 
                            {
                                expose_hardzero_cell(hard_grid, showhard_grid, i, j);
                                j--;
                            }
                        }
                    }
                    else if (e.key.code == Mouse::Right)
                    {
                        showhard_grid[x][y] = 11;
                        mine = h_mines--;
                        if (showhard_grid[x][y] == 11)
                        {
                            mine = h_mines--;
                            txt.setString(to_string(mine));

                        }
                        
                        
                    }
            }

            app.clear(Color::White);
            for (int i = 1; i <= 30; i++)
                for (int j = 1; j <= 16; j++)
                {
                    if (showhard_grid[x][y] == 9)
                    {
                        showhard_grid[i][j] = hard_grid[i][j];
                        txt1.setString(to_string(0));
                        app.draw(txt1);
                        

                    }
                    s.setTextureRect(IntRect(showhard_grid[i][j] * w, 0, w, w));
                
                    s.setPosition(i * w, j * w);
                    
                    app.draw(s);
                }
            for (int i = 1; i <= 30; i++)
                for (int j = 1; j <= 16; j++)
                    if (showhard_grid[i][j] == 9)
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
                    if (showhard_grid[i][j] != 9 && showhard_grid[i][j] != 10)
                    {
                        count++;
                    }
                }
            }
            if (count == 381)
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
            
            images1.setTexture(image1);
            images2.setTexture(image2);

            
            
            sf::Font font;
            sf::Font font1;
            
            font1.loadFromFile("font/LCALLIG.ttf");
            
            sf::Text text, text1;
            sf::Text clock_text;
            
            text.setFont(font);
            clock_txt.setFont(font1);
            text1.setFont(font1);
            
            string ax = "Time Played:";
            string bx = "seconds";
            
            images1.setScale(1.3, 1.2);
            
            images2.setScale(0.5, 0.5);
            
            text.setString(ax);
            text1.setString(bx);
            text.setPosition(10, 200);
            
            clock_txt.setPosition(250, 250);
            
            text1.setPosition(290, 250);
            text.setCharacterSize(40);
            text1.setCharacterSize(30);

            sf::Texture image3;
            image3.loadFromFile("images/ABC.jpg");
            sf::Sprite images3;
            images3.setTexture(image3);
            images3.setScale(0.3, 0.3);
            images3.setPosition(150, 150);
            app1.draw(images3);
            
            clock_txt.setCharacterSize(40);
            
            text.setFillColor(sf::Color::Red);
            
            clock_txt.setFillColor(sf::Color::Blue);
            
            text1.setFillColor(sf::Color::Green);
            text.setStyle(sf::Text::Underlined);
            
            clock_txt.setStyle(sf::Text::Bold);
            
            app1.draw(images1);
            
            app1.draw(images2);
            
            app1.draw(text);

            app1.draw(txt1);
            
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

