//
//  circle.hpp
//  作业2
//
//  Created by Ice Bear on 2021/3/27.
//  Copyright © 2021 Mushroom. All rights reserved.
//

#ifndef circle_hpp
#define circle_hpp

class Circle{
private:
    Point center;
    double radius;
public:
    Circle():radius(1){cout<<"默认构造了一个圆心为（0，0），半径为1的圆"<<endl;}
    Circle(double a, double b, double c):center(a,b),radius(c){
        cout<<"你构造了一个圆心为（"<<a<<"，"<<b<<"），半径为"<<c<<"的圆"<<endl;
    }
    Circle(Circle &c):center(c.center),radius(c.radius){
        cout<<"拷贝构造圆"<<endl;
    }
    ~Circle(){cout<<"圆析构"<<endl;}
    Point get_center(){return center;}
    double get_radius(){return radius;}
    bool xiangjiao(Circle a, Circle b);
};

bool Circle::xiangjiao(Circle a, Circle b){
    //两次圆拷贝对应两次圆点析构
    Point centera(a.center), centerb(b.center);
    //两次点拷贝对应两次点析构
    double r1 = a.radius,r2 = b.radius;
    double dis = centera.get_dis(centera, centerb);
    //两次点拷贝对应两次点析构
    if(dis>r1+r2) return false;
    else return true;
}

#endif /* circle_hpp */
