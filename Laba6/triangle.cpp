#include "triangle.h"

using namespace std;

Triangle::Triangle(float base, float height): base(base), height(height){}

void Triangle::scale(float scaleFactor = 1){
    area *= scaleFactor;
}

string Triangle::getName(){
    return "� ��㣮�쭨�!";
}

void Triangle::showInfo(){
    cout << getName();
    calculateArea();
    cout << endl;
    cout << "\t��� ���頤� = " << area << endl;
    cout << "\t����� ����� �᭮����� = " << base << endl;
    cout << "\t��� ���� = " << height << endl;
}

void Triangle::calculateArea(){
    area = 1/2 * base * height;
}