#include "sphere.h"

using namespace std;

Sphere::Sphere(float radius): radius(radius){}

void Sphere::scale(float scaleFactor = 1){
    volume *= scaleFactor;
}

string Sphere::getName(){
    return "Я сфера!";
}

void Sphere::showInfo(){
    cout << getName();
    calculateVolume();
    cout << endl;
    cout << "\tМой объём = " << volume << endl;
    cout << "\tМой радиус = " << radius << endl;
}

void Sphere::calculateVolume(){
    volume = 4/3 * M_PI * radius * radius * radius;
}