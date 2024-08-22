//
//  color.cpp
//  color
//


#include "color.h"
#include <iostream>

using namespace std;

int Color::getRed() {
    return red;
}

void Color::setRed(int r) {
    red = r;
}

int Color::getBlue() {
    return blue;
}

void Color::setBlue(int b) {
    blue = b;
}

int Color::getGreen() {
    return green;
}

void Color::setGreen(int g) {
    green = g;
}

/*
 Color& Color::operator=(const Color& other){
 // TODO: implement =
 return *this;
 }
 
 Color& Color::operator+=(const Color& rhs) {
 // TODO: implement +=
 return *this;
 }
 
 Color operator+(const Color& lhs, const Color& rhs) {
 // TODO: implement +
 Color c;
 return c;
 }
 
 bool operator==(const Color& lhs, const Color& rhs) {
 // TODO: implement ==
 return false;
 }
 
 bool operator!=(const Color& lhs, const Color& rhs) {
 // TODO: implement !=
 return false;
 }
 
 bool operator<(const Color& lhs, const Color& rhs) {
 // TODO: implement <
 return false;
 }
 
 bool operator>(const Color& lhs, const Color& rhs) {
 // TODO: implement >
 return false;
 }
 
 bool operator<=(const Color& lhs, const Color& rhs) {
 // TODO: implement <=
 return false;
 }
 
 bool operator>=(const Color& lhs, const Color& rhs) {
 // TODO: implement >=
 return false;
 }
 
 std::ostream& operator<<(std::ostream& os, const Color& c) {
 // TODO: implement <<
 return os;
 }
*/
