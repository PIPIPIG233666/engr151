#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Forward declarations
struct Rider;
class Bus;

// Define Rider struct
struct Rider {
    string startLocation;
    string endLocation;
};

// Define Bus class
class Bus {
public:
    // Constructor
    Bus(string n, vector<string> s, int i);

    // Member functions
    bool getOn(Rider rider);
    bool stopsAt(string dest);
    void drive();

private:
    // Member variables
    int id;
    string routeName;
    vector<string> stops;
    vector<string> riderDestinations;
    int capacity;
    int currentStop;
};


// Bus constructor implementation
Bus::Bus(string n, vector<string> s, int i) : id(i), routeName(n), stops(s), capacity(50), currentStop(0) {
    cout << "created bus " << id << " driving route " << routeName << endl;
}

// Bus member function implementations
bool Bus::getOn(Rider rider) {
    if (capacity >= 50) {
        return false;
    } else if (stops.at(currentStop) != rider.endLocation) {
        return false;
    } else if (!stopsAt(rider.endLocation)) {
        return false;
    } else {
        // Let the rider on
        riderDestinations.push_back(rider.endLocation);
        return true;
    }
}

bool Bus::stopsAt(string dest) {
    for (unsigned int i = 0; i < stops.size(); i++) {
        if (dest == stops.at(i)) {
            return true;
        }
    }
    return false;
}

void Bus::drive() {
    // Drive to the next stop
    currentStop = (currentStop + 1) % stops.size();

    // Check for anyone getting off
    int gotOff = 0;
    for (unsigned int i = 0; i < riderDestinations.size();) {
        // Check whether a rider is getting off at the current stop
        if (riderDestinations.at(i) == stops.at(currentStop)) {
            gotOff++;
            // Remove the ith rider
            riderDestinations.erase(riderDestinations.begin() + i);
        } else {
            i++;
        }
    }

    // Print out if people got off
    if (gotOff) {
        cout << gotOff << " people got off at " << stops.at(currentStop);
        cout << " from bus " << id << " driving route " << routeName << endl;
    }
    return;
}

// Function declarations
void readBus(vector<Bus>& buses);
void loadRiders(vector<Rider>& waitingRiders);
void moveBuses(vector<Bus>& buses);
void getOn(vector<Bus>& buses, vector<Rider>& riders);

int main() {
    // Declare an empty vector of type Bus called buses.
    vector<Bus> buses;

    // Read in bus data from file and store in buses
    readBus(buses);

    // Declare an empty vector of type Rider called riders.
    vector<Rider> riders;

    // Read in rider data from file and store in riders
    loadRiders(riders);

    while (riders.size()) {
        // Simulate all buses moving
        moveBuses(buses);
        // Try to have riders get on a bus
        getOn(buses, riders);
    }

    cout << "No more waiting riders!" << endl;
    return 0;
}

// Function implementations
void readBus(vector<Bus>& buses) {
    // Bus file format:
    // Routename numStops stop1 stop2 stop3 ...
    // ...
    ifstream bus_file("buses.txt");
    if (bus_file.fail()) {
        cerr << "failed to open bus file.\n";
        exit(1);
    }

    // Placeholder variables
    string routeName;
    int numStops;
    int id = 0;

    while (bus_file >> routeName >> numStops) {
        vector<string> stops;
        // Read in the list of stops the bus makes and store in stops
        for (int i = 0; i < numStops; ++i) {
            string stop;
            bus_file >> stop;
            stops.push_back(stop);
        }

        // Implement a Bus constructor so the following line runs
        // Take in a route name, a vector of strings, and an ID
        Bus temp(routeName, stops, id);
        buses.push_back(temp);
        // ID for the next bus will simply increase by one.
        id += 1;
    }
}

void loadRiders(vector<Rider>& waitingRiders) {
    // List of start dest pairs
    ifstream riders_file("riders.txt");
    if (riders_file.fail()) {
        cerr << "failed to open riders file.\n";
        exit(1);
    }

    string start, end;
    while (riders_file >> start >> end) {
        Rider tempRider;
        // Assign the appropriate members of tempRider
        // Assign start
        tempRider.startLocation = start;
        // Assign end
        tempRider.endLocation = end;
        waitingRiders.push_back(tempRider);
    }
}

void moveBuses(vector<Bus>& buses) {
    for (unsigned int i = 0; i < buses.size(); ++i) {
        // Pull out a single Bus and call your drive member function.
        buses[i].drive();
    }
}

void getOn(vector<Bus>& buses, vector<Rider>& riders) {
    // Loop through all waiting riders
    for (unsigned int r = 0; r < riders.size(); r++) {
        // Look at a specific Rider in the riders vector
        Rider rider = riders.at(r);

        // Loop through all possible buses.
        for (unsigned int b = 0; b < buses.size(); ++b) {
            // Pull out a single Bus and attempt to get the rider on
            // using the getOn member function of Bus.
            if (buses[b].getOn(rider)) {
                // Delete the rth element of riders and decrement r.
                riders.erase(riders.begin() + r--);
                cout << "A rider got on bus " << b << endl;
                break;  // For your practice: why break?
            }
        }
    }
}

