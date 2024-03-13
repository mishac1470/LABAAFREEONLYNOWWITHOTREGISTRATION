#include "circle.h"

using namespace std;

Circle::Circle(float radius): radius(radius){}

void Circle::scale(float scaleFactor = 1){
    area *= scaleFactor;
}

string Circle::getName(){
    return "Я круг!";
}

void Circle::showInfo(){
    cout << getName();
    calculateArea();
    cout << endl;
    cout << "\tМоя площадь = " << area << endl;
    cout << "\tМой радиус = " << radius << endl;
}

void Circle::calculateArea(){
    area = M_PI * radius * radius;
}