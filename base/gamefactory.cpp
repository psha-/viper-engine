#include "gamefactory.h"
#include <fstream>


void gamefactory::AddLevel( std::string name )
{
    GameState* level = LoadLevel(name);
    Game::Instance().AddState(name, level);
}

GameState* gamefactory::LoadLevel( std::string filePath )
{
    GameState* level = new GameState();

    std::string gameObjectName;
    std::ifstream levelFile(filePath);
    if (levelFile.is_open()) {
        // TODO make the file format more sophisticated
        while ( getline(levelFile, gameObjectName) )
        {
            GameObject* obj = gamefactory::Instantiate(gameObjectName);
            level->AddObject(obj);
        }
        levelFile.close();
    }
    return level;
}

std::map<std::string, std::function<GameObject*()>> gamefactory::gameObjectImplRegistry;

void gamefactory::RegisterGameObjectImpl(std::string name, std::function<GameObject*()> gameObjectInstantiateFunction)
{
    gamefactory::gameObjectImplRegistry[name] = gameObjectInstantiateFunction;
}

GameObject* gamefactory::Instantiate(std::string name)
{
    GameObject * instance = nullptr;

    auto it = gamefactory::gameObjectImplRegistry.find(name);
    if(it != gamefactory::gameObjectImplRegistry.end())
        instance = it->second();

    return instance;
}
