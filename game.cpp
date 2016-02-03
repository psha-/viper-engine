#include "game.h"
#include <SDL2/SDL.h>
#include "mesh.h"


#include <iostream>

Game::Game():m_snake(),m_boundaries()
{
}
void Game::Init()
{
    m_boundaries.Init();
    SpawnSnake();
    SpawnApple();

}

void Game::Update(float deltaTime)
{
    SDL_Event event;
    if( SDL_PollEvent( &event ) ){
        switch( event.type ){
            /* Keyboard event */
            /* Pass the event data onto PrintKeyInfo() */
            case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){
                    case SDLK_UP:
                        m_snake.pushDirection(Snake::DIR_UP);
                        break;
                    case SDLK_DOWN:
                        m_snake.pushDirection(Snake::DIR_DOWN);
                        break;
                    case SDLK_LEFT:
                        m_snake.pushDirection(Snake::DIR_LEFT);
                        break;
                    case SDLK_RIGHT:
                        m_snake.pushDirection(Snake::DIR_RIGHT);
                        break;
                }
                break;
            case SDL_KEYUP:

                break;

            /* SDL_QUIT event (window close) */
            //case SDL_QUIT:
                //quit = 1;
                //break;

            default:
                break;
        }

    }
    m_snake.Update(deltaTime);
    m_boundaries.Update(deltaTime);
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

Game::~Game()
{
    //dtor
}
void Game::SpawnSnake()
{
    m_snake.Init();
}

void Game::SpawnApple()
{
    apples.push_back(std::pair<short, short>(rand()%19-9,rand()%19-9));
}

template<typename Iterator>
bool Game::testCollision(const Iterator& begin, const Iterator& end)
{
    auto head = m_snake.getSegments().front();
    for( auto it = begin; it != end; ++it) {
        if( (*it).first == head.first && (*it).second == head.second ) {
            return true;
        }
    }
    return false;
}
