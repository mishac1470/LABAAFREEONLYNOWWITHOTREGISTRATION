#include "square.h"

using namespace std;

Square::Square(float side): side(side){}

void Square::scale(float scaleFactor = 1){
    area *= scaleFactor;
}

string Square::getName(){
    return "Я квадрат!";
}

void Square::showInfo(){
    cout << getName();
    calculateArea();
    cout << endl;
    cout << "\tМоя площадь = " << area << endl;
    cout << "\tДлина моей стороны = " << side << endl;
}

void Square::calculateArea(){
    area = side * side;
}