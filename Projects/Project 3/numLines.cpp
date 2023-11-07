#include <fstream>
#include <iostream>

int main() {
  std::ifstream file("init.txt");
  if (!file.is_open()) {
    std::cerr << "Unable to open file\n";
    return 1;
  }

  int line_count = 0;
  std::string line;
  while (std::getline(file, line)) {
    ++line_count;
  }

  std::cout << "Number of lines: " << line_count << '\n';

  return 0;
}
