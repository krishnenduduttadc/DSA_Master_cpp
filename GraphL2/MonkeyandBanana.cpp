#include <bits/stdc++.h>


using namespace std;

/*
Problem Statement:
A 3-foot-tall monkey is in a room where bananas are suspended from the 8-foot ceiling.
The monkey wants to reach the bananas.
There are two stackable 3-foot-high crates in the room.
The monkey can move crates, stack them, and climb to reach the bananas.
The goal is for the monkey to reach a height of 8 feet.
*/

struct State {
    int monkeyHeight;
    bool cratesStacked;

    bool operator<(const State& other) const {
        return tie(monkeyHeight, cratesStacked) < tie(other.monkeyHeight, other.cratesStacked);
    }
};

class MonkeyBananaProblem {
public:
    State start = {3, false}; // Monkey starts at 3 feet, crates are not stacked
    int goal = 8; // Monkey needs to reach 8 feet

    set<State> getSuccessors(State state) {
        set<State> successors;

        // Stack crates if not already stacked
        if (!state.cratesStacked) {
            successors.insert({state.monkeyHeight + 3, true});
        }

        // Climb onto stacked crates
        if (state.cratesStacked && state.monkeyHeight < goal) {
            successors.insert({goal, true});
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

            // Goal test: If monkey reaches 8 feet
            if (state.monkeyHeight == goal) {
                return state;
            }

            for (const State& successor : getSuccessors(state)) {
                if (visited.find(successor) == visited.end()) {
                    visited.insert(successor);
                    q.push(successor);
                }
            }
        }

        return {-1, false}; // No solution found
    }
};

int main() {
    MonkeyBananaProblem problem;
    State solution = problem.bfs();
    cout << "Monkey Banana Solution: Monkey Height = " << solution.monkeyHeight << ", Crates Stacked = " << solution.cratesStacked << endl;
    return 0;
}
