#ifndef TEMPORAL_H
#define TEMPORAL_H

#include "materialized.h"


class Temporal : public Materialized
{
    public:
        Temporal();
        virtual void Die();
        virtual void Respawn();
        virtual ~Temporal();
    protected:
    private:
};

#endif // TEMPORAL_H
