#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <SDL2/SDL.h>
#include "renderable.h"

class Snake: public Renderable
{
    public:
        Snake();
        void Init();
        inline auto getSegments() const {
            return m_segments;
        }
        inline unsigned short getDirection() const {
            return *nextDirection.begin();
        }
        void pushDirection(unsigned short dir);
        void Update(float deltaTime);
        void Die();
        inline void Accelerate(float s) {
            speed += s;
        };
        void AddSegment();
        virtual ~Snake();
        enum
        {
            DIR_NONE,
            DIR_LEFT,
            DIR_RIGHT,
            DIR_UP,
            DIR_DOWN
        };
    protected:
    private:
        void Move();
        Uint32 elapsedTime;
        float speed;
        const unsigned short directionBufferLength = 3;
        std::deque<unsigned short> nextDirection;
        std::deque<std::pair<short, short>> m_segments;
        bool addingSegment = false;
};

#endif // SNAKE_H
