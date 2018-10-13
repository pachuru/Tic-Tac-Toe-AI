#include <SFML/Graphics.hpp>
#include <iostream>
#include "cell.hpp"
#include "field.hpp"

int main(){


  int cellSize = 160;
  int fieldSize = 480;

  bool crossTurn = false;
  std::pair <int,int> calculatedMove = std::make_pair(0,0);


  Field gameField(fieldSize,fieldSize,cellSize);
  sf::RenderWindow window(sf::VideoMode(fieldSize,fieldSize), "Tic Tac Toe", sf::Style::Close);

  sf::Texture mainScreenTexture;
  mainScreenTexture.loadFromFile("./art/humanwins.png");
  sf::RectangleShape mainScreen(sf::Vector2f(480.0f, 480.0f));
  mainScreen.setTexture(&mainScreenTexture);

  while (true){
    window.clear();
    window.draw(mainScreen);
    window.display();
  }


/*
  while (true){
    sf::Event evnt;
    while (window.pollEvent(evnt)){
      switch(evnt.type){
        case sf::Event::Closed:
             window.close();
             break;
        case sf::Event::MouseButtonPressed:
              if ((evnt.mouseButton.button == sf::Mouse::Left)){
              if(gameField.changeCellState(evnt.mouseButton.x, evnt.mouseButton.y,false)){
                int result = gameField.checkForTerminalState(gameField.getField());
                switch(result){
                  case -10:
                  std::cout << "Circle Wins\n";
                  return false;
                  break;
                  case 10:
                  std::cout << "Cross Wins\n";
                  return false;
                  break;
                  case 0:
                  std::cout << "Tie\n";
                  return false;
                  break;
                  default:
                  std::cout << "The game keeps goin on\n";
                  //crossTurn = true;
                  break;
                }


              window.clear();
              for (int y = 0; y < fieldSize/ cellSize; y++)
                for (int x = 0; x < fieldSize / cellSize; x++)
                  window.draw(gameField.getCell(x,y));
              window.display();

                  calculatedMove = gameField.findBestMove(gameField.getField());
                  std::cout << "Should move to (y,x) -> " << calculatedMove.first << " , " << calculatedMove.second << "\n";
                  if(gameField.changeCellState_(calculatedMove.second, calculatedMove.first, true)){
                  std::cout << "Im not entering here\n";
                  result = gameField.checkForTerminalState(gameField.getField());
                  switch(result){
                    case -10:
                    std::cout << "Circle Wins\n";
                    return false;
                    break;
                    case 10:
                    std::cout << "Cross Wins\n";
                    return false;
                    crossTurn = false;
                    break;
                    case 0:
                    std::cout << "Tie\n";
                    return false;
                    break;
                    case 3:
                    std::cout << "The game keeps goin on\n";
                    crossTurn = false;
                    break;
                  }

                  window.clear();
                  for (int y = 0; y < fieldSize/ cellSize; y++)
                    for (int x = 0; x < fieldSize / cellSize; x++)
                      window.draw(gameField.getCell(x,y));
                  window.display();

                }
              }
            }



      }
    }

    window.clear();
    for (int y = 0; y < fieldSize/ cellSize; y++)
      for (int x = 0; x < fieldSize / cellSize; x++)
        window.draw(gameField.getCell(x,y));
    window.display();






  }
*/
}
