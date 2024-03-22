#include <iostream>
#include <stdbool.h>
#include <queue>
using namespace std;

//T is a big bit tree
//make a bit tree
typedef struct BiT_Node{
    char data;
    struct BiT_Node* rchild;
    struct BiT_Node* lchild;
}BiT_Node,*BiTree;

//初始化二叉树
void Init_Tree(BiTree& T){
    T=(BiT_Node*)malloc(sizeof(BiT_Node));  
    //分配相应大小的内存
    T->data='#';
    T->lchild=NULL;
    T->rchild=NULL;
}

//毁灭二叉树
void Destroy_Tree(BiTree& T){
    if(T){
        Destroy_Tree(T->lchild);
        Destroy_Tree(T->rchild);
        free(T);
    }
}

//创建
void Create_Tree(BiTree& T){
    char c;
    cin>>c;
    if(c=='#'){
        T=NULL;
    }
    else{
        T=(BiT_Node*)malloc(sizeof(BiT_Node));
        T->data=c;
        Create_Tree(T->lchild);
        Create_Tree(T->rchild);
    }
}

// clear the tree except the root
void Clear_Tree(BiTree& T){
    Destroy_Tree(T->lchild);
    Destroy_Tree(T->rchild);
    T=NULL;
}

//judge whether the tree is null or not;
bool Empty_Tree(BiTree T){
    if(T==NULL||T->data=='#'){
        return true;
    }
    else{
        return false;
    }
}

//find the depth of tree
int Depth_Tree(BiTree T){
    int leftdepth,rightdepth;
    if(T=NULL){
        return 0;
    }
    else{
        leftdepth=Depth_Tree(T->lchild);
        rightdepth=Depth_Tree(T->lchild);
        return max(rightdepth+1,leftdepth+1);
    }
}

//return the value of root and point 
char Root_tree(BiTree T){
    if(T!=NULL){
        return T->data;
    }
    else{
        return '#';
    }
}

//in the tree T,you want find the value that point p has
char Value_tree(BiTree T,BiTree P){
    if(T==NULL||P==NULL){
        return '#';
    }
    else{
        return P->data;
    }
}

//if p is not the son of T's ,then return the parents 
// point of p
BiTree Parent_tree(BiTree T,BiTree P){
    BiTree q=NULL;
    if(T==NULL||P==NULL){
        return NULL;
    }
    else{
        if(T->lchild==P||T->rchild==P){
            return T;
        }
        //define q in order to find the parent on the left
        q=Parent_tree(T->lchild,P);
        if(q=NULL){
        //if the left is not exist,find the right
            q=Parent_tree(T->rchild,P);
            return q;
        }
        return q;
    }
}

//return the left child of P
BiTree Leftchild_Tree(BiTree T,BiTree P){
    if(T!=NULL&&P!=NULL){
        return P->lchild;
    }
    else{
        return NULL;
    }
}

//find the left brother of p
BiTree Leftbrother_Tree(BiTree T,BiTree P){
    if(T==NULL){
        return NULL;
    }
    else{
        BiTree q=Parent_tree(T,P);
        if(q!=NULL&&q->lchild!=P){
            return q->lchild;
        }
        else{
            return NULL;
        }
    }
}

//as the same of the left
BiTree Rightbrother_Tree(BiTree T,BiTree P){
    if(T==NULL){
        return NULL;
    }
    else{
        BiTree q=Parent_tree(T,P);
        if(q!=NULL&&q->rchild){
            return q->rchild;
        }
        else{
            return NULL;
        }
    }
}

//print the whole tree follow the fisrt older
void PrePrint_Tree(BiTree T){
    if(T!=NULL){
        cout<<T->data;
        PrePrint_Tree(T->rchild);
        PrePrint_Tree(T->lchild);
    }
}

//print the whole tree follow the middle older
void InPrint_Tree(BiTree T){
    if(T!=NULL){
        InPrint_Tree(T->lchild);
        cout<<T->data;
        InPrint_Tree(T->rchild);
    }
}

