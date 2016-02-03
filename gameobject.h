#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "component.h"
#include <string>
#include <vector>
#include "glm/gtx/transform.hpp"

class GameObject
{
    public:
        GameObject();
        virtual void Init();
        virtual void Uninit();
        virtual void Update( float deltaTime );

        virtual ~GameObject();
    protected:
        glm::mat4 m_transform;
};

#endif // GAMEOBJECT_H
