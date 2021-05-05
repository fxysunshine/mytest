#include <iostream>
#include <atomic>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>

// example 1
std::atomic_flag lock = ATOMIC_FLAG_INIT;
std::stringstream stream;

void append_string(int x)
{
  while (lock.test_and_set());
  stream << "thread#" << x << "\n";
  lock.clear();
}

// example 2
std::atomic<bool> ready(false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void count(int i)
{
  while (!ready);
  for (int i = 0; i < 1000000; ++i);
  if (!winner.test_and_set()) {
    std::cout << "winner: " << i << std::endl;
  }
}

// example 3
std::atomic<int> foo(0);

void set_foo(int x)
{
  foo = x;
}

void print_foo()
{
  while (foo == 0) {
    std::this_thread::yield();
  }
  std::cout << "x: " << foo << std::endl;
}

// example 4
std::atomic<int> foo4(0);

void add_foo()
{
  for (int i = 0; i < 10; ++i) {
    foo4++;
    while (lock.test_and_set());
    std::cout << "add: " << foo4 << std::endl;
    lock.clear();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

void sub_foo()
{
  for (int i = 0; i < 10; ++i) {
    foo4--;
    while (lock.test_and_set());
    std::cout << "sub: " << foo4 << std::endl;
    lock.clear();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}

int main()
{
  std::vector<std::thread> ths;

  // example 1
  for (int i = 0; i < 10; ++i) {
    ths.push_back(std::thread(append_string, i));
  }
  for (int i = 0; i < 10; ++i) {
    ths[i].join();
  }
  std::cout << stream.str();

  // example 2
  ths.clear();
  for (int i = 0; i < 10; ++i) {
    ths.push_back(std::thread(count, i));
  }
  ready = true;
  for (int i = 0; i < 10; ++i) {
    ths[i].join();
  }

  // example 3
  std::thread print_th(print_foo);
  std::thread set_th(set_foo, 10);
  print_th.join();
  set_th.join();

  // example 4
  std::thread th1(add_foo);
  std::thread th2(sub_foo);
  th1.join();
  th2.join();

  return 0;
}
