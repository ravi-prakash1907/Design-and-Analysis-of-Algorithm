//Radix Sort

#include <iostream.h>
#include <conio.h>
#include <math.h>

int dig(int x)
{
	int num=0;
	while(x != 0) {
 		num++;
 		x /= 10;
 	}
	return num;
}

int reverse(int num)
{
	int digit, rev=0;
	while (num != 0)
  {
      digit = num % 10;
      rev = (rev * 10) + digit;
      num /= 10;
  }
	return rev;
}

 int digAtPosN(int x, int pos)		// Perfect
 {
	 x = reverse(x);
	 int numOfDig = dig(x);
	 if(numOfDig < pos)
	 	return 0;
	 int num = pow(10, pos);
	 while(x>=num)
	 {
		 x /= 10;
	 }
	 return (x%10);
 }

void radixSort(int a[], int size, int nLen)
{
	int i, j, k, t, ts, tl, temp[10], small[10], large[10], nthDigitReal, nthDigitTemp;

	for (i = 0; i < 10; i++) {
		small[i] = '\0';
		large[i] = '\0';
		temp[i] = (i<size) ? a[i] : '\0';
	}

	for (i = 1; i <= nLen; i++)		// how many times the shorting is done, once, tens....
	{
		for (j = 0; j < size; j++) {
			ts = tl = 0;
			nthDigitReal = digAtPosN(a[j], i);

			for (k = 0; k < size; k++) {
				nthDigitTemp = digAtPosN(temp[k], i);
				if(nthDigitTemp < nthDigitReal)
					small[ts++] = temp[k];
				else
					large[tl++] = temp[k];
			}

			for (k = 0; small[k] != '\0'; k++)
				temp[k] = small[k];
			for (t = 0; large[t] != '\0'; t++)
				temp[k+t] = large[t];

			for (k = 0; k < size; k++) {
				small[k] = '\0';
				large[k] = '\0';
			}
		}
		for (k = 0; k < size; k++) {
			a[k] = temp[k];
		}
	}
}


 void main()
 {
 	clrscr();
 	int arr[10], size, largest, i;

	cout<<"\nEnter the size of array (max. 10): ";
	cin>>size;
	cout<<"\nEnter positive elements in the array: \n";
	for(i=0; i<size; i++)
		cin>>arr[i];

	clrscr();
	largest = arr[0];
	cout<<"\n Your array: \n";
	for(i=0; i<size; i++)
 	{
 		cout<<arr[i]<<"  ";
 		if(arr[i]>largest)
			largest = arr[i];
 	}

	getch();
	int j = dig(largest);
	radixSort(arr, size, j);

	clrscr();
	cout<<"\n Sorted array: ";
 	for(i=0; i<size; i++)
 	{
 		cout<<arr[i]<<"  ";
 	}

 	getch();
 }
