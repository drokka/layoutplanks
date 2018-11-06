//
// Created by peter on 5/11/18.
//

#ifndef LAYOUTPLANKS_RECTANGLE_H
#define LAYOUTPLANKS_RECTANGLE_H


class Rectangle {
    // use millimetres
    int area;
public:
    int getArea() const {
        return width*length;
    }

    Rectangle(int width, int length);

public:
    int width; // x direction... sideways
    int length; // y direction... up/down

};


#endif //LAYOUTPLANKS_RECTANGLE_H
