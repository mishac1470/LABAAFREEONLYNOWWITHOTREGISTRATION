#include <vector>

#include "bus.h"

using namespace std;

int main(){

    Cylinder cr(2, 3);
    Circle ci(2);

    vector<Shape*> vec{&cr, &ci};

    vec[0]->showInfo();
    vec[1]->showInfo();

    return 0;
}