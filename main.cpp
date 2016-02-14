#define GLM_FORCE_RADIANS

#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "gamefactory.h"
#include "game.h"
#include "snake.h"
#include "apple.h"
#include "walls.h"

#define WIDTH 1200
#define HEIGHT 600
static const int FPS = 60;
static const double DELAY_TIME = 1000.f / FPS;

int main()
{

    Uint32 frameStart = SDL_GetTicks();
    Uint32 frameTime = frameStart;

    Display display(WIDTH,HEIGHT,"The Snake");
    Shader shader("./res/basicShader");
    Texture texture("./res/bricks.jpg");
    Camera camera(glm::vec3(0,0,-30), 70.0f, (float)WIDTH/(float)HEIGHT, 0.01f, 1000.0f);
    Transform cameraTransform;

    float counter = 0.0f;

    // TODO make main unaware of those
    gamefactory::RegisterGameObjectImpl("Snake", &Snake::Instantiate);
    gamefactory::RegisterGameObjectImpl("Apple", &Apple::Instantiate);
    gamefactory::RegisterGameObjectImpl("Walls", &Walls::Instantiate);

    gamefactory::AddLevel("res/snake_l1.txt");
    Game::Instance().Init();

    while(!display.isClosed()) {
        Uint32 currentTimeTicks = SDL_GetTicks();
        float deltaTime = (currentTimeTicks - frameStart) * 0.001f;
        frameStart = currentTimeTicks;

        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

        //float sinCounter = sinf(counter);
        //float cosCounter = cosf(counter);

        //cameraTransform.getRot().z = counter*100;
        //cameraTransform.getRot().y = counter*100;
        //cameraTransform.getRot().z = counter*50;
        //cameraTransform.setScale(glm::vec3(cosCounter, cosCounter, cosCounter));
        //cameraTransform.setScale(glm::vec3(0.1, 0.1, 0.1));

        shader.Bind();
        texture.Bind(0);

        shader.Update(cameraTransform, camera);
        Game::Instance().Update(deltaTime);
        display.Update();
        counter += 0.01f;

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)DELAY_TIME - frameTime);
		}

    }

    Game::Instance().Destroy();

    return 0;
}
