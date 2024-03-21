#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>

using namespace std;

template<class T>
class Matrix{
protected:
    T** data;
    int line, column;

    void CheckSize(const Matrix<T>& mat){
        if(line != mat.getLine() || column != mat.getColumn()){
            cout << "Матрицы разного размера";
            exit(EXIT_FAILURE);
        }
    }

    void CheckMultiplication(const Matrix<T>& mat){
        if(column != mat.getLine()){
            cout << "Матрицы нельзя умножить";
            exit(EXIT_FAILURE);
        }
    }

public:
    Matrix(int line, int column): line(line), column(column){
        data = new T*[line];
        for(int j = 0; j < line; ++j){
            data[j] = new T[column];
        }
    }

    Matrix(const Matrix<T>& mat){
        line = mat.getLine();
        column = mat.getColumn();
        data = new T*[line];
        for(int j = 0; j < line; ++j){
            data[j] = new T[column];
        }
        for(int j = 0; j < line; ++j){
            for(int i = 0; i < column; ++i){
                data[j][i] = mat[j][i];
            }
        }
    }

    ~Matrix(){
        for(int j = 0; j < line; ++j){
            delete[] data[j];
        }
        delete[] data;
    }

    void fill(){
        for(int j = 0; j < line; ++j){
            for(int i = 0; i < column; ++i){
                int r = rand();
                int rcopy = r;
                int colv = 0;
                for (int i = 0; rcopy != 0; ++i){
                    rcopy /= 10;
                    colv += 1;
                }
                data[j][i] = rand()%10 + 33 + (double)r/pow(10, colv);
            }
        }
    }

    int getLine()const{return line;}

    int getColumn()const{return column;}

    T* operator[](int i)const{return data[i];}

    Matrix<T>& operator+=(const Matrix<T>& mat){
        CheckSize(mat);
        for(int j = 0; j < line; ++j){
            for(int i = 0; i < column; ++i){
                data[j][i] += mat[j][i];
            }
        }
        return *this;
    }

    Matrix<T>& operator-=(const Matrix<T>& mat){
        CheckSize(mat);
        for(int j = 0; j < line; ++j){
            for(int i = 0; i < column; ++i){
                data[j][i] -= mat[j][i];
            }
        }
        return *this;
    }

    Matrix<T> operator+(const Matrix<T>& mat){
        CheckSize(mat);
        Matrix temp = *this;
        temp += mat;
        return temp;
    }

    Matrix<T> operator-(const Matrix<T>& mat){
        CheckSize(mat);
        Matrix temp = *this;
        temp -= mat;
        return temp;
    }

    Matrix<T> operator*(const Matrix<T>& mat){
        CheckMultiplication(mat);
        Matrix temp(line, mat.getColumn());
        for(int j = 0; j < line; ++j){
            for(int i = 0; i < mat.getColumn(); ++i){
                temp[j][i] = 0;
            }
        }
        for(int i = 0; i < line; ++i){
            for(int j = 0; j < mat.getColumn(); ++j){
                for(int k = 0; k < column; ++k){
                    temp[i][j] += data[i][k] * mat[k][j];
                }
            }
        }
        return temp;
    }

    void operator=(const Matrix<T>& mat){
        this->~Matrix();
        line = mat.getLine();
        column = mat.getColumn();
        data = new T*[line];
        for(int j = 0; j < line; ++j){
            data[j] = new T[column];
        }
        for(int j = 0; j < line; ++j){
            for(int i = 0; i < column; ++i){
                data[j][i] = mat[j][i];
            }
        }
    }

    bool operator==(const Matrix<T>& mat){
        if(line == mat.getLine() && column == mat.getColumn()){
            for(int j = 0; j < line; ++j){
                for(int i = 0; i < mat.getColumn(); ++i){
                    if(data[j][i] != mat[j][i]){return false;}
                }
            }
            return true;
        }
        else{return false;}
    }

    bool operator!=(const Matrix<T>& mat){
        if(*this == mat){return false;}
        else{return true;}
    }

    template<class Y>
    friend ostream& operator<<(ostream& os, const Matrix<Y>& mat);
};

template<class Y>
ostream& operator<<(ostream& os, const Matrix<Y>& mat){
    int maxlen = 0;
    string s;

    for(int i = 0; i < mat.line; ++i){
        for(int j = 0; j < mat.column; ++j){
            s = to_string(mat[i][j]);
            if(s.length() > maxlen){
                maxlen = s.length();
            }
        }
    }
    os.setf(ios::fixed, ios::floatfield);
    for(int i = 0; i < mat.line; ++i){
        for(int j = 0; j < mat.column; ++j){
            os << mat[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

#endif