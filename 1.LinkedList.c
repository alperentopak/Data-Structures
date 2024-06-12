#include <stdio.h>
#include <stdlib.h>

// Tek Yonlu Bagli Liste

struct node {
    int data;
    struct node* next;
};

struct liste {
    struct node* bas;
    struct node* son;
};

struct node* newNode(int veri) {
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
    yeniDugum->data = veri;
    yeniDugum->next = NULL;
    return yeniDugum;
}

struct liste* newList() {
    struct liste* yeniListe = (struct liste*)malloc(sizeof(struct liste));
    yeniListe->bas = NULL;
    yeniListe->son = NULL;
    return yeniListe;
}

void basaEkle(struct liste* liste, struct node* eklenecekEleman) {
    if (liste->bas == NULL) {
        liste->son = eklenecekEleman;
    }
    eklenecekEleman->next = liste->bas;
    liste->bas = eklenecekEleman;
}

void sonaEkle(struct liste* liste, struct node* eklenecekEleman) {
    if (liste->bas == NULL) {
        liste->bas = eklenecekEleman;
        liste->son = eklenecekEleman;
    } else {
        liste->son->next = eklenecekEleman;
        liste->son = eklenecekEleman;
    }
}

void arayaEkle(struct liste* liste, int k, struct node* eklenecekEleman) {
    struct node* temp = liste->bas;
    while (temp != NULL && temp->data != k) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Eleman bulunamadi. \n");
        return;
    }
    eklenecekEleman->next = temp->next;
    temp->next = eklenecekEleman;
}

void bastanSil(struct liste* liste) {
    if (liste->bas == NULL) {
        printf("Liste bos. \n");
        return;
    }
    struct node* temp = liste->bas;
    liste->bas = liste->bas->next;
    free(temp);
}

void sondanSil(struct liste* liste) {
    if (liste->bas == NULL) {
        printf("Liste bos. \n");
        return;
    }
    if (liste->bas->next == NULL) {
        free(liste->bas);
        liste->bas = NULL;
        liste->son = NULL;
        return;
    }
    struct node* temp = liste->bas;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    liste->son = temp;
}

void aradanSil(struct liste* liste, int k) {
    if (liste->bas == NULL) {
        printf("Liste bos. \n");
        return;
    }
    struct node* temp = liste->bas;
    if (temp->data == k) {
        bastanSil(liste);
        return;
    }
    while (temp->next != NULL && temp->next->data != k) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Eleman bulunamadi. \n");
        return;
    }
    struct node* silinecek = temp->next;
    temp->next = silinecek->next;
    if (silinecek == liste->son) {
        liste->son = temp;
    }
    free(silinecek);
}

void yazdir(struct liste* liste) {
    struct node* temp = liste->bas;
    while (temp != NULL) {
        printf("%d -->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void tersCevir(struct liste* liste) {
    struct node* temp = liste->bas;
    struct node* prev = NULL;
    struct node* next = NULL;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    liste->bas = prev;
}

int listeBoyut(struct liste* liste) {
    int count = 0;
    struct node* temp = liste->bas;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void listeyiTemizle(struct liste* liste) {
    while (liste->bas != NULL) {
        bastanSil(liste);
    }
}

int main() {
    struct node* d1, *d2, *d3, *d4, *d5, *d6, *d7, *d8, *d9, *d10;
    d1 = newNode(10);
    d2 = newNode(20);
    d3 = newNode(30);
    d4 = newNode(40);
    d5 = newNode(60);
    d6 = newNode(70);
    d7 = newNode(80);
    d8 = newNode(90);
    d9 = newNode(100);
    d10 = newNode(110);

    struct liste* liste1;
    liste1 = newList();

    basaEkle(liste1, d1);
    basaEkle(liste1, d2);
    basaEkle(liste1, d3);
    basaEkle(liste1, d4);

    yazdir(liste1); // 40 -->30 -->20 -->10 -->NULL
    printf("\n");

    sonaEkle(liste1, d5);
    sonaEkle(liste1, d6);
    sonaEkle(liste1, d7);
    sonaEkle(liste1, d8);

    yazdir(liste1); // 40 -->30 -->20 -->10 -->60 -->70 -->80 -->90 -->NULL
    printf("\n");

    arayaEkle(liste1, 60, d9);
    yazdir(liste1); // 40 -->30 -->20 -->10 -->60 -->100 -->70 -->80 -->90 -->NULL
    printf("\n");

    bastanSil(liste1);
    yazdir(liste1); // 30 -->20 -->10 -->60 -->100 -->70 -->80 -->90 -->NULL
    printf("\n");

    sondanSil(liste1);
    yazdir(liste1); // 30 -->20 -->10 -->60 -->100 -->70 -->80 -->NULL
    printf("\n");

    aradanSil(liste1, 60);
    yazdir(liste1); // 30 -->20 -->10 -->100 -->70 -->80 -->NULL
    printf("\n");

    tersCevir(liste1);
    yazdir(liste1); // 80 -->70 -->100 -->10 -->20 -->30 -->NULL
    printf("\n");

    int x = listeBoyut(liste1);
    printf("Liste boyutu: %d\n", x);

    listeyiTemizle(liste1);
    free(liste1);

    return 0;
}
