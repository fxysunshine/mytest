#include <future>
#include <string>
#include <iostream>
#include <chrono>

struct X {
    void foo(int i, std::string const& str) {
        std::cout << pthread_self() << ":" <<  __FUNCTION__ << " " << i << "," << str << std::endl;
    }
    std::string bar(std::string const &str) {
        std::cout << pthread_self() << ":" << __FUNCTION__ << " " << str << std::endl;
        return str;
    }
};

int main()
{
    X x;
    std::cout << pthread_self() << std::endl;
    auto f1 = std::async(&X::foo, &x, 42, "hello");
    auto f2 = std::async(&X::bar, x, "goodbye");

    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}
