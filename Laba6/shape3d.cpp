#include "shape3d.h"

float Shape3D::getVolume(){return volume;}

bool Shape3D::operator>(Shape3D& sh){return volume > sh.getVolume();}
bool Shape3D::operator<(Shape3D& sh){return volume < sh.getVolume();}
bool Shape3D::operator==(Shape3D& sh){return volume == sh.getVolume();}