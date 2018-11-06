//
// Created by peter on 5/11/18.
//

#include "PatchWork.h"

PatchWork::PatchWork(const std::shared_ptr<std::vector<Rectangle>> &rectangles,
                     const std::shared_ptr<std::vector<Join>> &joins) : rectangles(rectangles), joins(joins) {}

PatchWork::~PatchWork() {

}
