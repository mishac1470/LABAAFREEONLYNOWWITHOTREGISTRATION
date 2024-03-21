#ifndef VECTOR_H
#define VECTOR_H

#include "matrix.h"

template<class T>
class Vector : public Matrix<T>{
public:
    Vector(): Matrix<T>(1, 3){}
    Vector(const Vector<T>& vec): Matrix<T>(vec){}
    ~Vector(){}

    T operator*(const Vector<T>& vec){
        T temp = 0;
        for(int j = 0; j < this->column; ++j){
            temp += this->data[0][j] * vec[j];
        }
        return temp;
    }

    T& operator[](int i)const{return this->data[0][i];}

    Vector<T> operator^(const Vector<T>& vec){
        Vector<T> temp;
        temp[0] = this->data[0][1] * vec[2] - this->data[0][2] * vec[1];
        temp[1] = this->data[0][2] * vec[0] - this->data[0][0] * vec[2];
        temp[2] = this->data[0][0] * vec[1] - this->data[0][1] * vec[0];
        return temp;
    }
};

#endif