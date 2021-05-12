#include <iostream>
#include <vector>

using namespace std;
class Test
{
public:
  Test(int *p) : m_p(p) {}
  Test(Test &&test)
  {
    cout << "move constructor" << endl;
    cout << "move before:" << test.m_p << endl;
    m_p = move(test.m_p);
    cout << "move after:" << test.m_p << endl;
  }
  Test &operator=(Test &&test)
  {
    cout << "move assignment constructor" << endl;
    cout << "move before:" << test.m_p << endl;
    if (this != &test) {
      m_p = move(test.m_p);
    }
    cout << "move after:" << test.m_p << endl;
    return *this;
  }
  int *Get()
  {
    return m_p;
  }

private:
  int *m_p;
};

class Base
{
public:
  Base(int k)
  {
    p = new int(1);
    *p = q = k;
  }
  ~Base()
  {
    cout << "release address:" << p << endl;
    // need release p, leak or double free?
  }
  void show()
  {
    cout << "q address:" << &q << endl;
    cout << "p address:" << p << endl;
  }
private:
  int q;
  int *p;
};

int main()
{
  int a, b;
  cout << "address a:" << &a << endl;
  cout << "address b:" << &b << endl;
  // constructor
  Test foo = Test(&a);
  cout << "foo address:" << foo.Get() << endl;
  // remove assignment constructor
  foo = Test(&b);
  cout << "foo address:" << foo.Get() << endl;
  // remove constructor
  vector<Test> vec;
  vec.push_back(Test(&a));
  cout << "vec element address:" << vec[0].Get() << endl;

  cout << endl << "const ----------------------" << endl;
  int k = 6, s = 7;
  cout << k << " " << s << endl;
  k = move(s);
  cout << k << " " << s << endl;
  k = 8;
  cout << k << endl;

  cout << endl << "const array(auto clean) ------------------" << endl;
  vector<int> data1 = {1, 2};
  vector<int> data2 = {3, 4, 5, 6, 7, 8};
  data1 = move(data2);
  cout << endl << "after move, data1:" << endl;
  for (int foo : data1) cout << foo << " ";
  cout << endl << "after move, data2:" << endl;
  for (int foo : data2) cout << foo << " ";

  cout << endl << "point ------------------------" << endl;
  int m = 3, n = 5;
  int *p = &m, *q = &n;
  p = move(q);
  cout << p << "    " << *p << endl;
  cout << q << "    " << *q << endl;

  cout << endl << "object ------------------------" << endl;
  {
    Base ba(5);
    ba.show();
    Base bb(2);
    bb.show();
    bb = move(ba);
    cout << "after move" << endl;
    ba.show();
    bb.show();
  }

  cout << endl << "string(auto clean) -------------" << endl;
  string str = move("haha");
  string str1("go");
  str1 = move(str);
  cout << &str << "   " << str << endl;
  cout << &str1 << "   " << str1 << endl;
  return 0;
}
