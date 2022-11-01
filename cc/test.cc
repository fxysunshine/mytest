#include <iostream>
#include <memory>
#include <functional>

// c++11 support
template<typename T, typename U>
auto add(T x, U y) -> decltype(x+y) {
  return x + y;
}

// c++14 support
template<typename T, typename U>
auto add2(T x, U y) {
  return x + y;
}

class test {
public:
    test(int v)
        : value(v) {}
    ~test() {}
    void print();
private:
    int value;
};

void test::print() {
    std::cout << "print value:" << value << std::endl;
}

int foo(int para) {
  return para;
}

struct A;
struct B;

struct A {
    std::shared_ptr<B> pointer;
    ~A() {
        std::cout << "A destroy" << std::endl;
    }
};

struct B {
    //std::shared_ptr<A> pointer;
    std::weak_ptr<A> pointer;
    ~B() {
        std::cout << "B destroy" << std::endl;
    }
};

int main() {
    std::cout << "cplusplus version: " << __cplusplus << std::endl;

    auto u = add<int, double>(1, 2.0);
    if (std::is_same<decltype(u), double>::value) {
      std::cout << "u is double: ";
    }
    std::cout << u << std::endl;
    auto w = add2<int, double>(1, 2.0);
    if (std::is_same<decltype(w), double>::value) {
      std::cout << "w is double: ";
    }
    std::cout << w << std::endl;

    test(4).print();

    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
      return x + y + v1 + (*v2);
    };
    std::cout << add(3, 4) << std::endl;

    auto add2 = [](auto x, auto y) {
      return x + y;
    };
    std::cout << add2(1, 2) << std::endl;
    std::cout << add2(1.1, 2.2) << std::endl;

    // std::function 包装了一个返回值为int，参数为int的函数
    std::function<int(int)> func = foo;
    int i = 10;
    std::function<int(int)> func2 = [&](int value) -> int {
      return 1 + value + i;
    };
    std::cout << func(10) << std::endl;
    std::cout << func2(10) << std::endl;

    // shared_ptr reference
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->pointer = b;
    b->pointer = a;

    return 0;
}
