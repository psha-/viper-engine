#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "walls.h"
#include <vector>

class Game
{
    public:
        Game();
        void Init();
        void Destroy();
        void Update(float deltaTime);
        virtual ~Game();
    protected:
    private:
        Snake m_snake;
        //std::vector<std::pair<short, short>> boundaries;
        Walls m_boundaries;
        std::vector<std::pair<short, short>> apples;
        template<typename Iterator>
        bool testCollision(const Iterator& begin, const Iterator& end);
        template<typename Iterator>
        void Draw(const Iterator& begin, const Iterator& end);
        void SpawnSnake();
        void SpawnApple();
        //void InitBoundaries();
};
#endif // GAME_H
