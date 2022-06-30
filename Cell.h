#pragma once
using namespace std;
#include <string>
#include <iostream>

class Cell {
private:
    int red, green, blue, nbReproduction;
public:
    int getRed() const;

    void setRed(int red);

    int getGreen() const;

    void setGreen(int green);

    int getBlue() const;

    void setBlue(int blue);

    int getNbReproduction() const;

    void setNbReproduction(int nbReproduction);

    Cell();

    Cell(int red, int green, int blue, int nbReproduction);

    ~Cell();

    Cell(const Cell& other);

    void die();

    friend Cell operator+(const Cell left, const Cell right);

    friend ostream &operator<<(ostream &os, const Cell &cell);

    friend istream &operator>>(istream &is, Cell &cell);
};