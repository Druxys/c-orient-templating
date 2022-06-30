#include "Cell.h"

Cell::Cell(int red, int green, int blue, int nbReproduction) : red(red), green(green), blue(blue), nbReproduction(nbReproduction) {}

Cell::Cell(const Cell &other) {}

Cell::Cell() {}

Cell::~Cell() {}

void Cell::die() {
    this->~Cell();
}

int Cell::getNbReproduction() const {
    return this->nbReproduction;
}

void Cell::setNbReproduction(const int nbReproduction) {
    this->nbReproduction = nbReproduction;
    //die() if red + greend + blue < 50 or > 725
    if (this->getRed() + this->getGreen() + this->getBlue() < 50 || this->getRed() + this->getGreen() + this->getBlue() > 725) {
        return die();
    }
}

int Cell::getRed() const {
    return this->red;
}

void Cell::setRed(int red) {
    this->red = red;
}

int Cell::getGreen() const {
    return this->green;
}

void Cell::setGreen(int green) {
    this->green = green;
}

int Cell::getBlue() const {
    return this->blue;
}

void Cell::setBlue(int blue) {
    this->blue = blue;
}

Cell operator+(const Cell left, const Cell right) {
    // red = left.green + right.blue % 255
    // green = left.blue + right.red % 255
    // blue = left.red + right.green % 255
    return Cell(left.getRed() + right.getGreen() % 255, left.getGreen() + right.getBlue() % 255, left.getBlue() + right.getRed() % 255, left.getNbReproduction() + right.getNbReproduction());
}

ostream &operator<<(ostream &os, const Cell &cell) {
    os << "(" << cell.getRed() << ", " << cell.getGreen() << ", " << cell.getBlue() << ")";
    return os;
}

istream &operator>>(istream &is, Cell &cell) {
    is >> cell.red >> cell.green >> cell.blue;
    return is;
}

