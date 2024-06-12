#include <stdio.h>
#include <stdlib.h>

// Cift Yonlu Bagli Liste

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct liste {
    struct node* bas;
    struct node* son;
};

struct node* newNode(int veri){
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
    yeniDugum->data = veri;
    yeniDugum->next = NULL;
    yeniDugum->prev = NULL;

    return yeniDugum;
};

struct liste* newList(){
    struct liste* yeniListe = (struct liste*)malloc(sizeof(struct liste));
    yeniListe->bas = NULL;
    yeniListe->son = NULL;
    return yeniListe;
};

void basaEkle(struct liste* liste,struct node* eklenecekEleman){
    if(liste->bas == NULL){
        liste->son = eklenecekEleman;
    }
    eklenecekEleman->next = liste->bas;
    liste->son->prev = eklenecekEleman;
    liste->bas = eklenecekEleman;
}

void sonaEkle(struct liste* liste,struct node* eklenecekEleman){
    if(liste->bas == NULL){
        liste->bas = eklenecekEleman;
    }
    liste->son->next = eklenecekEleman;
    eklenecekEleman->prev = liste->son;
    liste->son = eklenecekEleman;
}

void yazdir(struct liste* liste) {
    struct node* temp = liste->bas;
    while (temp != NULL) {
        printf("%d -->", temp->data);
        temp = temp->next;
    }
}

int main()
{

    struct node* d1,*d2,*d3,*d4,*d5,*d6,*d7,*d8;
    d1 = newNode(10);
    d2 = newNode(20);
    d3 = newNode(30);
    d4 = newNode(40);
    d5 = newNode(50);
    d6 = newNode(60);
    d7 = newNode(70);
    d8 = newNode(80);

    struct liste* liste1;
    liste1 = newList();


    basaEkle(liste1,d1);
    basaEkle(liste1,d2);
    basaEkle(liste1,d3);
    basaEkle(liste1,d4);
    yazdir(liste1);
    printf("\n");

    sonaEkle(liste1,d5);
    sonaEkle(liste1,d6);
    sonaEkle(liste1,d7);
    sonaEkle(liste1,d8);
    yazdir(liste1);
    printf("\n");

}
