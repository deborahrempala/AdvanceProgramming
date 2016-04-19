#include <iomanip>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <windows.h>


// function prototype
void merge_sort(int [],int ,int );
void merge(int [],int,int ,int );

// quick sort prototype
int partition(int [], int , int , int );
void quicksort(int [], int , int );
using namespace std;
// start main
int main()
{
	// seed time
	srand(time(NULL));
	// create array
	int size = 10000;
	int swap;
	int count =0;
	// bubble sort timer
	int timer1 = clock();
	//quick sort timer
	
	// merge sort timer
	int timer3 = clock();
	// bubble sort 
	int sortarray[size];
	// quick sort array
	int quickarray[size];
	// merge sort array
	int mergearray[size];
	
	// temp array
	int temparray[size];
	int number[size];
	// put random number in  temp arrays
	for(int i =0; i< size; i ++)
	{
		number[i]= (rand() % 10001) + 1;
        //cout<<number[i]<<endl;
		Sleep(10);
		// put number in a temporary array
		temparray[i] = number [i];
		count ++;
	}
	// put temporary array into 3 seperate arrays
	// so that each sort has same numbers
	for(int c =0; c< size; c ++)
	{
		temparray[c] = sortarray[c];
		temparray[c] = quickarray[c];
		temparray[c] = mergearray[c];
	}
 
  // bubble sort
	

  for (int j = 0 ; j < ( size - 1 ); j++)
  {
	 
    for (int k = 0 ; k < size - j- 1; k++)
    {
      if (sortarray[k] > sortarray[k+1]) 
      {
        swap       = sortarray[k];
        sortarray[k]   = sortarray[k+1];
        sortarray[k+1] = swap;
	    timer1 = clock();
      }
    }
  }

  
  // debbugging purposes
  //for(int d =0; d < size; d ++)
   //cout<<sortarray[d]<<endl;



// print statement for total time 
cout<<"Bubble Sort...... "<<"it took "<<(timer1/1000)<<" seconds to sort "<<count<< " items"<<endl;


// merge Sort
   int first=1;
   merge_sort(mergearray,first,size);

// quick sort
int left =0;

quicksort(quickarray, 0, size);

}









// function for merge sort
void merge_sort(int a[],int p,int r)
    {
	    int timer2 = clock();
        int q;
        if(p<r)
        {
         q=(p+r)/2;
         merge_sort(a,p,q);
         merge_sort(a,q+1,r);
         merge(a,p,q,r);
	     timer2 = clock();
        }
		// print statement for time
		cout<<"Merge Sort...... "<<"it took "<<(timer2/1000)<<" seconds to sort "<<endl;
		
    }

 void merge(int a[],int p,int q,int r)
    {
        int n1=q-p+1;
        int n2=r-q;
        int L[n1+1];
        int R[n2+1];
        for(int i=1;i<=n1;i++)
        {
            L[i]=a[p+i-1];
        }
        for(int j=1;j<=n2;j++)
        {
            R[j]=a[q+j];
        }
        L[n1+1]=200000;
        R[n2+1]=200000;
        int i=1, j=1;
        for(int k=p;k<=r;k++)
        {
            if(L[i]<=R[j])
            {
                a[k]=L[i];
                i=i+1;
            }
            else
            {
                a[k]=R[j];
                j=j+1;
            }
        }
    }

// quick sort

// usinng lomatos partition
int partition(int a[], int left, int right, int pivotIndex)
{
    int pivot = a[pivotIndex];
    do
    {
        while (a[left] < pivot) left++;
        while (a[right] > pivot) right--;
        if (left < right && a[left] != a[right])
        {
            swap(a[left], a[right]);
        }
        else
        {
            return right;
        }
    }
    while (left < right);
    return right;
}
// quick sort function
void quicksort(int a[], int left, int right)
{ int timer3 = clock();
    if (left < right)
    {
        int pivot = (left + right) / 2; // middle
        int pivotNew = partition(a, left, right, pivot);
        quicksort(a, left, pivotNew - 1);
        quicksort(a, pivotNew + 1, right);
		timer3 = clock();
    }
		cout<<"Quick Sort...... "<<"it took "<<(timer3/1000)<<" seconds to sort "<<endl;
}












