#include "shape2d.h"

float Shape2D::getArea(){return area;}

bool Shape2D::operator>(Shape2D& sh){return area > sh.getArea();}
bool Shape2D::operator<(Shape2D& sh){return area < sh.getArea();}
bool Shape2D::operator==(Shape2D& sh){return area == sh.getArea();}