#include "renderable.h"

Renderable::Renderable():m_model()
{
}

void Renderable::DrawSquare( glm::vec3 p, float l )
{
        vertices.push_back(Vertex(glm::vec3(p.x+l, p.y,   0), glm::vec2(0,0)));
        vertices.push_back(Vertex(glm::vec3(p.x,   p.y,   0), glm::vec2(0,0)));
        vertices.push_back(Vertex(glm::vec3(p.x+l, p.y+l, 0), glm::vec2(0,0)));
        vertices.push_back(Vertex(glm::vec3(p.x,   p.y,   0), glm::vec2(0,0)));
        vertices.push_back(Vertex(glm::vec3(p.x,   p.y+l, 0), glm::vec2(0,0)));
        vertices.push_back(Vertex(glm::vec3(p.x+l, p.y+l ,0), glm::vec2(0,0)));

        unsigned int i=indices.size();
        indices.push_back(i++);
        indices.push_back(i++);
        indices.push_back(i++);
        indices.push_back(i++);
        indices.push_back(i++);
        indices.push_back(i++);

        m_mesh.addVertices(vertices, indices, m_model);
}

void Renderable::ResetMesh()
{
    m_model = IndexedModel();
}

void Renderable::InitMesh()
{
    m_mesh.InitMesh(m_model);
}

void Renderable::Update(float deltaTime)
{
    m_mesh.Draw();
}

Renderable::~Renderable()
{
    //dtor
}
