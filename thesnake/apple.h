#ifndef APPLE_H
#define APPLE_H

#include "temporal.h"
#include "snake.h"

class Apple : public Temporal
{
    public:
        Apple();
        void Init();
        static GameObject* Instantiate()
        {
            return new Apple();
        }
        void Update(float);
        virtual ~Apple();
    protected:
    private:
        Segment m_pos;
};

#endif // APPLE_H
