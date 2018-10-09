#pragma once
#include <SFML/Graphics.hpp>
#include "common.hpp"
#include "cell.hpp"




class Field{

    private:

      std::vector< std::vector <Cell> > field;
      std::pair<int,int> fieldDimension; // std::pair <xAxis, yAxis>
      float cellSize;


      public:

        Field(std::pair<int,int> fieldDimension, float cellSize);
        Field(int xAxisSize, int yAxisSize, float cellSize);

        bool changeCellState(int posX, int posY, bool crossTurn);
        Cell getCell(int posX, int posY);

        bool checkForWin();
};
