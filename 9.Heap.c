#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30

int heap[MAXSIZE];
int size = 0;

int findMax(){
    return heap[0];
}

int heapSize(){
    return size;
}

void insert(int value){
    if(size >= MAXSIZE){
        printf("Heap is full.\n");
        return;
    }
    heap[size] = value;
    heapifyUp(size);
    size++;
}

int delMax(){
    if(size <= 0){
        printf("Heap is empty.\n");
        return -1;
    }
    int max = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return max;
}


void heapifyUp(int index){
    int current = index;
    int parent = (index - 1) / 2;
    while(current > 0 && heap[parent] < heap[current]){
        swap(parent, current);
        current = parent;
        parent = (current - 1) / 2;
    }
}

void heapifyDown(int index){
    int current = index;
    int left = 2 * current + 1;
    int right = 2 * current + 2;
    while(heap[current] < heap[left]|| heap[current]< heap[right]){
        left = 2 * current + 1;
        right = 2 * current + 2;
        int largest = current;

        if(left < size && heap[left] > heap[largest]){
            largest = left;
        }
        if(right < size && heap[right] > heap[largest]){
            largest = right;
        }
        if(largest == current){
            break;
        }
        swap(current, largest);
        current = largest;
    }
}

void swap(int index1, int index2){
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}

int search(int value){
    for(int i = 0; i < size; i++){
        if(heap[i] == value){
            return i;
        }
    }
    return -1;
}

int main(){
    insert(10);
    insert(20);
    insert(50);
    insert(30);
    insert(40);
    insert(70);
    insert(25);

    printf("Heap size : %d\n", heapSize());
    printf("Max value : %d\n", findMax());

    printf("Deleting max value: %d\n", delMax());
    printf("Max value after deletion: %d\n", findMax());

    int a = 30;
    int index = search(a);
    if(index != -1){
        printf("Value %d found at index : %d\n",a, index);
    } else {
        printf("Value %d not found in heap.\n",a);
    }

    return 0;
}
