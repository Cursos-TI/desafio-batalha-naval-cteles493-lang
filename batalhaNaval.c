/**
 * Desafio de Batalha Naval - Solução Completa
 * * Este código implementa os três níveis do desafio (Novato, Aventureiro, Mestre)
 * utilizando vetores, matrizes e loops, conforme solicitado.
 */

// Inclui a biblioteca padrão de entrada e saída (Requisito Funcional Comum)
#include <stdio.h>

// ===================================================================
// CONSTANTES E FUNÇÕES AUXILIARES
// ===================================================================

// Constantes para os tamanhos dos tabuleiros
#define TAM_AVENTUREIRO 10
#define TAM_MESTRE 5 // O tamanho 5x5 é ideal para os padrões de exemplo

/**
 * @brief Função auxiliar para imprimir uma matriz (tabuleiro) no console.
 * Atende ao requisito de exibição clara e ao formato de exemplo.
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 * @param matriz A matriz a ser impressa (deve ser C99 VLA ou com
 * dimensões fixas, mas [linhas][colunas] é mais flexível).
 */
void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    // Utiliza estruturas de repetição aninhadas (loops aninhados)
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // Exemplo de comando de saída: printf("%d ", matriz[i][j]);
            printf("%d ", matriz[i][j]);
        }
        printf("\n"); // Pula para a próxima linha ao final de cada linha da matriz
    }
    printf("\n"); // Adiciona um espaço extra para legibilidade
}


// ===================================================================
// 🏅 NÍVEL NOVATO - Posicionamento Básico
// ===================================================================

/**
 * @brief Executa a lógica do Nível Novato.
 * Posiciona dois navios (H e V) e exibe suas coordenadas.
 */
void nivelNovato() {
    printf("🏅 NÍVEL NOVATO - Posicionamento e Coordenadas 🏅\n\n");

    // 1. Posicionamento dos Navios (Entrada de Dados Manual)
    // Usando "vetores bidimensionais" para armazenar as coordenadas [Parte][Linha, Coluna]
    
    // Navio 1: Horizontal (3 partes)
    int navioHorizontal[3][2] = {
        {1, 2}, // {Linha 1, Coluna 2}
        {1, 3}, // {Linha 1, Coluna 3}
        {1, 4}  // {Linha 1, Coluna 4}
    };
    int tamanhoNavioH = 3;

    // Navio 2: Vertical (4 partes)
    int navioVertical[4][2] = {
        {3, 6}, // {Linha 3, Coluna 6}
        {4, 6}, // {Linha 4, Coluna 6}
        {5, 6}, // {Linha 5, Coluna 6}
        {6, 6}  // {Linha 6, Coluna 6}
    };
    int tamanhoNavioV = 4;

    // 2. Exibição de Coordenadas (Saída de Dados)
    printf("Coordenadas do Navio Horizontal:\n");
    for (int i = 0; i < tamanhoNavioH; i++) {
        // Exibição clara usando printf
        printf("  Parte %d: (Linha: %d, Coluna: %d)\n",
               i + 1, navioHorizontal[i][0], navioHorizontal[i][1]);
    }
    
    printf("\nCoordenadas do Navio Vertical:\n");
    for (int i = 0; i < tamanhoNavioV; i++) {
        printf("  Parte %d: (Linha: %d, Coluna: %d)\n",
               i + 1, navioVertical[i][0], navioVertical[i][1]);
    }
    printf("\n");
}


// ===================================================================
// 🏅 NÍVEL AVENTUREIRO - Tabuleiro 10x10
// ===================================================================

/**
 * @brief Executa a lógica do Nível Aventureiro.
 * Posiciona quatro navios (H, V, 2x Diag) em um tabuleiro 10x10
 * e exibe o tabuleiro completo.
 */
void nivelAventureiro() {
    printf("🏅 NÍVEL AVENTUREIRO - Tabuleiro 10x10 🏅\n\n");

    // 1. Matriz 10x10: Implementação de uma matriz maior
    // Inicializa todo o tabuleiro com 0 (água)
    int tabuleiro[TAM_AVENTUREIRO][TAM_AVENTUREIRO] = {0};
    
    // 2. Posicionamento de Quatro Navios (Entrada Manual)
    // Onde 3 indica uma posição ocupada por navio

    // Navio 1: Horizontal (4 partes) na linha 1
    for (int j = 1; j <= 4; j++) {
        tabuleiro[1][j] = 3;
    }

    // Navio 2: Vertical (5 partes) na coluna 8
    for (int i = 3; i <= 7; i++) {
        tabuleiro[i][8] = 3;
    }

    // Navio 3: Posicionamento na Diagonal (3 partes, descendo p/ direita)
    // (3,1), (4,2), (5,3)
    for (int i = 0; i < 3; i++) {
        tabuleiro[3 + i][1 + i] = 3;
    }

    // Navio 4: Posicionamento na Diagonal (3 partes, subindo p/ direita)
    // (8,4), (7,5), (6,6)
    for (int i = 0; i < 3; i++) {
        tabuleiro[8 - i][4 + i] = 3;
    }

    // 3. Exibição do Tabuleiro Completo
    printf("Exibição do Tabuleiro 10x10 (0 = Água, 3 = Navio):\n");
    imprimirMatriz(TAM_AVENTUREIRO, TAM_AVENTUREIRO, tabuleiro);
}


