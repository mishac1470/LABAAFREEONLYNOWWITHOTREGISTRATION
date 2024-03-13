#include "cylinder.h"

using namespace std;

Cylinder::Cylinder(float radiusc, float height): cr(radiusc), height(height){}

void Cylinder::scale(float scaleFactor = 1){
    volume *= scaleFactor;
}

string Cylinder::getName(){
    return "� 樫����!";
}

void Cylinder::showInfo(){
    cout << getName();
    calculateVolume();
    cout << endl;
    cout << "\t��� ���� = " << volume << endl;
    cout << "\t������ ����� �᭮����� = " << cr.radius << endl;
    cout << "\t��� ���� = " << height << endl;
}

void Cylinder::calculateVolume(){
    volume = M_PI * cr.radius * cr.radius * height;
}