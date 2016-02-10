#include "game.h"
#include <SDL2/SDL.h>
#include "mesh.h"


#include <iostream>

Game::Game()
{
}

void Game::Init()
{
    for( auto it = m_activeState->GetObjects().begin(); it != m_activeState->GetObjects().end(); ++it) {
        (*it)->Init();
    }

}

void Game::Update(float deltaTime)
{
    for( auto it = m_activeState->GetObjects().begin(); it != m_activeState->GetObjects().end(); ++it) {
        (*it)->Update(deltaTime);
    }
}

void Game::AddState(std::string name, GameState* state)
{
    m_states[name] = state;
    m_activeState = state;
}

void Game::Destroy()
{
    for( auto it = m_activeState->GetObjects().begin(); it != m_activeState->GetObjects().end(); ++it) {
        delete *it;
    }
}

Game::~Game()
{
    //dtor
}

