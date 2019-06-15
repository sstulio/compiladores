#include <stdio.h>
#include <time.h>

#define N 100000000

#define fim_string -1
#define AP -2 //Abre Parenteses
#define FP -3 //Fecha Parenteses
#define K -4
#define S -5
#define I -6
#define B -7
#define C -8
#define D -9
#define E -10
#define F -11

#define sub -20
#define mul -21
#define lt  -22
#define add  -23
#define eq -24

#define CTRUE -25
#define CFALSE -26
#define Y -27


//FAT
//static int entrada[N] = {S, AP, K, AP, S, I, I, FP, FP, AP, S, AP, S, AP, K, S, FP, K, FP, AP, K, AP, S, I, I, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 2, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, lt, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, 1, FP, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, K, K, FP, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 1, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, sub, FP, FP, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, mul, FP, FP, FP, FP, 20, fim_string};

//FAT TURNER
//static int entrada[N] = {Y, AP, AP, B, AP, S, AP, S, AP, C, AP, C, I, 1, FP, eq, FP, AP, K, 1, FP, FP, FP, FP, AP, C, AP, B, C, AP, B, AP, S, I, FP, AP, C, AP, B, B, I, FP, AP, C, AP, C, I, 1, FP, sub, FP, FP, FP, FP, mul, FP, FP, 20, fim_string};

//FIB
//static int entrada[N] = {S, AP, K, AP, S, I, I, FP, FP, AP, S, AP, S, AP, K, S, FP, K, FP, AP, K, AP, S, I, I, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 2, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, lt, FP, FP, FP, FP, AP, K, I, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, K, K, FP, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 1, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, sub, FP, FP, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, K, K, FP, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 2, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, sub, FP, FP, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, add, FP, FP, FP, FP, 25, fim_string};

//FIB TURNER
static int entrada[N] = {Y, AP, B, AP, S, AP, S, AP, C, AP, C, I, 2, FP, lt, FP, I, FP, FP, AP, F, C, AP, S, AP, F, D, I, AP, C, AP, C, I, 2, FP, sub, FP, FP, AP, F, B, I, AP, C, AP, C, I, 1, FP, sub, FP, FP, FP, add, FP, FP, 35, fim_string};

static int saida[N];

void printar_array(unsigned int *array1) {
   int i;
   unsigned int fimString = -1;
   for(i = 0;array1[i] != fimString;i++){
       switch (array1[i]){
           case S:
               printf("S");
               break;
           case K:
               printf("K");
               break;
           case FP:
               printf(")");
               break;
           case AP:
               printf("(");
               break;
           case fim_string:
                break;
           default:
               printf("%u ", array1[i]);
       }
   }
   printf("\n");
}

/*
 * Remove o parenteses da posição 0 e seu oposto
 */

void remove_parenteses(int *array1){
    int p = 0;
    int paren = 1;
    while (paren) {
        array1[p] = array1[p+1];
        p++;
        if(array1[p] == AP){
            paren++;
        }else if(array1[p] == FP){
            paren--;
        }
    }
    p--;
    while(array1[p+1] != fim_string && array1[p+2] != fim_string){
        array1[p] = array1[p+2];
        p++;
    }
    array1[p] = fim_string;
}

/*
 * Procura o fim do conjunto de inteiros
 */
void casa_parenteses(int* array1, int* p) {
    int paren = 1;
    int a = *p;
    while (paren) {
        unsigned int c  = array1[a];
        if(c == AP){
            paren++;
        }else if(c == FP){
            paren--;
        }
        a++;
    }
    *p = a;
}

/*
 * Verifica se a posicao do array é um inteiro ou um conjunto de inteiros
 */
void acha_argumento(int *array1, int *p){
    int c = (*p)++;
    if (array1[c] == AP) {
        casa_parenteses(array1,p);
    }
}

/*
 * Kab = a
 */

void reduz_K(int* array1, int* array2) {
    int A, nA;
    int n = 1;

    A = n;
    acha_argumento(array1,&n);

    nA = n-1;
    acha_argumento(array1,&n);

    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Sabc = ac(bc)
 */
void reduz_S(int *array1, int *array2) {
    int A, nA;
    int BB, nBB;
    int CC, nCC;
    int n = 1;
    A = n;
    acha_argumento(array1,&n);
    nA = n-1;
    BB = n;
    acha_argumento(array1,&n);
    nBB = n-1;
    CC = n;
    acha_argumento(array1,&n);
    nCC = n-1;

    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }
    for (i = CC; i <= nCC; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = BB; i <= nBB; i++) {
        array2[k] = array1[i];
        k++;
    }
    for (i = CC; i <= nCC; i++) {
        array2[k] = array1[i];
        k++;
    }
    array2[k] = FP;
    k++;
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }
    array2[k] = fim_string;
}

