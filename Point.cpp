/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

// TODO: implement two constructors, setX, getX, setY, getY, read, write, checkRange.

int Point::checkRange(int val){
    if(val<=0){
        return 0;
    }
    else if(val>=DIMENSION){
        return DIMENSION-1;
    }
    else{
        return val;
    }
}

Point::Point(){
    x=0;
    y=0;
}

Point::Point(int xVal,int yVal){
    x=checkRange(xVal);
    y=checkRange(yVal);
}

void Point::setX(int xVal){
    x=checkRange(xVal);
}
int Point::getX(){
    return x;
}
void Point::setY(int yVal){
    y=checkRange(yVal);
}
int Point::getY(){
    return y;
}
void Point::read(istream& ins){
    char value;
    ins>>value>>x>>value>>y>>value;

    x=checkRange(x);
    y=checkRange(y);

}
void Point::write(ostream& outs){
    outs<<"("<<x<<","<<y<<")";
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
