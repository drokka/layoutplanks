//
// Created by peter on 5/11/18.
//
#include <cmath>
#include "Join.h"
#include "LayoutException.h"

int Join::getTrIndent() const {

    return trIndent;
}

int Join::getSharedEdgeLen() const {
    return sharedEdgeLen;
}

Join::Join(const Rectangle &rectangleBottomLeft, const Rectangle &rectangleTopRight, Join::JoinType joinType,
           int blIndent) : rectangleBottomLeft(rectangleBottomLeft), rectangleTopRight(rectangleTopRight),
                           joinType(joinType), blIndent(blIndent) {

    switch(joinType) {
        case TOP :
          //  if(abs( blIndent ) >= rectangleTopRight.width){LayoutException x ; x.setMsg("No overlap!"); throw (x);}
            trIndent = (-rectangleTopRight.width - blIndent + rectangleBottomLeft.width);
            if(blIndent < 0 && trIndent >=0){ sharedEdgeLen = rectangleBottomLeft.width - trIndent;}
            else if(blIndent<0 && trIndent <0) {sharedEdgeLen = rectangleBottomLeft.width;}
            else if(blIndent >= 0 && trIndent >= 0) {sharedEdgeLen = rectangleTopRight.width;}
            else if(blIndent >= 0 && trIndent <0) {sharedEdgeLen = rectangleBottomLeft.width - blIndent;}
            break;
        case RIGHT:
          //  if(abs( blIndent ) >= rectangleBottomLeft.length){LayoutException x ; x.setMsg("No overlap!"); throw (x);}
            trIndent = (-rectangleTopRight.length - blIndent + rectangleBottomLeft.length);
            if(blIndent < 0 && trIndent >=0){ sharedEdgeLen = rectangleBottomLeft.length - trIndent;}
            else if(blIndent<0 && trIndent <0) {sharedEdgeLen = rectangleBottomLeft.length;}
            else if(blIndent >= 0 && trIndent >= 0) {sharedEdgeLen = rectangleTopRight.length;}
            else if(blIndent >= 0 && trIndent <0) {sharedEdgeLen = rectangleBottomLeft.length - blIndent;}

    }

    if(sharedEdgeLen <=0) {LayoutException xx;xx.setMsg("No overlap!!"); throw (xx);}

}
