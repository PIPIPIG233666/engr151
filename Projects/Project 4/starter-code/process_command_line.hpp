#include <iostream>

using namespace std;

void process_command_line(int argc, char* argv[], int* case_number) {
  // TODO: Read command line arguments
  if (argc != 3) {
    cout << "Incorrect number of arguments.";
    exit(1);
  }
  *case_number = stoi(argv[2]);
  if (*case_number > 4 || *case_number < 1) {
    cout << "“Case number must be either 1, 2, 3, or 4.";
    exit(1);
  }
  srand(stoi(argv[1]));
}
