/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

char const VAZIO = '.';
char const PREENCHER = 'x';
char const MARK = '!';
int const PERCA_MAX = 3;

int procurarElementoVer(char *matriz, int i, int a, int l, char elemento, int ignore) {
    int j;
    for (j = 0; j < a; j++) {
        if ((matriz[j * a + i] == elemento) && (j != ignore)) {
            return j;
        }
    }
    return -1;
}

int procurarElementoHor(char *matriz, int i, int a, int l, char elemento, int ignore) {
    int j;
    for (j = 0; j < l; j++) {
        if ((matriz[i * l + j] == elemento) && (j != ignore)) {
            return j;
        }
    }
    return -1;
}

int procurarIElemento(char *matriz, int a, int l, int aSubM, int lSubM, int iS, int jS, char numero) {
    int i, j;
    for (i = iS; i < iS + aSubM; i++) {
        for (j = jS; j < jS + lSubM; j++) {
            if (matriz[i * l + j] == numero) return i;
        }
    }
    return -1;
}

int procurarJElemento(char *matriz, int a, int l, int aSubM, int lSubM, int iS, int jS, char numero) {
    int i, j;
    for (i = iS; i < iS + aSubM; i++) {
        for (j = jS; j < jS + lSubM; j++) {
            if (matriz[i * l + j] == numero) return j;
        }
    }
    return -1;
}

int converterIntToNum(int numero) {
    return numero + 48;
}

int verificarCompletudeHor(int jS, char *matriz, int i, int a, int l, int aSubM, int lSubM) {
    int j;
    for (j = jS; j < l; j++) {
        if (matriz[i * l + j] < converterIntToNum(1) || matriz[i * l + j] > converterIntToNum(aSubM * lSubM))
            return 0;
    }
    return 1;
}

void zerarMatriz(char *matriz, int a, int l) {
    int i,j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < l; j++) {
            matriz[i * l + j] = VAZIO;
        }
    }
}

void imprimirMatriz(char *matriz, int a, int l) {
    int i,j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < l; j++) {
            printf(" %c", matriz[i * l + j]);
        }
        printf("\n");
    }
}
/*
void imprimirSudoku(char *matriz) {
    int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            imprimirMatriz(&matriz[i * 3 + j], 3, 3);
        }
        printf("\n------------------\n");
    }
}
*/

void intersecionarMatrizes(char *matriz, int a, int l, char *submatriz, int aSubM, int lSubM, int iS, int jS) {
    int i,j;
    for (i = 0; i < aSubM; i++) {
        for (j = 0; j < lSubM; j++) {
            matriz[(iS + i) * l + (jS + j)] = submatriz[i * lSubM + j];
        }
    }
}

void subtrairMatrizes(char *matriz, int a, int l, char *submatriz, int aSubM, int lSubM, int iS, int jS) {
    int i,j;
    for (i = 0; i < aSubM; i++) {
        for (j = 0; j < lSubM; j++) {
            submatriz[i * lSubM + j] = matriz[(iS + i) * l + (jS + j)];
        }
    }
}
/*
void substituirElemento(char *matriz, int a, int l, int aSubM, int lSubM, int iS, int jS, char symbol1, char symbol2) {
    int i,j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < l; j++) {
            switch (matriz[(iS + i) * l + (jS + j)]) {
                case '.':
                    matriz[(iS + i) * l + (jS + j)] = symbol2;
                    break;
                case 'x':
                    matriz[(iS + i) * l + (jS + j)] = symbol1;
                    break;
            }
        }
    }
}
*/
int converterNumToInt(char numero) {
    return numero - 48;
}

int avancarI(int i, int j, int jMax) {
    if (j == jMax) return ++i;
}

int avancarJ(int i, int j, int jMax) {
    if (j < jMax) return ++j;
    else return 0;
}

