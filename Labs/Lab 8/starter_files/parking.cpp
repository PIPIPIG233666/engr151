#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void read_info(int& rows, int& cols, vector<vector<int>>& parking_lot,
               vector<vector<string>>& license_plates);
void print_info(int free_spaces, vector<string> illegal,
                vector<string> expired);

//DECLARE YOUR FUNCTION HERE//
int parking_police(vector<vector<int>>& parking_lot,
                   vector<vector<string>>& license_plates,
                   vector<string>& expired, vector<string>& illegal);

int main() {
  vector<vector<int>> parking_lot;
  vector<vector<string>> license_plates;
  int rows, cols;
  int free_spaces;

  vector<string> expired;
  vector<string> illegal;

  //fill vectors with data from input files
  read_info(rows, cols, parking_lot, license_plates);

  free_spaces = parking_police(parking_lot, license_plates, expired,
                               illegal);  //CALL YOUR FUNCTION HERE//

  //print parking info
  print_info(free_spaces, illegal, expired);

  return 0;
}

//DEFINE YOUR FUNCTION HERE//
int parking_police(vector<vector<int>>& parking_lot,
                   vector<vector<string>>& license_plates,
                   vector<string>& expired, vector<string>& illegal) {
  int ret = 0;
  for (unsigned long int r = 0; r < parking_lot.size(); r++) {
    for (unsigned long int c = 0; c < parking_lot[r].size(); c++) {
      if (parking_lot[r][c] == 404)
        illegal.push_back(license_plates[r][c]);
      else if (parking_lot[r][c] < 0)
        expired.push_back(license_plates[r][c]);
      else if (parking_lot[r][c] == 0)
        ret++;
    }
  }
  return ret;
}
void read_info(int& rows, int& cols, vector<vector<int>>& parking_lot,
               vector<vector<string>>& license_plates) {

  ifstream input1("parking_lot.txt");
  vector<int> init_int;
  vector<string> init_string;

  int car;
  string plate;

  input1 >> rows >> cols;

  for (int i = 0; i < rows; i++) {
    parking_lot.push_back(init_int);
    for (int j = 0; j < cols; j++) {
      input1 >> car;
      parking_lot.at(i).push_back(car);
    }
  }

  input1.close();

  ifstream input2("license_plates.txt");
  for (int i = 0; i < rows; i++) {
    license_plates.push_back(init_string);
    for (int j = 0; j < cols; j++) {
      input2 >> plate;
      license_plates.at(i).push_back(plate);
    }
  }
  input2.close();
  return;
}

void print_info(int free_spaces, vector<string> illegal,
                vector<string> expired) {
  ofstream output("parking_output.txt");

  output << "There are " << free_spaces << " empty parking spaces in the lot\n";
  output << "There are " << illegal.size() << " cars parked illegally:\n";

  cout << "There are " << free_spaces << " empty parking spaces in the lot\n";
  cout << "There are " << illegal.size() << " cars parked illegally:\n";
  for (int i = 0; i < (int)illegal.size(); i++) {
    cout << '\t' << illegal.at(i) << '\n';
    output << '\t' << illegal.at(i) << '\n';
  }
  cout << "There are " << expired.size() << " cars with expired time:\n";
  output << "There are " << expired.size() << " cars with expired time:\n";
  for (int i = 0; i < (int)expired.size(); i++) {
    cout << '\t' << expired.at(i) << '\n';
    output << '\t' << expired.at(i) << '\n';
  }
  return;
}
