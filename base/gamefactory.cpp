#include "gamefactory.h"
#include "game.h"
#include "snake.h"
#include "walls.h"
#include "apple.h"


void gamefactory::AddLevel( std::string name )
{
    GameState* level = LoadLevel(name);
    Game::Instance().AddState(name, level);
}

GameState* gamefactory::LoadLevel( std::string name )
{
    GameState* level = new GameState();

    // TODO: Use external resource file
    if( "snake_l1" == name ) {
        GameObject* snake = Snake::Instance();
        GameObject* walls = new Walls();
        GameObject* apple = new Apple();

        level->AddObject(snake);
        level->AddObject(walls);
        level->AddObject(apple);
    }
    return level;
}
