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

// ctrl + c, ctrl + v
void insertionSort_x(Ponto arr[], int n)
{
    int i, j;
    Ponto key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        // coordenadas em x
        while (j >= 0 && arr[j].x > key.x) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSort_y(Ponto arr[], int n)
{
    int i, j;
    Ponto key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        // coordenadas em x
        while (j >= 0 && arr[j].y > key.y) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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

    // mudar pra merge-sort
    insertionSort_x(pontos, num_pontos);
    printf("----------- insertion sort ------------");
    for (int i = 0; i < num_pontos; i++) {
        printf("ponto x: %f, ponto i: %f\n", pontos[i].x, pontos[i].y);
    }



    return 0;
}
