#include "apple.h"

Apple::Apple()
{
    //ctor
}

void Apple::Init()
{
    m_pos = std::pair<short, short>(rand()%19-9,rand()%19-9);
    DrawSquare(glm::vec3(m_pos.first, m_pos.second, 0), 1);
    InitMesh();
}

Apple::~Apple()
{
    //dtor
}
