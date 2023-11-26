#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int testTochnost(double E1, double E2, double tochnost){
    if(fabs(E1 - E2) <= tochnost){return 1;}
    else{return 0;}
}

double EkscentrAnomIter(double Ei, double M, double e, double tochnost){
    double EI = Ei;
    Ei = M + e*sin(EI);
    
    if(testTochnost(Ei, EI, tochnost) == 1){return Ei;}
    EkscentrAnomIter(Ei, M, e, tochnost);
}

double EkscentrAnomPolov(double a, double b, double e, double M, double tochnost){
    if(M == 0){return 0;}
    
    double c = (b + a)/2;
    if(((a - e*sin(a) - M)*(c - e*sin(c) - M)) < 0){b = c;}
    else if(((c - e*sin(c) - M)*(b - e*sin(b) - M)) < 0){a = c;}
    else{return c;}
    
    if (testTochnost(a, b, 2*tochnost) == 1){return c;}
    EkscentrAnomPolov(a, b ,e, M, tochnost);
}

double EkscentrAnomGold(double a, double b, double e, double M, double tochnost){
    if(M == 0){return 0;}
    
    double c = a + (b - a)/((pow(5,0.5) + 1)/2);
    if(((a - e*sin(a) - M)*(c - e*sin(c) - M)) < 0){b = c;}
    else if(((c - e*sin(c) - M)*(b - e*sin(b) - M)) < 0){a = c;}
    else{return c;}
    
    if(testTochnost(a, b, 2*tochnost) == 1){return c;}
    EkscentrAnomGold(a, b, e, M, tochnost);
}

double EkscentrAnomNuton(double Ei, double M, double e, double tochnost){
    double EI = Ei;
    Ei = EI - (EI - e*sin(EI) - M)/(1 - e*cos(EI));
    
    if(testTochnost(Ei, EI, tochnost) == 1){return Ei;}
    EkscentrAnomNuton(Ei, M, e, tochnost);
}

int main(){
    cout.precision(32);
    double E, e, aa, ra, rp, M, tochnost;
    cout << "Введите M, радиус апогея, радиус перегея (радиусы с учётом радиуса планеты), точность (пример: 0.0001)" << endl;
    cin >> M >> ra >> rp >> tochnost;
    M = fmod(M, 2*M_PI);
    aa = (ra + rp)/2;
    e = (ra-rp)/(ra+rp);
    cout << "Большая полуось: " << aa << endl;
    cout << "Эксцентриситет: " << e << endl;
    cout << "Метод Итерации: " << EkscentrAnomIter(M, M, e, tochnost) << endl;
    cout << "Метод Половинного деления: " << EkscentrAnomPolov(0, 2*M_PI, e, M, tochnost) << endl;
    cout << "Метод Золотого сечения: " << EkscentrAnomGold(0, 2*M_PI, e, M, tochnost) << endl;
    cout << "Метод Ньютона: " << EkscentrAnomNuton(M, M, e, tochnost) << endl;
}