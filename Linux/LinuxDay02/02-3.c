#include<stdio.h>

int findMin(int arr[], int n){
	int left=0,right=n-1;
	while(left<right){
		int mid=left+(right-left>>1);
		if(arr[mid]>arr[right]){
			left=mid+1;
		}else{
			right=mid;
		}
	}
	return arr[left];
}

int main()
{
	int arr[]={4,5,6,7,0,1,2};
	int n=sizeof(arr)/sizeof(arr[0]);;
	printf("%d ",findMin(arr,n));
	return 0;
}
