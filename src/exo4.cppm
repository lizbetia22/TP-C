module;
import std;

export module exo4;

export namespace exo4 {
    class Shape {
    public:

       [[nodiscard]] virtual double Perimeter() const = 0;

       [[nodiscard]] virtual std::string ToString() const = 0;

        virtual ~Shape() = default;
    };

    class Circle : public Shape {
    public:
      double radius;
        explicit Circle(const double radius): radius{radius} {
        }

        double Perimeter() const override {
            return 2.0 * std::numbers::pi * radius;
        }

        [[nodiscard]] std::string ToString() const override {
            return std::format("Circle({0:.2f})", radius);
        }
    };


    class Application {
    public:
        void displayPerimeter(const Shape& shape) const {
            std::cout
                << "Perimeter " << shape.ToString()
                << std::format(" is {0:.2f}", shape.Perimeter())
                << std::endl;
        }

        Application() {
            displayPerimeter(Circle{1.2});
        }
    };
}