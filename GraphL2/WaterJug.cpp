#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

/*
Problem Statement:
You have three jugs with capacities of 12 gallons, 8 gallons, and 3 gallons, respectively.
You can fill, empty, or transfer water between jugs.
The goal is to measure exactly 1 gallon of water in any jug.
*/

struct State {
    int jug1, jug2, jug3;
    
    bool operator<(const State& other) const {
        return tie(jug1, jug2, jug3) < tie(other.jug1, other.jug2, other.jug3);
    }
};

class WaterJugProblem {
public:
    int capacities[3] = {12, 8, 3};
    State start = {0, 0, 0};

    set<State> getSuccessors(State state) {
        set<State> successors;

        // Fill each jug
        for (int i = 0; i < 3; i++) {
            State newState = state;
            if (i == 0) newState.jug1 = capacities[i];
            else if (i == 1) newState.jug2 = capacities[i];
            else newState.jug3 = capacities[i];
            successors.insert(newState);
        }

        // Empty each jug
        for (int i = 0; i < 3; i++) {
            State newState = state;
            if (i == 0) newState.jug1 = 0;
            else if (i == 1) newState.jug2 = 0;
            else newState.jug3 = 0;
            successors.insert(newState);
        }

        // Transfer water between jugs
        int jugs[3] = {state.jug1, state.jug2, state.jug3};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    State newState = state;
                    int transfer = min(jugs[i], capacities[j] - jugs[j]);
                    if (i == 0) newState.jug1 -= transfer;
                    if (i == 1) newState.jug2 -= transfer;
                    if (i == 2) newState.jug3 -= transfer;
                    if (j == 0) newState.jug1 += transfer;
                    if (j == 1) newState.jug2 += transfer;
                    if (j == 2) newState.jug3 += transfer;
                    successors.insert(newState);
                }
            }
        }

        return successors;
    }

    State bfs() {
        queue<State> q;
        set<State> visited;
        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            State state = q.front();
            q.pop();

            // Goal test: Check if any jug contains exactly 1 gallon
            if (state.jug1 == 1 || state.jug2 == 1 || state.jug3 == 1) {
                return state;
            }

            for (const State& successor : getSuccessors(state)) {
                if (visited.find(successor) == visited.end()) {
                    visited.insert(successor);
                    q.push(successor);
                }
            }
        }

        return {-1, -1, -1}; // No solution found
    }
};

int main() {
    WaterJugProblem problem;
    State solution = problem.bfs();
    cout << "Water Jug Solution: (" << solution.jug1 << ", " << solution.jug2 << ", " << solution.jug3 << ")" << endl;
    return 0;
}
