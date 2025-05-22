#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Inicializa o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Exibe o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se há espaço livre para qualquer tipo de navio
int verificarEspacoLivre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int coordenadas[][2], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int linha = coordenadas[i][0];
        int coluna = coordenadas[i][1];

        if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO)
            return 0; // Fora do tabuleiro

        if (tabuleiro[linha][coluna] != AGUA)
            return 0; // Já tem navio aqui
    }
    return 1;
}

// Posiciona qualquer tipo de navio dado suas coordenadas
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int coordenadas[][2], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int linha = coordenadas[i][0];
        int coluna = coordenadas[i][1];
        tabuleiro[linha][coluna] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas dos 4 navios
    int navioHorizontal[3][2] = {{1, 2}, {1, 3}, {1, 4}};         // → Horizontal
    int navioVertical[3][2] = {{3, 6}, {4, 6}, {5, 6}};           // ↓ Vertical
    int navioDiagonal1[3][2] = {{6, 1}, {7, 2}, {8, 3}};          // ↘ Diagonal principal
    int navioDiagonal2[3][2] = {{3, 7}, {4, 6}, {5, 5}};          // ↙ Diagonal secundária (vai colidir com vertical!)

    // Tenta posicionar e valida sobreposição
    if (verificarEspacoLivre(tabuleiro, navioHorizontal, TAMANHO_NAVIO))
        posicionarNavio(tabuleiro, navioHorizontal, TAMANHO_NAVIO);
    else
        printf("Erro ao posicionar navio horizontal.\n");

    if (verificarEspacoLivre(tabuleiro, navioVertical, TAMANHO_NAVIO))
        posicionarNavio(tabuleiro, navioVertical, TAMANHO_NAVIO);
    else
        printf("Erro ao posicionar navio vertical.\n");

    if (verificarEspacoLivre(tabuleiro, navioDiagonal1, TAMANHO_NAVIO))
        posicionarNavio(tabuleiro, navioDiagonal1, TAMANHO_NAVIO);
    else
        printf("Erro ao posicionar navio diagonal ↘.\n");

    if (verificarEspacoLivre(tabuleiro, navioDiagonal2, TAMANHO_NAVIO))
        posicionarNavio(tabuleiro, navioDiagonal2, TAMANHO_NAVIO);
    else
        printf("Erro ao posicionar navio diagonal ↙.\n");

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}