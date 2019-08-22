//����������������
//��ֵΪX�Ľ��Ĳ��� 
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
		void PreOrder(BiNode<DataType> *&bt);   //ǰ��
		void InOrder(BiNode<DataType> *&bt);    //����
		BiNode<DataType>* root; //ָ�������ͷ���
		BiNode<DataType>* CreatBT(DataType *pre , DataType *in ,int n);  //����������������
        int level(BiNode<DataType> *bt, DataType x, int h);  //��ֵΪX�Ľ��Ĳ��� 
	private:
		void Release(BiNode<DataType> *bt);    //�ͷŶ�����
};

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

/* �㷨 
1��ͨ����������ҵ������A����ͨ��A�����������λ���ҳ��������������� 
2����A���������У����������ĸ���㣨���������ң���ת����1 
3����A���������У����������ĸ���㣨���������ң���ת����1    
*/  
template<class DataType>
BiNode<DataType>* BiTree<DataType>::CreatBT(DataType *pre ,DataType *in ,int n){  //pre������������У�in������������У�nΪ�����������ظ�ָ��  
	BiNode<DataType> *b;  //����� 
    DataType *p ;  
    int k ;   //�����Ӧֵ���ڵ����� 
    if(n<=0)  return NULL;  //�п� 
    b=new BiNode<DataType>;  
    b->data = *pre ;  //ǰ���һ���Ǹ���� 
    for(p=in;p<in+n;p++) { //���������ҵ�ֵΪ*pre��λ��k  
        if(*p == *pre)   //ָ������ 
            break;  //��in���ҵ����˳�ѭ�� 
    }  
    k=p-in;           //ȷ�����ڵ�����������(in)�е�λ�� ���Ϊ0,1,2,...,n-1 (�����е��±�ţ������߼����)   
    b->lchild = CreatBT(pre+1,in,k);   //�ݹ鹹��������   
    b->rchild = CreatBT(pre+1+k,p+1,n-k-1);  //�ݹ鹹��������   
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
	cout<<"ǰ�����Σ�"<<endl;
	T.PreOrder(T.root);
	cout<<endl; 
	cout<<"�������Σ�"<<endl;
	T.InOrder(T.root);
	cout<<endl;
	cout<<"����ֵΪE�Ľ��Ĳ�����"<<endl;
	cout<<T.level(T.root,'E',1);
	return 0;
} 
