#ifndef GAME_H
#define GAME_H

#include "gamestate.h"
#include <string>
#include <vector>
#include <map>

class Game
{
    public:
        Game();
        static Game& Instance()
        {
            static Game instance;
            return instance;
        }
        void Init();
        void Destroy();
        void AddState( std::string, GameState * );
        inline GameState* const GetActiveState() const
        {
            return m_activeState;
        }
        void Update(float deltaTime);
        virtual ~Game();
    protected:
    private:
        Game(Game const&);
        void operator=(Game const&);
        std::map<std::string, GameState*> m_states;
        GameState* m_activeState;
};
#endif // GAME_H
