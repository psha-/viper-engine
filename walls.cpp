#include "walls.h"

Walls::Walls()
{
    //ctor
}

void Walls::Init()
{
    m_segments.reserve(50);
    for( short int i=-10; i<=10; i++ ) {
        m_segments.push_back(std::pair<short, short>(i, -10));
    }
    for( short int i=-10; i<=10; i++ ) {
        m_segments.push_back(std::pair<short, short>(i, 10));
    }
    for( short int i=-9; i<=9; i++ ) {
        m_segments.push_back(std::pair<short, short>(-10, i));
    }
    for( short int i=-9; i<=9; i++ ) {
        m_segments.push_back(std::pair<short, short>(10, i));
    }
    for( auto it = m_segments.begin(); it != m_segments.end(); ++it ) {
        DrawSquare(glm::vec3((*it).first, (*it).second, 0), 1);
    }
    InitMesh();
}

void Walls::Update(float deltaTime)
{
    Renderable::Update(deltaTime);
}


Walls::~Walls()
{
    //dtor
}
