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
    float x, y;
} Ponto;

void change(int **array, int length)
{
    free(*array);

    *array = malloc(length * sizeof(int));
    if (*array == NULL)
        return;
    for (int i = 0 ; i < length ; i++)
        (*array)[i] = 1;
}

int main () {

    FILE *in=fopen("input.txt","r");

    // reading line by line, max 256 bytes
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    int linha = 0;
    int num_pontos = 0;

    num_pontos = atoi(fgets(buffer, MAX_LENGTH, in));
    Ponto pontos[num_pontos];

    while (fgets(buffer, MAX_LENGTH, in)) {
        if (linha != 0) {
            //char delim[] = " ";
            //char linebr[] = "\n";
            char *ptr = strtok(buffer, " ");
            pontos[linha].x = atof(ptr);
            ptr = strtok(NULL, " ");
            char *ycoord = strtok(ptr, "\n");
            pontos[linha].y = atof(ycoord);
            printf("ponto x: %f, ponto i: %f\n", pontos[linha].x, pontos[linha].y);
        }
        linha++;
    }

    // fechar o arquivo
    fclose(in);



    return 0;
}