//from the post order
void PostPrint_Tree(BiTree T){
    if(T!=NULL){
        PostPrint_Tree(T->lchild);
        PostPrint_Tree(T->rchild);
        cout<<T->data;
    }
}

//the level 
void LevelPrint_Tree(BiTree T){
    BiTree p;
    queue<BiTree>qu;
    qu.push(T);
    while(!qu.empty()){
        p=qu.front();
        //访问队列首节点
        cout<<p->data;
        qu.pop();
        if(p->lchild!=NULL){
            qu.push(p->lchild);
        }
        if(p->rchild!=NULL){
            qu.push(p->rchild);
        }
    }
}

//give the value c to the point p
void Assign_Tree(BiTree& T,BiTree p,char c){
    if(T==NULL||p==NULL){
        return ;
    }
    else{
        p->data=c;
    }

}

//insert the left child of c into T
void Insert_Tree(BiTree& T,BiTree p,int LR ,BiTree c){
    if(T==NULL||p==NULL||c==NULL){
        return ;
    }
    else{
        if(LR==0){
            c->rchild=p->lchild;
            p->lchild=c;
        }
        else{
            c->rchild=p->rchild;
            p->lchild=c;
        }
    }
}

void Delete_Tree(BiTree& T,BiTree p,int LR){
    if(LR==0){
        Destroy_Tree(p->lchild);
        p->lchild=NULL;
    }
    else{
        Destroy_Tree(p->rchild);
        p->rchild=NULL;
    }
}

//find the point you want
BiTree Find_Tree(BiTree T,char c){
    BiTree p=NULL;
    if(T==NULL){
        return NULL;
    }
    else if(T->data==c){
        return T;
    }
    else{
        p=Find_Tree(T->lchild,c);
        if(p==NULL){
            p=Find_Tree(T->rchild,c);
            return p;
        }
        return p;
    }
    return p;
}

//for the test
int main(){
    BiTree T;
    Init_Tree(T);
    bool t=Empty_Tree(T);

    if(t){
        cout<<"is empty"<<endl;
    }
    else{
        cout<<"is not empty"<<endl;
    }
    cout<<"ceate your tree:"<<endl;

    Create_Tree(T);
    int d=Depth_Tree(T);
    cout<<"the depth is "<<d<<endl;

    char c=Root_tree(T);
    cout<<"the value of root is"<<c<<endl;

    cout<<"you want find the p points what:"<<endl;
    BiTree p,q;
    BiTree q1,q2;

    cin>>c;
    p=Find_Tree(T,c);
    c=Value_tree(T,p);
    cout<<"p points to:"<<c<<endl;

    q2=Parent_tree(T,p);
    cout<<"the parent of p is:"<<q2<<endl;

    q1=Leftbrother_Tree(T,p);
    cout<<"the left brother of p is:"<<q1<<endl;

    cout<<"level the tree:"<<endl;
    LevelPrint_Tree(T);
    cout<<endl;
//change the value 
    char k;
    cout<<"enter the value you want to change:"<<endl;
    cin>>k;
    BiTree q3;
    q3=Find_Tree(T,k);
    Assign_Tree(T,q3,k);
    InPrint_Tree(T);
//create another bitree
    BiTree S;
    Init_Tree(S);
    cout<<"enter the value to cearte your tree:"<<endl;
    Create_Tree(S);

    cout<<"enter what you want to insert into the bitree:"<<endl;
   //insert a value in the p
    cout<<"where do you want to insert:"<<endl;
    int LR;
    cout<<"if left then enter 0,"<<endl;
    cout<<"if right then enter 1"<<endl;
    Insert_Tree(T,p,LR,S);
    Delete_Tree(T,p,LR);
    PrePrint_Tree(T);
    
    cout<<"we have clear the tree"<<endl;
    Clear_Tree(T);
    t=Empty_Tree(T);

    if(t){
        cout<<"yoou have clear it!"<<endl;
    }
    else{
        cout<<"not yet"<<endl;
    }

    Destroy_Tree(T);
    cout<<"you have destroy it!"<<endl;
    return 0;
}
