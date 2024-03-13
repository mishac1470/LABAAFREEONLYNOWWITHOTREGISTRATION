#include "triangularpyramid.h"

using namespace std;

TriangularPyramid::TriangularPyramid(float baset, float heightt, float height): tr(baset, heightt), height(height){}

void TriangularPyramid::scale(float scaleFactor = 1){
    volume *= scaleFactor;
}

string TriangularPyramid::getName(){
    return "� ��ࠬ���!";
}

void TriangularPyramid::showInfo(){
    cout << getName();
    calculateVolume();
    cout << endl;
    cout << "\t��� ���� = " << volume << endl;
    cout << "\t����� ����� �᭮����� = " << tr.base << endl;
    cout << "\t���� ����� �᭮����� = " << tr.height << endl;
    cout << "\t��� ���� = " << height << endl;
}

void TriangularPyramid::calculateVolume(){
    volume = 1/3 * tr.base * tr.height * height;
}