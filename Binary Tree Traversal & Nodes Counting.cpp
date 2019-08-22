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
		void PreOrder(BiNode<DataType> *&bt);   //ǰ��
		void InOrder(BiNode<DataType> *&bt);    //����
		void PostOrder(BiNode<DataType> *&bt);  //����
		void LeverOrder(BiNode<DataType> *&bt); //����
		BiNode<DataType> *root; //ָ�������ͷ���
		void Displeaves(BiNode<DataType> *&bt);  //����Ҷ������
    	int leaves;  //Ҷ���� 
	private:
	    BiNode<DataType>* Creat(BiNode<DataType> *bt);    //����������
		void Release(BiNode<DataType> *bt);    //�ͷŶ�����
};

template<class DataType>
BiNode<DataType>* BiTree<DataType>::Creat(BiNode<DataType> *bt){  //btΪָ�������ָ��
	DataType ch;
	cin>>ch;    //�������������Ϣ
	if(ch=='#') bt=NULL;     //������#ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�
	else{
		bt=new BiNode<DataType>;    //bt��Ϊָ����һ�������ĸ����
		bt->data=ch;
		bt->lchild=Creat(bt->lchild);    //ǰ�������Ȳ�ͣ�ؽ������ӵ����ӵ����ӵġ���һ��һ������һֱ������#Ȼ��ص������ڶ���
		bt->rchild=Creat(bt->rchild);    //����һ��һ�����Ϸ��أ�û���Һ��Ӿͷ�����һ��
	}
	return bt;    //��ʱbt�ֻص��˳�ʼλ�ã�ָ���������ĸ�
}

template<class DataType>
void BiTree<DataType>::Release(BiNode<DataType> *bt){
	if(bt!=NULL){
		Release(bt->lchild);    //�ͷ�������
		Release(bt->rchild);    //�ͷ�������
		delete bt;    //�ͷŸ����
	}
}

template<class DataType>
void BiTree<DataType>::PreOrder(BiNode<DataType> *&root){
	if(root==NULL) return;    //�ݹ���õĽ�������
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
	cout<<"�����봴��һ�ö������Ľ������"<<endl;
	BiTree<char> T;
	T.leaves=0;
	cout<<"------ǰ�����------ "<<endl;
	T.PreOrder(T.root);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	T.InOrder(T.root);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	T.PostOrder(T.root);
	cout<<endl;
	cout<<"------�������------ "<<endl;
	//T.LeverOrder();
	cout<<endl;
	cout<<"------Ҷ�ڵ���------ "<<endl;
	T.Displeaves(T.root);
	cout<<T.leaves;
	return 0;
}
