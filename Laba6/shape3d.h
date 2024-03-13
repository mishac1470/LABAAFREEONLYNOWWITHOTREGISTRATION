#ifndef SHAPE3D_H
#define SHAPE3D_H

#include "shape.h"
// #include "triangularpyramid.h"
// #include "cylinder.h"
// #include "sphere.h"

class Shape3D : public Shape{
    protected:
        float volume;
        void virtual calculateVolume() = 0;
        
    public:
        float getVolume();

        bool operator>(Shape3D& sh);
        bool operator<(Shape3D& sh);
        bool operator==(Shape3D& sh);
};

#endif