int validarEscolha(char *matriz, int a, int l, int aSubM, int lSubM, int i, int j, int iS, int jS, char numero) {
    if (procurarElementoHor(matriz, i, a, l, numero, -1) >= 0 || procurarElementoVer(matriz, j, a, l, numero, -1) >= 0 || procurarIElemento(matriz, a, l, aSubM, lSubM, iS, jS, numero) >= 0 || (/*matriz[i * l + j] != numero && */matriz[i * l + j] != VAZIO && matriz[i * l + j] != PREENCHER) /*|| verificarCancelamento(matriz, a, l, avancarI(i, j, lSubM - 1) * aSubM, avancarJ(i, j, lSubM - 1) * lSubM, aSubM, lSubM, numero)*/)
        return 0;
    return 1;
}

void retrocederIJ(int *i, int *j, int jMax) {
    if (j[0] > 0) {
        j[0]--;
    } else {
        i[0]--;
        j[0] = jMax;
    }
    printf(" Retrocedido!\n");
}

void eliminarOcorrencias(char *matriz, int a, int l, int iS, int jS, int aSubM, int lSubM, char numero) {
    int i, j;
    for (i = iS; i < iS + aSubM; i++) {
        for (j = jS; j < jS + lSubM; j++) {
            if (matriz[i * l + j] == numero) matriz[i * l + j] = VAZIO;
        }
    }
}

void imprimirMatrizMesclada(char *matriz, int a, int l, int aSubM, int lSubM, int iS, int jS, char canvas, char replace) {
    int i,j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < l; j++) {
            if (i >= iS && i < iS + aSubM && j >= jS && j < jS + lSubM) {
                if (matriz[i * l + j] != canvas)
                    printf(" %c", matriz[i * l + j]);
                else printf(" %c", replace);
            } else printf(" %c", matriz[i * l + j]);
        }
        printf("\n");
    }
}

int contarPossibilidades(char *matriz, int a, int l, int aSubM, int lSubM, int iS, int jS, char numero) {
    int soma = 0;
    int i, j;
    for (i = iS; i < iS + aSubM; i++) {
        for (j = jS; j < jS + lSubM; j++) {
            soma += validarEscolha(matriz, a, l, aSubM, lSubM, i, j, iS, jS, numero);
        }
    }
    return soma;
}

void pedirIJ(char *matriz, int a, int l, int aSubM, int lSubM, int iS, int jS, char numero, char *linhacoluna, int *y, int *x) {
    eliminarOcorrencias(matriz, a, l, iS, jS, aSubM, lSubM, numero);
    //printf(" Possibilidades: %d\n", contarPossibilidades(matriz, a, l, aSubM, lSubM, iS, jS, numero));
    //imprimirMatrizMesclada(matriz, a, l, aSubM, lSubM, iS, jS, VAZIO, PREENCHER);
    //printf(" Informe linha e coluna nessa ordem e sem espaco: ");
    /*
    scanf("%s", linhacoluna);
    y[0] = converterNumToInt(linhacoluna[0]) - 1;
    x[0] = converterNumToInt(linhacoluna[1]) - 1;
    */
    y[0] = rand() % aSubM;
    x[0] = rand() % lSubM;
    //printf(" %d, %d\n", y[0] + 1, x[0] + 1);
    if (!validarEscolha(matriz, a, l, aSubM, lSubM, iS + y[0], jS + x[0], iS, jS, numero)) {
        //printf(" Posicao invalida\n");
        //getchar();
    }
    //system("clear");
}

void pedirEscolha(char *matriz, int a, int l, int aSubM, int lSubM, int iS, int jS, char *choice, char numero) {
    //srand(time(NULL));
    //system("clear");
    //imprimirMatrizMesclada(matriz, a, l, aSubM, lSubM, iS, jS, VAZIO, PREENCHER);
    printf(" Numero: %c\n", numero);
    printf(" Quer colocar o numero nessa submatriz, s ou n: ");
    //scanf("%s", choice);
    choice[0] = 115 * (rand() % 2);
    printf(" Escolha: %c\n", choice[0]);
}

