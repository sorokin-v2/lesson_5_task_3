#include <iostream>
#include <string>


class Figure {
public:
    Figure() 
    {
        name = "Фигура";
        sides_count = 0;
    }
    virtual void print_info() { std::cout << name << ": \n" << (check() ? "Правильная" : "Неправильная") << "\nКоличество сторон: " <<
        sides_count << std::endl; }

protected:
    virtual bool check() { return true; }

    std::string name;
    int sides_count;
};

class Triangle : public Figure {
public:
    Triangle(int new_a, int new_b, int new_c, int new_A, int new_B, int new_C) :
        a{ new_a }, b{ new_b }, c{ new_c }, A{ new_A }, B{ new_B }, C{ new_C }
    {
        name = "Треугольник";
        sides_count = 3;
    }
    virtual void print_info() override
    {
        Figure::print_info();
        std::cout << "Стононы: a=" << a << " b=" << b << " c=" << c << "\n" <<
            "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }

protected:
    virtual bool check()  override { return (A + B + C) == 180 ? true : false; }
    
    int a;
    int b;
    int c;
    int A;
    int B;
    int C;
};

class Right_triangle : public Triangle {
public:
    Right_triangle(int new_a, int new_b, int new_c, int new_A, int new_B) :
        Triangle(new_a, new_b, new_c, new_A, new_B, 90)
    {
        name = "Прямоугольный треугольник";
    }
protected:
    virtual bool check()  override { return ((A + B) == 90 && C == 90) ? true : false; }

};

class Isosceles_triangle : public Triangle {
public:
    Isosceles_triangle(int new_a, int new_b, int new_A, int new_B) :
        Triangle(new_a, new_b, new_a, new_A, new_B, new_A)
    {
        name = "Равнобедренный треугольник";
    }
protected:
    virtual bool check()  override { return (((A + B + C) == 180) && a == c && A == C) ? true : false; }
};

class Equilateral_triangle : public Triangle {
public:
    Equilateral_triangle(int new_a) :
        Triangle(new_a, new_a, new_a, 60, 60, 60)
    {
        name = "Равносторонний треугольник";
    }
protected:
    virtual bool check()  override { return (A == 60 && B == 60 && C == 60 && a == b && b == c)? true : false; }

};

class Quadrangle : public Figure {
public:

    Quadrangle(int new_a, int new_b, int new_c, int new_d, int new_A, int new_B, int new_C, int new_D) :
        a{ new_a }, b{ new_b }, c{ new_c }, d{ new_d }, A{ new_A }, B{ new_B }, C{ new_C }, D{ new_D }
    {
        name = "Четырёхугольник";
        sides_count = 4;
    }
    virtual void print_info() override
    {
        Figure::print_info();
        std::cout << "Стононы: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n" <<
            "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
protected:
    virtual bool check()  override { return (A + B + C + D) == 360 ? true : false; }

    int a;
    int b;
    int c;
    int d;
    int A;
    int B;
    int C;
    int D;
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int new_a, int new_b, int new_A, int new_B) :
        Quadrangle(new_a, new_b, new_a, new_b, new_A, new_B, new_A, new_B)
    {
        name = "Параллелограмм";
    }
protected:
    virtual bool check()  override { return ((A + B + C + D) == 360 && a == c && b == d && A == C && B == D)? true : false; }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int new_a, int new_b) :
        Parallelogram(new_a, new_b, 90, 90)
    {
        name = "Прямоугольник";
    }
protected:
    virtual bool check()  override { return (A == 90 && B == 90 && C == 90 && D == 90 && a == c && b == d) ? true : false; }

};

class Rhomb : public Parallelogram {
public:
    Rhomb(int new_a, int new_A, int new_B) :
        Parallelogram(new_a, new_a, new_A, new_B)
    {
        name = "Ромб";
    }
protected:
    virtual bool check()  override { return ((A + B + C + D) == 360 && a == b && b == c && c==d && A == C && B == D) ? true : false; }
};

class Square : public Rectangle {
public:
    Square(int new_a) :
        Rectangle(new_a, new_a)
    {
        name = "Квадрат";
    }
protected:
    virtual bool check()  override { return (A == 90 && B == 90 && C == 90 && D == 90 && a == b && b == c && c == d)  ? true : false; }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    Triangle triangle(10, 20, 30, 50, 60, 70);
    Right_triangle right_triangle(10, 20, 30, 50, 60);
    Isosceles_triangle isosceles_triangle(10, 20, 50, 60);
    Equilateral_triangle equilateral_triangle(30);

    Figure figure;
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rectangle rectangle(10, 20);
    Rhomb rhomb(30, 30, 40);
    Square square(20);

    figure.print_info();
    std::cout << std::endl;
    triangle.print_info();
    std::cout << std::endl;
    right_triangle.print_info();
    std::cout << std::endl;
    isosceles_triangle.print_info();
    std::cout << std::endl;
    equilateral_triangle.print_info();
    std::cout << std::endl;
    quadrangle.print_info();
    std::cout << std::endl;
    rectangle.print_info();
    std::cout << std::endl;
    square.print_info();
    std::cout << std::endl;
    parallelogram.print_info();
    std::cout << std::endl;
    rhomb.print_info();
}
