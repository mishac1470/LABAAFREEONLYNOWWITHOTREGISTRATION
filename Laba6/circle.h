#ifndef CIRCLE_H
#define CIRCLE_H

#include <math.h>
#include "shape2d.h"

class Circle : public Shape2D{
    private:
        float radius;
        void calculateArea() override;
        std::string getName() override;
    
    public:
        Circle(float radius);
        void scale(float scaleFactor) override;
        void showInfo() override;

        friend class Cylinder;
};

#endif