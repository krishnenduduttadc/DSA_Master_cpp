#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to be optimized (hill climbing searches for max value)
double function(double x) {
    return -(x - 3) * (x - 3) + 9;  // A simple parabola with a peak at x=3
}

// Hill climbing algorithm
double hillClimb(double start, double stepSize, int maxIterations) {
    double current = start;
    double currentValue = function(current);

    for (int i = 0; i < maxIterations; i++) {
        double next = current + ((rand() % 2 == 0) ? stepSize : -stepSize); // Move left or right
        double nextValue = function(next);

        if (nextValue > currentValue) { // Move only if better
            current = next;
            currentValue = nextValue;
        }
    }

    return current;
}

int main() {
    srand(time(0)); // Seed for randomness

    double startPoint = 0.0;     // Hardcoded starting point
    double stepSize = 0.1;       // Step size for movement
    int maxIterations = 1000;    // Number of iterations

    double result = hillClimb(startPoint, stepSize, maxIterations);
    cout << "Optimal solution found at x = " << result << " with f(x) = " << function(result) << endl;

    return 0;
}
