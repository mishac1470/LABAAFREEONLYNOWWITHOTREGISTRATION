#ifndef SHAPE2D_H
#define SHAPE2D_H

#include "shape.h"
// #include "square.h"
// #include "triangle.h"
// #include "circle.h"

class Shape2D : public Shape{
    protected:
        float area;
        void virtual calculateArea() = 0;
        
    public:
        float getArea();

        bool operator>(Shape2D& sh);
        bool operator<(Shape2D& sh);
        bool operator==(Shape2D& sh);
};

#endif