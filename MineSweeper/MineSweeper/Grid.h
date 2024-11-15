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

class grid
{
private:
    string grid_level;

   
    int showmedium_grid[17][17];
    int showhard_grid[31][17];

    
    int medium_grid[17][17];
    int hard_grid[31][17];
    int mine;
    
    int med_mines = 40;
    int h_mines = 99;

    
    
    int medium_mines = 40;
    int hard_mines = 99;

    

public:

    grid()
    {
       // grid_level = "easy";
    }


    void expose_easyzero_cell(int arr[][10], int showarr[][10], int x, int y)
    {
        int a = x, b = y;

        showarr[a - 1][b - 1] = arr[a - 1][b - 1];

        showarr[a - 1][b] = arr[a - 1][b];

        showarr[a - 1][b + 1] = arr[a - 1][b + 1];

        showarr[a][b - 1] = arr[a][b - 1];

        showarr[a][b + 1] = arr[a][b + 1];

        showarr[a + 1][b - 1] = arr[a + 1][b - 1];

        showarr[a + 1][b] = arr[a + 1][b];

        showarr[a + 1][b + 1] = arr[a + 1][b + 1];
    }

    void expose_mediumzero_cell(int arr[][17], int showarr[][17], int x, int y)
    {
        int a = x, b = y;

        showarr[a - 1][b - 1] = arr[a - 1][b - 1];

        showarr[a - 1][b] = arr[a - 1][b];

        showarr[a - 1][b + 1] = arr[a - 1][b + 1];

        showarr[a][b - 1] = arr[a][b - 1];

        showarr[a][b + 1] = arr[a][b + 1];

        showarr[a + 1][b - 1] = arr[a + 1][b - 1];

        showarr[a + 1][b] = arr[a + 1][b];

        showarr[a + 1][b + 1] = arr[a + 1][b + 1];
    }

    void expose_hardzero_cell(int arr[][17], int showarr[][17], int x, int y)
    {
        int a = x, b = y;

        showarr[a - 1][b - 1] = arr[a - 1][b - 1];

        showarr[a - 1][b] = arr[a - 1][b];

        showarr[a - 1][b + 1] = arr[a - 1][b + 1];

        showarr[a][b - 1] = arr[a][b - 1];

        showarr[a][b + 1] = arr[a][b + 1];

        showarr[a + 1][b - 1] = arr[a + 1][b - 1];

        showarr[a + 1][b] = arr[a + 1][b];

        showarr[a + 1][b + 1] = arr[a + 1][b + 1];
    }

    
    virtual void print_grid() = 0;
    
    

};