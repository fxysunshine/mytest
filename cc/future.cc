#include <future>
#include <iostream>

int find_the_answer()
{
    int count = 0;
    for (int i = 0; i < 100000; ++i) {
        count += i;
    }
    return count;
}

void do_other_stuff()
{
    for (int i = 0; i < 10000000; ++i) {
    }
}

int main()
{
    std::future<int> the_answer = std::async(find_the_answer);
    do_other_stuff();
    std::cout << "The answer is " << the_answer.get() << std::endl;
    return 0;
}
