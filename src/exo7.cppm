module;
import std;
export module exo7;

export namespace exo7 {

    class Resource {
    public:
      Resource() {
          std::printf("Created constructor Resource\n");
      }
        ~Resource() {
          std::printf("Destructed constructor Resource\n");
      }
         void DoSomething() {
          std::printf("Do something message\n");
      }
    };

    class Application {
    public:
        void UniquePtr() {
            const auto res = std::make_unique<Resource>();
            res->DoSomething();
        }
        void UseSharedPtr(const std::shared_ptr<Resource> res) {
            std::cout << "resource use count: " << res.use_count() << '\n';
            res->DoSomething();
            if (res.use_count() < 5) UseSharedPtr(res);
        }

        void SharedPtr() {
            const auto res = std::make_shared<Resource>();
            std::cout << "resource use count: " << res.use_count() << '\n';
            UseSharedPtr(res);
            std::cout << "resource use count: " << res.use_count() << '\n';
        }

        Application() {
            UniquePtr();
            SharedPtr();
        }

    };

}