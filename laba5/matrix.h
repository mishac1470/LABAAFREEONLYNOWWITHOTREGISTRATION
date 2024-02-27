#pragma once

#include <iostream>

class Matrix{ 
private:
    int** data;
    int line, column;

    void CheckSize(const Matrix& mat);
    void CheckMultiplication(const Matrix& mat);

public:
    Matrix(int line, int column);
    Matrix(const Matrix& mat);
    ~Matrix();

    void fill();

    int getLine()const;
    int getColumn()const;

    int* operator[](int i)const;

    Matrix& operator+=(const Matrix& mat);

    Matrix& operator-=(const Matrix& mat);
     
    Matrix operator+(const Matrix& mat);

    Matrix operator-(const Matrix& mat);

    Matrix operator*(const Matrix& mat);

    void operator=(const Matrix& mat);

    bool operator==(const Matrix& mat);

    bool operator!=(const Matrix& mat);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
};