#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Simulação de movimentação das peças de xadrez utilizando diferentes estruturas de repetição

// Função recursiva para movimento da Torre
void mover_torre(int casas_restantes) {
    if (casas_restantes <= 0) {
        return; // Caso base: não há mais casas para mover
    }
    printf("Direita\n");
    mover_torre(casas_restantes - 1); // Chamada recursiva
}

// Função recursiva para movimento da Rainha
void mover_rainha(int casas_restantes) {
    if (casas_restantes <= 0) {
        return; // Caso base: não há mais casas para mover
    }
    printf("Esquerda\n");
    mover_rainha(casas_restantes - 1); // Chamada recursiva
}

// Função recursiva para movimento do Bispo com loops aninhados
void mover_bispo_recursivo(int casas_restantes) {
    if (casas_restantes <= 0) {
        return; // Caso base: não há mais casas para mover
    }
    
    // Loops aninhados: externo para vertical, interno para horizontal.
    for (int vertical = 0; vertical < 1; vertical++) {
        for (int horizontal = 0; horizontal < 1; horizontal++) {
            printf("Cima, Direita\n");
        }
    }
    
    mover_bispo_recursivo(casas_restantes - 1); // Chamada recursiva.
}

int main() {
    // Declaração de constantes para o número de casas
    const int CASAS_TORRE = 5;
    const int CASAS_BISPO = 5;
    const int CASAS_RAINHA = 8;
    
    printf("=== SIMULACAO DE MOVIMENTACAO DAS PECAS DE XADREZ ===\n\n");
    
    // TORRE: Movimento horizontal para a direita (5 casas) - usando RECURSIVIDADE
    printf("Torre movendo 5 casas para a direita:\n");
    mover_torre(CASAS_TORRE);
    printf("\n");
    
    // BISPO: Movimento diagonal para cima e direita (5 casas) - usando RECURSIVIDADE e LOOPS ANINHADOS
    printf("Bispo movendo 5 casas na diagonal (cima e direita):\n");
    mover_bispo_recursivo(CASAS_BISPO);
    printf("\n");
    
    // RAINHA: Movimento horizontal para a esquerda (8 casas) - usando RECURSIVIDADE
    printf("Rainha movendo 8 casas para a esquerda:\n");
    mover_rainha(CASAS_RAINHA);
    printf("\n");
    
    // CAVALO: Movimento em "L" (2 casas para cima, 1 casa para a direita) - usando LOOPS COMPLEXOS com continue e break
    printf("Cavalo movendo em L (2 casas para cima, 1 casa para a direita):\n");
    
    int movimento_completo = 0;
    int fase = 1; // 1 = movimento para cima, 2 = movimento para direita
    int casas_movidas = 0;
    int max_casas_fase = 2; // Começa com 2 casas para cima
    
    for (int tentativa = 1; tentativa <= 10; tentativa++) { // Loop externo com limite de segurança
        if (movimento_completo) {
            break; // Sai do loop quando movimento estiver completo
        }
        
        for (int passo = 1; passo <= max_casas_fase; passo++) {
            if (fase == 1) {
                printf("Cima\n");
                casas_movidas++;
                
                if (casas_movidas >= 2) {
                    fase = 2; // Muda para fase de movimento para direita
                    max_casas_fase = 1; // Próxima fase terá apenas 1 casa
                    casas_movidas = 0;
                    continue; // Continua para próxima iteração
                }
            } else if (fase == 2) {
                printf("Direita\n");
                casas_movidas++;
                
                if (casas_movidas >= 1) {
                    movimento_completo = 1;
                    break; // Movimento do cavalo completo
                }
            }
        }
        
        if (fase == 2 && casas_movidas >= 1) {
            break; // Garante saída do loop externo
        }
    }
    printf("\n");
    
    printf("=== FIM DA SIMULACAO ===\n");
    
    return 0;
}
