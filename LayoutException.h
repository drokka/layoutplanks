//
// Created by peter on 5/11/18.
//

#ifndef LAYOUTPLANKS_LAYOUTEXCEPTION_H
#define LAYOUTPLANKS_LAYOUTEXCEPTION_H


#include <bits/exception.h>

class LayoutException : std::exception {
    char* msg;
public:
    void setMsg(char *msg);

    char *getMsg() const;
};


#endif //LAYOUTPLANKS_LAYOUTEXCEPTION_H
