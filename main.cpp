/*Project 1
    Name: Andrewdai Truong and Stephany Murillo Munoz
    Algorithm 2: Greedy Approach to Hamiltonian Problem
    Class: CPSC-335-06
-------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

int getStartingCity();
int traverseCity(int start);

using namespace std;

// Own created sample using the same city_distanes from document
vector<int> city_distances = {5, 25, 15, 10, 15};
vector<int> fuel = {1, 3, 2, 2, 4};
int mpg = 10;

int main() {
    int preferredCity = getStartingCity();
    cout << "The starting city is " << preferredCity + 1 << endl;

    traverseCity(preferredCity);

    return 0;
}

int getStartingCity() {
    int n;
    cout << "Choose preferred starting city (1-5): ";
    cin >> n;
    if (n < 1 || n > 5)
        throw out_of_range("ERROR: Input must be between 1 and 5");
    
    return n - 1;
}

int traverseCity(int start){
    int remainingFuel = 0;
    int size = city_distances.size();

    for (int i = 0; i < size + 1; i++) {
        int currentCity = (start + i) % size; // city wrapping
        int fuelGain = fuel[currentCity] * mpg;
        int fuelLoss = city_distances[currentCity];

        remainingFuel += fuelGain - fuelLoss;

        cout << "City " << currentCity + 1 << ": Gained " << fuelGain << " fuel." << endl;
        cout << "Lost: " << fuelLoss << " fuel." << endl;
        cout << "Remaining Fuel: " << remainingFuel << endl << endl;

        if (remainingFuel < 0) {
            throw runtime_error("ERROR: Remaining Fuel is under 0. Car will not be able to traverse any further than city " 
                + to_string(currentCity + 1));
        }
    }

    return remainingFuel;
}