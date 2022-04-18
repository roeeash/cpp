// Twitch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/Math/Vector3.h"
#include "FlappyTwitch/Flapper.h"
#include <iostream>

int main()
{
    std::cout << "Hello Twitch!\n";
    Engine engine;
    char title[] = "Twitch";
    engine.Initiallize(title);

    Sprite testSprite = Sprite("Assets/Art/Biplane.png",Vector3(100,100,0));
    testSprite.setScale(0.25f);
    Flapper player(testSprite);

    while (true) {
        //update engine and sprite
        engine.Update();
        testSprite.Update();
        //player.Update();
        //render
        
        //testSprite.MoveTo((float)Mouse::getMouseX(), (float)Mouse::getMouseY());
        
        //if left click was pressed
        if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)){
            testSprite.RotateBy(100);
        }

        //if right click was released
        if (Mouse::ButtonUp(GLFW_MOUSE_BUTTON_RIGHT)) {
            testSprite.RotateBy(-100);
        }
       
        //if middle click was pressed
        if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE)) {
            testSprite.RotateBy(-100);
        }

        //if middle click was pressed
        if (Keyboard::Key(GLFW_KEY_W)) {
            testSprite.MoveUp();
        }
        //if middle click was pressed
        if (Keyboard::Key(GLFW_KEY_S)) {
            testSprite.MoveDown();
        }
        //if middle click was pressed
        if (Keyboard::Key(GLFW_KEY_A)) {
            player.GetSprite().MoveLeft();
        }
        //if middle click was pressed
        if (Keyboard::Key(GLFW_KEY_D)) {
            testSprite.MoveRight();
        }

        engine.BeginRender();
        testSprite.Render();
        //player.Render();
        engine.EndRender();
    }
    return 0;
}
