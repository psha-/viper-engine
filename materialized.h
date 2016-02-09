#ifndef MATERIALIZED_H
#define MATERIALIZED_H

#include "renderable.h"
#include "collider.h"
#include <vector>

class Materialized : public Renderable
{
    public:
        Materialized();
        inline static void SetCollider(Collider* collider) {
            //Materialized::m_collider = collider;
        }
        inline static Collider* const GetCollider() {
            return m_collider;
        }
        void Update(float);
        virtual std::vector<Materialized *> GetCollisions();
        virtual bool CheckCollision(Materialized *);
        virtual ~Materialized();
    protected:
        static Collider* m_collider;
    private:
};

#endif // MATERIALIZED_H
