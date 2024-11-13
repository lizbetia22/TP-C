module;
import std;
export module exo1;

export namespace exo1 {

    class Vector {
    public:
        double x, y, z;
        Vector(const double x, const double y, const double z): x{x}, y{y}, z{z} {
        }

        //Getter
        [[nodiscard]] double GetX() const { return x; }
        [[nodiscard]] double GetY() const { return y; }
        [[nodiscard]] double GetZ() const { return z; }

        //Setter
        void SetX(const double x) { this->x = x; }
        void SetY(const double y) { this->y = y; }
        void SetZ(const double z) { this->z = z; }

        void Homothety(const double value) {
            x *= value;
            y *= value;
            z *= value;
        }

        void Sum(const Vector vector) {
            x += vector.x;
            y += vector.y;
            z += vector.z;
        }

        [[nodiscard]] std::string ToString() const {
            return std::format("({0:.2f},{1:.2f},{2:.2f})", x, y, z);
        }
    };

    class Application {
    public:
        Application() {
            auto v1 = Vector{5, 10, 15};
            std::cout << v1.ToString() << std::endl;
            v1.Homothety(2);
            std::cout << v1.ToString() << std::endl;
            v1.Sum(Vector{1, 2, 3});
            std::cout << v1.ToString() << std::endl;
        }
    };

}