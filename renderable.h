#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "gameobject.h"
#include "mesh.h"
#include <glm/glm.hpp>
#include <vector>

class Renderable : public GameObject
{
    public:
        Renderable();
        void ResetMesh();
        void DrawSquare( glm::vec3 p, float l );
        void InitMesh();
        virtual void Update(float deltaTime);
        virtual ~Renderable();
    protected:
        Mesh m_mesh;
        IndexedModel m_model;
    private:
};

#endif // RENDERABLE_H
