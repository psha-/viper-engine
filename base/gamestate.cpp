#include "gamestate.h"

GameState::GameState():m_objects()
{
    //ctor
}

void GameState::AddObject(GameObject* object)
{
    m_objects.push_back(object);
}

GameState::~GameState()
{
    //dtor
}
