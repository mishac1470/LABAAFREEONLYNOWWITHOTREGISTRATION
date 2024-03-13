#include "square.h"

using namespace std;

Square::Square(float side): side(side){}

void Square::scale(float scaleFactor = 1){
    area *= scaleFactor;
}

string Square::getName(){
    return "� ������!";
}

void Square::showInfo(){
    cout << getName();
    calculateArea();
    cout << endl;
    cout << "\t��� ���頤� = " << area << endl;
    cout << "\t����� ���� ��஭� = " << side << endl;
}

void Square::calculateArea(){
    area = side * side;
}