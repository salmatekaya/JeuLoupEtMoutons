#include "Position.h"

Position::Position() {}
Position::Position(int x,int y) {
    this -> x = x;
    this -> y = y;
}
int Position::get_x() {
    return x;
}

void Position::set_x(int x){
    this->x = x;
}
int Position::get_y() {
    return y;
}
void Position::set_y(int y){
    this->y = y;
}
