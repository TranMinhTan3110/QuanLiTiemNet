/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct node{
	int info;
	node*left, *right;
};
//
typedef node* Tree;
//tao node
node* getNode(int x) {
    node* p = new node;
    p->info = x;
	p->left = NULL;
	p->right =NULL;
    return p;
}
void insertTree(Tree &T, int x){
	if(T!=NULL){
	if(T->info==x)
		cout<<" ";
	else if(x<T->info){
		//them x vao trai
		//lenh goi de quy
		insertTree(T->left,x);
		}
	else{
		insertTree(T->right,x);
	}
	}
	else
	//cay hien hanh o lan goi de quy có goc la null
	T=getNode(x);
	//T->left=x;
}
//
//void NLR(Tree T){
//	//T==NULL
//	if(!T) return;
//	cout<<T->info<<" ";
//	//doc hêt nhanh trai
//	NLR(T->left);
//	NLR(T->right);
//}
////LRN
//void LRN(Tree T){
//	if(!T) return;
//	LRN(T->left);
//	LRN(T->right);
//	cout<<T->info<<" ";
//}
void LNR(Tree T){
	if(!T) return;
	LNR(T->left);
	cout<<T->info<<" ";
	LNR(T->right);
}
void inputTree(Tree &T){
	int n;
	cin>>n;
	int x;
	for(int i=0; i<n; i++){
		cin>>x;
		insertTree(T,x);
		//them x vao cây T
	}
}
	//dem so luong
int countNodes(Tree T){
	if(T==NULL) return 0;
	int dem=0;
	if(T!=NULL){
		dem++;
		return dem+countNodes(T->left)+countNodes(T->right);
	}
}
int countLeafs(Tree T){
	if(T==NULL) return 0;
	int dem=0;
	if(T!=NULL){
		if(T->left ==NULL && T->right==NULL)
			dem++;
			 return dem+countLeafs(T->left)+countLeafs(T->right);
	}
}
//1 con
int countOneChild(Tree T){
		if(T==NULL) return 0;
	int dem=0;
	if(T!=NULL){
		if((T->left !=NULL && T->right==NULL) || (T->left ==NULL && T->right!=NULL) )
			dem++;
			 return dem+countOneChild(T->left)+countOneChild(T->right);
	}
}
//2 con
int countTwoChildren(Tree T){
		if(T==NULL) return 0;
	int dem=0;
	if(T!=NULL){
		if((T->left !=NULL && T->right!=NULL))
			dem++;
			 return dem+countTwoChildren(T->left)+countTwoChildren(T->right);
	}
}	
//so sanh
int countLess(Tree T, int x){
	if(!T)
	return 0;
	int dem =0;
	if(T->info<x)
	dem++;
	 return dem+ countLess(T->left,x)+countLess(T->right,x);
}
int countBetweenValues(Tree T,int x, int y){
		if(!T)
	return 0;
	int dem =0;
	if(T->info>x && T->info<y)
	dem++;
	 return dem+ countBetweenValues( T->left,x,y)+countBetweenValues( T->right,x,y);
}
int countInternalNodes(Tree T) {
    if (T == NULL || (T->left == NULL && T->right == NULL)) return 0;
    return 1 + countInternalNodes(T->left) + countInternalNodes(T->right);
}
	
	
int main()
{
	Tree T = NULL;
	inputTree(T);

    cout<<"Number of nodes: " << countNodes(T)<<endl;
	cout<<"Number of leaf nodes: " << countLeafs(T)<<endl;
	cout<<"Number of internal nodes: "<< countInternalNodes(T)<<endl;
	cout<<"Number of nodes with one child: "<< countOneChild(T)<<endl;
	cout<<"Number of nodes with two children: "<< countTwoChildren(T)<<endl;

	int x;cout<<"Enter x: ";cin>>x;
	cout<<"\nNumber of nodes less than "<<x<<": "<< countLess(T,x)<<endl;
	int y; cout<<"Enter x,y: ";cin>>x>>y;
	cout<<"\nNumber of nodes greater than "<<x<<" and less than "<<y<<": "<< countBetweenValues(T,x,y)<<endl;

	return 0;
}
