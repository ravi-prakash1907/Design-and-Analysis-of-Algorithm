//Longest Common Sub-sequence  (LCS)

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

void LCS(char *x, char *y){
  int m, n;
  m = strlen(x);
  n = strlen(y);
  char b[20][20];
  char c[20][20];  //c[m+1][n+1]

  for(int i=0; i<m+1; i++)
  {
    c[i][0] = '0';
    b[i][0] = ' ';
  }
  for(int j=0; j<n+1; j++)   // j==1 probably
  {
    c[0][j] = '0';
    b[0][j] = ' ';
  }

  for(i=1; i<m+1; i++)
    for(j=1; j<n+1; j++)
    {
      if(x[i-1] == y[j-1]){
	c[i][j]=c[i-1][j-1] + 1;
	b[i][j] = '\\';
      }
      else if(c[i-1][j] >= c[i][j-1]){
	c[i][j]=c[i-1][j];
	b[i][j] = '|';
      }
      else{
	c[i][j]=c[i][j-1];
	b[i][j] = '-';
      }
    }
  for (i = 0; i < m+1; i++) {
    for (j = 0; j < m+1; j++) {
      cout<<c[i][j]<<b[i][j]<<"  ";
    }
    cout<<endl;
  }
}

void main()
{
  clrscr();
   int m, n;
   char y[10], x[10];
   cout<<"Enter the array \'X\' and \'Y\': ";
   gets(x);
   gets(y);

   LCS(x, y);

  getch();
}
