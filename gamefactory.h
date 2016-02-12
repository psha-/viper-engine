#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include "game.h"
#include "gamestate.h"
#include <string>

namespace gamefactory
{
        void AddLevel(std::string name);
        GameState* LoadLevel(std::string name);
}

#endif // GAMEFACTORY_H
