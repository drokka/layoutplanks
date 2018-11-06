//
// Created by peter on 5/11/18.
//

#include "LayoutException.h"

void LayoutException::setMsg(char *msg) {
    LayoutException::msg = msg;
}

char *LayoutException::getMsg() const {
    return msg;
}
