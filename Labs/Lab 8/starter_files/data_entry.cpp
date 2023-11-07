#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace ::std;
// Function to convert month names to numbers
int getMonthNumber(const string& month) {
  const vector<string> months = {
      "January", "February", "March",     "April",   "May",      "June",
      "July",    "August",   "September", "October", "November", "December"};

  for (unsigned long int i = 0; i < months.size(); ++i) {
    if (months[i] == month) {
      return i + 1;  // January is 1, February is 2, and so on
    }
  }
  return 0;  // Month not found
}

int main() {
  // Open input and output files
  ifstream inputFile("data_entry_input.txt");
  ofstream outputFile("data_entry_output.txt");

  if (!inputFile.is_open() || !outputFile.is_open()) {
    cerr << "Error opening files." << endl;
    return 1;
  }

  string line;

  while (getline(inputFile, line)) {
    // Use string streams to parse the input
    istringstream iss(line);
    string time, ampm, on, month, dayRaw;
    int year;

    iss >> time >> ampm >> on >> month >> dayRaw >> year;

    // Check if the time is in the format "HH:MM" or "H:MM"
    size_t colonPos = time.find(":");
    int hour, minute;
    if (colonPos != string::npos) {
      hour = stoi(time.substr(0, colonPos));
      minute = stoi(time.substr(colonPos + 1));
    } else {
      hour = stoi(time);
      minute = 0;
    }

    int day;
    if (dayRaw.size() < 5)
      day = stoi(dayRaw.substr(0, 1));
    else
      day = stoi(dayRaw.substr(0, 2));

    // Convert "AM" and "PM" to military time
    if (ampm == "PM" && hour != 12) {
      hour += 12;
    } else if (ampm == "AM" && hour == 12) {
      hour = 0;
    }

    // Get the month number
    int monthNumber = getMonthNumber(month);

    // Output the result in the desired format
    outputFile << minute << '\t' << hour << '\t' << day << '\t' << monthNumber
               << '\t' << year << '\n';
  }

  // Close files
  inputFile.close();
  outputFile.close();

  return 0;
}
