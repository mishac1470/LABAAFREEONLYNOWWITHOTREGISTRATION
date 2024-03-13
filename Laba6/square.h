#ifndef SQUARE_H
#define SQUARE_H

#include "shape2d.h"

class Square : public Shape2D{
    private:
        float side;
        void calculateArea() override;
        std::string getName() override;
    
    public:
        Square(float side);
        void scale(float scaleFactor) override;
        void showInfo() override;

};

#endif