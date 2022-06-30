#include "Point3D.h"

Point3D::~Point3D() {}

Point3D::Point3D() : Point3D (0,0,0){}

Point3D::Point3D(string name, int x, int y, int z) : name(name), x(x), y(y), z(z) {}

Point3D::Point3D(int x, int y, int z) : Point3D("Unnamed", x, y, z) {}

Point3D::Point3D(const Point3D& other) : Point3D("Copy of " + other.name, other.x, other.y, other.z) {}

string Point3D::getName() {
    return this->name;
}

void Point3D::setName(const string name) {
    this->name = name;
}

int Point3D::getX() {
    return this->x;
}

void Point3D::setX(const int x) {
    this->x = x;
}

int Point3D::getY() {
    return this->y;
}

void Point3D::setY(const int y) {
    this->y = y;
}

int Point3D::getZ() {
    return this->z;
}

void Point3D::setZ(const int z) {
    this->z = z;
}

float Point3D::getNorm() {
    return sqrtf(powf((float) this->getX(), 2) + powf((float)this->getY(), 2) + powf((float)this->getZ(), 2));
}

Point3D& Point3D::operator=(Point3D other) {
    this->setName(other.getName());
    this->setX(other.getX());
    this->setY(other.getY());
    this->setZ(other.getZ());
    return *this;
}

Point3D& Point3D::operator++() {
    this->setX(this->getX() + 1);
    this->setY(this->getY() + 2);
    this->setZ(this->getZ() + 3);
    return *this;
}

Point3D Point3D::operator++(int) {
    Point3D temp = *this;
    ++* this;
    return temp;
}

Point3D& Point3D::operator--() {
    this->setX(this->getX() - 1);
    this->setY(this->getY() - 1);
    this->setZ(this->getZ() - 1);
    return *this;
}

Point3D Point3D::operator--(int) {
    Point3D temp = *this;
    --* this;
    return temp;
}

Point3D operator+(Point3D left, Point3D right) {
    return Point3D(left.getName() + "+" + right.getName(), left.getX() + right.getX(), left.getY() + right.getY(), left.getZ() + right.getZ());
}

Point3D operator-(Point3D left, Point3D right) {
    return Point3D(left.getName() + "-" + right.getName(), left.getX() - right.getX(), left.getY() - right.getY(), left.getZ() - right.getZ());
}

bool operator<=(Point3D left, Point3D right) {
    return left.getNorm() <= right.getNorm();
}

ostream& operator<<(ostream& os, const Point3D& point) {
    os << point.name << "(" << point.x << ", " << point.y << ", " << point.z << ")";
    return os;
}

istream& operator>>(istream& is, Point3D& point) {
    is >> point.name;
    is >> point.x;
    is >> point.y;
    is >> point.z;
    return is;
}
