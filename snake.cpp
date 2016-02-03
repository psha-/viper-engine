#include "snake.h"
#include "mesh.h"

Snake::Snake()
{
}

void Snake::Init()
{
    Uint32 elapsedTime = SDL_GetTicks();

    m_segments = {
        std::pair<short, short>(0,0),
        std::pair<short, short>(0,1),
        std::pair<short, short>(0,2),
        std::pair<short, short>(0,3),
    };

    speed = 2;
    nextDirection = {DIR_UP};
}

void Snake::pushDirection(unsigned short dir) {
    if( nextDirection.size() >= directionBufferLength ) return;

    unsigned short currentDir = getDirection();
    switch( dir ) {
        case DIR_UP:
        case DIR_DOWN:
            if( DIR_DOWN == currentDir || DIR_UP == currentDir ) return;
            break;
        case DIR_LEFT:
        case DIR_RIGHT:
            if( DIR_LEFT == currentDir || DIR_RIGHT == currentDir ) return;
            break;
    }
    nextDirection.push_back(dir);
}

void Snake::Die() {
    m_segments.clear();
}

void Snake::AddSegment() {
    //auto newSegment = m_segments.back();
    //m_segments.push_back(newSegment);
    addingSegment = true;
}

void Snake::Move()
{
    if( SDL_GetTicks() - elapsedTime < 1000/speed ) {
        return;
    }
    elapsedTime = SDL_GetTicks();

    unsigned short direction = *nextDirection.begin();
    if( nextDirection.size() > 1) {
        nextDirection.pop_front();
    }

    auto newSegment = *m_segments.begin();
    switch( direction ) {
        case DIR_UP:
            newSegment.second++;
            break;
        case DIR_DOWN:
            newSegment.second--;
            break;
        case DIR_LEFT:
            newSegment.first++;
            break;
        case DIR_RIGHT:
            newSegment.first--;
            break;
    }
    m_segments.push_front(newSegment);
    if( !addingSegment ) {
        m_segments.pop_back();
    }
    else {
        addingSegment = false;
    }
}

void Snake::Update(float deltaTime)
{
    Move();
    ResetMesh();
    for( auto it = m_segments.begin(); it != m_segments.end(); ++it ) {
        DrawSquare(glm::vec3((*it).first, (*it).second, 0), 1);
    }
    InitMesh();
    Renderable::Update(deltaTime);
}

Snake::~Snake()
{
    //dtor
}
