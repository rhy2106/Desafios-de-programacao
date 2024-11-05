#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> matriz;
vector<vector<bool>> visitados;
int N, M;

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visitados[startX][startY] = true;

    // Definindo os movimentos possíveis (cima, baixo, esquerda, direita)
    vector<pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : direcoes) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && matriz[nx][ny] == '.' && !visitados[nx][ny]) {
                visitados[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    matriz.resize(N, vector<char>(M));
    visitados.resize(N, vector<bool>(M, false));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matriz[i][j];
        }
    }
    
    int cont = 0;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (matriz[i][j] == '.' && !visitados[i][j]) {
                cont++;
                bfs(i, j);
            }
        }
    }
    
    cout << cont << endl;
    return 0;
}
