//   DFS

#include<iostream.h>
#include<conio.h>

int graph[20][3], rows=-1;
int vFlag[20][2], tNodes, index = 0;

///////////////////////////////////
/////      STACK              /////
///////////////////////////////////

class node
{
  public:
	int info;
	node *next;

  node(int data, node *ptr = '\0')
	{
	  info = data;
	  next = ptr;
	}
};

class stack
{
	node *top;

  public:
  stack()
	{ top = '\0'; }

  int givetop()
  {  return top->info;  }

  void push(int val)
  {
    if(top != '\0')
      top = new node(val, top);
    else
      top = new node(val);
  }

  void pop()
  {
    if(top != '\0')
	    top = top->next;
    else
	    return;
  }

}S;

///////////////////////////////////

int getFirstIndex(int n)
{
  for (int c = 0; c < rows; c++)
    if(graph[c][0] == n)
      return c;
  return -1;
}

void printGraph()
{
 clrscr();
 cout<<"\nYour Graph: ";
 cout<<"\n\n  From     To\n\n";
  for(int i = 0; i < rows; i++) {
    for (int j = 0; j < 2; j++) {
      cout<<"    "<<graph[i][j]<<"\t";
    }
    cout<<endl;
  }
}

int checkPeresence(int a, int row, int col)
{
   for(int i=0; i<row; i++)
     if(graph[i][col] == a)
       return 1;
   return 0;
}

void drawGraph(int x, int i, int limit)
{
    int n;
    clrscr();
    cout<<"\nEnter total number of unvisited neighbours of node \'"<<x<<"\': ";
    cin>>n;
    rows += n;

    if(n>0)
    {
      for (int j = i; j < i+n; j++) {
	       graph[j][0] = x;
      }

      for (j = i; j < i+n; j++) {
  	     cout<<"\n\nEnter neighbour("<<j-i+1<<") of \'"<<x<<"\': ";
  	     cin>>graph[j][1];

         for(int c=0; (c<index) && (graph[j][1] != vFlag[c][0]); c++);
  	     if(c == index)
  	       vFlag[index++][0] = graph[j][1];

  	     if(checkPeresence(graph[j][1], rows, 0) == 0)
  	       drawGraph(graph[j][1], rows, limit);
      }
    }
}

/////////////////////////////////////////////////////////////
void markVisited(int val) {
  for(int i=0; i<tNodes; i++)
    if(vFlag[i][0] == val)
    {
      vFlag[i][1] = 1;
      return;
    }
}

int isVisited(int x){
  for (int i = 0; i < tNodes; i++)
    if (vFlag[i][0] == x){
      return (vFlag[i][1] == 1) ? 0 : -1;
    }
  return -1;
}

void fill(int x)
{
  cout<<x<<"   ";
  markVisited(x);
  S.push(x);
}

void DFS(int v, int i)
{
  int j, temp;
  if(isVisited(v == -1))
    fill(v);

  while((S.givetop() == graph[i][0])&&(i<rows)){
    if(isVisited(graph[i][1]) == -1){
      j = getFirstIndex(graph[i][1]);
      if(j != -1){
	      DFS(graph[i][1], j);
      }
      else{
	      fill(graph[i][1]);
	      S.pop();
      }
    }
    i++;
  }
  S.pop();
}

void main()
{
  clrscr();
    int start, t=0;
    rows = 0;

    cout<<"\nEnter total number of nodes in the graph: ";
    cin>>tNodes;
    cout<<"Enter the starting node: ";
    cin>>start;
    vFlag[index++][0] = start;

    clrscr();
    cout<<"Enter the starting node: ";
    drawGraph(start, 0, tNodes-1);
    printGraph();

    for (int c = 0; c < tNodes; c++) {
	     vFlag[c][1] = 0;
    }

    getch();

    cout<<"-------------------\n\n"
	      <<"Output of Depth First Search (DFS) for this graph:"
	      <<"\n\n";

    DFS(start, 0);

  getch();
}
