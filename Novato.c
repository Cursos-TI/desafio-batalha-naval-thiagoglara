#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10
// Valor que representa um navio
#define NAVIO 3
// Tamanho dos navios
#define TAM_NAVIO 3

int main() {
    // Declaração e inicialização do tabuleiro com zeros (água)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Coordenadas iniciais dos navios (linha e coluna)
    // Navio horizontal começa na linha 2, coluna 1
    int linha_horizontal = 2, coluna_horizontal = 1;
    // Navio vertical começa na linha 5, coluna 4
    int linha_vertical = 5, coluna_vertical = 4;

    // Validação de limites para o navio horizontal
    if (coluna_horizontal + TAM_NAVIO <= TAMANHO) {
        // Verifica se há sobreposição
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio horizontal no tabuleiro
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
            }
        }
    }

    // Validação de limites para o navio vertical
    if (linha_vertical + TAM_NAVIO <= TAMANHO) {
        // Verifica se há sobreposição
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // Posiciona o navio vertical no tabuleiro
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
            }
        }
    }

    // Exibe o tabuleiro no console
    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
