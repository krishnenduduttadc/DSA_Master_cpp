#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

struct State {
    int jug1, jug2, jug3;
    bool operator<(const State& other) const {
        return tie(jug1, jug2, jug3) < tie(other.jug1, other.jug2, other.jug3);
    }
};

const int cap[3] = {12, 8, 3};

set<State> getSuccessors(State state) {
    set<State> successors;

    int jugs[3] = {state.jug1, state.jug2, state.jug3};

    // Fill any jug
    for (int i = 0; i < 3; ++i) {
        State newState = state;
        if (i == 0) newState.jug1 = cap[i];
        else if (i == 1) newState.jug2 = cap[i];
        else newState.jug3 = cap[i];
        successors.insert(newState);
    }

    // Empty any jug
    for (int i = 0; i < 3; ++i) {
        State newState = state;
        if (i == 0) newState.jug1 = 0;
        else if (i == 1) newState.jug2 = 0;
        else newState.jug3 = 0;
        successors.insert(newState);
    }

    // Pour from one jug to another
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;

            int src = jugs[i];
            int dst = jugs[j];
            int pour = min(src, cap[j] - dst);

            if (pour > 0) {
                State newState = state;
                if (i == 0) newState.jug1 -= pour;
                if (i == 1) newState.jug2 -= pour;
                if (i == 2) newState.jug3 -= pour;

                if (j == 0) newState.jug1 += pour;
                if (j == 1) newState.jug2 += pour;
                if (j == 2) newState.jug3 += pour;

                successors.insert(newState);
            }
        }
    }

    return successors;
}

State bfs() {
    State start = {0, 0, 0};
    queue<State> q;
    set<State> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.jug1 == 1 || current.jug2 == 1 || current.jug3 == 1) {
            return current;
        }

        set<State> successors = getSuccessors(current);
        for (const State& next : successors) {
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push(next);
            }
        }
    }

    return {-1, -1, -1}; // No solution
}

int main() {
    State result = bfs();
    if (result.jug1 == -1) {
        cout << "No solution found." << endl;
    } else {
        cout << "Solution state: (" << result.jug1 << ", " << result.jug2 << ", " << result.jug3 << ")" << endl;
    }
    return 0;
}
