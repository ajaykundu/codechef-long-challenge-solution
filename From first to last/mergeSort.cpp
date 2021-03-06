#include<stdlib.h>
#include<stdio.h>
#include <iostream>
using namespace std;

void merge(int arr[],int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;
     int L[n1],R[n2];

	for(int i=0;i<n1;i++)
	{
           L[i]=arr[l+i];
	}
	for(int i=0;i<n2;i++)
	{
		R[i]=arr[m+i+1];
	}

	int j=0,p=0,k=l;

	while(j<n1 && p<n2)
	{
		if(L[j]<=R[p])
		{
			arr[k]=L[j];
			j++;
		}
		else
		{
			arr[k]=R[p];
			p++;
		}
		k++;
	}
    while(j<n1)
    {
    	arr[k]=L[j];
    	j++;
    	k++;
    }

    while(p<n2)
    {
    	arr[k]=R[p];
    	p++;
    	k++;
    }
}

void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}