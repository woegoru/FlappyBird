#define NOMINMAX
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>

#include <stdio.h> 
#include <time.h>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <D:_PORTFOLIO_/code libraries/GameController.h>
#undef min
#undef max

const int WEIGHT = 1500;
const int HEIGHT = 1000;

sf::RenderWindow window(sf::VideoMode(WEIGHT, HEIGHT), "FlappyBird");

int main()
{
    Object2D bird;

    bird.AddAnim("птичка кадры\\bird.png", "fly", 3);
    //creating a scaleand position
    bird.SetScale(0.3, 0.3);
    bird.SetPosition(50, 350);
    //creating bird sizes
    bird.weight = bird.scale.x * 250;
    bird.height = bird.scale.y * 175;

    float boostFall = 0.0025; //acceleration of free fall
    float velocityUp = 0.5; //the speed of the bird's push

    float vy_bird = 0; //the bird's own speed

    while (window.isOpen()) //loop while the game window is open
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
    }

    window.clear({ 255, 255, 255 });
    bird.Animate("fly", 100, window);
    window.display();
}
