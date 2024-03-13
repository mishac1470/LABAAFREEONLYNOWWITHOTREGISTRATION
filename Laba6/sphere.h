#ifndef SPHERE_H
#define SPHERE_H

#include <math.h>
#include "shape3d.h"

class Sphere : public Shape3D{
    private:
        float radius;
        void calculateVolume() override;
        std::string getName() override;
    
    public:
        Sphere(float radiusc);
        void scale(float scaleFactor) override;
        void showInfo() override;
};

#endif