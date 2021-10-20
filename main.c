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

//Um objeto representando a distância entre dois pontos
typedef struct
{
    Ponto p1, p2;
    float d;
}Dist;

int compararX(const void* a, const void* b) {
    Ponto *p1 = (Ponto *) a;
    Ponto *p2 = (Ponto *) b;
    if(p1->x < p2->x) return(-1);
    if(p1->x == p2->x) return(0);
    if(p1->x > p2->x) return(1);
}

int compararY(const void* a, const void* b) {
    Ponto *p1 = (Ponto *) a;
    Ponto *p2 = (Ponto *) b;
    if(p1->y < p2->y) return(-1);
    if(p1->y == p2->y) return(0);
    if(p1->y > p2->y) return(1);
}

//Função que calcula a distância eucliana entre dois pontos
Dist distance(Ponto p1, Ponto p2)
{
    Dist d;
    d.d = sqrt(pow((p1.x - p2.x),2)+pow((p1.y - p2.y),2));
    d.p1 = p1;
    d.p2 = p2;
    return(d);
}

//Função que calcula a menor distância entre um array de pontos
Dist closest(Ponto X[], Ponto Y[], int tamanho)
{
    //Variáveis:
    Dist d; //É a distância que será retornado
    Dist d_esq; //Distância do lado esquerdo da divisão
    Dist d_dir; //Distância do lado direito da divisão

    Ponto mid; //Variável que vai receber o ponto do meio onde faz a divisão pra direita e esquerda

    int meio = tamanho/2; //Metade do vetor
    int impar = 0; //Flag pra saber se tamanho é ímpar


    //Caso base:
    //Se tiver 2 pontos, apenas retorna a distancia entre eles
    if(tamanho == 2)
    {
        d = distance(X[0],X[1]);
        return(d);
    }
    //Se tiver 3 pontos, calcula a distancia entre os 3 e retorna a menor distancia
    if(tamanho == 3)
    {
        Dist d1 = distance(X[0],X[1]);
        Dist d2 = distance(X[0],X[2]);
        Dist d3 = distance(X[1],X[2]);

        if(d1.d<d2.d && d1.d<d3.d) {return(d1);}//quando d1 menor

        if(d2.d<d1.d && d2.d<d3.d) {return(d2);}//quando d2 menor

        //Se chegou até aqui é porque d3 é menor
        return(d3);
    }

    //Divisão:
    //Pega o meio do vetor de ponto
    if(tamanho%2 != 0){impar = 1;}//quando é ímpar

    Ponto X_esq[meio+impar];
    Ponto X_dir[meio];

    Ponto Y_esq[meio+impar];
    Ponto Y_dir[meio];

    mid = X[meio+impar];

    for(int i=0; i<(meio+impar); i++) {X_esq[i] = X[i];}
    for(int i=0; i<meio;i++){X_dir[i] = X[meio+impar+i];}

    for(int i=0; i<meio+impar;i++) {Y_esq[i] = Y[i];}
    for(int i=0; i<meio;i++){Y_dir[i] = Y[meio+impar+i];}

    int tam_esq = meio+impar;
    int tam_dir = meio;
    d_esq = closest(X_esq, Y_esq, tam_esq);//Lado esquerdo
    d_dir = closest(X_dir, Y_dir, tam_dir);//Lado direito

    //Pega menor distância entre os dois
    if(d_esq.d < d_dir.d)
        {
            d = d_esq;
    }
    else {
            d = d_dir;
    }

    //Combina:
    Ponto S[tamanho]; //Vetor do retangulo
    int s_size = 0;

    for(int i=0; i<tamanho; i++)
    {
        if((Y->x >= mid.x-d.d)&&(Y->x <=  mid.x+d.d))
        {
            S[i] = Y[i];
            s_size++;
        }
    }

    for(int i=0; i < s_size; i++)
    {
        for(int j=i+1; j < s_size && ((S[j].y - S[i].y) < d.d);j++)
        {
            if ((distance(S[i],S[j])).d < d.d)
            {
                d = (distance(S[i],S[j]));
            }
        }
    }

    return (d);
}

int main () {

    //Start no tempo de execução
    Dist menor_dist;

    FILE *in=fopen("input.txt","r");

    // ler linha por linha, máximo 256 bytes
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    int linha = 0;
    int num_pontos = 0;

    num_pontos = atoi(fgets(buffer, MAX_LENGTH, in));
    Ponto pontos_ord_x[num_pontos];
    Ponto pontos_ord_y[num_pontos];

    while (fgets(buffer, MAX_LENGTH, in)) {
        //char delim[] = " ";
        //char linebr[] = "\n";
        char *xcoord = strtok(buffer, " ");
        pontos_ord_x[linha].x = atof(xcoord);
        pontos_ord_y[linha].x = atof(xcoord);
        xcoord = strtok(NULL, " ");
        char *ycoord = strtok(xcoord, "\n");
        pontos_ord_x[linha].y = atof(ycoord);
        pontos_ord_y[linha].y = atof(ycoord);
        printf("ponto x: %f, ponto i: %f\n", pontos_ord_x[linha].x, pontos_ord_x[linha].y);
        linha++;
    }

    // fechar o arquivo
    fclose(in);

    //Ordena os pontos pela coordenada x e salva em um vetor X
    qsort(pontos_ord_x, num_pontos, sizeof(Ponto), compararX);

    //Ordena os pontos pela coordenada y e salva em um vetor Y
    qsort(pontos_ord_y, num_pontos, sizeof(Ponto), compararY);

    //Chama a função que pega a menor distância
    menor_dist = closest(pontos_ord_x, pontos_ord_y, num_pontos);

    //Para tempo de execução

    //Printa saída (tempo distância x1 y1 x2 y2)
    printf("tempo %f %f %f %f %f\n", menor_dist.d, menor_dist.p1.x, menor_dist.p1.y, menor_dist.p2.x, menor_dist.p2.y);

    return 0;
}
