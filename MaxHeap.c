#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Function to create heap
// Function to heapify
// Function to retrive value of heap
// Insert new data in MaxHeap
struct Heap{
    int* array;
    int size;
    int capacity;
};
void maxHeapify(struct Heap* maxHeap,int index){
    int left = index*2 + 1;
    int right = index*2 + 2;
    int max = index;
    if(left >= maxHeap->size || left < 0){
        left = -1;
    }
    if(right >= maxHeap->size || right < 0){
        right = -1;
    }
    if(left != -1 && maxHeap->array[left] > maxHeap->array[max]){
        max = left;
    }
    if(right != -1 && maxHeap->array[right] > maxHeap->array[max]){
        max = right;
    }
    if(max != index){
        int temp = maxHeap->array[index];
        maxHeap->array[index] = maxHeap->array[max];
        maxHeap->array[max] = temp;
        maxHeapify(maxHeap,max);
    }
}
struct Heap* createMaxHeap(int capacity,int size,int* nums){
    struct Heap* maxHeap = (struct Heap*) malloc(sizeof(struct Heap)*capacity);
    if(maxHeap == NULL){
        printf("Error creating MaxHeap.\n");
        return NULL;
    }
    maxHeap->array = (int*) malloc(sizeof(int)*capacity);
    if(maxHeap->array == NULL){
        printf("Error creating MaxHeap.\n");
        return NULL;
    }
    maxHeap->capacity = capacity;
    int i=0;
    maxHeap->size = size;
    for(i=0;i<maxHeap->size;i++){
        maxHeap->array[i] = nums[i];
    }
    i = (maxHeap->size - 1)/2;
    while(i >= 0){
        maxHeapify(maxHeap,i);
        i--;
    }
    return maxHeap;
}
void insertSingleValueInMaxHeap(struct Heap* maxHeap,int value){
    if(maxHeap == NULL || maxHeap->size >= maxHeap->capacity){
        printf("Cannot insert data into Max Heap.");
        return;
    }
    maxHeap->array[maxHeap->size] = value;
    maxHeap->size++;
    int i = maxHeap->size - 1;
    while(i > 0){
        int parent = (i - 1)/2; 
        if(maxHeap->array[parent] < maxHeap->array[i]){
            int temp = maxHeap->array[parent];
            maxHeap->array[parent] = maxHeap->array[i];
            maxHeap->array[i] = temp;
        }
        i--;
    }
}
int getMaxHeapData(struct Heap* maxHeap){
    if(maxHeap->size == 0){
        printf("MaxHeap is Empty.");
        return INT_MIN;
    }
    int value = maxHeap->array[0];
    maxHeap->array[0] = maxHeap->array[maxHeap->size-1];
    maxHeap->size--;
    maxHeapify(maxHeap,0);
    return value;
}
int main() {
    int nums[] = {3,6,9,2,14,78,2,5,7,9,4,3,12};
    int size = sizeof(nums)/sizeof(int);
    struct Heap* maxHeap = createMaxHeap(20,size,nums);
    int i =0;
    for(i=0;i<maxHeap->size;i++){
        printf("%d ",maxHeap->array[i]);
    }
    printf("\n");
    insertSingleValueInMaxHeap(maxHeap,100);
    insertSingleValueInMaxHeap(maxHeap,43);
    insertSingleValueInMaxHeap(maxHeap,10);
    while(maxHeap->size > 0){
        int value = getMaxHeapData(maxHeap);
        printf("%d\n",value);
    }
    free(maxHeap->array);
    free(maxHeap);
    return 0;
}