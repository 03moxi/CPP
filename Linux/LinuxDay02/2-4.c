#include<stdio.h>

#define SWAP(arr, i, j) {       \
    int tmp = arr[i];           \
    arr[i]  = arr[j];           \
    arr[j]  = tmp;              \
}

int findMinId(int arr[], int n){
    int left=0,right=n;
    while(left<right){
        int mid=left+(right-left>>1);
        int count=left;
        for(int i=left;i<right;i++){
            if(arr[i]<mid){
                SWAP(arr,count,i);
                count++;
            }
        }
        if(count==mid+1){
            left=count;
        }else{
            right=count-1;
        }
    }
    if(arr[left]==left){
        return left+1;
    }
    return left;
}

int main(void) {
    int arr[] = {9, 5, 2, 7, 20, 3, 1, 6, 8, 11};
    int minId = findMinId(arr, 10);

    printf("minId = %d\n", minId);

    return 0;
}
