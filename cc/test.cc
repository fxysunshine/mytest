#include <iostream>

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
    std::cout << " print value:" << value << std::endl;
}

int main() {
    test(4).print();
    return 0;
}
