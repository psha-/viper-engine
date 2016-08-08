#include "gamefactory.h"
#include <fstream>
#include <functional>


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

template<typename F>
std::map<std::string, F> gamefactory::gameObjectImplRegistry;

template<typename F>
void gamefactory::RegisterGameObjectImpl(std::string name, F> gameObjectInstantiateFunction)
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
