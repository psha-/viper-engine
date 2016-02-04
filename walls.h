#ifndef WALLS_H
#define WALLS_H

#include "materialized.h"


class Walls : public Materialized
{
    public:
        Walls();
        void Init();
        virtual ~Walls();
    protected:
    private:
        std::vector<std::pair<short, short>> m_segments;

};

#endif // WALLS_H
