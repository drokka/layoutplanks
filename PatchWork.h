//
// Created by peter on 5/11/18.
//

#ifndef LAYOUTPLANKS_PATCHWORK_H
#define LAYOUTPLANKS_PATCHWORK_H

#include <set>
#include <memory>
#include <bits/shared_ptr.h>
#include <vector>

#include "Rectangle.h"
#include "Join.h"

class PatchWork {
public:
    typedef std::vector<Rectangle> RectangleSet;
    typedef  std::shared_ptr<RectangleSet> RectangleSetPtr;
    typedef std::vector<Join> JoinSet;
    typedef  std::shared_ptr<JoinSet> JoinSetPtr;

    RectangleSetPtr rectangles;
    JoinSetPtr joins;

    virtual ~PatchWork();

    PatchWork(const std::shared_ptr<std::vector<Rectangle>> &rectangles, const std::shared_ptr<std::vector<Join>> &joins);

    int rectangleCount(){ return rectangles->size();}
    int joinCount() { return  joins->size();}


};


#endif //LAYOUTPLANKS_PATCHWORK_H
