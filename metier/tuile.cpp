#include "tuile.h"

Tuile::Tuile(){

}

void Tuile::setRectangle(int l,int h,int x,int y){
    _rectangle.w = l;
    _rectangle.h = h;
    _rectangle.x = x;
    _rectangle.y = y;
}

void Tuile::setType(TypeTuile type){
    _type = type;
}

SDL_Rect& Tuile::getRectangle(){
    return _rectangle;
}

TypeTuile Tuile::getType()const{
    return  _type;
}
