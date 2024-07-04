#include <iostream>
#include <cmath>
#include <string>

enum Color { None, Red, Green, Blue };

class Figure {
private:
    std::pair<double, double> center_coordinates;
    Color color;

public:
    Figure(double x, double y, Color color) : center_coordinates(x, y), color(color) {}

    virtual double getArea() const = 0;
    virtual void getBoundingBox(double& width, double& height) const = 0;

    std::string getColorName() const {
        switch (color) {
        case Color::None: return "None";
        case Color::Red: return "Red";
        case Color::Blue: return "Blue";
        case Color::Green: return "Green";
        }
        return "Unknown";
    }
};


class Circle : public Figure {
private:
    double radius;

public:
    Circle(double x, double y, Color color, double radius_t) : Figure(x, y, color), radius(radius_t) {}

    double getArea() const override {
        return atan(1) * 4 * radius;
    }

    void getBoundingBox(double& width, double& height) const override {
        width = height = 2 * radius;
    }
};


class Rectangle : public Figure {
private:
    double side_height;
    double side_width;

public:
    Rectangle(double x, double y, Color color, double side_width_t, double side_height_t)
        : Figure(x, y, color), side_height(side_height_t), side_width(side_width_t) {}

    double getArea() const override {
        return side_width * side_height;
    }

    void getBoundingBox(double& width, double& height) const override {
        width = this->side_width;
        height = this->side_height;
    }
};


class Square : public Rectangle {
private:
    double side;

public:
    Square(double x, double y, Color color, double side_t)
        : Rectangle(x, y, color, side_t, side_t) {}

    //double getArea() const override {
    //    return side * side;
    //}

    //void getBoundingBox(double& width, double& height) const override {
    //    width = height = side;
    //}
};


class Triangle : public Figure {
private:
    double side;

public:
    Triangle(double x, double y, Color color, double side_t) : Figure(x, y, color), side(side_t) {}

    double getArea() const override {
        return side * side * std::sqrt(3) / 4;
    }

    void getBoundingBox(double& width, double& height) const override {
        width = height = side;
    }
};


Color stringToColor(const std::string& colorStr) {
    if (colorStr == "None") return Color::None;
    if (colorStr == "Red") return Color::Red;
    if (colorStr == "Green") return Color::Green;
    if (colorStr == "Blue") return Color::Blue;
    return Color::None;
}

int main() {
    std::cout << "-- Hierarchy of geometric shapes --\n";

    std::string command;
    while (std::cin >> command) {
        std::cout << "Enter a name for the shape: ";
        if (command == "circle") {
            double x, y, radius;
            std::string color;
            std::cout << "Enter the characteristics of the circle: (center_x, center_y, color, radius)\n";
            std::cin >> x >> y >> color >> radius;
            Circle circle(x, y, stringToColor(color), radius);
            double width, height;
            circle.getBoundingBox(width, height);
            std::cout << "Area: " << circle.getArea() << "\n";
            std::cout << "Bounding Box: " << width << " x " << height << "\n";
        } else if (command == "square") {
            double x, y, side;
            std::string color;
            std::cout << "Enter the characteristics of the square: (center_x, center_y, color, side)\n";
            std::cin >> x >> y >> color >> side;
            Square square(x, y, stringToColor(color), side);
            double width, height;
            square.getBoundingBox(width, height);
            std::cout << "Area: " << square.getArea() << "\n";
            std::cout << "Bounding Box: " << width << " x " << height << "\n";
        } else if (command == "triangle") {
            double x, y, side;
            std::string color;
            std::cout << "Enter the characteristics of the triangle: (center_x, center_y, color, side)\n";
            std::cin >> x >> y >> color >> side;
            Triangle triangle(x, y, stringToColor(color), side);
            double width, height;
            triangle.getBoundingBox(width, height);
            std::cout << "Area: " << triangle.getArea() << "\n";
            std::cout << "Bounding Box: " << width << " x " << height << "\n";
        } else if (command == "rectangle") {
            double x, y, width, height;
            std::string color;
            std::cout << "Enter the characteristics of the triangle: (center_x, center_y, color, width, height)\n";
            std::cin >> x >> y >> color >> width >> height;
            Rectangle rectangle(x, y, stringToColor(color), width, height);
            double rect_width, rectHeight;
            rectangle.getBoundingBox(rect_width, rectHeight);
            std::cout << "Area: " << rectangle.getArea() << "\n";
            std::cout << "Bounding Box: " << rect_width << " x " << rectHeight << "\n";
        } else {
            std::cout << "Unknown command!\n";
        }
    }
}
