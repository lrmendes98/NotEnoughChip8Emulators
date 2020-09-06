#pragma once

#include <SDL2/SDL.h>
#include <iostream>

#include "aux.h"

class Rectangle {
    private:
        /**
        *   Position refers to the upper left corner of the rectangle
        *   Coord and Color is a struct defined in aux.h
        */
        Coord position;
        Color color;
        int height;
        int width;

    public:
        Rectangle(Coord position, Color color, int height, int width);
        ~Rectangle();
        void setPosition(Coord position);
        void setColor(Color color);
        void setHeight(int height);
        void setWidth(int width);
        Coord getPosition();
        Color getColor();
        int getHeight();
        int getWidth();
};