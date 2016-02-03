#ifndef WALLS_H
#define WALLS_H

#include "renderable.h"


class Walls : public Renderable
{
    public:
        Walls();
        void Init();
        void Update(float deltatime);
        virtual ~Walls();
    protected:
    private:
        std::vector<std::pair<short, short>> m_segments;

};

#endif // WALLS_H
