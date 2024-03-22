//the queue and stack
#define MAXSIZE 1000
#define ERROR false
#define OK true

#include <iostream>
#include <string>
using namespace std;
//define ElemType as int,
//but it can be any type such as double long

typedef int ElemType;
typedef bool Status;
void Initstack(SqStack *S);
bool isempty(SqStack S);
Status Push(SqStack *S,ElemType e);
Status Pop(SqStack *S,ElemType e);
Status GetTop(SqStack *S,ElemType *e);

Status InitQueue(SqQueue *Q);
bool whetherempty(SqQueue *Q);

int Queuelenth(SqQueue Q){
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

typedef struct{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

//top means the number of the top of stack
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SqStack;

//make a stack NODE
typedef struct StackNode{
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPrt;


//make a stack link chain
typedef struct LinkStack{
    LinkStackPrt top;
    int count;
}LinkStack;

//these are of sighficant importance
//the link push the node together

//start the stack
void Initstack(SqStack *S){
    S->top=-1;
}

//is stack empty
bool isempty(SqStack S){
    if(S.top==-1){
        return true;
    }
    else{
        return false;
    }
}

//push the elem into the stack
Status Push(SqStack *S,ElemType e){
    if(S->top==MAXSIZE-1){
        return ERROR;
    }
    ++S->top;
    S->data[S->top]=e;
    return OK;
}

//pop the elem of stack out
Status Pop(SqStack *S,ElemType *e){
    if(S->top==-1){
        return ERROR;
    }
    *e=S->data[S->top];
    --S->top;
    return OK;
}

//read the top of stack
Status GetTop(SqStack *S,ElemType *e){
    if(S->top==-1){
        return ERROR;
    }
    *e=S->data[S->top];
    return OK;
}

//push the stack into the linknode
Status Push(LinkStack *S,ElemType e){
    LinkStackPrt p=(LinkStackPrt)malloc(sizeof(StackNode));
    p->data=e;
    p->next=S->top;
    S->top=p;
    S->count++;
    return OK;
}

//pop the stacknode out of stacklink
Status Pop(LinkStack *S,ElemType *e)
Status InitQueue(SqQueue *Q){
    Q->front=0;
    Q->rear=0;
    return OK;
}

bool whetherempty(SqQueue *Q){
    if(Q->front==Q->rear){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cout<<"hello world"<<endl;
    return 0;
}
