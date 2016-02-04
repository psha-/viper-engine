#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "gameobject.h"
#include <vector>

class GameState
{
    public:
        GameState();
        void AddObject(GameObject*);
        inline std::vector<GameObject*> const &GetObjects() const
        {
            return m_objects;
        }
        virtual ~GameState();
    protected:
    private:
        std::vector<GameObject*> m_objects;
};

#endif // GAMESTATE_H
