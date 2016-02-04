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
    SpawnApple();

}

void Game::Update(float deltaTime)
{
    for( auto it = m_activeState->GetObjects().begin(); it != m_activeState->GetObjects().end(); ++it) {
        (*it)->Update(deltaTime);
    }
    //Draw(apples.begin(), apples.end());
    //if( testCollision(boundaries.begin(), boundaries.end())) {
    //    m_snake.Die();
    //    SpawnSnake();
    //    return;
    //}
    //if( testCollision(segments.begin(), segments.end())) {
    //    m_snake.Die();
    //    SpawnSnake();
    //    return;
    //}
    //if( testCollision(apples.begin(), apples.end()) ) {
    //    m_snake.AddSegment();
    //    m_snake.Accelerate(0.5);
    //    apples.clear();
    //    SpawnApple();
    //    return;
    //}

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

void Game::SpawnApple()
{
}

template<typename Iterator>
bool Game::testCollision(const Iterator& begin, const Iterator& end)
{
    //auto head = m_snake.getSegments().front();
    //for( auto it = begin; it != end; ++it) {
    //    if( (*it).first == head.first && (*it).second == head.second ) {
    //        return true;
    //    }
    //}
    return false;
}
