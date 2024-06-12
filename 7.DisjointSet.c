#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Oge {
    int icerik;
    int ebeveyn;
    int derinlik;
};

struct Ayrikkume {
    struct Oge* kumeler;
    int kactane;
};

void newOge(struct Oge* oge, int icerik) {
    oge->icerik = icerik;
    oge->ebeveyn = icerik;
    oge->derinlik = 1;
}

struct Ayrikkume* createAyrikkume(int N) {
    struct Ayrikkume* yeniKume = (struct Ayrikkume*)malloc(sizeof(struct Ayrikkume));
    yeniKume->kumeler = (struct Oge*)malloc(N * sizeof(struct Oge));
    yeniKume->kactane = N;
    for (int i = 0; i < N; i++) {
        newOge(&yeniKume->kumeler[i], i);
    }
    return yeniKume;
    // 0'dan N'e kadar Ogeleri olusturup ozellestirdim.
}

int kumeBul(struct Ayrikkume* kume, int sira) {
    if (kume->kumeler[sira].ebeveyn != sira) {
        kume->kumeler[sira].ebeveyn = kumeBul(kume, kume->kumeler[sira].ebeveyn);
    }
    // kumeler[sira] elemanin ebeveyninin kendisi olup olmadigi kontrol edilir. Eðer ebeveyni kendisi degilse,
    // bu eleman bir kok eleman degildir ve yukariya dogru bir yol takip edilerek kok eleman bulunmalidir.
    // birlestirme islemi yapacakken bana kok eleman gerekmektedir
    return kume->kumeler[sira].ebeveyn;
}

void kumeBirlestir(struct Ayrikkume* kume, int sira1, int sira2) {
    int x = kumeBul(kume, sira1); // kok parent'leri atadik
    int y = kumeBul(kume, sira2);

    if (kume->kumeler[x].derinlik < kume->kumeler[y].derinlik) {
        kume->kumeler[x].ebeveyn = y;
    }
    else {
        kume->kumeler[y].ebeveyn = x;
        if (kume->kumeler[x].derinlik == kume->kumeler[y].derinlik) {
            kume->kumeler[x].derinlik++;
        }
    }

}
int main() {
    struct Ayrikkume* s1 = createAyrikkume(10);
    kumeBirlestir(s1, 0, 1);
    kumeBirlestir(s1, 1, 2);
    kumeBirlestir(s1, 3, 4);

    printf("%d\n", kumeBul(s1, 2)); // Output: 0 -- Gonderilen elemanin kok parent'ini gösterecektir. suan 2'nin kok parent'i 0'dir.
    printf("%d\n", kumeBul(s1, 4)); // Output: 3 -- 4'un parent'i 3'tur.
    printf("%d\n", kumeBul(s1, 5)); // Output: 5 -- 5'in parent'i 5'tir, Bir yere bagli degildir(parent'i kendisidir).
    // printf("%d\n", kumeBul(s1, 10)); // ERROR Boyle bir tanimlama yapilamaz, kumede 0'dan 10'a kadar(10 dahil degil) Ogeler olusturduk.

    printf("*********************\n");

    struct Ayrikkume* s2 = createAyrikkume(10);
    kumeBirlestir(s2, 2, 3);
    kumeBirlestir(s2, 2, 0);
    kumeBirlestir(s2, 3, 6);
    kumeBirlestir(s2, 1, 5);
    kumeBirlestir(s2, 5, 7);

    printf("%d\n", kumeBul(s2, 2)); // Output: 2
    printf("%d\n", kumeBul(s2, 3)); // Output: 2
    printf("%d\n", kumeBul(s2, 0)); // Output: 2
    printf("%d\n", kumeBul(s2, 6)); // Output: 2
    printf("%d\n", kumeBul(s2, 1)); // Output: 1
    printf("%d\n", kumeBul(s2, 5)); // Output: 1
    printf("%d\n", kumeBul(s2, 7)); // Output: 1
    printf("%d\n", kumeBul(s2, 4)); // Output: 4

    printf("*********************\n");

    kumeBirlestir(s2, 4, 2);
    printf("%d\n", kumeBul(s2, 4)); // Output: 2

    free(s1->kumeler);
    free(s1);
    free(s2->kumeler);
    free(s2);

    return 0;
}
