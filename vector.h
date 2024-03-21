#ifndef VECTOR_H
#define VECTOR_H

#include "matrix.h"

template<class T>
class Vector : public Matrix<T>{
public:
    Vector(int column): Matrix<T>(1, column){}
    Vector(const Vector<T>& vec): Matrix<T>(vec){}
    ~Vector(){}

    T operator*(const Vector<T>& vec){
        this->CheckSize(vec);
        T temp = 0;
        for(int i = 0; i < this->line; ++i){
            for(int j = 0; j < this->column; ++j){
                // cout << data[i][j] << " " << vec[i][j];
                temp += this->data[i][j] * vec[i][j];
            }
        }
        return temp;
    }
};

#endif