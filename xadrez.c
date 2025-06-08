#include <stdio.h>

void movimentosTorre(int linha, int coluna) {
    printf("\nMovimentos possíveis da Torre (%d, %d):\n", linha, coluna);

    // Movimento vertical (linha muda, coluna fixa)
    for (int i = 1; i <= 8; i++) {
        if (i != linha)
            printf("(%d, %d)\n", i, coluna);
    }

    // Movimento horizontal (coluna muda, linha fixa)
    int j = 1;
    while (j <= 8) {
        if (j != coluna)
            printf("(%d, %d)\n", linha, j);
        j++;
    }
}

void movimentosBispo(int linha, int coluna) {
    printf("\nMovimentos possíveis do Bispo (%d, %d):\n", linha, coluna);

    int i = 1;
    do {
        // Diagonal superior esquerda
        if (linha - i >= 1 && coluna - i >= 1)
            printf("(%d, %d)\n", linha - i, coluna - i);

        // Diagonal superior direita
        if (linha - i >= 1 && coluna + i <= 8)
            printf("(%d, %d)\n", linha - i, coluna + i);

        // Diagonal inferior esquerda
        if (linha + i <= 8 && coluna - i >= 1)
            printf("(%d, %d)\n", linha + i, coluna - i);

        // Diagonal inferior direita
        if (linha + i <= 8 && coluna + i <= 8)
            printf("(%d, %d)\n", linha + i, coluna + i);

        i++;
    } while (i <= 7);
}

void movimentosCavalo(int linha, int coluna) {
    printf("\nMovimentos possíveis do Cavalo (%d, %d):\n", linha, coluna);

    int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for (int i = 0; i < 8; i++) {
        int novaLinha = linha + dx[i];
        int novaColuna = coluna + dy[i];

        if (novaLinha >= 1 && novaLinha <= 8 && novaColuna >= 1 && novaColuna <= 8) {
            printf("(%d, %d)\n", novaLinha, novaColuna);
        }
    }
}

int main() {
    int peca, linha, coluna;

    printf("=== Simulador de Peças de Xadrez ===\n");
    printf("Escolha a peça:\n");
    printf("1 - Torre\n");
    printf("2 - Bispo\n");
    printf("3 - Cavalo\n");
    printf("Opção: ");
    scanf("%d", &peca);

    if (peca < 1 || peca > 3) {
        printf("Peça inválida.\n");
        return 1;
    }

    printf("Informe a posição da peça (linha e coluna de 1 a 8):\n");
    printf("Linha: ");
    scanf("%d", &linha);
    printf("Coluna: ");
    scanf("%d", &coluna);

    if (linha < 1 || linha > 8 || coluna < 1 || coluna > 8) {
        printf("Posição inválida no tabuleiro.\n");
        return 1;
    }

    switch (peca) {
        case 1:
            movimentosTorre(linha, coluna);
            break;
        case 2:
            movimentosBispo(linha, coluna);
            break;
        case 3:
            movimentosCavalo(linha, coluna);
            break;
    }

    return 0;
}
