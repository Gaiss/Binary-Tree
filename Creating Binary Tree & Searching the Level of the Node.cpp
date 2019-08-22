//先序和中序构造二叉树
//求值为X的结点的层数 
#include<iostream>
using namespace std;

template<class DataType>
struct BiNode{
	DataType data;
	BiNode<DataType> *lchild,*rchild;
};

template<class DataType>
class BiTree{
	public:
	    BiTree(){root=NULL;}
		~BiTree(){Release(root);}
		void PreOrder(BiNode<DataType> *&bt);   //前序
		void InOrder(BiNode<DataType> *&bt);    //中序
		BiNode<DataType>* root; //指向根结点的头结点
		BiNode<DataType>* CreatBT(DataType *pre , DataType *in ,int n);  //先序和中序构造二叉树
        int level(BiNode<DataType> *bt, DataType x, int h);  //求值为X的结点的层数 
	private:
		void Release(BiNode<DataType> *bt);    //释放二叉树
};

template<class DataType>
void BiTree<DataType>::Release(BiNode<DataType> *bt){
	if(bt!=NULL){
		Release(bt->lchild);    //释放左子树
		Release(bt->rchild);    //释放右子树
		delete bt;    //释放根结点
	}
}

template<class DataType>
void BiTree<DataType>::PreOrder(BiNode<DataType> *&root){
	if(root==NULL) return;    //递归调用的结束条件
	else{
		cout<<root->data;
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}

template<class DataType>
void BiTree<DataType>::InOrder(BiNode<DataType> *&root){
	if(root==NULL) return;
	else{
		InOrder(root->lchild);
		cout<<root->data;
		InOrder(root->rchild);
	}
}

/* 算法 
1、通过先序遍历找到根结点A，再通过A在中序遍历的位置找出左子树，右子树 
2、在A的左子树中，找左子树的根结点（在先序中找），转步骤1 
3、在A的右子树中，找右子树的根结点（在先序中找），转步骤1    
*/  
template<class DataType>
BiNode<DataType>* BiTree<DataType>::CreatBT(DataType *pre ,DataType *in ,int n){  //pre：存放先序序列，in：存放中序序列，n为结点个数，返回根指针  
	BiNode<DataType> *b;  //根结点 
    DataType *p ;  
    int k ;   //储存对应值所在的序列 
    if(n<=0)  return NULL;  //判空 
    b=new BiNode<DataType>;  
    b->data = *pre ;  //前序第一个是根结点 
    for(p=in;p<in+n;p++) { //在中序中找到值为*pre的位置k  
        if(*p == *pre)   //指向根结点 
            break;  //在in中找到后退出循环 
    }  
    k=p-in;           //确定根节点在中序序列(in)中的位置 编号为0,1,2,...,n-1 (数组中的下标号，不是逻辑序号)   
    b->lchild = CreatBT(pre+1,in,k);   //递归构造左子数   
    b->rchild = CreatBT(pre+1+k,p+1,n-k-1);  //递归构造右子树   
    return b ;  
}

template<class DataType>
int BiTree<DataType>::level(BiNode<DataType> *bt, DataType x, int h){
	if(bt!= NULL){  
        if (bt->data == x)   return h;  
        level(bt->lchild, x, h++);  
        level(bt->rchild, x, h++);  
    }  
}  

int main(){
	BiTree<char> T;
	char pre[20]="ABDEHICFG";  
	char in[20]="DBHEIAFCG";
	T.root=T.CreatBT(pre,in,9);
	cout<<"前序周游："<<endl;
	T.PreOrder(T.root);
	cout<<endl; 
	cout<<"中序周游："<<endl;
	T.InOrder(T.root);
	cout<<endl;
	cout<<"查找值为E的结点的层数："<<endl;
	cout<<T.level(T.root,'E',1);
	return 0;
} 