void reduzI(int* array1, int* array2){
    int k = 0;
    int i;
    for(i = 1; array1[i] != fim_string; i++){
        array2[k] = array1[i];
        k++;
    }
    array2[k] = fim_string;
}

//Procedimento que recebe duas vari�veis que apontam para
//dois arrays e executa a regra do combinador B: B a b c => a ( b c ),
//copiando os argumentos do array1 para o array2.
void reduzB(int* array1, int* array2) {
    int A, nA;
    int BB, nB;
    int CC, nC;
    int n = 1;

    A = n;
    acha_argumento(array1,&n);
    nA = n-1;
    BB = n;
    acha_argumento(array1,&n);
    nB = n-1;
    CC = n;
    acha_argumento(array1,&n);
    nC = n-1;

    //B a b c => a ( b c )
    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = BB; i <= nB; i++) {
        array2[k] = array1[i];
        k++;
    }
    for (i = CC; i <= nC; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

//Procedimento que recebe duas vari�veis que apontam para
//dois arrays e executa a regra do combinador C: C a b c => a c b,
//copiando os argumentos do array1 para o array2.
void reduzC(int* array1, int* array2) {
    int A, nA;
    int BB, nB;
    int CC, nC;
    int n = 1;

    A = n;
    acha_argumento(array1,&n);
    nA = n-1;
    BB = n;
    acha_argumento(array1,&n);
    nB = n-1;
    CC = n;
    acha_argumento(array1,&n);
    nC = n-1;

    //C a b c => a c b 
    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = CC; i <= nC; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = BB; i <= nB; i++) {
        array2[k] = array1[i];
        k++;
    }
    
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

//Procedimento que recebe duas vari�veis que apontam para
//dois arrays e executa a regra do combinador D: D a b c d => a (b d)(c d),
//copiando os argumentos do array1 para o array2.
void reduzD(int* array1, int* array2) {
    int A, nA;
    int BB, nB;
    int CC, nC;
    int DD, nD;
    int n = 1;

    A = n;
    acha_argumento(array1,&n);
    nA = n-1;
    BB = n;
    acha_argumento(array1,&n);
    nB = n-1;
    CC = n;
    acha_argumento(array1,&n);
    nC = n-1;
    DD = n;
    acha_argumento(array1,&n);
    nD = n-1;

    //D a b c d => a (b d)(c d)
    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = BB; i <= nB; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = DD; i <= nD; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    array2[k] = AP;
    k++;

    for (i = CC; i <= nC; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = DD; i <= nD; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;
    
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

//Procedimento que recebe duas vari�veis que apontam para
//dois arrays e executa a regra do combinador E: E a b c d => a b (c d),
//copiando os argumentos do array1 para o array2.
void reduzE(int* array1, int* array2) {
    int A, nA;
    int BB, nB;
    int CC, nC;
    int DD, nD;
    int n = 1;

    A = n;
    acha_argumento(array1,&n);
    nA = n-1;
    BB = n;
    acha_argumento(array1,&n);
    nB = n-1;
    CC = n;
    acha_argumento(array1,&n);
    nC = n-1;
    DD = n;
    acha_argumento(array1,&n);
    nD = n-1;

    //D a b c d => a b (c d)
    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = BB; i <= nB; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = CC; i <= nC; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = DD; i <= nD; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;
    
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

//Procedimento que recebe duas vari�veis que apontam para
//dois arrays e executa a regra do combinador F: F a b c d => a (b d) c,
//copiando os argumentos do array1 para o array2.
void reduzF(int* array1, int* array2) {
    int A, nA;
    int BB, nB;
    int CC, nC;
    int DD, nD;
    int n = 1;

    A = n;
    acha_argumento(array1,&n);
    nA = n-1;
    BB = n;
    acha_argumento(array1,&n);
    nB = n-1;
    CC = n;
    acha_argumento(array1,&n);
    nC = n-1;
    DD = n;
    acha_argumento(array1,&n);
    nD = n-1;

    //D a b c d => a (b d) c
    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = BB; i <= nB; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = DD; i <= nD; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    for (i = CC; i <= nC; i++) {
        array2[k] = array1[i];
        k++;
    }
    
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Add ab = (a Add b)
 */
void reduzAdd(int* array1, int* array2){
    array2[0] = array1[1] + array1[2];
    int n1 = 3;
    int n2 = 1;

    for (; array1[n1] != fim_string; n1++) {
        array2[n2] = array1[n1];
        n2++;
    }

    array2[n2] = fim_string;
}

/*
 * Sub ab = (a Sub b)
 */
void reduzSub(int* array1, int* array2){
    array2[0] = array1[1] - array1[2];
    int n1 = 3;
    int n2 = 1;

    for (; array1[n1] != fim_string; n1++) {
        array2[n2] = array1[n1];
        n2++;
    }

    array2[n2] = fim_string;
}

/*
 * Mul ab = (a Mul b)
 */
void reduzMul(int* array1, int* array2){
    array2[0] = array1[1] * array1[2];
    int n1 = 3;
    int n2 = 1;

    for (; array1[n1] != fim_string; n1++) {
        array2[n2] = array1[n1];
        n2++;
    }

    array2[n2] = fim_string;
}

/*
 * Lt ab = (a Lt b)
 */
void reduzLt(int* array1, int* array2){

    array2[0] = array1[1] < array1[2] ? CTRUE : CFALSE;
    int n1 = 3;
    int n2 = 1;

    for (; array1[n1] != fim_string; n1++) {
        array2[n2] = array1[n1];
        n2++;
    }

    array2[n2] = fim_string;
}

/*
 * Eq ab => a == b ? CTRUE : CFALSE
 */
void reduzEq(int* array1, int* array2){

    array2[0] = array1[1] == array1[2] ? CTRUE : CFALSE;
    int n1 = 3;
    int n2 = 1;

    for (; array1[n1] != fim_string; n1++) {
        array2[n2] = array1[n1];
        n2++;
    }

    array2[n2] = fim_string;
}

/*
 * Tab = a
 */

void reduz_True(int* array1, int* array2) {
    int A, nA;
    int n = 1;

    A = n;
    acha_argumento(array1,&n);

    nA = n-1;
    acha_argumento(array1,&n);

    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Fab = b
 */

void reduz_False(int* array1, int* array2) {
    int A, nA;
    int BB, nBB;
    int n = 1;
    A = n;
    acha_argumento(array1,&n);
    nA = n-1;
    BB = n;
    acha_argumento(array1,&n);
    nBB = n-1;

    int k = 0;
    int i;

    for (i = BB; i <= nBB; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }
    array2[k] = fim_string;
}

/*
 * Ya => a (Y a)
 */
void reduz_Y(int *array1, int *array2) {
    int A, nA;
    int n = 1;
    A = n;
    acha_argumento(array1,&n);
    nA = n-1;

    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    array2[k] = Y;
    k++;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }
    array2[k] = fim_string;
}

// abc = bca
void inverte(int* array1, int* array2) {
    int A = 0, nA = 0;
    int BB, nBB;
    int CC, nCC;
    int n = 1;

    BB = n;
    acha_argumento(array1,&n);
    nBB = n-1;
    CC = n;
    acha_argumento(array1,&n);
    nCC = n-1;

    int k = 0;
    int i;

    for (i = BB; i <= nBB; i++) {
        array2[k] = array1[i];
        k++;
    }
    for (i = CC; i <= nCC; i++) {
        array2[k] = array1[i];
        k++;
    }
    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }
    array2[k] = fim_string;
}

int main(){
    int *array1, *array2, *array3;
    array1 = entrada;
    array2 = saida;
    while(array1[1] != fim_string){
        switch (array1[0]){
            case AP:
                remove_parenteses(array1);
                array2[0] = fim_string;
                break;
            case K:
                reduz_K(array1, array2);
                break;
            case S:
                reduz_S(array1, array2);
                break;
            case I:
                reduzI(array1, array2);
                break;
            case B:
                reduzB(array1, array2);
            break;
            case C:
                reduzC(array1, array2);
                break;
            case D:
                reduzD(array1, array2);
                break;
            case E:
                reduzE(array1, array2);
                break;
            case F:
                reduzF(array1, array2);
                break;
            case Y:
                reduz_Y(array1, array2);
            break;
            case mul:
                reduzMul(array1, array2);
                break;
            case add:
                reduzAdd(array1, array2);
                break;
            case sub:
                reduzSub(array1, array2);
                break;
            case eq:
                reduzEq(array1, array2);
            break;
            case lt:
                reduzLt(array1, array2);
                break;
            case CTRUE:
                reduz_True(array1, array2);
                break;
            case CFALSE:
                reduz_False(array1, array2);
                break;
            case fim_string:
                // DO NOTHING
            break;
            default:
                inverte(array1, array2);
                break;
        }
        array3 = array1;
        array1 = array2;
        array2 = array3;
    }
    printar_array(array1);
    float clks = CLOCKS_PER_SEC;
    printf("\nTempo = %f", (clock()/clks));
    return 0;
}
