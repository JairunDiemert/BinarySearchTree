//Amit 19/11/12
//BST  
//Creation, Deletion, Recursive traversals

#include<iostream>

using std::cout;
using std::cin;
using std::endl;
//#include<process>

class btree
{
      int data;
      int ptr;
      btree *lchild,*rchild;
   public:
      btree()
      {
          rchild = 0;
          lchild = 0;
      }

      void create();
      void delete1();
      void preorderRec(btree *a);
      void inorderRec(btree *a);
      void postorderRec(btree *a);

}  *root = 0;

void btree::create()
{
    btree *newNode,*current,*temp;
    newNode = new btree;
    int i;
    cout << "\n\n Please enter data for the new Node: ";
    cin >> i;
    newNode->data = i;

    if(root == 0)
	root = newNode;
    else
    {
        current = root;
	while(current)
	{
	   temp = current;
	   if(current->data < newNode->data)
	       current = current->rchild;
	   else
	       current = current->lchild;
        }

        if(temp->data < newNode->data)
            temp->rchild = newNode;
	else
            temp->lchild = newNode;
    } //end else
} //end create()

void btree::inorderRec(btree *trN)
{
    if(trN->lchild != 0)
    inorderRec(trN->lchild);
    cout << trN->data << "  ";
    if(trN->rchild != 0)
	inorderRec(trN->rchild);
} //end inorderRec()

void btree::preorderRec(btree *trN)
{
    cout << trN->data << "  ";
    if(trN->lchild != 0)
	preorderRec(trN->lchild);
    if(trN->rchild != 0)
	preorderRec(trN->rchild);
} //end preorderRec()


void btree::postorderRec(btree *trN)
{
    if(trN->lchild != 0)
	postorderRec(trN->lchild);
    if(trN->rchild != 0)
	postorderRec(trN->rchild);
    cout << trN->data << "  ";
} //end postorderRec()


void btree::delete1()
{
    btree *lower,*upper;
    int key;
    lower = root;
    upper = NULL;
    cout << "\n\n Enter the data of node to be deleted:   ";
    cin >> key;
    while(lower != NULL && key != lower->data)
    {
	upper = lower;
	if(lower->data < key)
	    lower = lower->rchild;
	else
	    lower = lower->lchild;
    }
    if(lower == NULL)
    {
	cout << "\n\n Key not present in the tree..... ";
	//break;
	return;
    }
    else {
	if(lower->lchild == NULL && lower->rchild == NULL)
	{
            if(upper->data < lower->data)
		upper->rchild = NULL;
	    else
		upper->lchild = NULL;
	    delete(lower);
        }
	else {
	   if(lower->lchild == NULL && lower->rchild != NULL)
	   {
	       if(upper->data < lower->data)
		   upper->rchild = lower->rchild;
	       else
		   upper->lchild = lower->rchild;
	       delete(lower);
	   }
	   else {
	      if(lower->rchild == NULL && lower->lchild != NULL)
	      {
	          if(upper->data < lower->data)
		      upper->rchild = lower->lchild;
		  else
		      upper->lchild = lower->lchild;
		  delete(lower);
	      }
	      else
	      {
	          btree *first,*res,*second;
	          first = lower;
	          res = lower->rchild;
	          second = res->lchild;

                  while(second != NULL)
                  {
	              first = res;
		      res = second;
		      second = res->lchild;
		  }
		  if(first != lower)
		  {
		      first->lchild = res->rchild;
		      res->rchild = lower->rchild;
	          }
		  res->lchild = lower->lchild;
                  if(upper == NULL)
	              root = res;
		  else
		  {
		      if(lower == upper->lchild)
		          upper->lchild = res;
		      else
		          upper->rchild = res;
                  }
	      }
          }
      }
   }
}

int main()
{
    cout << "\tThis program creates a BST for you. It allows to add and delete nodes." << endl;
    cout <<"\tIt allows you to print traversals." << endl;
    btree bt;
    while(1)
    {
        cout << "\n\n\t  Binary Search Tree: Options ";
	cout << "\n      ------------------------------------------";
	cout << "\n\t    Insert a Tree Node - 1 ";
	cout << "\n\t    Delete a Tree Node - 2 ";
	cout << "\n\t    Print Inorder      - 3 ";
	cout << "\n\t    Print Preorder     - 4 ";
	cout << "\n\t    Print Postorder    - 5 ";
	cout << "\n\t    End the Program    - 6 ";
	cout << "\n      ------------------------------------------";
	cout << "\n\t\t  Please enter your choice [1-6] : ";
	int ch;
	cin >> ch;

	switch(ch)
	{
	   case 1:
	           bt.create();
		   break;
	   case 2:
		   bt.delete1();
		   break;
	   case 3:
                   cout << "\n\n\t\tThe tree - InOrder: "; 
                   bt.inorderRec(root);
                   cout << "\n" << endl;
		   break;
	   case 4:
                   cout << "\n\n\t\tThe tree - PreOrder: "; 
                   bt.preorderRec(root);
                   cout << "\n" << endl;
		   break;
	   case 5:
                   cout << "\n\n\t\tThe tree - PostOrder: "; 
      	           bt.postorderRec(root);
                   cout << "\n" << endl;
		   break;
	   case 6:
		   cout << "\n\n\t\t Thanks! Ending now...\n\n";
		   std::exit(0);
	    } //end switch
    } //end while

    return 0;
} // end main
