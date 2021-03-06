#ifndef WALLS_H
#define WALLS_H

#include "materialized.h"
#include "snake.h"

class Walls : public Materialized
{
    public:
        Walls();
        void Init();
        static GameObject* Instantiate()
        {
            return new Walls();
        }
        void Update(float);
        virtual ~Walls();
    protected:
    private:
        std::vector<Segment> m_segments;

};

#endif // WALLS_H
