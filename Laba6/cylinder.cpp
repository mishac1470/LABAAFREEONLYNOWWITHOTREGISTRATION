#include "cylinder.h"

using namespace std;

Cylinder::Cylinder(float radiusc, float height): cr(radiusc), height(height){}

void Cylinder::scale(float scaleFactor = 1){
    volume *= scaleFactor;
}

string Cylinder::getName(){
    return "Я цилиндр!";
}

void Cylinder::showInfo(){
    cout << getName();
    calculateVolume();
    cout << endl;
    cout << "\tМой объём = " << volume << endl;
    cout << "\tРадиус моего основания = " << cr.radius << endl;
    cout << "\tМоя высота = " << height << endl;
}

void Cylinder::calculateVolume(){
    volume = M_PI * cr.radius * cr.radius * height;
}