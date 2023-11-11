#include <iostream>
#include <chrono>
//asim sawafta
//202111479
using namespace std;
using namespace chrono;

long long factorialIterative(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}


long long factorialRecursive(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

int main() {
    
    
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout<< "The value is : "<< factorialIterative(n)<<endl;
    const int iterations = 10000; 

    //time for iterative
    auto startIterative = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        factorialIterative(n);
    }
    auto endIterative = high_resolution_clock::now();
    auto durationIterative = duration_cast<microseconds>(endIterative - startIterative);
    cout << "Time taken by iterative factorial: " << durationIterative.count() << " microseconds" << endl;

    //  time for recursive 
    auto startRecursive = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        factorialRecursive(n);
    }
    auto endRecursive = high_resolution_clock::now();
    auto durationRecursive = duration_cast<microseconds>(endRecursive - startRecursive);
    cout << "Time taken by recursive factorial: " << durationRecursive.count() << " microseconds" << endl;

return 0;
}