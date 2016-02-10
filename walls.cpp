#include "walls.h"

#include <iostream>


Walls::Walls()
{
    //ctor
}

void Walls::Init()
{
    m_segments.reserve(50);
    for( short int i=-10; i<=10; ++i ) {
        m_segments.push_back(Segment(i, -10));
    }
    for( short int i=-10; i<=10; ++i ) {
        m_segments.push_back(Segment(i, 10));
    }
    for( short int i=-9; i<=9; ++i ) {
        m_segments.push_back(Segment(-10, i));
    }
    for( short int i=-9; i<=9; ++i ) {
        m_segments.push_back(Segment(10, i));
    }
    for( auto it = m_segments.begin(); it != m_segments.end(); ++it ) {
        DrawSquare(glm::vec3((*it).x, (*it).y, 0), 1);
    }
    InitMesh();
}

void Walls::Update(float deltaTime)
{
    auto head = Snake::Instance()->getSegments().front();

    for( auto it = m_segments.begin(); it != m_segments.end(); ++it) {
        if( *it == head ) {
            Snake::Instance()->Die();
            Snake::Instance()->Respawn();
            std::cout<<"wall collision\n";
        }
    }
    Renderable::Update(deltaTime);
}

Walls::~Walls()
{
    //dtor
}
