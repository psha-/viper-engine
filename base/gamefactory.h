#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include "game.h"
#include "gamestate.h"
#include <map>
#include <string>

namespace gamefactory
{
        template<typename F>
        extern std::map<std::string, F> gameObjectImplRegistry;

        void AddLevel(std::string name);
        GameState* LoadLevel(std::string filePath);
        template<typename F>
        void RegisterGameObjectImpl(std::string name, F> gameObjectInstantiateFunction);
        GameObject* Instantiate(std::string name);
}

#endif // GAMEFACTORY_H
