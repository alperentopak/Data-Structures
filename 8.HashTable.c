#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

int hashTable[SIZE];

int hashFunction(int key){
    return key % SIZE;
}

void insert(int key){
    int index = hashFunction(key);
    while(hashTable[index] != 0){
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

int search(int key){
    int index = hashFunction(key);
    while(hashTable[index] != key && hashTable[index] != 0){
        index = (index + 1) % SIZE;
    }
    if(hashTable[index] == key){
        return index;
    }
    else{
        return -1;
    }
}

void delete(int key){
    int index = search(key);
    if(index != -1){
        hashTable[index] = 0;
    }
    else{
        printf("Not found \n");
    }
}

void display(){
    for(int i = 0; i < SIZE; i++){
        if(hashTable[i] != 0)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: ~\n", i);
    }
}

int main() {
    insert(12);
    insert(22);
    insert(44);
    insert(36);
    insert(52);
    insert(64);

    display();

    int key = 30;
    int index = search(key);
    if(index != -1)
        printf("Key %d found at index %d\n", key, index);
    else
        printf("Key %d not found\n", key);

    delete(30);

    display();

    return 0;
}
