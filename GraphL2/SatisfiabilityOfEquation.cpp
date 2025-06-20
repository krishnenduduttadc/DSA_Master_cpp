#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> parent(26);
vector<int> rank_map(26);

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    int temp = find(parent[x]);
    parent[x] = temp;
    return temp;
}

void unionSets(int x, int y) {
    int lx = find(x);
    int ly = find(y);
    
    if (lx != ly) {
        if (rank_map[lx] > rank_map[ly]) {
            parent[ly] = lx;
        } else if (rank_map[lx] < rank_map[ly]) {
            parent[lx] = ly;
        } else {
            parent[lx] = ly;
            rank_map[ly]++;
        }
    }
}

bool equationsPossible(vector<string>& equations) {
    for (int i = 0; i < 26; ++i) {
        parent[i] = i;
        rank_map[i] = 1;
    }

    for (string e : equations) {
        if (e[1] == '=') {
            unionSets(e[0] - 'a', e[3] - 'a');
        }
    }

    for (string eqn : equations) {
        if (eqn[1] == '!') {
            int lx = find(eqn[0] - 'a');
            int ly = find(eqn[3] - 'a');
            if (lx == ly) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<string> equations = {"b==c", "c!=b"};
    cout << (equationsPossible(equations) ? "true" : "false") << endl;
    return 0;
}
