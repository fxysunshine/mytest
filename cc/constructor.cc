#include <iostream>

class A {
public: 
    A();
private:
    int a;
};

class B {
public:
    B();
private:
    int b;
};

A::A() {
    std::cout << "A structor" << std::endl;
}

B::B() {
    std::cout << "B structor" << std::endl;
}

class C : public A, B {
public:
    C();
    C(int);
private:
    int c;
};

C::C() {
    std::cout << "C structor" << std::endl;
}

C::C(int c) 
    : C() {
    std::cout << "C int structor " << c << std::endl;
}

int main() {
    C C(3);
    return 0;
}
