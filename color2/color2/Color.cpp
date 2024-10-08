//
//  Color.cpp
//  color2
//
//  Created by Delaney Farrell on 4/1/19.
//  Copyright © 2019 Delaney Farrell. All rights reserved.
//

/*******************************************************************************
 * Color.cpp                                                                    *
 *******************************************************************************/
#include "Color.h"
using namespace std;

ostream& operator<<(ostream& os, Color const & c) {
    os << c.get_R() << ',' << c.get_G() << ',' << c.get_B();
    return os;
}

Color::Color() {
    R = 255;
    G = 255;
    B = 255;
}

Color::Color(int r, int g, int b) {
    R = r;
    G = g;
    B = b;
}
