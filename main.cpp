#include <iostream>
#include "Rectangle.h"
#include "Join.h"
#include "LayoutException.h"
#include "PatchWork.h"

int main() {

    int res = 0;
    Rectangle r1(3,5);
    Rectangle r2(3,3);
    Rectangle r3=r2;
    Rectangle r4(5,7);

    Join j1(r1,r2,Join::TOP, 0);

    if(j1.getTrIndent() != 0) { std::cout <<"j1 indent wrong!" <<std::endl; res = -1;}

    if(j1.getSharedEdgeLen() != 3) { std::cout <<"j1 sh len wrong!" <<std::endl; res = -1;}

    Join j3(r1,r4,Join::TOP,0);

    if(j3.getTrIndent() != -2) { std::cout <<"j3 getTrIndent wrong!" << " " << j3.getTrIndent() <<std::endl; res = -1;}

    Join j2(r3, r1, Join::RIGHT, 0);

    if(j2.getTrIndent() != -2) { std::cout <<"j2 indent wrong!" << j2.getTrIndent() << std::endl; res = -1;}

    Join j4(r4,r1, Join::TOP, 1);
    if(j4.getTrIndent() != 1) { std::cout <<"j4 indent wrong!" << j4.getTrIndent() << std::endl; res = -1;}
    if(j4.getSharedEdgeLen() != 3) { std::cout <<"j4 sh len wrong!"<< " "<< j4.getSharedEdgeLen() <<std::endl; res = -1;}

    Join j5(r4,r1, Join::TOP, -2);
    if(j5.getTrIndent() != 4) { std::cout <<"j5 indent wrong!" << j5.getTrIndent() << std::endl; res = -1;}
    if(j5.getSharedEdgeLen() != 1) { std::cout <<"j5 sh len wrong!"<< " "<< j5.getSharedEdgeLen() <<std::endl; res = -1;}

    Join j6(r4,r1, Join::RIGHT, 2);
    if(j6.getTrIndent() != 0) { std::cout <<"j6 indent wrong!" << j6.getTrIndent() << std::endl; res = -1;}
    if(j6.getSharedEdgeLen() != 5) { std::cout <<"j6 sh len wrong!"<< " "<< j6.getSharedEdgeLen() <<std::endl; res = -1;}

    bool didThrow = false;
    try {

        Join j7(r4, r1, Join::RIGHT, -5);
        if (j7.getTrIndent() != 7) {
            std::cout << "j7 indent wrong!" << j7.getTrIndent() << std::endl;
            res = -1;
        }
        if (j7.getSharedEdgeLen() != 0) {
            std::cout << "j7 sh len wrong!" << " " << j7.getSharedEdgeLen() << std::endl;
            res = -1;
        }

        Join j8(r4, r1, Join::RIGHT, -6);
        if (j8.getTrIndent() != 8) {
            std::cout << "j8 indent wrong!" << j8.getTrIndent() << std::endl;
            res = -1;
        }
        if (j8.getSharedEdgeLen() != -1) {
            std::cout << "j8 sh len wrong!" << " " << j8.getSharedEdgeLen() << std::endl;
            res = -1;
        }

    } catch (LayoutException x)
    {
        didThrow = true;
    }
    if(!didThrow) {std::cout<< "didn't throw" <<std::endl; res=-1; }

    PatchWork::RectangleSetPtr recs1 = PatchWork::RectangleSetPtr(new PatchWork::RectangleSet());
    recs1->push_back(r1);  recs1->push_back(r2);
    PatchWork::JoinSetPtr joins1 = PatchWork::JoinSetPtr(new PatchWork::JoinSet());
    joins1->push_back(j1);

    PatchWork pw1(recs1, joins1);

    if(pw1.rectangleCount() != 2){std::cout<<"pw1 wrong rec coint!" <<" "<< pw1.rectangleCount() <<std::endl; res=-1;}
    if(pw1.joinCount() != 1){std::cout<<"pw1 wrong join coint!" <<" "<< pw1.joinCount() <<std::endl; res=-1;}

    std::cout << "Hello, World!" << std::endl;
    return res;
}