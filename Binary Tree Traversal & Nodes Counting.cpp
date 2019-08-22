#include<iostream>
#include<string>
using namespace std;

template<class DataType>
struct BiNode{
	DataType data;
	BiNode<DataType> *lchild,*rchild;
};

template<class DataType>
class BiTree{
	public:
	    BiTree(){root=Creat(root);}
		~BiTree(){Release(root);}
		void PreOrder(BiNode<DataType> *&bt);   //前序
		void InOrder(BiNode<DataType> *&bt);    //中序
		void PostOrder(BiNode<DataType> *&bt);  //后序
		void LeverOrder(BiNode<DataType> *&bt); //层序
		BiNode<DataType> *root; //指向根结点的头结点
		void Displeaves(BiNode<DataType> *&bt);  //计算叶子数；
    	int leaves;  //叶子数 
	private:
	    BiNode<DataType>* Creat(BiNode<DataType> *bt);    //建立二叉树
		void Release(BiNode<DataType> *bt);    //释放二叉树
};

template<class DataType>
BiNode<DataType>* BiTree<DataType>::Creat(BiNode<DataType> *bt){  //bt为指向根结点的指针
	DataType ch;
	cin>>ch;    //输入结点的数据信息
	if(ch=='#') bt=NULL;     //当遇到#时，令树的根节点为NULL，从而结束该分支的递归
	else{
		bt=new BiNode<DataType>;    //bt变为指向下一层子树的根结点
		bt->data=ch;
		bt->lchild=Creat(bt->lchild);    //前序建立，先不停地建立左孩子的左孩子的左孩子的……一层一层往下一直到出现#然后回到倒数第二层
		bt->rchild=Creat(bt->rchild);    //现在一层一层往上返回，没有右孩子就返回上一层
	}
	return bt;    //此时bt又回到了初始位置，指向整个树的根
}

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

template<class DataType>
void BiTree<DataType>::PostOrder(BiNode<DataType> *&root){
	if(root==NULL) return;
	else{
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		cout<<root->data;
	}
}

template<class DataType>
void BiTree<DataType>::LeverOrder(BiNode<DataType> *&root){

}

template<class DataType>
void BiTree<DataType>::Displeaves(BiNode<DataType> *&root){
	if(root!=NULL){
		if(root->lchild==NULL&&root->rchild==NULL) leaves++;
		Displeaves(root->lchild);
		Displeaves(root->rchild);
	}
}

int main(){
	cout<<"请输入创建一棵二叉树的结点数据"<<endl;
	BiTree<char> T;
	T.leaves=0;
	cout<<"------前序遍历------ "<<endl;
	T.PreOrder(T.root);
	cout<<endl;
	cout<<"------中序遍历------ "<<endl;
	T.InOrder(T.root);
	cout<<endl;
	cout<<"------后序遍历------ "<<endl;
	T.PostOrder(T.root);
	cout<<endl;
	cout<<"------层序遍历------ "<<endl;
	//T.LeverOrder();
	cout<<endl;
	cout<<"------叶节点数------ "<<endl;
	T.Displeaves(T.root);
	cout<<T.leaves;
	return 0;
}
