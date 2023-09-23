#include <iostream>
#include <string>

using namespace std;

/*
1) int *ptr = (int*)malloc(sizeof(int)) - int *ptr = new int
2) int *ptrArr = (int*)malloc(sizeof(int)*N) - int *ptrArr = new int[N]
3) free(ptr) - delete ptr
4) free(ptrArr) - delete[] ptrArr

Динамическую память необходимо освобождать.
Можно освободить выделенную память дважды, но это приведёт к неизвестному поведению программы.
Невыделенную память нельзя освободить.
*/

void fillMasive(int** arr, int height){
    for(int i = 0; i < height; ++i){
        for(int j = 0; j <= i; ++j){
            if(i - 1 > j){
                *(*(arr + i) + j) = *(*(arr + i - 1) + j) + *(*(arr + i - 2) + j);
            }
            else{
                if(j >= 2){
                    *(*(arr + i) + j) = *(*(arr + i - 1) + j - 1) + *(*(arr + i - 2) + j - 2);
                }
                else{
                    *(*(arr + i) + j) = 1;
                }
            }
        }
    }
}

void printMasive(int** arr, int height){
   int elementLen, elLen;
   string lastElement, el;
   lastElement = to_string(*(*(arr + height - 1) + height - 1));
   elementLen = lastElement.length();
    
    for(int i = 0; i < height; ++i){
        cout << string((height - i - 1) * elementLen, ' ');
        for(int j = 0; j <= i; ++j){
            el = to_string(*(*(arr + i) + j));
            elLen = el.length();
            cout << string(elementLen - elLen, ' ') << *(*(arr + i) + j) << string(elementLen, ' ');
        }
        cout << '\n';
    }
}

int main()
{
    int height;
    cin >> height;
    
    int **arr = new int *[height];
    for(int i = 0; i < height; ++i){
        *(arr + i) = new int[i + 1];
    }
    
   fillMasive(arr, height);
   printMasive(arr, height); 
    return 0;
}
