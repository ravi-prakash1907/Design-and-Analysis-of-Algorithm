//  Red-Black Tree
//  INsertion & Inorder Traversal

#include<stdlib.h>
#include <iostream.h>
#include <conio.h>

#define RED	1
#define BLACK	2


struct node {
	int key;

	struct node *left, *right, *p;
	int color;
};

typedef struct node *NODEPTR;
struct node NIL;
NODEPTR NILPTR = &NIL;

void inorder(NODEPTR x) {
	if (x != NILPTR) {
    inorder(x->left);
    char c = (x->color == RED) ? 'R' : 'B';
		cout<<x->key<<"("<<c<<")  ";
		inorder(x->right);
	}
}

void leftrotate(NODEPTR *treeroot, NODEPTR x) {
	NODEPTR y = x->right;
	x->right = y->left;
	if (y->left != NILPTR)
		y->left->p = x;
	y->p = x->p;
	if (x->p == NILPTR)
		*treeroot = y;
	else if (x->p->left == x)
		x->p->left = y;
	else
		x->p->right = y;
	y->left = x;
	x->p = y;
}

void rightrotate(NODEPTR *treeroot, NODEPTR y) {
	NODEPTR x = y->left;
	y->left = x->right;
	if (x->right != NILPTR)
		x->right->p = y;
	x->p = y->p;
	if (y->p == NILPTR)
		*treeroot = x;
	else if (y->p->left == y)
		y->p->left = x;
	else
		y->p->right = x;
	x->right = y;
	y->p = x;
}

void rbinsertfixup(NODEPTR *treeroot, NODEPTR z) {
	while (z->p->color == RED) {
		if (z->p == z->p->p->left) {
			NODEPTR y = z->p->p->right;
			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {
				if (z == z->p->right) {
					z = z->p;
					leftrotate(treeroot,z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				rightrotate(treeroot,z->p->p);
			}
		}
		else {
			NODEPTR y = z->p->p->left;
			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {
				if (z == z->p->left) {
					z = z->p;
					rightrotate(treeroot,z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				leftrotate(treeroot,z->p->p);
			}
		}
	}
	(*treeroot)->color = BLACK;
}

void rbinsert(NODEPTR *treeroot, int z) {
	NODEPTR Z = (NODEPTR) malloc(sizeof(struct node));
	Z->key = z;
	NODEPTR y = NILPTR;
	NODEPTR x = *treeroot;
	while (x != NILPTR) {
		y = x;
		if (Z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	Z->p = y;
	if (y == NILPTR)
		*treeroot = Z;
	else if (Z->key < y->key)
		y->left = Z;
	else
		y->right = Z;
	Z->left = NILPTR;
	Z->right = NILPTR;
	Z->color = RED;
	rbinsertfixup(treeroot,Z);
}

////////////////////////////////////////////

int menu() {
  clrscr();
  int c;
  cout<<"\nMENU (RBT)\n---------\n";
  cout<<"\n1) Insert Node"
      <<"\n2) Traversal"
      <<"\n3) Exit"
      <<"\n\n* Enter your choice: ";
      cin>>c;
  clrscr();
  return c;
}

int main()
{
  clrscr();
	NIL.left = NIL.right = NIL.p = NILPTR;
	NIL.color = BLACK;
	NODEPTR tree = NILPTR;
	int n;
	int num;

	while (1) {
    n = menu();
			switch(n){
			case 1:	cout<<"\nEnter value of the node: ";
							cin>>num;
					rbinsert(&tree, num);
				break;


				case 2:
					cout<<"\n\nInorder traversal:\n\n";
					inorder(tree);
					cout<<"\n";
					getch();
					break;

					case 3: goto end;

					default:  cout<<"\nInvalid Input!! Try again.";
										getch();
				}
			}
      end:
		return 0;
}
