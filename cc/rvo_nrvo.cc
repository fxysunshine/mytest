#include <iostream>

class A
{
  public:
    A() {
      std::cout << "[C] constructor fired." << std::endl;
    }

    A(const A &a) {
      std::cout << "[C] copying constructor fired." << std::endl;
    }

    A(A &&a) {
      std::cout << "[C] moving copying constructor fired." << std::endl;
    }

    ~A() {
      std::cout << "[C] destructor fired." << std::endl;
    }
};

A getTempA() {
  return A();
}
 
int main(int argc, char **argv) {
  std::cout << "###########" << std::endl;
  {
    auto x = getTempA();
  }

  std::cout << "###########" << std::endl;
  {
    auto y = A(A(A(getTempA())));
  }

  return 0;
}
