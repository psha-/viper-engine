#ifndef APPLE_H
#define APPLE_H

#include "temporal.h"


class Apple : public Temporal
{
    public:
        Apple();
        void Init();
        virtual ~Apple();
    protected:
    private:
        std::pair<short, short> m_pos;
};

#endif // APPLE_H
