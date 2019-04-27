// complete
// debugged

#include<iostream.h>
#include<conio.h>

int graph[20][3], rows=-1, index = 0;


///////////////////////////////////
/////      QUEUE              /////
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

class queue
{
	node *head, *tail;

  public:
  queue()
	 {
	    head = '\0';
	    tail = '\0';
	 }

  int giveHead()
  {
    return head->info;
  }
	void enqueue(int val)
  {
    if(head != '\0')
    {
      tail->next = new node(val);
      tail = tail->next;
    }
    else
      head = tail = new node(val);
  }

	int dequeue()
  {
    int temp;
    if(head != '\0')
    {
       temp = head->info;
	   head = head->next;
       return temp;
    }
    else
	return -1;
  }
  int find(int x)
  {
    for(node *i = head; i != '\0'; i=i->next)
      if(i->info == x)
	return 1;
    return 0;
  }

} Q;

///////////////////////////////////


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

	if(checkPeresence(graph[j][1], rows, 0) == 0)  //not present
	  drawGraph(graph[j][1], rows, limit);
      }
    }
}

/////////////////////////////////////////////////////////////
void fill(int x)
{
  cout<<x<<"   ";
  Q.enqueue(x);
}

void BFS()
{
  while ((index < rows) && (Q.giveHead() == graph[index][0])) {
    if(checkPeresence(graph[index][1], index, 1) == 0)  //not present
      fill(graph[index][1]);
    index++;
  }
  if(index < rows)
  {
    do {
      if (Q.dequeue() == -1)
	return;
    } while(Q.giveHead() != graph[index][0]);

    BFS();
  }

  return;
}

void main()
{
  clrscr();
    int t, start;
    rows = 0;

    cout<<"\nEnter total number of nodes in the graph: ";
    cin>>t;
    cout<<"Enter the starting node: ";
    cin>>start;


    clrscr();
    cout<<"Enter the starting node: ";
    drawGraph(start, 0, t-1);
    printGraph();

    getch();

    cout<<"--------------\n\n"
	<<"Output of Breadth First Search (BFS) for this graph:"
	<<"\n\n";
    fill(start);
    BFS();

  getch();
}
