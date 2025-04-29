#include <stdio.h>

// Tamanho do tabuleiro e dos navios
#define TAMANHO 10
#define TAM_NAVIO 3
#define NAVIO 3

// Função para verificar se as posições estão livres
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linhas[], int colunas[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linhas[i];
        int c = colunas[i];
        if (l < 0 || l >= TAMANHO || c < 0 || c >= TAMANHO || tabuleiro[l][c] == NAVIO) {
            return 0; // posição inválida ou ocupada
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linhas[], int colunas[]) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhas[i]][colunas[i]] = NAVIO;
    }
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // ----- NAVIO 1: Horizontal (linha 2, colunas 1 a 3) -----
    int navio1_linhas[] = {2, 2, 2};
    int navio1_colunas[] = {1, 2, 3};

    // ----- NAVIO 2: Vertical (coluna 5, linhas 4 a 6) -----
    int navio2_linhas[] = {4, 5, 6};
    int navio2_colunas[] = {5, 5, 5};

    // ----- NAVIO 3: Diagonal Principal (começando em 0,0 até 2,2) -----
    int navio3_linhas[] = {0, 1, 2};
    int navio3_colunas[] = {0, 1, 2};

    // ----- NAVIO 4: Diagonal Secundária (começando em 0,9 até 2,7) -----
    int navio4_linhas[] = {0, 1, 2};
    int navio4_colunas[] = {9, 8, 7};

    // Verifica e posiciona cada navio
    if (podePosicionar(tabuleiro, navio1_linhas, navio1_colunas))
        posicionarNavio(tabuleiro, navio1_linhas, navio1_colunas);

    if (podePosicionar(tabuleiro, navio2_linhas, navio2_colunas))
        posicionarNavio(tabuleiro, navio2_linhas, navio2_colunas);

    if (podePosicionar(tabuleiro, navio3_linhas, navio3_colunas))
        posicionarNavio(tabuleiro, navio3_linhas, navio3_colunas);

    if (podePosicionar(tabuleiro, navio4_linhas, navio4_colunas))
        posicionarNavio(tabuleiro, navio4_linhas, navio4_colunas);

    // Exibe o tabuleiro
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