int verificarCancelamento(char *matriz, int a, int l, int iS, int jS, int aSubM, int lSubM, char numero) {
    /*
    int i,j;
    for (i = 0; i < aSubM; i++) {
        for (j = 0; j < lSubM; j++) {
            if (matriz[(iS + i) * l + (jS + j)] == VAZIO || matriz[(iS + i) * l + (jS + j)] == numero)
                if (procurarElementoHor(matriz, iS + i, a, l, numero, jS + j) <= -1 && procurarElementoVer(matriz, jS + j, a, l, numero, iS + i) <= -1)
                    return 0;
        }
    }
    */
    return !contarPossibilidades(matriz, a, l, aSubM, lSubM, iS, jS, numero);
}
/*
int procurarSubmatrizGenerosa(char *matriz, int a, int l, int aSubM, int lSubM, char numero, int possib) {
    int i,j;
    for (i = 0; i < aSubM; i++) {
        for (j = 0; j < lSubM; j++) {
            if (contarPossibilidades(matriz, a, l, aSubM, lSubM, i, j, numero) >= possib) return (i * lSubM + j);
        }
    }
}
*/
int procurarISubmatrizGenerosa(char *matriz, int a, int l, int aSubM, int lSubM, char numero, int possib) {
    int i,j;
    for (i = 0; i < a / aSubM; i++) {
        for (j = 0; j < l / lSubM; j++) {
            if (contarPossibilidades(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, numero) == possib) return i;
        }
    }
    return -1;
}

int procurarJSubmatrizGenerosa(char *matriz, int a, int l, int aSubM, int lSubM, char numero, int possib) {
    int i,j;
    for (i = 0; i < a / aSubM; i++) {
        for (j = 0; j < l / lSubM; j++) {
            if (contarPossibilidades(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, numero) == possib) return j;
        }
    }
    return -1;
}

int verificarCancelamentoLinha(char *matriz, int a, int l, int i, char numero) {
    return !contarPossibilidades(matriz, a, l, 1, l, i, 0, numero);
}

int verificarCancelamentoColuna(char *matriz, int a, int l, int j, char numero) {
    return !contarPossibilidades(matriz, a, l, a, 1, 0, j, numero);
}

int verificarCancelamentoCompleto(char *matriz, int a, int l, int aSubM, int lSubM) {
    int i, j, n;
    for (n = 1; n <= aSubM * lSubM; n++)
        for (i = 0; i < a/aSubM; i++)
            for (j = 0; j < l/lSubM; j++)
                if (verificarCancelamento(matriz, a, l, i * aSubM, j * lSubM, aSubM, lSubM, converterIntToNum(n)) && procurarIElemento(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, converterIntToNum(n)) <= -1)
                    return 1;
    return 0;
}

void popularMatrizSudokuCompleto(char *matriz, int a, int l, int aSubM, int lSubM, int iS, int jS, int tMax) {
    srand(time(NULL));
    /*
    if (aSubM > 1 && lSubM > 1) {
        int i,j;
        for (i = iStart; i < a / aSubM; i++) {
            for (j = jStart; j < l / lSubM; j++) {
                do {
                    // algoritmo de popular submatriz
                    popularMatrizSudoku(matriz, i * aSubM, j * lSubM, aSubM * (i + 1), lSubM * (j + 1), lSubM, 1, 1);
                } while ((procurarElementoHor(matriz, i, a, l, elemento, j) > -1) || (procurarElementoVer(matriz, j, a, l, elemento, i) > -1) || (procurarElementoSubmatriz(matriz, a, l, ) > -1));
            }
        }
    }
    */
    int i, j, n;
    for (n = 1; n <= aSubM * lSubM; n++) {
        if (n == 1) srand(time(NULL));
        int tries = 0;
        for (i = 0; i < a / aSubM; i++) {
            for (j = 0; j < l / lSubM; j++) {
                char linhacoluna[2];
                int y = 0;
                int x = 0;
                /*
                zerarMatriz(submatriz, aSubM, lSubM);
                popularSubmatrizSudoku(matriz, submatriz, aSubM, lSubM, i * aSubM, j * lSubM);
                intersecionarMatrizes(matriz, a, l, submatriz, aSubM, lSubM, i * aSubM, j * lSubM);
                */
                if (verificarCancelamento(matriz, a, l, i * aSubM, j * lSubM, aSubM, lSubM, converterIntToNum(n))) {
                    //imprimirMatrizMesclada(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, VAZIO, PREENCHER);
                    //printf(" Cancelamento!\n");
                    //printf(" Possibilidades: %d\n", contarPossibilidades(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, converterIntToNum(n)));
                    //printf(" Primeira matriz generosa tem numero: %d\n", procurarSubmatrizGenerosa(matriz, a, l, aSubM, lSubM, converterIntToNum(n), 2));
                    eliminarOcorrencias(matriz, a, l, 0, 0, a, l, converterIntToNum(n));
                    i = 0;
                    j = 0;
                    if (tries >= tMax)
                        while (n > 1)
                            eliminarOcorrencias(matriz, a, l, 0, 0, a, l, converterIntToNum(n--));
                    //printf(" Tries: %d\n", tries);
                    tries++;
                    //getchar();
                }
                do {
                    pedirIJ(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, converterIntToNum(n), linhacoluna, &y, &x);
                } while(!validarEscolha(matriz, a, l, aSubM, lSubM, i * aSubM + y, j * lSubM + x, i * aSubM, j * lSubM, converterIntToNum(n)));
                matriz[(i * aSubM + y) * l + (j * lSubM + x)] = converterIntToNum(n);
            }
        }
    }
}

