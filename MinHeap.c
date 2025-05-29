#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct MinHeap{
    int* array;
    int size;
    int capacity;
};
void heapify(struct MinHeap* heap,int index){
    int left = index*2 + 1;
    int right = index*2 + 2;
    int min = index;
    if(left >= heap->size || left < 0){
        left = -1;
    }
    if(right >= heap->size || right < 0){
        right = -1;
    }
    if(left != -1 && heap->array[left] < heap->array[min]){
        min = left;
    }
    if(right != -1 && heap->array[right] < heap->array[min]){
        min = right;
    }
    if(min != index){
        int temp = heap->array[min];
        heap->array[min] = heap->array[index];
        heap->array[index] = temp;
        heapify(heap,min);
    }
}
struct MinHeap* createHeap(int capacity,int* nums){
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    if(minHeap == NULL){
        printf("Error while creating MinHeap");
        return NULL;
    }
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (int*)malloc(sizeof(int)*capacity);
    int i=0;
    for(i=0;i<capacity;i++){
        minHeap->array[i] = nums[i];
        minHeap->size++;
    }
    i = (minHeap->size-1)/2;
    while(i >= 0){
        heapify(minHeap,i);
        i--;
    }
    return minHeap;
}
int getValue(struct MinHeap* heap){
    if(heap->size == 0) return INT_MIN;
    int value = heap->array[0];
    heap->array[0] = heap->array[heap->size-1];
    heap->size--;
    heapify(heap,0);
    return value;
}
void main(){
    int nums[] = {40,6,22,5,91,2,19,96,0,2,6,3};
    int capacity = sizeof(nums)/sizeof(int);
    struct MinHeap* minHeap = createHeap(capacity,nums);
    int i=0;
    for(i=0;i<capacity;i++){
        printf("%d ",minHeap->array[i]);
    }
    printf("\n");
    int value;
    while(minHeap->size > 0){
        value = getValue(minHeap);
        printf("%d \n",value);
    }
    for(i=0;i<minHeap->size;i++){
        printf("%d ",minHeap->array[i]);
    }
    free(minHeap);
}