//
//  color.h
//  color
//
//  Created by Delaney Farrell on 3/20/19.
//

#ifndef COLOR_H
#define COLOR_H

class Color {
    int red;
    int green;
    int blue;
    
public:
    Color (int red, int green, int blue): red(red), green(green), blue(blue) {}
    Color () : red(80), green(0), blue(0) {}
    int getRed();
    void setRed(int red);
    int getBlue();
    void setBlue(int blue);
    int getGreen();
    void setGreen(int green);
};

#endif 
