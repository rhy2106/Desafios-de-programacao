#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

const int MAXN = 50000;
const int LOG = 16;

vector<int> adj[MAXN];
int depth[MAXN];
int up[MAXN][LOG];
int in_time[MAXN], out_time[MAXN];
int timer;

void dfs(int v, int p) {
    in_time[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i < LOG; i++) {
        if (up[v][i-1] != -1) {
            up[v][i] = up[up[v][i-1]][i-1];
        } else {
            break;
        }
    }
    for (int u : adj[v]) {
        if (u != p) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
    out_time[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return in_time[u] <= in_time[v] && out_time[u] >= out_time[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    }
    if (is_ancestor(v, u)) {
        return v;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != -1 && !is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int main() {
    int N;
    cin >> N;

    vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
        cards[i]--;
    }

    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    timer = 0;
    fill(depth, depth + N, 0);
    fill(in_time, in_time + N, 0);
    fill(out_time, out_time + N, 0);
    for (int i = 0; i < N; i++) {
        fill(up[i], up[i] + LOG, -1);
    }

    dfs(0, -1);

    map<int, vector<int>> positions;
    for (int i = 0; i < N; i++) {
        positions[cards[i]].push_back(i);
    }

    long long total_points = 0;
    for (auto& p : positions) {
        if (p.second.size() == 2) {
            int u = p.second[0];
            int v = p.second[1];
            int ancestor = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[ancestor];
            total_points += dist;
        }
    }

    cout << total_points << endl;

    return 0;
}
