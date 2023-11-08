/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * Contains functions for testing classes in the project.
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Point();
                      // call other test functions here
    test_Circle();
    test_Color();
    test_Line();
    test_Rectangle();
    test_Triangle();



    return;
}

void test_Point() {
    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;

    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member functions: setX(), setY(),getX() and getY()
    p1.setX(5);
    p1.setY(3);
    cout<<"Expected : (5,3), actual (" <<p1.getX() << ","<< p1.getY() << ")" <<endl;

    return;
}
void test_Color(){
    //test of default constructor
    Color c1;
    cout<<"Expected: 0,0,0 : actual: "<<c1<<endl;

    //test of non-default constructor
    Color c2(100,250,150);
    cout<<"Expected 100,250,150 : actual: "<<c2<<endl;

    //test of member functions: setRed(),setGreen(),setBlue(),getRed(),getGreen() and getBlue()
    c1.setRed(120);
    c1.setGreen(200);
    c1.setBlue(250);

    cout<<"test setters and getters in Color class"<<endl;
    cout<<"Expected: 120,200,250 : actual: "<<c1.getRed()<<","<<c1.getGreen()<<","<<c1.getBlue()<<endl;

    //test of member functions with fault values
    //test of member functions: setRed(),setGreen(),setBlue(),getRed(),getGreen() and getBlue()
    c1.setRed(-20);
    c1.setGreen(500);
    c1.setBlue(120);

    cout<<"test setters and getters in Color class"<<endl;
    cout<<"Expected: 0,255,120 : actual: "<<c1.getRed()<<","<<c1.getGreen()<<","<<c1.getBlue()<<endl;

    Color c3(100,150,200);
return;
}

void test_Line(){

        //test line default constructor
        Line l1;
        l1.write(cout);
        cout << endl;

        //test line non defualt constructer
        Point p1(0,0);
        Point p2(50,50);
        Point p3(70,80);
        Color c2(100,150,200);
        Line l2(p1, p2, c2);  //c2 p1 and p2 is from above test_Color() and test_Point()
        l2.write(cout);
        cout << endl;


        //tests setEnd and setStart
        Point p4(5,15);
        Color c3(100,150,200);
        Line l3;
        l3.setStart(p3);
        l3.setEnd(p2);
        l3.write(cout);
        cout << endl;

        //test setEnd and setStart with bad data
        Line l4;
        l4.setEnd(p3);
        l4.setStart(p3);
        l4.write(cout);
        cout << endl;

        //tests getStart
        Point t;
        t = l1.getStart();
        t.write(cout);
        t = l4.getStart();
        t.write(cout);
        cout << endl;
}

void test_Triangle(){

        //tests default constructor
        Triangle tr1;
        tr1.write(cout);
        cout << endl;

        //test non default constructor

        Point p1(0,0);
        Point p2(50,50);
        Point p3(70,80);
        Color c1(100,150,200);
        Color c2(250,150,50);
        Color c3(100,175,255);

        Triangle tr2(p1, p2, p3, c1);
        tr2.write(cout);
        cout << endl;



        //test non defualt constructor 2
        Triangle tr4(p1, c1, p2, c2, p3, c3);
        tr4.write(cout);
        cout << endl;


        //tests setVertex
        Point p4(0,100);
        tr1.setVertexOne(p1);
        tr1.setVertexTwo(p2);
        tr1.setVertexThree(p4);
        tr1.write(cout);
        cout << endl;


        //test getVertex
        Point tr = tr2.getVertexOne();
        tr.write(cout);
        cout << endl;
        tr = tr2.getVertexTwo();
        tr.write(cout);
        cout << endl;
        tr = tr2.getVertexThree();
        tr.write(cout);
        cout << endl;



        //tests getVertexColor
        Color  temp = tr2.getVertexOneColor();
        temp.write(cout);
        cout << endl;
        temp = tr2.getVertexTwoColor();
        temp.write(cout);
        cout << endl;
        temp = tr2.getVertexThreeColor();
        temp.write(cout);
        cout << endl;

        temp = tr4.getVertexOneColor();
        temp.write(cout);
        cout << endl;
        temp = tr4.getVertexTwoColor();
        temp.write(cout);
        cout << endl;
        temp = tr4.getVertexThreeColor();
        temp.write(cout);
        cout << endl;
}

void test_Rectangle(){
             //tests Rectangle default constructor
             Rectangle rec1;
             rec1.write(cout);
             cout << endl;

             //tests Rectangle non defualt constructor
             Point p1(20,20);
             Point p2(50,50);
             Point p3(12,25);
             Color c1(50,100,125);
             Color c2(250,150,50);
             Color c3(100,175,255);
             Color c4(0,0,50);
             Rectangle rec2(p1, p2, c1);
             rec2.write(cout);
             cout << endl;


             //tests Rectangle non default constructor 2
             Rectangle rec3(p2, p3, c1, c2, c3, c4);
             rec3.write(cout);
             cout << endl;


             //tests setColor
             rec1.setColorTopRight(c1);
             Color color1 = rec1.getColorTopRight();
             color1.write(cout);
             cout << endl;

             rec1.setColorTopLeft(c2);
             Color temp = rec1.getColorTopLeft();
             temp.write(cout);
             cout << endl;

             rec1.setColorBottomRight(c3);
             color1 = rec1.getColorBottomRight();
             color1.write(cout);
             cout << endl;

             rec1.setColorBottomLeft(c4);
             color1 = rec1.getColorBottomLeft();
             color1.write(cout);
             cout << endl;

             //tests setStart
             Rectangle rec4;
             rec4.setStart(p3);
             Point point1 = rec4.getStart();
             point1.write(cout);
             cout << endl;

             //tests getEnd
             Point point2 = rec4.getEnd();
             point2.write(cout);
             cout << endl;

}

void test_Circle(){
            //tests Circle default constructor
            Circle cir1;
            cir1.write(cout);
            cout << endl;

            //tests Circle non default constructor
            Color c1(50,0,100);
            Point p5(50,50);
            Circle cir2(p5, 20, c1);
            cir2.write(cout);
            cout << endl;


             //tests setRadius and
             Circle cir3;
             cir3.setRadius(10);
             int rd1 = cir3.getRadius();
             cout << rd1 << endl;

             //tests set center
             cir3.setCenter(p5);
             Point p = cir3.getCenter();
             p.write(cout);
             cout << endl;


}