void popularMatrizSudokuFurada(char *matriz, int a, int l, int aSubM, int lSubM, int iS, int jS, int nMax) {
    int i, j, n;
    char linhacoluna[2];
    char escolha[1];
    int y = 0;
    int x = 0;
    for (i = 0; i < a / aSubM; i++) {
        for (j = 0; j < l / lSubM; j++) {
            int nMaxR = nMax;
            for (n = 1; n <= nMaxR; n++) {
                pedirEscolha(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, escolha, converterIntToNum(n));
                if (escolha[0] == 's') {
                    do {
                        pedirIJ(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, converterIntToNum(n), linhacoluna, &y, &x);
                    } while(!validarEscolha(matriz, a, l, aSubM, lSubM, i * aSubM + y, j * lSubM + x, i * aSubM, j * lSubM, converterIntToNum(n)));
                    matriz[(i * aSubM + y) * l + (j * lSubM + x)] = converterIntToNum(n);
                }
            }
        }
    }
}

int verificarCompletude(char *matriz, int a, int l, int iS, int jS, int aSubM, int lSubM) {
    int i, j;
    for (i = iS; i < iS + aSubM; i++) {
        for (j = jS; j < jS + lSubM; j++) {
            if (matriz[i * l + j] == VAZIO)
                return 0;
        }
    }
    return 1;
}

void informarJogo(char *matriz, int a, int l, int aSubM, int lSubM, int iS, int jS, int percas, char preencher) {
    printf("Jogo: percas x %d\n", percas);
    imprimirMatrizMesclada(matriz, a, l, aSubM, lSubM, iS, jS, VAZIO, preencher);
}

void processarFim(char *matriz, int a, int l, int percas) {
    if (verificarCompletude(matriz, a, l, 0, 0, a, l))
        printf(" Parabens! Vc ganhou!\n");
    else /*if (percas > PERCA_MAX)*/
        printf(" Vc perdeu.\n");
}

void empurrarParaBaixo(char *matriz, int a, int l, int i, int j) {
    if (i < a - 1) {
        empurrarParaBaixo(matriz, a, l, i + 1, j);
        if (matriz[(i + 1) * l + j] == VAZIO) {
            printf("Empurrando %c em %d, %d...\n", matriz[i * l + j], i, j);
            matriz[(i + 1) * l + j] = matriz[i * l + j];
            matriz[i * l + j] = VAZIO;
        }
    }
}

void pedirEscolhaColocarOuApagar(char *matriz, int a, int l, int aSubM, int lSubM, int iSG, int jSG, int percas, char *colocOuApag) {
    system("clear");
    printf("-- ADIVINHAR --\n");
    if (iSG >= 0 && jSG >= 0)
        informarJogo(matriz, a, l, aSubM, lSubM, iSG * aSubM, jSG * lSubM, percas, MARK);
    else
        informarJogo(matriz, a, l, aSubM, lSubM, 0, 0, percas, VAZIO);
    printf(" Quer colocar ou apagar, c ou a: ");
    scanf("%s", colocOuApag);
}

