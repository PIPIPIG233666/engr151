#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Data structure to hold fuel mass and resulting height
struct FuelHeight {
  double fuel_mass;
  double height;
};

// Function to partition the data for QuickSort
int partition(vector<FuelHeight>& data, int low, int high) {
  double pivot = data[high].height;
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (data[j].height <= pivot) {
      i++;
      swap(data[i], data[j]);
    }
  }

  swap(data[i + 1], data[high]);
  return i + 1;
}

// QuickSort algorithm
void quickSort(vector<FuelHeight>& data, int low, int high) {
  if (low < high) {
    int pivotIndex = partition(data, low, high);
    quickSort(data, low, pivotIndex - 1);
    quickSort(data, pivotIndex + 1, high);
  }
}

int main() {
  cout.precision(3);
  ifstream inF("init_opt.txt");
  // constants
  const double dt = 0.001, r_Earth = 6356, C_D = 0.500,
               A = 3.1415 * pow(6.6e-3 / 2, 2), h_tar = 2000;
  int T;
  double M_fuel, M_n, M_total, v_n = 0, M_payload, g_n, h_n = 0, v_esc, v_e,
                               roh_n;
  vector<double> lineVec;
  string line;
  while (getline(inF, line)) {
    // append the lines to a vector
    lineVec.push_back(stod(line));
  }
  // close the input file
  inF.close();

  // assign the vectors to corresponding variables
  T = lineVec[0];
  v_e = lineVec[1];
  M_payload = lineVec[2];

  roh_n = 1.225e6 * exp(-h_n / 9);
  g_n = 3.962e5 / pow(h_n + r_Earth, 2);
  double M_fuel_0 = 0;
  // maximum allowed fuel will be at g0
  double M_fuel_max = T / g_n;
  M_total = M_fuel_max;
  // cout << T << "\t" << g_n<<"\t" << airR<<"\t"<<M_fuel_max;
  // return 0;
  // mass starts with fuel
  M_n = M_total;
  // mass decreases by payload
  M_fuel = M_n - M_payload;
  roh_n = 1.225e6 * exp(-h_n / 9);
  bool exceed;
  double fuel_step = 500.0;  // Adjust this step size as needed
  vector<FuelHeight> fuel_height_data;

  while (fuel_step > 0.1) {
  bool heavy=false;
    while (abs(h_n - h_tar) != 5) {
      while (v_n >= 0) {
        M_fuel = M_n - M_payload;
        M_n -= (T * dt) / v_e;

        // out of fuel
        // thrust is zero
        if (M_fuel <= 0)
          T = 0;

        // return early if escape velocity is exceeded
        exceed = v_esc <= v_n;
        if (exceed) {
          cout << "Escape velocity reached";
          return 1;
        }

        // formulas from the spec
        h_n += v_n * dt;
        g_n = 3.962e5 / pow(h_n + r_Earth, 2);
        roh_n = 1.225e6 * exp(-h_n / 9);
        v_esc = sqrt(2 * g_n * (h_n + r_Earth));
        double airR = 1 / (2 * M_n) * roh_n * C_D * A * pow(v_n, 2);
        v_n += ((T / M_n) - g_n - airR) * dt;

        // testing output
        // cout << "v_n is: " << v_n << "\th_n is: " << h_n << "\tg_n is: " << g_n << "\tv_esc is: " << v_esc << endl;
      }
      if (heavy) {
        cout << "Rocket too heavy";
        return 1;
      }  // cout << "Test " << (i / 4) + 1 << ": " << h_n << endl;
    }
    if (!exceed && !heavy) {
      // If the rocket reached the target height and didn't become too heavy, store the data
      FuelHeight data;
      data.fuel_mass = M_fuel;
      data.height = h_n;
      fuel_height_data.push_back(data);
    }

    // Decrease the fuel mass for the next iteration
    fuel_step -= 100.0;  // Adjust this decrement as needed
                       // Sort the data using QuickSort
    quickSort(fuel_height_data, M_fuel_0, M_fuel_max);

    cout << fuel_height_data[0].fuel_mass;
  }
  return 0;
}

