#pragma once
using namespace std;
#include <string>
#include <iostream>

class Point3D {
    private:
    string name;
    int x;
    int y;
    int z;

    public:
    ~Point3D();
    Point3D();
    Point3D(string name, int x, int y, int z);
    Point3D(int x, int y, int z);
    Point3D(const Point3D& other);

    string getName();
    void setName(const string name);
    int getX();
    void setX(const int x);
    int getY();
    void setY(const int y);
    int getZ();
    void setZ(const int z);

    float getNorm();

    friend ostream& operator<<(ostream& os, const Point3D& point);
    friend istream& operator>>(istream& is, Point3D& point);

    Point3D& operator=(const Point3D opther);

    Point3D& operator++();
    Point3D operator++(int);
    Point3D& operator--();
    Point3D operator--(int);
    friend Point3D operator+(const Point3D left, const Point3D right);
    friend Point3D operator-(const Point3D left, const Point3D right);

    friend bool operator<=(const Point3D left, const Point3D right);
    friend bool operator!=(const Point3D left, const Point3D right);
};

