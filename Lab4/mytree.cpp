#include "bst.h"
using namespace std;

int main()
{
  //creats binary search tree object
  BinarySearchTree  <int> T(0); 

  //populates BST
  T.insert(6);
  T.insert(2);
  T.insert(1);
  T.insert(4);
  T.insert(3);
  T.insert(8);	

  //calls printTree
  cout<< "Print Tree :" << endl;
  T.printTree();
  cout<< endl;

  //calls postOrder
  cout<< "Post Order print: ";
  T.postOrder();
  cout<< endl;

  //calls height
  int treeHeight= T.height();
  if(treeHeight == -1)
	cout<< "Tree is empty. Height cannot be computed" << endl;
  else
	  cout<< "Height of BST: "<< treeHeight << endl;
  
  //calls NumLeaves
  int leaves= T.NumLeaves();
  cout<< "Number of leaves in BST: " << leaves << endl;
  
  //calls isBalanced
  bool balance= T.isBalanced();
  if(balance == true)
	cout<< "Tree is balanced." << endl;
  else
	cout<< "Tree is not balanced." << endl;  

  //tests adding nine to see if balanced
  T.insert(9);
  balance = T.isBalanced();
  if(balance == true)
	cout<< "Tree is balanced after adding 9" << endl;
  else
	cout<< "Tree is NOT balanced after adding 9" << endl;
   
 

  return 0;
}
