#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <cstdlib>
#include <time.h>

using namespace std;

unordered_map<uint64_t, uint64_t> stepsMap; // Map to store numbers and their respective step counts

uint64_t steps(uint64_t j);
uint64_t findNumberWithSteps(uint64_t k);

int bigCounter = 0;

int main() {
    uint64_t targetSteps = 0;  // Change this to the desired number of steps
    cout << "Enter target steps: " << endl;
    cin >> targetSteps;
    uint64_t result = findNumberWithSteps(targetSteps);
    cout << "The smallest number with " << targetSteps << " steps is: " << result << endl;
    cout << "BLAH!" << endl;
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
            // cout << n << endl;
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
        num+=rand();
    }
    
}