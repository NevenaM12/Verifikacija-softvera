#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../../2048/app/Game.hpp"
#include "../../2048/app/Utils.hpp"
#include "../../2048/app/Config.hpp"

//Game.cpp -> init(), fillRandPos(), Utils.cpp -> randEven()

TEST_CASE("Initialization test"){
    Game game;
    game.init();
    //na pocetku se popunjavaju dve random pozicije sa random 2 ili 4 (ver 3:1)
    //treba da budu popunjena tacno dva polja od 20 sa 2 ili 4
    Game::GameBoard gb = game.getGameBoard();
    int noTwos=0;
    int noFours=0;
    int zeros=0;
    for (int i = 0; i < GAMEBOARD_ROWS; i++)
        for (int j = 0; j < GAMEBOARD_COLS; j++){
            int ij = gb.at(i).at(j);
            if(ij == 2)
                noTwos ++;
            else if(ij == 4)
                noFours ++;
            else if(ij == 0)
                zeros++;
        }

    REQUIRE(noTwos + noFours == GAMEBOARD_COLS*GAMEBOARD_ROWS - zeros);
}
