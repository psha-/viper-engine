#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <SDL2/SDL.h>
#include "temporal.h"

struct Segment {
    Segment(){}
    Segment(short x_, short y_):x(x_),y(y_)
    {}
    short x;
    short y;
    bool operator==(const Segment& rhs) {
        return rhs.x == x && rhs.y == y;
    }
};

class Snake: public Temporal
{
    public:
        Snake();
        static Snake* Instance()
        {
            static Snake* instance = new Snake();
            return instance;
        }
        void Init();
        static GameObject* Instantiate()
        {
            return Instance();
        }
        inline std::deque<Segment>& getSegments() {
            return m_segments;
        }
        inline unsigned short getDirection() const {
            return *nextDirection.begin();
        }
        void pushDirection(unsigned short dir);
        void Update(float deltaTime);
        inline void Accelerate(float s=1) {
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
        Snake(Snake const&);
        void operator=(Snake const&);
        void Move();
        bool CheckSelfCollision();
        Uint32 elapsedTime;
        float speed;
        const unsigned short directionBufferLength;
        std::deque<unsigned short> nextDirection;
        std::deque<Segment> m_segments;
        bool addingSegment;
};

#endif // SNAKE_H
