// Assignment 1: Part 2
// Team members: 1. Hui Zhang 40170679
//               2. Zexu Hao 40233332
//               3. Mingming Zhang 40258080
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

// Develop a class Point. A point is represented by 3 coordinates: x, y, and z. The class must provide the
// following functions:
// translate (int d, char axis). d is the distance the point will move in the given axis. Axis can have one of the
// following 3 values: ‘x’, ‘y’, and ‘z’. If any other value is given, the function should do nothing and return a
// value of -1. The function returns 0 if everything is valid and the point is translated.
class Point {
    private:
        int x, y, z;

    public:
        // Constructor
        Point(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

        //Destrustor
        ~Point() {
            cout << "Point destroyed: ";
            display();
            cout << endl;
        }

        // Translate the point by d units in the given axis
        int translate(int d, char axis) {
            if (axis == 'x')
                x += d;
            else if (axis == 'y')
                y += d;
            else if (axis == 'z')
                z += d;
            else
                return -1; // Invalid axis

            return 0; //sucessful return
        }

        // Print the coordinates of the point
        void display() const {
            cout << "Point: (" << x << ", " << y << ", " << z << ")" << endl;
        }

        // Getters
        int getX() const { return x; }
        int getY() const { return y; }
        int getZ() const { return z; }

        

};


//Develop a class Triangle. A triangle consists of 3 Points. In the implementation of the attributes of the
// triangle class, you must represent the three points as pointers to Point. You may name them vertex_1,
// vertex_2, and vertex_3.
// Implement a method translate (int d, char axis) that translates the three vertices of the triangle by d in
// the direction of the given axis.
// Implement a function to calculate the area of the triangle. Name it calcArea(). You decide its return type.
// Develop a constructor that takes three points as parameters.
// Develop a default constructor that sets the three pointers to the three points to null.

//Triangle class
class Triangle {
    private:
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;
   
    public:
    // Default constructor
    Triangle() : vertex_1(nullptr), vertex_2(nullptr), vertex_3(nullptr) {}

    // Constructor
    Triangle(Point* p1, Point* p2, Point* p3) : vertex_1(p1), vertex_2(p2), vertex_3(p3) {}

    // Destructor
    ~Triangle(){
        cout << "Triangle destroyed."<< endl;
        delete vertex_1;
        delete vertex_2;
        delete vertex_3;
    }

    //Translate method
    void translate(int d, char axis) {
        if (vertex_1) vertex_1->translate(d, axis);
        if (vertex_2) vertex_2->translate(d, axis);
        if (vertex_3) vertex_3->translate(d, axis);
    }

    //Calculate the area of the triangle
    double calArea() const{
        if (!vertex_1 || !vertex_2 || !vertex_3) {
            cout << "Invalid triangle" << endl;
            return -1;
        }
        
        //Coordinaes of the vertices
        int x1 = vertex_1->getX(), y1 = vertex_1->getY(), z1 = vertex_1->getZ();
        int x2 = vertex_2->getX(), y2 = vertex_2->getY(), z2 = vertex_2->getZ();
        int x3 = vertex_3->getX(), y3 = vertex_3->getY(), z3 = vertex_3->getZ();

        // Vectors u and v
    int ux = x2 - x1, uy = y2 - y1, uz = z2 - z1;
    int vx = x3 - x1, vy = y3 - y1, vz = z3 - z1;

    // Cross product of u and v
    int cx = uy * vz - uz * vy;
    int cy = uz * vx - ux * vz;
    int cz = ux * vy - uy * vx;

    // Magnitude of the cross product vector
    double magnitude = sqrt(cx * cx + cy * cy + cz * cz);

    // Area of the triangle
    return magnitude / 2.0;

    }

    void display() const {
        if (vertex_1 && vertex_2 && vertex_3) {
            cout << "Triangle: " << endl;
            vertex_1->display();
            vertex_2->display();
            vertex_3->display();
        } else {
            cout << "Invalid triangle" << endl;
        }
    }

    

};

// Driver
int main(){
    int x, y, z;

    //Prompt user to enter coordinates for the 3 vertices of the triangle
    cout << "Enter the coordinates for Vertex 1(x, y, z): ";
    cin >> x >> y >> z;
    Point* p1 = new Point(x, y, z);

    cout << "Enter the coordinates for Vertex 2(x, y, z): ";
    cin >> x >> y >> z;
    Point* p2 = new Point(x, y, z);

    cout << "Enter the coordinates for Vertex 3(x, y, z): ";
    cin >> x >> y >> z;
    Point* p3 = new Point(x, y, z);

    //Create a triangle object
    Triangle triangle(p1, p2, p3);

    int choice;
    do{
        cout <<"\nMenu:"<< endl;
        cout << "1. Translate the triangle" << endl;
        cout << "2. Display Triagnle Coordinates" << endl;
        cout << "3. Calculate Triangle Area" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        switch(choice){
            case 1: {
                int d;
                char axis;
                cout << "Enter the distance to translate: ";;
                cin >> d;
                cout << "Enter the axis (x,y,z): ";
                cin>> axis;
                triangle.translate(d, axis);
                break;
            }
            case 2: {
                triangle.display();
                break;
            }
            case 3: {
                cout <<"Area of the triangle: "<<triangle.calArea() << endl;
                break;
            }
            case 4: {
                cout << "Exiting..." << endl;
                delete p1, p2, p3,triangle;
                break;
            }
            default: {
                cout << "Invalid choice. Try again." << endl;
            }

        }
        

    }while (choice != 4);
    
    return 0;
    
}