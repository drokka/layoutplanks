//
// Created by peter on 5/11/18.
//

#ifndef LAYOUTPLANKS_JOIN_H
#define LAYOUTPLANKS_JOIN_H


#include "Rectangle.h"

class Join {
public:
    typedef  enum {TOP, RIGHT} JoinType;

    Rectangle rectangleBottomLeft; // Assume plank direction is up/down
    Rectangle rectangleTopRight;   // so above and /or to the right

    JoinType joinType;

    Join(const Rectangle &rectangleBottomLeft, const Rectangle &rectangleTopRight, JoinType joinType, int blIndent);

    int blIndent;

private:
    int trIndent;
public:
    int getTrIndent() const;

    int getSharedEdgeLen() const;

private:
    int sharedEdgeLen;
};


#endif //LAYOUTPLANKS_JOIN_H
