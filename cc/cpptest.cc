#include <iostream>
#include <vector>
#include <algorithm>

class MyNumber
{
public:
  MyNumber(const std::initializer_list<int> &v) {
    for (auto item : v)
      mVec.push_back(item);
  }
  void print() {
    for (auto item : mVec)
      std::cout << item << " ";
    std::cout << std::endl;
  }
private:
  std::vector<int> mVec;
};

int main()
{
  std::vector<int> a, b;
  std::vector<int> v {1, 2, 3, 4, 5};

  // c++03
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    a.push_back(*it);

  // c++11
  for (auto it = v.begin(); it != v.end(); ++it)
    b.push_back(*it);

  for (int item : a)
    std::cout << item << " ";    // read only access
  std::cout << std::endl;

  for (auto &item : b) {
    item *= 10;
    std::cout << item << " "; 
  }
  std::cout << std::endl;

  MyNumber m = {0, 1, 2, 3, 4, 5, 6};
  m.print();

  // lambda
  std::vector<int> vec(10);
  std::for_each(vec.begin(), vec.end(), [](int v) {
    std::cout << v << " ";
  });
  std::cout << std::endl;

  std::for_each(vec.begin(), vec.end(), [](int& v) {
    static int n = 1;
    v = n++;
  });
  std::for_each(vec.begin(), vec.end(), [](int v) {
    std::cout << v << " ";
  });
  std::cout << std::endl;

  // lambda
  auto f = [](int a, int b) {
    return a * b;
  };
  std::cout << f(4, 5) << std::endl;   // 20
  std::cout << [](int a, int b) {return a + b;} (4, 5) << std::endl;   // 9

  return 0;
}
