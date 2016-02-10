#include "apple.h"

#include <iostream>

Apple::Apple():m_pos()
{
    //ctor
}

void Apple::Init()
{
    m_pos = Segment(rand()%19-9,rand()%19-9);
    DrawSquare(glm::vec3(m_pos.x, m_pos.y, 0), 1);
    InitMesh();
}

void Apple::Update(float deltaTime)
{
    auto head = Snake::Instance()->getSegments().front();

    if( m_pos == head ) {
        Die();
        Respawn();
        Snake::Instance()->AddSegment();
        std::cout<<"apple collision\n";
    }
    Renderable::Update(deltaTime);
}

Apple::~Apple()
{
    //dtor
}
