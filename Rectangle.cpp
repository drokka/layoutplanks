//
// Created by peter on 5/11/18.
//

#include <bits/exception.h>
#include <regex>
#include "Rectangle.h"

Rectangle::Rectangle(int width, int length) : width(width), length(length) {
    if(width <= 0 || length <= 0) {
        throw  (0);
    }
}


