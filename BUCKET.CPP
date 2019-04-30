#include <conio.h>
#include <iostream.h>
#include <stdlib.h>

class bucket {
public:
	float data;
	bucket* next;

	bucket(float a, bucket* b)
	{
		data = a;
		next = b;
	}
};

void bucketSort(bucket* list[], float arr[], int s)
{
	int pos;
	float tempData, x;
	bucket* temp = NULL;

	for (int i = 0; i < s; i++)
	{
		tempData = arr[i];
		pos = s*tempData;
		temp = list[pos];

	  check:
		if (temp == NULL)
		{
			list[pos] = new bucket(tempData, NULL);
		}
		else if (temp->data > tempData)
		{
			list[pos] = new bucket(tempData, list[pos]);
		}
		else{
			list[pos] = list[pos]->next;
			goto check;
		}

	}


}

void join(float arr[], bucket* list[], int s) {
	clrscr();
	int j=0;
	for (int i = 0; i < s; i++)
	{
		if (list[i] != NULL)
		{
			for (bucket* temp = list[i]; temp != NULL; temp =temp->next)
			{
				arr[j] = temp->data;
				j++;
			}
		}
	}
}

void main()
{
	clrscr();
		int size;
		float array[10];

		cout<<"Size: ";
		cin>>size;

		cout<<"Array (of size "<<size<<"): \n";
		for (int i = 0; i < size; i++)
		{
			cin>>array[i];
		}

		getch();
		clrscr();

		cout<<"\n\n Your array: \n";
		for (i = 0; i < size; i++)
		{
			cout<<array[i]<<"  ";
		}

		getch();
		clrscr();

		//create bucket
		bucket* list[10];
		for (i = 0; i < size; i++)
		{
			list[i] = NULL;
		}

		bucketSort(list, array, size);
		join(array, list, size);

		cout<<"\n\n Sorted array: \n";
		for (i = 0; i < size; i++)
		{
			cout<<array[i]<<"  ";
		}

	getch();
}