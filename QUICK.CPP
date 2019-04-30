#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

int partition(int a[], int p, int r)
{
  int j = p-1, i, x;
  for (i = p; i <= r-1; i++) {
    if(a[i] <= a[r]){
      j += 1;
      //  swap a[j] a[i]
      x = a[j];
      a[j] = a[i];
      a[i] = x;
    }
  }

  x = a[j+1];
  a[j+1] = a[r];
  a[r] = x;

  return j+1;
}

void quickSort(int a[], int p, int r)
{
  if (p<r) {
    int q = partition(a, p, r);
    quickSort(a, p, q-1);
    quickSort(a, q+1, r);
  }
}

void main()
{
 clrscr();
 int arr[10], size, i;

 cout<<"\nEnter the size of array (max. 10): ";
 cin>>size;
 cout<<"\nEnter the array: \n";
 for(i=0; i<size; i++)
   cin>>arr[i];

 clrscr();
 cout<<"\n Your array: \n";
 for(i=0; i<size; i++)
   cout<<arr[i]<<"  ";

 getch();
 quickSort(arr, 0, size-1);

 clrscr();
 cout<<"\n Sorted array: ";
 for(i=0; i<size; i++)
   cout<<arr[i]<<"  ";

 getch();
}
