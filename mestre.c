#include <stdio.h>
#define TAM 10
#define TAM_HAB 5

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 3)
                printf(" N "); // Navio
            else if (tabuleiro[i][j] == 5)
                printf(" * "); // Área afetada pela habilidade
            else
                printf(" ~ "); // Água
        }
        printf("\n");
    }
    printf("\n");
}

// Função para sobrepor uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemX, int origemY) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int posX = origemX + i - TAM_HAB / 2;
            int posY = origemY + j - TAM_HAB / 2;
            if (posX >= 0 && posX < TAM && posY >= 0 && posY < TAM && habilidade[i][j] == 1 && tabuleiro[posX][posY] == 0) {
                tabuleiro[posX][posY] = 5;
            }
        }
    }
}

// Cria matriz de habilidade em forma de cone apontando para baixo
void criarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i >= j - TAM_HAB / 2 && i >= TAM_HAB / 2 - j)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz de habilidade em forma de cruz
void criarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria matriz de habilidade em forma de octaedro (losango)
void criarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posiciona 2 navios horizontais/verticais
    for (int i = 2; i < 5; i++) tabuleiro[1][i] = 3;         // Horizontal
    for (int i = 6; i < 9; i++) tabuleiro[i][7] = 3;         // Vertical

    // Posiciona 2 navios diagonais
    for (int i = 0; i < 3; i++) tabuleiro[3+i][3+i] = 3;     // Diagonal principal
    for (int i = 0; i < 3; i++) tabuleiro[8-i][i+1] = 3;     // Diagonal secundária

    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);

    // Imprimir resultado final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
