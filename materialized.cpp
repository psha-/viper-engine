#include "game.h"
#include "materialized.h"

Materialized::Materialized()
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
    for( auto it = Game::Instance().GetActiveState()->GetObjects().begin(); it != Game::Instance().GetActiveState()->GetObjects().end(); ++it) {
        Materialized *obj = static_cast<Materialized*>(*it);
        if( obj != nullptr) {
            collisions.push_back(obj);
        }
    }

    return collisions;
}

bool Materialized::CheckCollision(Materialized *)
{
}

Materialized::~Materialized()
{
    //dtor
}
