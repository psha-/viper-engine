#include "game.h"
#include "materialized.h"

Materialized::Materialized():m_collider()
{
    //ctor
}

void Materialized::Update(float deltaTime)
{
    Renderable::Update(deltaTime);
}

std::vector<Materialized *> Materialized::GetCollisions()
{
    std::vector<Materialized*> collisions = std::vector<Materialized*>();
    collisions.reserve(10);
    auto objects = Game::Instance().GetActiveState()->GetObjects();
    for( auto it = objects.begin(); it != objects.end(); ++it) {
        Materialized *obj = static_cast<Materialized*>(*it);
        if( obj != nullptr && CheckCollision(obj)) {
            collisions.push_back(obj);
        }
    }

    return collisions;
}

bool Materialized::CheckCollision(Materialized* target)
{
    return m_collider->CheckCollision(target->GetCollider());
}

Materialized::~Materialized()
{
    //dtor
}
