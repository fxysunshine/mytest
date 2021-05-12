#include <mutex>
#include <queue>
#include <condition_variable>
#include <memory>
#include <thread>
#include <iostream>
#include <cassert>

template<typename T>
class threadsafe_queue
{
private:
  mutable std::mutex m;
  std::queue<T> data_queue;
  std::condition_variable data_cond;
public:
  threadsafe_queue() {}

  void push(T new_value)
  {
    std::lock_guard<std::mutex> lock(m);
    data_queue.push(std::move(new_value));
    data_cond.notify_one();
  }

  void wait_and_pop(T& value)
  {
    std::lock_guard<std::mutex> lock(m);
    data_cond.wait(lock, [this]{return !data_queue.empty();});
    value = std::move(data_queue.front());
    data_queue.pop();
  }

  std::shared_ptr<T> wait_and_pop()
  {
    std::lock_guard<std::mutex> lock(m);
    data_cond.wait(lock, [this]{return !data_queue.empty();});
    std::shared_ptr<T> const res =
      std::make_shared<T>(std::move(data_queue.front()));
    data_queue.pop();
    return res;
  }

  bool try_pop(T& value)
  {
    std::lock_guard<std::mutex> lock(m);
    if (data_queue.empty())
      return false;
    value = std::move(data_queue.front());
    data_queue.pop();
    return true;
  }

  std::shared_ptr<T> try_pop()
  {
    std::lock_guard<std::mutex> lock(m);
    if (data_queue.empty())
      return std::make_shared<T>();
    std::shared_ptr<T> const res =
      std::make_shared<T>(std::move(data_queue.front()));
    data_queue.pop();
    return res;
  }

  bool empty() const
  {
    std::lock_guard<std::mutex> lock(m);
    return data_queue.empty();
  }
};

template<typename T>
class threadsafe_queue_opt
{
private:
  mutable std::mutex m;
  std::queue<std::shared_ptr<T> > data_queue;
  std::condition_variable data_cond;
public:
  threadsafe_queue_opt() {}

  void push(T new_value)
  {
    std::shared_ptr<T> data(
        std::make_shared<T>(std::move(new_value)));
    std::lock_guard<std::mutex> lock(m);
    data_queue.push(data);
    data_cond.notify_one();
  }

  void wait_and_pop(T& value)
  {
    std::lock_guard<std::mutex> lock(m);
    data_cond.wait(lock, [this]{return !data_queue.empty();});
    value = std::move(*data_queue.front());
    data_queue.pop();
  }

  std::shared_ptr<T> wait_and_pop()
  {
    std::lock_guard<std::mutex> lock(m);
    data_cond.wait(lock, [this]{return !data_queue.empty();});
    std::shared_ptr<T> res = data_queue.front();
    data_queue.pop();
    return res;
  }

  bool try_pop(T& value)
  {
    std::lock_guard<std::mutex> lock(m);
    if (data_queue.empty())
      return false;
    value = std::move(*data_queue.front());
    data_queue.pop();
    return true;
  }

  std::shared_ptr<T> try_pop()
  {
    std::lock_guard<std::mutex> lock(m);
    if (data_queue.empty())
      return std::make_shared<T>();
    std::shared_ptr<T> res = data_queue.front();
    data_queue.pop();
    return res;
  }

  bool empty() const
  {
    std::lock_guard<std::mutex> lock(m);
    return data_queue.empty();
  }
};

int main()
{
  threadsafe_queue<int> q;
  assert(q.empty() == true);

  threadsafe_queue_opt<int> qt;
  assert(qt.empty() == true);

  return 0;
}
