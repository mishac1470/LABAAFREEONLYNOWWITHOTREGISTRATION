#include "triangle.h"

using namespace std;

Triangle::Triangle(float base, float height): base(base), height(height){}

void Triangle::scale(float scaleFactor = 1){
    area *= scaleFactor;
}

string Triangle::getName(){
    return "Я треугольник!";
}

void Triangle::showInfo(){
    cout << getName();
    calculateArea();
    cout << endl;
    cout << "\tМоя площадь = " << area << endl;
    cout << "\tДлина моего основания = " << base << endl;
    cout << "\tМоя высота = " << height << endl;
}

void Triangle::calculateArea(){
    area = 1/2 * base * height;
}