void pedirEscolhaN(char *matriz, int a, int l, int aSubM, int lSubM, int iSG, int jSG, int percas, int *n, int mode) {
    system("clear");
    switch (mode) {
        case 1:
            printf("-- ADIVINHAR --\n");
            if (iSG >= 0 && jSG >= 0)
                informarJogo(matriz, a, l, aSubM, lSubM, iSG * aSubM, jSG * lSubM, percas, MARK);
            else
                informarJogo(matriz, a, l, aSubM, lSubM, 0, 0, percas, VAZIO);
            break;
        default:
            printf("-- CRIAR --\n");
            imprimirMatriz(matriz, a, l);
            break;
    }
    printf(" Informe o numero: ");
    scanf("%d", &n[0]);
}

void pedirEscolhaSubmatriz(char *matriz, int a, int l, int aSubM, int lSubM, int iSG, int jSG, int percas, char *linhacoluna, int mode) {
    system("clear");
    switch (mode) {
        case 1:
            printf("-- ADIVINHAR --\n");
            if (iSG >= 0 && jSG >= 0)
                informarJogo(matriz, a, l, aSubM, lSubM, iSG * aSubM, jSG * lSubM, percas, MARK);
            else
                informarJogo(matriz, a, l, aSubM, lSubM, 0, 0, percas, VAZIO);
            break;
        default:
            printf("-- CRIAR --\n");
            imprimirMatriz(matriz, a, l);
            break;
    }
    printf(" Informe linha e coluna da submatriz nessa ordem e sem espaco: ");
    scanf("%s", linhacoluna);
}

void pedirEscolhaMudaNumero(char *matriz, int a, int l, int aSubM, int lSubM, int iSG, int jSG, int percas, char *mudarN) {
    system("clear");
    printf("-- ADIVINHAR --\n");
    if (iSG >= 0 && jSG >= 0)
        informarJogo(matriz, a, l, aSubM, lSubM, iSG * aSubM, jSG * lSubM, percas, MARK);
    else
        informarJogo(matriz, a, l, aSubM, lSubM, 0, 0, percas, VAZIO);
    printf(" Submatriz invalida\n");
    printf(" Quer mudar de numero, s ou n: \n");
    scanf("%s", mudarN);
}

void pedirEscolhaPosicaoNum(char *matriz, int a, int l, int aSubM, int lSubM, int iS, int jS, int percas, char *linhacoluna, int mode) {
    system("clear");
    switch (mode) {
        case 1:
            printf("-- ADIVINHAR --\n");
            informarJogo(matriz, a, l, aSubM, lSubM, iS, jS, percas, PREENCHER);
            break;
        default:
            printf("-- CRIAR --\n");
            imprimirMatrizMesclada(matriz, a, l, aSubM, lSubM, iS, jS, VAZIO, PREENCHER);
            break;
    }
    printf(" Informe linha e coluna nessa ordem e sem espaco: ");
    scanf("%s", linhacoluna);
}

void pedirEscolhaAcabouCria(char *matriz, int a, int l, int aSubM, int lSubM, int iS, int jS, char *escolha) {
    system("clear");
    printf("-- CRIAR --\n");
    imprimirMatrizMesclada(matriz, a, l, aSubM, lSubM, iS, jS, VAZIO, PREENCHER);
    printf(" Ja acabou, s ou n: ");
    scanf("%s", escolha);
}

