#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include "game.h"
#include "gamestate.h"
#include <map>
#include <string>
#include <functional>

namespace gamefactory
{
        extern std::map<std::string, std::function<GameObject*()>> gameObjectImplRegistry;

        void AddLevel(std::string name);
        GameState* LoadLevel(std::string filePath);

        void RegisterGameObjectImpl(std::string name, std::function<GameObject*()> gameObjectInstantiateFunction);
        GameObject* Instantiate(std::string name);
}

#endif // GAMEFACTORY_H
