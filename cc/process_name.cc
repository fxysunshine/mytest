#include <unistd.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

static string GetProcessName(pid_t pid) {
  string process;
  stringstream ss;
  ss << "/proc/" << pid << "/comm";
  ifstream in(ss.str());
  getline(in, process);
  return process;
}

int main() {
  pid_t pid = getpid();
  const string& name = GetProcessName(pid);
  cout << "process pid: " << pid << " name: " << name << endl;

  return 0;
}
