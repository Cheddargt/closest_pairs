/* ALUNOS */
/* GUSTAVO HENRIQUE ZENI - RA: 1985370 */
/* IANCA POLIZELO - RA: 1985388 */
/* VITOR GABRIEL ANDRADE TEIXEIRA - RA: 1655655 */

#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

// TODO: ler o input.txt

// criar um vetor de pontos
// adicionar todos os pontos ao vetor
// ordenar usando merge-sort

// Um objeto representando um ponto
typedef struct
{
    int x, y;
} Ponto;

int main () {

    FILE *in=fopen("input.txt","r");

    // reading line by line, max 256 bytes
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    int linha = 0;
    int num_pontos = 0;
    char delim[] = " ";
    Ponto pontos[100];

    while (fgets(buffer, MAX_LENGTH, in)) {
        if (linha == 0) {
            num_pontos = atoi(buffer);
        } else {
            char *ptr = strtok(buffer, delim);
            pontos[linha].x = atof(*ptr);
            ptr = strtok(NULL, delim);
            pontos[linha].y = atof(*ptr);
            printf("ponto x: %i, ponto i: %i\n", pontos[linha].x, pontos[linha].y);
        }
        linha++;
    }

    // fechar o arquivo
    fclose(in);

    return 0;
}
