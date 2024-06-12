#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* next;
};

struct liste{
    struct node* bas;
};

struct node* newNode(int veri){
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
    yeniDugum->data= veri;
    yeniDugum->next = NULL;
    return yeniDugum;
};

struct liste* newList(){
    struct liste* yeniListe = (struct liste*)malloc(sizeof(struct liste));
    yeniListe->bas = NULL;
    return yeniListe;
};

void push(struct liste* liste,struct node* eklenecekEleman){

    eklenecekEleman->next = liste->bas;
    liste->bas = eklenecekEleman;

}

void pop(struct liste* liste){
    if(liste->bas == NULL){
        printf("Liste bos!");
    }
    struct node* temp = NULL;
    temp = liste->bas->next;
    free(liste->bas);
    liste->bas = temp;
}

void yazdir(struct liste* liste){
    struct node* temp = liste->bas;

    while(temp != NULL){
        printf("%d -->",temp->data);
        temp = temp->next;

    }

}

int main()
{
    struct node* d1,*d2,*d3,*d4,*d5,*d6,*d7,*d8,*d9,*d10,*d11,*d12,*d13;
    d1 = newNode(10);
    d2 = newNode(20);
    d3 = newNode(30);
    d4 = newNode(40);
    d5 = newNode(50);
    d6 = newNode(60);
    d7 = newNode(70);
    d8 = newNode(80);
    d9 = newNode(90);
    d10 = newNode(100);

    struct liste* liste1;
    liste1 = newList();

    push(liste1,d1);
    push(liste1,d2);
    push(liste1,d3);
    push(liste1,d4);
    yazdir(liste1);
    printf("\n");

    pop(liste1);
    yazdir(liste1);
}