void popularMatrizSudokuManual(char *matriz, int a, int l, int aSubM, int lSubM) {
    char escolha[1];
    int i, j;
    do {
        char linhacoluna[2];
        int n;
        do {
            pedirEscolhaN(matriz, a, l, aSubM, lSubM, -1, -1, 0, &n, 0);
            if (n < 1 || n > 9)
                printf(" Numero invalido\n");
        } while(n < 1 || n > 9);
        do {
            pedirEscolhaSubmatriz(matriz, a, l, aSubM, lSubM, -1, -1, 0, linhacoluna, 0);
            i = converterNumToInt(linhacoluna[0]) - 1;
            j = converterNumToInt(linhacoluna[1]) - 1;
            if (verificarCompletude(matriz, a, l, i * aSubM, j * lSubM, aSubM, lSubM) || procurarIElemento(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, converterIntToNum(n)) >= 0)
                printf(" Submatriz invalida\n");
        } while(verificarCompletude(matriz, a, l, i * aSubM, j * lSubM, aSubM, lSubM) || procurarIElemento(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, converterIntToNum(n)) >= 0);
        int y, x;
        do {
            pedirEscolhaPosicaoNum(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, 0, linhacoluna, 0);
            y = converterNumToInt(linhacoluna[0]) - 1;
            x = converterNumToInt(linhacoluna[1]) - 1;
        } while(!validarEscolha(matriz, a, l, aSubM, lSubM, i * aSubM + y, j * lSubM + x, i * aSubM, j * lSubM, converterIntToNum(n)));
        matriz[(i * aSubM + y) * l + (j * lSubM + x)] = converterIntToNum(n);
        pedirEscolhaAcabouCria(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, escolha);
    } while(escolha[0] != 's');
}

void adivinharSudoku(char *matriz, int a, int l, char *matrizOri, int aSubM, int lSubM, int guide) {
    int percas = 0;
    do {
        char linhacoluna[2];
        int n;
        int iSG;
        int jSG;
        if (guide) {
            for (n = 1; n <= aSubM * lSubM; n++) {
                iSG = procurarISubmatrizGenerosa(matriz, a, l, aSubM, lSubM, converterIntToNum(n), 1);
                jSG = procurarJSubmatrizGenerosa(matriz, a, l, aSubM, lSubM, converterIntToNum(n), 1);
                if (iSG >= 0) break;
            }
        } else {
            iSG = -1;
            jSG = -1;
        }
        char colocOuApag[1];
        pedirEscolhaColocarOuApagar(matriz, a, l, aSubM, lSubM, iSG, jSG, percas, colocOuApag);
        if (colocOuApag[0] == 'c') {
            int i = 0;
            int j = 0;
            char mudarN[1];
            mudarN[0] = 'n';
            do {
                pedirEscolhaN(matriz, a, l, aSubM, lSubM, iSG, jSG, percas, &n, 1);
                if (n < 1 || n > 9)
                    printf(" Numero invalido\n");
            } while(n < 1 || n > 9);
            do {
                pedirEscolhaSubmatriz(matriz, a, l, aSubM, lSubM, iSG, jSG, percas, linhacoluna, 1);
                i = converterNumToInt(linhacoluna[0]) - 1;
                j = converterNumToInt(linhacoluna[1]) - 1;
                if (verificarCompletude(matriz, a, l, i * aSubM, j * lSubM, aSubM, lSubM) || procurarIElemento(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, converterIntToNum(n)) >= 0) {
                    percas++;
                    pedirEscolhaMudaNumero(matriz, a, l, aSubM, lSubM, iSG, jSG, percas, mudarN);
                    if (mudarN[0] == 's') break;
                }
            } while(verificarCompletude(matriz, a, l, i * aSubM, j * lSubM, aSubM, lSubM) || procurarIElemento(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, converterIntToNum(n)) >= 0);
            int y = 0;
            int x = 0;
            if (mudarN[0] == 'n') {
                do {
                    pedirEscolhaPosicaoNum(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, percas, linhacoluna, 1);
                    y = converterNumToInt(linhacoluna[0]) - 1;
                    x = converterNumToInt(linhacoluna[1]) - 1;
                    if (!validarEscolha(matriz, a, l, aSubM, lSubM, i * aSubM + y, j * lSubM + x, i * aSubM, j * lSubM, converterIntToNum(n))) {
                        percas++;
                    }
                } while(!validarEscolha(matriz, a, l, aSubM, lSubM, i * aSubM + y, j * lSubM + x, i * aSubM, j * lSubM, converterIntToNum(n)));
                matriz[(i * aSubM + y) * l + (j * lSubM + x)] = converterIntToNum(n);
            }
            /*
            if (verificarCancelamentoCompleto(matriz, a, l, aSubM, lSubM))
                percas = PERCA_MAX;
            */
        } else {
            int i = 0;
            int j = 0;
            pedirEscolhaSubmatriz(matriz, a, l, aSubM, lSubM, iSG, jSG, percas, linhacoluna, 1);
            i = converterNumToInt(linhacoluna[0]) - 1;
            j = converterNumToInt(linhacoluna[1]) - 1;
            int y = 0;
            int x = 0;
            do {
                pedirEscolhaPosicaoNum(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, percas, linhacoluna, 1);
                y = converterNumToInt(linhacoluna[0]) - 1;
                x = converterNumToInt(linhacoluna[1]) - 1;
                if (matrizOri[(i * aSubM + y) * l + (j * lSubM + x)] != VAZIO) {
                    system("clear");
                    printf("-- ADIVINHAR --\n");
                    informarJogo(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, percas, PREENCHER);
                    printf(" Numero fixo, informe outro: ");
                }
            } while(matrizOri[(i * aSubM + y) * l + (j * lSubM + x)] != VAZIO);
            matriz[(i * aSubM + y) * l + (j * lSubM + x)] = VAZIO;
        }
    } while(percas < PERCA_MAX && !verificarCompletude(matriz, a, l, 0, 0, a, l));
    processarFim(matriz, a, l, percas);
}

