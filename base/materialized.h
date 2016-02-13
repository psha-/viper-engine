#ifndef MATERIALIZED_H
#define MATERIALIZED_H

#include "renderable.h"
#include "collider.h"
#include <vector>

class Materialized : public Renderable
{
    public:
        Materialized();
        void Update(float);
        virtual std::vector<Materialized *> GetCollisions();
        virtual bool CheckCollision(Materialized *);
        Collider* GetCollider() {
            return m_collider;
        }
        virtual ~Materialized();
    protected:
        void setCollider( Collider* collider) {
            m_collider = collider;
        }
        Collider* m_collider;
    private:
};

#endif // MATERIALIZED_H
