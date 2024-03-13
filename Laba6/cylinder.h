#ifndef CYLINDER_H
#define CYLINDER_H

#include <math.h>
#include "shape3d.h"
#include "circle.h"

class Cylinder : public Shape3D{
    private:
        float height;
        void calculateVolume() override;
        std::string getName() override;
        Circle cr;
    
    public:
        Cylinder(float radiusc, float height);
        void scale(float scaleFactor) override;
        void showInfo() override;
};

#endif