void rodarJogo(char *matriz, int a, int l, char *matriz2, int aSubM, int lSubM, int guide) {
    system("clear");
    zerarMatriz(matriz, a, l);
    zerarMatriz(matriz2, a, l);
    char escolha;
    printf(" Quer criar um sudoku, s ou n: ");
    scanf("%c", &escolha);
    if (escolha == 's') {
        popularMatrizSudokuManual(matriz, a, l, aSubM, lSubM);
    }
    else {
        popularMatrizSudokuCompleto(matriz, a, l, aSubM, lSubM, 0, 0, 2);
        furarMatriz(matriz, a, l, aSubM, lSubM, 1);
    }
    intersecionarMatrizes(matriz2, a, l, matriz, a, l, 0, 0);
    adivinharSudoku(matriz2, a, l, matriz, aSubM, lSubM, guide);
}

void furarMatriz(char *matriz, int a, int l, int aSubM, int lSubM, int nMax) {
    int i, j, n;
    char linhacoluna[2];
    char escolha[1];
    int y = 0;
    int x = 0;
    for (i = 0; i < aSubM; i++) {
        for (j = 0; j < lSubM; j++) {
            int nMaxR = nMax;
            for (n = 1; n <= nMaxR; n++) {
                pedirEscolha(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, escolha, converterIntToNum(n));
                if (escolha[0] == 's') {
                    pedirIJ(matriz, a, l, aSubM, lSubM, i * aSubM, j * lSubM, converterIntToNum(n), linhacoluna, &y, &x);
                    matriz[(i * aSubM + y) * l + (j * lSubM + x)] = VAZIO;
                }
            }
        }
    }
}

void testeZerarMatriz(char *matriz, int a, int l) {
    zerarMatriz(matriz, a, l);
    printf("\nZerando matriz...\n");
    imprimirMatriz(matriz, a, l);
}

void testeProcurarElemento(char *matriz, int a, int l) {
    zerarMatriz(matriz, a, l);
    // procurar com ignore -1 retorna a primeira ocorrência de elemento.
    int ignore = -1;
    // procurar com ignore retorna a primeira ocorrência de elemento excluindo sua ocorrência de posição ignore.
    //int ignore = 1;
    // procurar elemento inexistente retorna -1.
    int elemento = -1;
    //int elemento = 0;
    int i = 0;
    printf("\nProcurando indice...\n");
    printf("%d\n", procurarElementoVer(matriz, i, a, l, elemento, ignore));
}

