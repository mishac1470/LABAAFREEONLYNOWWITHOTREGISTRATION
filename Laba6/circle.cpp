#include "circle.h"

using namespace std;

Circle::Circle(float radius): radius(radius){}

void Circle::scale(float scaleFactor = 1){
    area *= scaleFactor;
}

string Circle::getName(){
    return "� ���!";
}

void Circle::showInfo(){
    cout << getName();
    calculateArea();
    cout << endl;
    cout << "\t��� ���頤� = " << area << endl;
    cout << "\t��� ࠤ��� = " << radius << endl;
}

void Circle::calculateArea(){
    area = M_PI * radius * radius;
}