#include "rectangle.h"

Rectangle::Rectangle(Coord position, Color color, int height, int width) {
    this->position = position;
    this->color = color;
    this->height = height;
    this->width = width;
}

Rectangle::~Rectangle() {}

void Rectangle::setPosition(Coord position) {
    this->position = position;
}

void Rectangle::setColor(Color color) {
    this->color = color;
}

void Rectangle::setHeight(int height) {
    this->height = height;
}

Coord Rectangle::getPosition() {
    return this->position;
}

Color Rectangle::getColor() {
    return this->color;
}

int Rectangle::getHeight() {
    return this->height;
}

int Rectangle::getWidth() {
    return this->width;
}