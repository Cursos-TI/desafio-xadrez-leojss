#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Simulação de movimentação das peças de xadrez utilizando diferentes estruturas de repetição

int main() {
    // Declaração de constantes para o número de casas
    const int CASAS_TORRE = 5;
    const int CASAS_BISPO = 5;
    const int CASAS_RAINHA = 8;
    
    printf("=== SIMULACAO DE MOVIMENTACAO DAS PECAS DE XADREZ ===\n\n");
    
    // TORRE: Movimento horizontal para a direita (5 casas) - usando FOR
    printf("Torre movendo 5 casas para a direita:\n");
    for (int i = 1; i <= CASAS_TORRE; i++) {
        printf("Direita\n");
    }
    printf("\n");
    
    // BISPO: Movimento diagonal para cima e direita (5 casas) - usando WHILE
    printf("Bispo movendo 5 casas na diagonal (cima e direita):\n");
    int casas_bispo = 1;
    while (casas_bispo <= CASAS_BISPO) {
        printf("Cima, Direita\n");
        casas_bispo++;
    }
    printf("\n");
    
    // RAINHA: Movimento horizontal para a esquerda (8 casas) - usando DO-WHILE
    printf("Rainha movendo 8 casas para a esquerda:\n");
    int casas_rainha = 1;
    do {
        printf("Esquerda\n");
        casas_rainha++;
    } while (casas_rainha <= CASAS_RAINHA);
    printf("\n");
    
    // CAVALO: Movimento em "L" (2 casas para baixo, 1 casa para a esquerda) - usando FOR e WHILE aninhados
    printf("Cavalo movendo em L (2 casas para baixo, 1 casa para a esquerda):\n");
    const int MOVIMENTOS_CAVALO = 2; // Duas etapas: primeiro baixo, depois esquerda
    
    for (int etapa = 1; etapa <= MOVIMENTOS_CAVALO; etapa++) {
        if (etapa == 1) {
            // Primeira etapa: 2 casas para baixo
            int casas_baixo = 1;
            while (casas_baixo <= 2) {
                printf("Baixo\n");
                casas_baixo++;
            }
        } else {
            // Segunda etapa: 1 casa para a esquerda
            int casas_esquerda = 1;
            while (casas_esquerda <= 1) {
                printf("Esquerda\n");
                casas_esquerda++;
            }
        }
    }
    printf("\n");
    
    printf("=== FIM DA SIMULACAO ===\n");
    
    return 0;
}