// ===================================================================
// 🥇 NÍVEL MESTRE - Habilidades Especiais
// ===================================================================

/**
 * @brief Preenche e exibe a matriz de habilidade "Cone".
 * @param tabuleiro A matriz 5x5 para modificar.
 */
void exibirHabilidadeCone(int tabuleiro[TAM_MESTRE][TAM_MESTRE]) {
    printf("Habilidade: CONE (Padrão 3x5 do exemplo)\n");
    
    // Reinicializa o tabuleiro com 0s
    for (int i = 0; i < TAM_MESTRE; i++) {
        for (int j = 0; j < TAM_MESTRE; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Padrão de Habilidade: Cone (conforme exemplo 3x5, centralizado)
    // 0 0 1 0 0  (Linha 1)
    tabuleiro[1][2] = 1;
    // 0 1 1 1 0  (Linha 2)
    for (int j = 1; j <= 3; j++) {
        tabuleiro[2][j] = 1;
    }
    // 1 1 1 1 1  (Linha 3)
    for (int j = 0; j < TAM_MESTRE; j++) {
        tabuleiro[3][j] = 1;
    }
    
    imprimirMatriz(TAM_MESTRE, TAM_MESTRE, tabuleiro);
}

/**
 * @brief Preenche e exibe a matriz de habilidade "Octaedro".
 * @param tabuleiro A matriz 5x5 para modificar.
 */
void exibirHabilidadeOctaedro(int tabuleiro[TAM_MESTRE][TAM_MESTRE]) {
    printf("Habilidade: OCTAEDRO (Padrão 3x5 do exemplo)\n");

    // Reinicializa o tabuleiro com 0s
    for (int i = 0; i < TAM_MESTRE; i++) {
        for (int j = 0; j < TAM_MESTRE; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Padrão de Habilidade: Octaedro (conforme exemplo 3x5, centralizado)
    // 0 0 1 0 0  (Linha 1)
    tabuleiro[1][2] = 1;
    // 0 1 1 1 0  (Linha 2)
    for (int j = 1; j <= 3; j++) {
        tabuleiro[2][j] = 1;
    }
    // 0 0 1 0 0  (Linha 3)
    tabuleiro[3][2] = 1;

    imprimirMatriz(TAM_MESTRE, TAM_MESTRE, tabuleiro);
}

/**
 * @brief Preenche e exibe a matriz de habilidade "Cruz".
 * @param tabuleiro A matriz 5x5 para modificar.
 */
void exibirHabilidadeCruz(int tabuleiro[TAM_MESTRE][TAM_MESTRE]) {
    printf("Habilidade: CRUZ (Padrão 3x5 do exemplo)\n");

    // Reinicializa o tabuleiro com 0s
    for (int i = 0; i < TAM_MESTRE; i++) {
        for (int j = 0; j < TAM_MESTRE; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Padrão de Habilidade: Cruz (conforme exemplo 3x5, centralizado)
    // 0 0 1 0 0  (Linha 1)
    tabuleiro[1][2] = 1;
    // 1 1 1 1 1  (Linha 2)
    for (int j = 0; j < TAM_MESTRE; j++) {
        tabuleiro[2][j] = 1;
    }
    // 0 0 1 0 0  (Linha 3)
    tabuleiro[3][2] = 1;

    imprimirMatriz(TAM_MESTRE, TAM_MESTRE, tabuleiro);
}

/**
 * @brief Executa a lógica do Nível Mestre.
 * Define e exibe as matrizes de habilidades especiais.
 */
void nivelMestre() {
    printf("🥇 NÍVEL MESTRE - Habilidades Especiais (Matrizes 5x5) 🥇\n\n");
    
    // 1. Matrizes de Habilidades: 
    //    Cria uma única matriz 5x5 que será reutilizada
    int tabuleiroHabilidade[TAM_MESTRE][TAM_MESTRE];

    // 2. Padrões de Habilidade e Exibição
    //    Usa loops aninhados (dentro das funções) para preencher
    //    e exibir as áreas afetadas (0=não afetado, 1=afetado)
    
    exibirHabilidadeCone(tabuleiroHabilidade);
    exibirHabilidadeOctaedro(tabuleiroHabilidade);
    exibirHabilidadeCruz(tabuleiroHabilidade);
}


// ===================================================================
// FUNÇÃO PRINCIPAL (MAIN) - Execução do Desafio
// ===================================================================
int main() {
    printf("======================================\n");
    printf("🚀 INICIANDO DESAFIO BATALHA NAVAL 🚀\n");
    printf("======================================\n\n");
    
    // Executa cada nível em sequência
    nivelNovato();
    nivelAventureiro();
    nivelMestre();

    printf("======================================\n");
    printf("✅ DESAFIO CONCLUÍDO! ✅\n");
    printf("======================================\n");

    return 0; // Indica que o programa terminou com sucesso
}
