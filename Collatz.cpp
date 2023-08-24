#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <cstdlib>
#include <random>
#include <ctime>
#include <cmath>


using namespace std;

unordered_map<uint64_t, uint64_t> stepsMap; // Map to store numbers and their respective step counts
int getRandomNumber(int minValue, int maxValue);
uint64_t steps(uint64_t j);
uint64_t findNumberWithSteps(uint64_t k);

int bigCounter = 0;

bool isFast = true; // change to true if you want to find ANY number with target steps quickly, probably won't give you the smallest

int main() {
    uint64_t targetSteps = 0;  // Change this to the desired number of steps
    cout << "Enter target steps: " << endl;
    cin >> targetSteps;
    uint64_t result = findNumberWithSteps(targetSteps);
    if(isFast) {
        cout << "One of the numbers with " << targetSteps << " steps is: " << result << endl;
    } else {
        cout << "The smallest number with " << targetSteps << " steps is: " << result << endl;
    }
    return 0;
}

uint64_t steps(uint64_t n) {
    //cout << "STARTING NUMBER: " << n << endl; 
    uint64_t initialNumber = n;
    uint64_t counter = 0; // this is the counter
    while(n!=1) {
        if(n==0) exit(0);
        if (n%2==0) {            
            n/=2;
            // cout << "Divide" << endl;
            // cout << n << endl;fgsf
            } else {
            n = (n*3)+1;
            // cout << "Multiply" << endl;
            // cout << n << endl;
        }
        counter++;
        if (stepsMap.find(n) != stepsMap.end()) {
            counter += stepsMap[n];
            //stepsMap[n] = counter;
            break;
        }
    }
    if(counter >= bigCounter) {
        cout << "The total steps was: " << counter << " Given from number " << initialNumber << endl;
        bigCounter=counter;
    }
    return counter;
}

uint64_t findNumberWithSteps(uint64_t targetSteps) {
    int num = 1;
    while (true) {
        int numSteps = steps(num);
        stepsMap[num] = numSteps;
        if (numSteps == targetSteps) {
            return num;
        }
        if(isFast) {
            num+=getRandomNumber(1,fabs(targetSteps-bigCounter));
        } else {
            num++;
        }
    }
    
}

int getRandomNumber(int minValue, int maxValue) {
    std::random_device rd;  // Create a random_device to generate a seed
    std::mt19937 gen(rd()); // Use the seed from random_device for the Mersenne Twister engine
    std::uniform_int_distribution<int> distribution(minValue, maxValue); // Define the distribution
    std::cout << "Some words" << endl;
    return distribution(gen); // Generate and return a random number within the specified range
}