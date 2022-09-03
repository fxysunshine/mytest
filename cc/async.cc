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

void test()
{
  X x;
  std::cout << pthread_self() << std::endl;
  auto f1 = std::async(&X::foo, &x, 42, "hello");
  auto f2 = std::async(&X::bar, x, "goodbye");
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void test1()
{
  std::promise<bool> prom;
  std::future<bool> f = prom.get_future();
  prom.set_value(true);
  std::cout << f.get() << std::endl;
}

void test2()
{
  std::promise<int> prom;
  auto f = prom.get_future();
  std::thread t(
    [](std::promise<int> p) {
      std::this_thread::sleep_for(std::chrono::seconds(2));
      p.set_value(100);
    },
    std::move(prom));
  std::cout << f.get() << std::endl;
  if (t.joinable()) t.join();
}

void test3()
{
  std::packaged_task<int(int, int)> task([](int a, int b) {
      return a + b;
    });
  auto f = task.get_future();
  std::thread t(std::move(task), 1, 2);
  std::cout << f.get() << std::endl;
  if (t.joinable()) t.join();
}

void test4()
{
  auto f = std::async(
    std::launch::async, [](int a, int b) {
      return a + b;
    }, 1, 2);
  std::cout << f.get() << std::endl;
}

int main()
{
  test();
  test1();
  test2();
  test3();
  test4();
  return 0;
}
