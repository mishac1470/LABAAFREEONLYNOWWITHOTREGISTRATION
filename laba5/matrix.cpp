#include "matrix.h"

using namespace std;

void Matrix::CheckSize(const Matrix& mat){
    if(line != mat.getLine() || column != mat.getColumn()){
        cout << "Матрицы разного размера";
        exit(EXIT_FAILURE);
    }
}

void Matrix::CheckMultiplication(const Matrix& mat){
    if(column != mat.getLine()){
        cout << "Матрицы нельзя умножить";
        exit(EXIT_FAILURE);
    }
}

Matrix::Matrix(int line, int column): line(line), column(column){
    data = new int*[line];
    for(int j = 0; j < line; ++j){
        data[j] = new int[column];
    }
}
Matrix::Matrix(const Matrix& mat){
    line = mat.getLine();
    column = mat.getColumn();
    data = new int*[line];
    for(int j = 0; j < line; ++j){
        data[j] = new int[column];
    }
    for(int j = 0; j < line; ++j){
        for(int i = 0; i < column; ++i){
            data[j][i] = mat[j][i];
        }
    }
}
Matrix::~Matrix(){
    for(int j = 0; j < line; ++j){
        delete[] data[j];
    }
    delete[] data;
}

void Matrix::fill(){
    for(int j = 0; j < line; ++j){
        for(int i = 0; i < column; ++i){
            data[j][i] = rand()%10;
        }
    }
}

int Matrix::getLine()const{return line;}
int Matrix::getColumn()const{return column;}

int* Matrix::operator[](int i)const{return data[i];}

Matrix& Matrix::operator+=(const Matrix& mat){
    CheckSize(mat);
    for(int j = 0; j < line; ++j){
        for(int i = 0; i < column; ++i){
            data[j][i] += mat[j][i];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& mat){
    CheckSize(mat);
    for(int j = 0; j < line; ++j){
        for(int i = 0; i < column; ++i){
            data[j][i] -= mat[j][i];
        }
    }
    return *this;
}
    
Matrix Matrix::operator+(const Matrix& mat){
    CheckSize(mat);
    Matrix temp = *this;
    temp += mat;
    return temp;
}

Matrix Matrix::operator-(const Matrix& mat){
    CheckSize(mat);
    Matrix temp = *this;
    temp -= mat;
    return temp;
}

Matrix Matrix::operator*(const Matrix& mat){
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

void Matrix::operator=(const Matrix& mat){
    this->~Matrix();
    line = mat.getLine();
    column = mat.getColumn();
    data = new int*[line];
    for(int j = 0; j < line; ++j){
        data[j] = new int[column];
    }
    for(int j = 0; j < line; ++j){
        for(int i = 0; i < column; ++i){
            data[j][i] = mat[j][i];
        }
    }
}

bool Matrix::operator==(const Matrix& mat){
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

bool Matrix::operator!=(const Matrix& mat){
    if(*this == mat){return false;}
    else{return true;}
}

ostream& operator<<(ostream& os, const Matrix& mat){
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
    for(int i = 0; i < mat.line; ++i){
        for(int j = 0; j < mat.column; ++j){
            s = to_string(mat[i][j]);
            os << string(maxlen - s.length(), ' ') << mat[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}