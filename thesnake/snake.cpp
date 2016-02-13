#include "snake.h"
#include "mesh.h"

Snake::Snake():
elapsedTime(),
speed(),
directionBufferLength(2),
nextDirection(),
m_segments(),
addingSegment(false)
{
}

void Snake::Init()
{
    elapsedTime = SDL_GetTicks();

    m_segments = {
        Segment(0,2),
        Segment(0,1),
        Segment(0,0),
        Segment(0,-1),
        Segment(0,-2),
    };

    speed=2;

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

void Snake::AddSegment() {
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
            newSegment.y++;
            break;
        case DIR_DOWN:
            newSegment.y--;
            break;
        case DIR_LEFT:
            newSegment.x++;
            break;
        case DIR_RIGHT:
            newSegment.x--;
            break;
    }
    m_segments.push_front(newSegment);
    if( !addingSegment ) {
        m_segments.pop_back();
    }
    else {
        addingSegment = false;
    }

    if( CheckSelfCollision() ) {
        Die();
        Respawn();
    }

    ResetMesh();
    for( auto it = m_segments.begin(); it != m_segments.end(); ++it ) {
        DrawSquare(glm::vec3((*it).x, (*it).y, 0), 1);
    }
    InitMesh();

}

void Snake::Update(float deltaTime)
{
    SDL_Event event;
    if( SDL_PollEvent( &event ) ){
        switch( event.type ){
            case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){
                    case SDLK_UP:
                        pushDirection(DIR_UP);
                        break;
                    case SDLK_DOWN:
                        pushDirection(DIR_DOWN);
                        break;
                    case SDLK_LEFT:
                        pushDirection(DIR_LEFT);
                        break;
                    case SDLK_RIGHT:
                        pushDirection(DIR_RIGHT);
                        break;
                }
                break;
            case SDL_KEYUP:

                break;
        }
    }
    Move();
    Renderable::Update(deltaTime);
}

bool Snake::CheckSelfCollision()
{
    auto head = getSegments().front();

    for( auto it = m_segments.begin()+1; it != m_segments.end(); ++it) {
        if( *it == head ) {
            return true;
        }
    }
    return false;
}


Snake::~Snake()
{
    //dtor
}
