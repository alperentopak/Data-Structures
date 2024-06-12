#include <stdlib.h>
#include <stdio.h>
#define BOYUT 100

struct stack{
    int dizi[BOYUT];
    int bas;

};

void yerDegistir(struct stack* stack){
    if(stack->bas <= 1){
        printf("Stack en az 2 elemanli olmalidir");
    }
    else{
        int temp = stack->dizi[stack->bas -1];
        stack->dizi[stack->bas - 1] = stack->dizi[stack->bas - 2];
        stack->dizi[stack->bas - 2] = temp;
    }
}

void push(struct stack* stack,int veri){
    if(stack->bas == BOYUT){
        printf("Dizi doldu!");
    }
    else{
        stack->dizi[stack->bas] = veri;
        stack->bas= stack->bas+1;
    }

}

void pop(struct stack* stack){
    stack->bas -= 1;

}

void yazdir(struct stack* stack){
    int i;
    for(i = 0 ; i < stack->bas; i++){
        printf("%d ", stack->dizi[i]);
    }

    printf("==> En ustteki eleman\n");

}

int main()
{
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->bas = 0;
    push(stack,10); // 1
    push(stack,20); // 2
    push(stack,30); // 3
    push(stack,40); // 4
    yazdir(stack); // 10 20 30 40 ==> En ustteki eleman

    pop(stack);
    yazdir(stack); // 10 20 30 ==> En ustteki eleman

    yerDegistir(stack);
    yazdir(stack);


}
