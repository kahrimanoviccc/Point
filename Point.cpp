#include "Point.hpp"
#include <stdexcept>
#include <math.h>


Point::Point(){
x_=0.0;
y_=0.0;
}

Point::Point(double x, double y){
x_= x;
y_= y;
}

Point::Point(const Point& point){
x_=point.x_;
y_=point.y_;
}

Point::Point(Point&& point) : x_{point.x_},y_{point.y_}{
point.x_=0.0;
point.y_=0.0;
}


double Point::x() const{
return x_;
}

double Point::y() const{
return y_;
}

Point& Point::operator=(const Point& point){
x_=point.x_;
y_=point.y_;
return *this;
}

Point& Point::operator=(Point&& point){
x_=point.x_;
y_=point.y_;
point.x_=0.0;
point.y_=0.0;
return *this;
}

Point Point::operator+(const Point& point) const{
return Point(x_+point.x_, y_+point.y_);
}

Point Point::operator-(const Point& point) const{
return Point(x_-point.x_, y_-point.y_);
}

Point Point::operator*(double scalar) const{
return Point(x_*scalar, y_*scalar);
}

Point Point::operator/(double scalar) const{
if(scalar== 0.0) throw std::invalid_argument{"Djeljenje s nulom"};
return Point(x_/scalar, y_/scalar);
}

Point& Point::operator+=(const Point& point){
x_=x_+point.x_;
y_=y_+point.y_;
return *this;
}

Point& Point::operator-=(const Point& point){
x_=x_-point.x_;
y_=y_-point.y_;
return *this;
}

Point& Point::operator*=(double scalar){
x_= x_*scalar;
y_= y_*scalar;
return *this;
}

Point& Point::operator/=(double scalar){
if(scalar == 0.0) throw std::invalid_argument{"Djeljenje s nulom nije moguce!"};
x_= x_/scalar;
y_= y_/scalar;
return *this;
}

bool Point::operator==(const Point& point) const{
if (((x_== point.x_) && (y_ == point.y_)) == true){
return true;
}else return false;
}

bool Point::operator!=(const Point& point) const{
if (((x_== point.x_) && (y_ == point.y_)) == false){
return true;
}else return false;
}

void Point::setX(double x){
x_ = x;
}

void Point::setY(double y){
y_ = y;
}

double Point::distance(const Point& point) const{
 return sqrt(pow((point.x_ - x_),2) + pow((point.y_ - y_),2));
}
std::ostream& operator<<(std::ostream& os, const Point& point){
os<<"Point(x="<<point.x()<< ", y="<<point.y()<<")\n";
return os;
}

std::istream& operator>>(std::istream& is, Point& point){
double x,y;
//point.setX(is>>x);
//point.setY(is>>y);
return is;
}
