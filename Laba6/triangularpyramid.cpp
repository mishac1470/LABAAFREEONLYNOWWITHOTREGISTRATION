#include "triangularpyramid.h"

using namespace std;

TriangularPyramid::TriangularPyramid(float baset, float heightt, float height): tr(baset, heightt), height(height){}

void TriangularPyramid::scale(float scaleFactor = 1){
    volume *= scaleFactor;
}

string TriangularPyramid::getName(){
    return "Я пирамида!";
}

void TriangularPyramid::showInfo(){
    cout << getName();
    calculateVolume();
    cout << endl;
    cout << "\tМой объём = " << volume << endl;
    cout << "\tДлина моего основания = " << tr.base << endl;
    cout << "\tВысота моего основания = " << tr.height << endl;
    cout << "\tМоя высота = " << height << endl;
}

void TriangularPyramid::calculateVolume(){
    volume = 1/3 * tr.base * tr.height * height;
}