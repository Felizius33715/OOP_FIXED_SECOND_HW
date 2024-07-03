#include <iostream>
#include <string>

class Figure
{
protected:
    std::string name;
    int a, b, c;
    int A, B, C;
public:
    Figure() {}
    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    std::string get_name() { return name; }
};

class Triangle : public Figure
{
public:
    Triangle() {}
    Triangle(int a, int b, int c, int A, int B, int C)
    {
        name = "Triangle";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    void print_info(Triangle* triangle)
    {
        std::cout << triangle->get_name() << ":" << std::endl;
        std::cout << "Sides: a=" << triangle->get_a()
            << " b=" << triangle->get_b()
            << " c=" << triangle->get_c() << std::endl;

        std::cout << "Angles: A=" << triangle->get_A()
            << " B=" << triangle->get_B()
            << " C=" << triangle->get_C() << std::endl;
        std::cout << std::endl;
    }
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(int a, int b, int c, int A, int B)
    {
        name = "Right Triangle";
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        C = 90;
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int a, int b, int A, int B)
    {
        name = "Isosceles Triangle";
        this->a = a;
        this->b = b;
        this->A = A;
        this->B = B;
        c = a;
        C = A;
    }

};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(int a)
    {
        name = "Equilateral Triangle";
        this->a = a;
        b = c = a;
        A = B = C = 60;
    }
};

class Quadrangle : public Figure
{
protected:
    int d;
    int D;
public:
    Quadrangle() {}
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
    {
        name = "Quadrangle";
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    int get_d() { return d; }
    int get_D() { return D; }

    void print_info(Quadrangle* quadrangle)
    {
        std::cout << quadrangle->get_name() << ":" << std::endl;
        std::cout << "sides: a=" << quadrangle->get_a()
            << " b=" << quadrangle->get_b()
            << " c=" << quadrangle->get_c()
            << " d=" << quadrangle->get_d() << std::endl;
        std::cout << "Angles: A=" << quadrangle->get_A()
            << " B=" << quadrangle->get_B()
            << " C=" << quadrangle->get_C()
            << " D=" << quadrangle->get_D() << std::endl;
        std::cout << std::endl;
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram() {}
    Parallelogram(int a, int b, int A, int B)
    {
        name = "Parallelogram";
        this->a = a;
        this->b = b;
        this->A = A;
        this->B = B;
        c = a;
        d = b;
        C = A;
        D = B;
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(int a, int b, int A)
    {
        name = "Rectangle";
        this->a = a;
        this->b = b;
        this->A = A;
        c = a;
        d = b;
        B = C = D = A;
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus() {}
    Rhombus(int a, int A, int B)
    {
        name = "Rhombus";
        this->a = a;
        this->A = A;
        this->B = B;
        b = c = d = a;
        C = A;
        D = B;
    }
};

class Square : public Rhombus
{
public:
    Square(int a, int A)
    {
        name = "square";
        this->a = a;
        this->A = A;
        b = c = d = a;
        B = C = D = A;
    }
};

int main()
{
    Triangle triangle(10, 20, 30, 50, 60, 70);
    Square square(20, 90);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);
    Rectangle rectangle(10, 20, 90);
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    EquilateralTriangle equilateralTriangle(30);
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    RightTriangle rightTriangle(10, 20, 30, 50, 60);

    triangle.print_info(&triangle);
    rightTriangle.print_info(&rightTriangle);
    isoscelesTriangle.print_info(&isoscelesTriangle);
    equilateralTriangle.print_info(&equilateralTriangle);
    quadrangle.print_info(&quadrangle);
    rectangle.print_info(&rectangle);
    square.print_info(&square);
    parallelogram.print_info(&parallelogram);
    rhombus.print_info(&rhombus);
    return 0;
}