void testePopularMatrizSudokuCompleto(char *matriz, int a, int l, int aSubM, int lSubM) {
    zerarMatriz(matriz, a, l);
    popularMatrizSudokuCompleto(matriz, a, l, aSubM, lSubM, 0, 0, 2);
    printf("\nPopulando sudoku completo...\n");
    imprimirMatriz(matriz, a, l);
}

void testePopularMatrizSudokuFurada(char *matriz, int a, int l, int aSubM, int lSubM) {
    zerarMatriz(matriz, a, l);
    popularMatrizSudokuFurada(matriz, a, l, aSubM, lSubM, 0, 0, 9);
    printf("\nPopulando sudoku furado...\n");
    imprimirMatriz(matriz, a, l);
}

void testeRand() {
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++) {
        printf("Procurando numero aleatorio: %d\n", rand() % 10);
    }
}

void testeGameLoop(char *matriz, int a, int l, char *matriz2, int aSubM, int lSubM) {
    //zerarMatriz(matriz, a, l);
    rodarJogo(matriz, a, l, matriz2, aSubM, lSubM, 1);
}

void testeEliminarOcorrencias(char *matriz, int a, int l, int aSubM, int lSubM) {
    zerarMatriz(matriz, a, l);
    popularMatrizSudokuFurada(matriz, a, l, aSubM, lSubM, 0, 0, 5);
    printf("\nPopulando sudoku furado...\n");
    imprimirMatriz(matriz, a, l);
    printf("\nEliminando ocorrencias..\n");
    eliminarOcorrencias(matriz, a, l, 0, 0, a, l, converterIntToNum(1));
    imprimirMatriz(matriz, a, l);
}

void testeIntersecionarMatrizes(char *matriz, int a, int l, char *submatriz, int aSubM, int lSubM, int iS, int jS) {
    zerarMatriz(submatriz, aSubM, lSubM);
    printf("\nMatriz A...\n");
    imprimirMatriz(matriz, a, l);
    printf("\nMatriz B antes...\n");
    imprimirMatriz(submatriz, aSubM, lSubM);
    intersecionarMatrizes(submatriz, aSubM, lSubM, matriz, a, l, iS, jS);
    printf("\nMatriz B depois...\n");
    imprimirMatriz(submatriz, aSubM, lSubM);
}

void testeFurarMatriz(char *matriz, int a, int l, int aSubM, int lSubM) {
    printf("\nMatriz B antes...\n");
    imprimirMatriz(matriz, a, l);
    furarMatriz(matriz, a, l, aSubM, lSubM, 5);
    printf("\nMatriz B depois...\n");
    imprimirMatriz(matriz, a, l);
}

void testeEmpurrarParaBaixo(char *matriz, int a, int l) {
    //int iP = 0;
    int iP = 2;
    int jP = 8;
    //int jP = 7;
    printf("\nEmpurrando %d, %d para baixo...\n", iP + 1, jP + 1);
    zerarMatriz(matriz, a, l);
    //popularMatrizSudokuCompleto(matriz, a, l, 3, 3, 0, 0, 2);
    popularMatrizSudokuFurada(matriz, a, l, 3, 3, 0, 0, 9);
    system("clear");
    printf("\nAntes:\n");
    imprimirMatriz(matriz, a, l);
    empurrarParaBaixo(matriz, a, l, iP, jP);
    printf("\nDepois:\n");
    imprimirMatriz(matriz, a, l);
}

int main()
{
    char m[81];
    char m2[81];
    
    //testeZerarMatriz(m, 9, 9);
    
    //testeProcurarElemento(m, 9, 9);

    //testeRand();

    //testePopularMatrizSudokuCompleto(m, 9, 9, 3, 3);
    
    //testePopularMatrizSudokuFurada(m, 9, 9, 3, 3);
    
    //testeIntersecionarMatrizes(m, 9, 9, m2, 9, 9, 0, 0);
    
    //testeFurarMatriz(m2, 9, 9, 3, 3);
    
    //testeEliminarOcorrencias(m, 9, 9, 3, 3);
    
    testeGameLoop(m, 9, 9, m2, 3, 3);
    
    //testeEmpurrarParaBaixo(m, 9, 9);

    printf("\n FIM \n");

    return 0;
}