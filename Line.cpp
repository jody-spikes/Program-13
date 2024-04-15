//
//  Line.cpp
//  Program 13 (line Class)
//
//  Created by Jody Spikes on 4/12/24.
//

#include "Line.h"

Line::Line(Point a, Point b){
    p1 = a;
    p2 = b;
}

void Line::setFirstPoint(const Point& p){
    p1 = p;
}
void Line::setSecondPoint(const Point& p){
    p2 = p;
}

Point Line::getFirstPoint() const{
    return p1;
}
Point Line::getSecondPoint() const{
    return p2;
}


bool Line::hasSlope() const{
    return p1.x != p2.x;
}

double Line::slope() const{
    return (p1.y - p2.y)/(p1.x - p2.x);
}

double Line::yIntercept() const{
    return p1.y - slope() *p1.x;
}


bool Line::isParallel(const Line& other) const{
    bool flag = false;
    if(hasSlope() && other.hasSlope()){
        if(slope() == other.slope()){
            if(yIntercept() != other.yIntercept()){
                flag = true;
            }
        }
    }
    else if(!hasSlope() and !other.hasSlope()){
        if(p1.x != other.p1.x){
            flag = true;
        }
    }
    return flag;
}
