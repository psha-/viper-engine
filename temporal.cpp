#include "temporal.h"

Temporal::Temporal()
{
    //ctor
}

void Temporal::Die()
{
    ResetMesh();
}

void Temporal::Respawn()
{
    Init();
}

Temporal::~Temporal()
{
    //dtor
}
