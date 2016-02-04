#ifndef MATERIALIZED_H
#define MATERIALIZED_H

#include "renderable.h"
#include <vector>

class Materialized : public Renderable
{
    public:
        Materialized();
        void Update(float);
        virtual std::vector<Materialized *> GetCollisions();
        virtual bool CheckCollision(Materialized *);
        virtual ~Materialized();
    protected:
    private:
};

#endif // MATERIALIZED_H
