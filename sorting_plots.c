/*
bubble -> green
heapsort -> red
insertion -> chocolate
mergesort -> blue
quicksort ->black
selection -> magenta
*/
#include "koolplot.h"
#include<time.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void printArray(double arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%lf ", arr[i]);
	printf("\n");
}
void adjust(int *a,int i,int n)
{
    int j,t;
    while(2*i<=n)
    {
        j=2*i;
        if(j+1<=n)
        {
            if(a[j+1]>a[j])
            j=j+1;
        }
        if(a[j]>a[i])
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
        else
            break;
        i=j;
    }
}
void maxheapify(int *a,int n)
{
    int i;
    for(i=n/2;i>0;i--)
        adjust(a,i,n);
}
void heapsort(int *a,int n)
{
    int t,i;
    maxheapify(a,n);
    for(i=n;i>1;i--)
    {
        t=a[1];
        a[1]=a[i];
        a[i]=t;
        adjust(a,1,i-1);
    }
}
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
void merge(int *a,int low,int mid,int high)
{
    int i=low,j=mid+1,k=0;
    int c[100000],s;
    s=high-low+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=high)
        c[k++]=a[j++];
	for(i=0;i<k;i++)
    a[low+i]=c[i];
    return;
}
void mergesort(int *a,int low,int high)
{
    if(low<high)
    {
        int mid;
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
    return;
}
int partition(int *a,int low,int high)
{
    int t,i,j,pivot,r;
    r=rand()%(high-low+1);
    i=low;
    j=high+1;
    t=a[low];
    a[low]=a[low+r];
    a[low+r]=t;
    pivot=a[low];
    do{
    do{
        i++;
    }while(a[i]<pivot);
    do{
        j--;
    }while(a[j]>pivot);
    if(i<j)
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    }while(i<j);
    t=a[j];
    a[j]=a[low];
    a[low]=t;
    return j;
}
void quicksort(int *a,int low,int high)
{
    if(low<high)
    {
        int j;
        j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}
void makearray(int arr[],int a[],int k,int lim)
{
	int m,i,j=0;
	for(i=0;i<lim/k;i++)
	{
		for(m=0;m<k;m++)
		a[j++]=arr[m];
	}
}
int main()
{
	int lim,arr[20]={58,2,951,425,687,25,0,87,689,145,124,745,555,298,780,359,158,901,36,499},k=20;
	int a[400000],n,i,p;
	p=20000;
	clock_t start,end;
	double cpu,x[5],y[5];
	plotdata pdata,qdata;
	n=p;
	for(i=0;i<5;i++)
	{
	start=clock();
	makearray(arr,a,k,n);
    bubbleSort(a,n);
	end=clock();
	cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
	x[i]=n/1000;
	y[i]=cpu;
	n+=p;
	}
	printArray(x,5);
	printArray(y,5);
	insert(pdata,x,5);
	insert(qdata,y,5);
	setColor(pdata,qdata,REDRED);
	n=p;
	for(i=0;i<5;i++)
	{
	start=clock();
	makearray(arr,a,k,n);
    heapsort(a,n-1);
	end=clock();
	cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
	x[i]=n/1000;
	y[i]=cpu;
	n+=p;
	}
	printArray(x,5);
	printArray(y,5);
	insert(pdata,x,5);
	insert(qdata,y,5);
	setColor(pdata,qdata,CHOCOLATE);
	n=p;
	for(i=0;i<5;i++)
	{
	start=clock();
	makearray(arr,a,k,n);
    insertionSort(a,n);
	end=clock();
	cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
	x[i]=n/1000;
	y[i]=cpu;
	n+=p;
	}
	printArray(x,5);
	printArray(y,5);
	insert(pdata,x,5);
	insert(qdata,y,5);
	setColor(pdata,qdata,MEDIUMBLUE);
	n=p;
	for(i=0;i<5;i++)
	{
	start=clock();
	makearray(arr,a,k,n);
    mergesort(a,0,n-1);
	end=clock();
	cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
	x[i]=n/1000;
	y[i]=cpu;
	n+=p;
	}
	printArray(x,5);
	printArray(y,5);
	insert(pdata,x,5);
	insert(qdata,y,5);
	setColor(pdata,qdata,BLACK);
	n=p;
	for(i=0;i<5;i++)
	{
	start=clock();
	makearray(arr,a,k,n);
    quicksort(a,0,n-1);
	end=clock();
	cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
	x[i]=n/1000;
	y[i]=cpu;
	n+=p;
	}
	printArray(x,5);
	printArray(y,5);
	insert(pdata,x,5);
	insert(qdata,y,5);
	setColor(pdata,qdata,MAGENTA);
	n=p;
	for(i=0;i<5;i++)
	{
	start=clock();
	makearray(arr,a,k,n);
    selectionSort(a,n);
	end=clock();
	cpu = ((double) (end - start)) / CLOCKS_PER_SEC;
	x[i]=n/1000;
	y[i]=cpu;
	n+=p;
	}
	printArray(x,5);
	printArray(y,5);
	insert(pdata,x,5);
	insert(qdata,y,5);
	axesTopRight(pdata,qdata,1,0.005);
	plot(pdata,qdata);
	/*makearray(arr,a,k,n);
	heapsort(a,n-1);
	makearray(arr,a,k,n);
    counting(a,n,999);
	makearray(arr,a,k,n);
	mergesort(a,0,n-1);
	makearray(arr,a,k,n);
	insertionSort(a,n);
	makearray(arr,a,k,n);
	quicksort(a,0,n-1);
	makearray(arr,a,k,n);
	selectionSort(a,n); 
	printArray(a,n);
	*/return 0;
}

