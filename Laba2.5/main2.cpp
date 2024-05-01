#include <iostream>
#include <fstream>
#include <time.h>
#include "matrix.h"

using namespace std;

int main(){
    // Запись Matrix
    srand(time(NULL));
    int inp1;

    Matrix<int> m1(2, 2);
    m1.fill();
    Matrix<int> m2(3, 3);
    m2.fill();

    Matrix<int> mt1(2, 2);
    Matrix<int> mt2(3, 3);

    Matrix<int> mb1(2, 2);
    Matrix<int> mb2(3, 3);

    ofstream out("matr.txt");
    if(out.is_open()){
        out << m1 << m2;
    }
    out.close();

    ifstream in3("matr.txt");
    if(in3.is_open()){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                in3 >> inp1;
                mt1[i][j] = inp1;
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                in3 >> inp1;
                mt2[i][j] = inp1;
            }
        }
    }
    cout << mt1 << mt2;
    in3.close();

    ofstream out1("matr.bin", ios::binary | ios::out);
    if(out1.is_open()){
        out1.write((char*)&m1, sizeof(m1));
        out1.write((char*)&m2, sizeof(m2));
    }
    out1.close();

    ifstream in4("matr.bin", ios::binary | ios::in);
    if(in4.is_open()){
        in4.read((char*)&mb1, sizeof(m1));
        in4.read((char*)&mb2, sizeof(m2));
    }
    cout << mb1 << mb2;
    in4.close();

    return 0;
}