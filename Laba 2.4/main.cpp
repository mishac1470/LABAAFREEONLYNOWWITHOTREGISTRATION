#include <time.h>
#include "matrix.h"
#include "vector.h"

using namespace std;

template<typename T>
int findSecond(T* first, int size){
    int n = -1;

    T first_max = *first, second_max;
    for(int i = 1; i < size; ++i){
        if(*(first + i) > first_max){
            n = i - 1;
            second_max = first_max;
            first_max = *(first + i);
        }
        else if((*(first + i) > second_max) && (*(first + i) < first_max)){
            n = i;
            second_max = *(first + i);
        }
    }
    return n;
}

int main(){

    srand(time(NULL));

    // int arri[3]{1, 3, 3};
    // float arrf[3]{3., 2., 3.};
    // double arrd[3]{3., 2., 1.};
    // char arrc[3]{'a', 'b', 'c'};

    // cout << findSecond(arri, 3) << endl;
    // cout << findSecond(arrf, 3) << endl;
    // cout << findSecond(arrd, 3) << endl;
    // cout << findSecond(arrc, 3) << endl;

    // Matrix<double> ch(4, 4);
    // ch.fill();
    // cout << ch;

    Vector<char> vc1;
    Vector<char> vc2;

    vc1.fill();
    vc2.fill();

    cout << vc1;
    cout << vc2;

    cout << vc1 * vc2 << endl;;
    cout << (vc1 ^ vc2);

    return 0;
}