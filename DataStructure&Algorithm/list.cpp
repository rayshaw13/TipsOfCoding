// 线性表的顺序存储结构
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Elemtype;
#include"stdio.h"
#include<iostream>

// 通过数组定义线性表
typedef struct
{
    Elemtype data[MAXSIZE];
    int length;
}SqList;

// 获取某位置上的元素
Status GetElem(SqList l,int pos,Elemtype *e){
    // 异常输出
    if(pos<1||pos>l.length)
        return ERROR;
    *e=l.data[pos-1];
    return OK;
}

// 插入元素
Status InsertElem(SqList *l,int pos,Elemtype e){
    // 异常输出 线性表已满，或者pos超出线性表范围
    if(l->length==MAXSIZE)
        return ERROR;
    if(pos<1||pos>l->length)
        return ERROR;
    if(pos<l->length+1)// 假设l.length=5，pos=3, pos<6
        for(int j=l->length-1;j>=pos-1;--j)// (j=4;j>=2;--j)
            l->data[j+1]=l->data[j];// data[5]=data[4],data[4]=data[3],data[3]=data[2]
    l->data[pos-1]=e;// data[2]=e
    l->length++;// length=6
    return OK;
}

// 删除元素
Status DeleteElem(SqList *l,int pos,Elemtype *e){
    // 异常输出 线性表为空，或者pos超出线性表范围
    if(l->length==0)
        return ERROR;
    if(pos<1||pos>l->length)
        return ERROR;
    //*e=l->data[pos-1];
    if(pos<l->length){
        for(int ix=pos;ix<=l->length-1;++ix)
            l->data[ix-1]=l->data[ix];
    }
    l->length--;
    return OK;
}

void PrintList(SqList sq){
    if(sq.length==0)
        std::cerr<<"ERROR no elements"<<"\n";
    for(int ix=0;ix<sq.length;++ix){
        std::cout<<sq.data[ix]<<",";
    }
    std::cout<<std::endl;
}

// 测试线性表的顺序存储结构
int main()
{
	SqList L;
	L.length = 7;
	std::cout << "请输入" << L.length << "个数字：" << std::endl;
	for ( int i = 0;  i <= L.length -1 ; i++)
	{
		std::cin >> L.data[i];
	}
 
	InsertElem(&L,4,9);
 
	std::cout << "插入数字后的结果是：" << std::endl;
	for (int i = 0; i <= L.length -1; i++)
	{
		std::cout << L.data[i] << " ";
	}
	std::cout << std::endl;
    Elemtype *e;
	DeleteElem(&L, 4, e);
	std::cout << "删除数字后的结果是：" << std::endl;
	for (int i = 0; i <= L.length - 1; i++)
	{
		std::cout << L.data[i] << " ";
	}
    std::cout << std::endl;
 
	return 0;
}
