#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

int parition(int arr[],int low,int high)
{
     int pivot=arr[high];
      int i=low-1;

      for(int j=low;j<=high-1;j++)
      {
      	   if(arr[j]<=pivot)
      	   {
      	   	   i++;
      	   	   swap(arr[i],arr[j]);
      	   }
      }

      swap(arr[i+1],arr[high]);
      return i+1;
}

void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int par=parition(arr,low,high);
		quickSort(arr,low,par-1);
		quickSort(arr,par+1,high);
	}
}



void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}