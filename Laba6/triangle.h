#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape2d.h"

class Triangle : public Shape2D{
    private:
        float base, height;
        void calculateArea() override;
        std::string getName() override;
    
    public:
        Triangle(float base, float height);
        void scale(float scaleFactor) override;
        void showInfo() override;

        friend class TriangularPyramid;
};

#endif