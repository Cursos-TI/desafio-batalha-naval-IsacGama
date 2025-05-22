#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Inicializa o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Exibe o tabuleiro com diferentes marcadores
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == NAVIO)
                printf("3 ");
            else if (tabuleiro[i][j] == HABILIDADE)
                printf("5 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}

// Coloca navio fixo (tamanho 3) horizontal
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (coluna + i < TAM)
            tabuleiro[linha][coluna + i] = NAVIO;
    }
}

// Cria uma matriz de cone 5x5
void criarMatrizCone(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria uma matriz de cruz 5x5
void criarMatrizCruz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria uma matriz de octaedro (losango) 5x5
void criarMatrizOctaedro(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Aplica a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int matriz[5][5], int origemLinha, int origemColuna) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int linha = origemLinha - 2 + i;
            int coluna = origemColuna - 2 + j;

            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (matriz[i][j] == 1 && tabuleiro[linha][coluna] == AGUA) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[5][5], cruz[5][5], octaedro[5][5];

    inicializarTabuleiro(tabuleiro);

    // Posiciona navio de exemplo
    posicionarNavioHorizontal(tabuleiro, 1, 2);
    posicionarNavioHorizontal(tabuleiro, 4, 4);

    // Cria as matrizes das habilidades
    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    // Aplica cada habilidade em pontos diferentes do tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone no topo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // Octaedro mais embaixo

    // Exibe tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}