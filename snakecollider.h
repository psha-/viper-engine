#ifndef SNAKECOLLIDER_H
#define SNAKECOLLIDER_H

#include "collider.h"
#include "snake.h"
#include <vector>

class SnakeCollider: public Collider
{
    public:
        SnakeCollider();
        bool CheckCollision(Collider *);
        virtual ~SnakeCollider();
    protected:
    private:
        std::vector<Segment>* m_segments;
};

#endif // SNAKECOLLIDER_H
