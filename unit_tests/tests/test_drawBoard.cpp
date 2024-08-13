#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include "catch.hpp"
#include "../../2048/app/Game.hpp"

std::string stripColor(const std::string& input){
    std::regex colorCode("\x1b\\[[0-9;]*m");
    return std::regex_replace(input,colorCode,"");
}

TEST_CASE("Draw board test"){
    Game game;

    std::stringstream buffer;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    Game::GameBoard gb = {
     {0,2,0,0,0},
     {0,0,4,0,32},
     {256,0,16,64,0},
     {0,8,0,0,128}
    };
    game.setGameBoard(gb);
    game.drawGameBoard();

    std::cout.rdbuf(oldCoutBuffer);

    std::string strippedOfColor = stripColor(buffer.str());

    std::string expectedOutput =
    R"(<2048 version console> :: Dark.Hades
+-----+-----+-----+-----+-----+
|     |    2|     |     |     |
+-----+-----+-----+-----+-----+
|     |     |    4|     |   32|
+-----+-----+-----+-----+-----+
|  256|     |   16|   64|     |
+-----+-----+-----+-----+-----+
|     |    8|     |     |  128|
+-----+-----+-----+-----+-----+
Point: 0
)";

    REQUIRE(strippedOfColor == expectedOutput);
}
