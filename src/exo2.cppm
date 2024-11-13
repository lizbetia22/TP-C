module;
import std;
export module exo2;

export namespace exo2 {

    class Vector {
    public:
        double x, y, z;
        Vector(const double x, const double y, const double z): x{x}, y{y}, z{z} {
            std::cout << "Vector(x,y,z) created" << std::endl;
        }

        Vector(const Vector& vector): x{vector.x}, y{vector.y}, z{vector.z} {
            std::cout << "Vector(vector) copied" << std::endl;
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

        void Sum1(const Vector vector) {
            x += vector.x;
            y += vector.y;
            z += vector.z;
        }

        void Sum2(const Vector& vector) {
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
            auto v1 = Vector{1, 2, 3};
            std::cout << v1.ToString() << std::endl;
            v1.Homothety(2);
            std::cout << v1.ToString() << std::endl;
            const auto v2 = Vector{1, 2, 3};
            v1.Sum1(v2);
            std::cout << v1.ToString() << std::endl;
            v1.Sum2(v2);
            std::cout << v1.ToString() << std::endl;
        }
    };

}