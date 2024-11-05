#include <iostream>
#include <vector>
using namespace std;

struct Ponto {
    int x, y;
};

// Função para calcular o produto vetorial
int produtoVetorial(Ponto a, Ponto b, Ponto c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Função para verificar se o ponto p está dentro do triângulo formado por a, b e c
bool pontoDentro(Ponto a, Ponto b, Ponto c, Ponto p) {
    int d1 = produtoVetorial(a, b, p);
    int d2 = produtoVetorial(b, c, p);
    int d3 = produtoVetorial(c, a, p);
    
    // Verifica se todos os produtos vetoriais têm o mesmo sinal (ou são zero)
    return (d1 >= 0 && d2 >= 0 && d3 >= 0) || (d1 <= 0 && d2 <= 0 && d3 <= 0);
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<Ponto> pretos(N);
        vector<Ponto> brancos(M);
        
        // Leitura dos pontos pretos
        for (int i = 0; i < N; ++i) {
            cin >> pretos[i].x >> pretos[i].y;
        }
        
        // Leitura dos pontos brancos
        for (int i = 0; i < M; ++i) {
            cin >> brancos[i].x >> brancos[i].y;
        }
        
        long long somaEnergia = 0;
        
        // Gerar todos os triângulos formados pelos pontos pretos
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    int pontosBrancosDentro = 0;
                    
                    // Contar quantos pontos brancos estão dentro do triângulo
                    for (int b = 0; b < M; ++b) {
                        if (pontoDentro(pretos[i], pretos[j], pretos[k], brancos[b])) {
                            pontosBrancosDentro++;
                        }
                    }
                    
                    // Calcular a energia do triângulo e somar
                    somaEnergia += pontosBrancosDentro * pontosBrancosDentro;
                }
            }
        }
        
        // Imprimir o resultado para o caso de teste atual
        cout << somaEnergia << endl;
    }
    
    return 0;
}
