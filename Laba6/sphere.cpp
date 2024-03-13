#include "sphere.h"

using namespace std;

Sphere::Sphere(float radius): radius(radius){}

void Sphere::scale(float scaleFactor = 1){
    volume *= scaleFactor;
}

string Sphere::getName(){
    return "� ���!";
}

void Sphere::showInfo(){
    cout << getName();
    calculateVolume();
    cout << endl;
    cout << "\t��� ���� = " << volume << endl;
    cout << "\t��� ࠤ��� = " << radius << endl;
}

void Sphere::calculateVolume(){
    volume = 4/3 * M_PI * radius * radius * radius;
}