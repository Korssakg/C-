#include <stdio.h>
#include <stdlib.h>
#include "verifica_cubo.h"

extern int cubo[6][3][3];

int verifica_cubo() {
    // Abre o arquivo "teste_cubo" solicitado
    FILE *arquivo = fopen("teste_cubo", "r");
    
    // O arquivo existe?
    if (arquivo == NULL) {
        printf("Erro: Não foi possível abrir o arquivo 'teste_cubo'.\n");
        return 0; 
    }

    // Leitura das 6 faces do cubo mágico
    for (int face = 0; face < 6; face++) {
        for (int linha = 0; linha < 3; linha++) {
            for (int coluna = 0; coluna < 3; coluna++) {
                
                // arquivo funciona?
                if (fscanf(arquivo, "%d", &cubo[face][linha][coluna]) != 1) {
                    printf("Erro: O arquivo 'teste_cubo' está incompleto na Face %d.\n", face);
                    fclose(arquivo);
                    return 0; 
                }

                //  cor válida?
                if (cubo[face][linha][coluna] < 0 || cubo[face][linha][coluna] > 6) {
                    printf("Erro: Valor inválido (%d) na Face %d, Linha %d, Coluna %d.\n", 
                            cubo[face][linha][coluna], face, linha, coluna);
                    fclose(arquivo);
                    return 0;
                }
            }
        }
    }

    fclose(arquivo);
    printf("Cubo carregado e completo com sucesso!\n");
    return 1; 
}