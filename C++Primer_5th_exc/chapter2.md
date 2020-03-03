chapter2的练习题

### 2.1

int、long、long long、short的区别，signed与unsigned区别，float和double区别

short 和int最少16位，long至少32位，long long至少64位；

signed可以表示负数，unsigned只能表示0与正数；

float表示单精度浮点数，有6位有效数字，double表示双精度浮点数，有10位有效数字

### 2.2

按揭贷款时，对于利率 本金 付款分别选择何种数据类型？

double或者float

### 2.3

写出程序的结果

32 ***** 32 -32 0 0  其中第二个结果越界

### 2.5

指出字面值的数据类型并说明区别

(a) 字符型 宽字符型 字符串类型 宽字符串类型

(b) 整型 无符号整型 长整型 无符号长整型 十六进制

(c) 双精度 浮点数 长双精度

(d) 整型 无符号整型 双精度 双精度

### 2.6

第一组数是十进制，第二组中number1无效，因为八进制没有9，number2有效

### 2.7

类型分别为字符串，长双精度，浮点数，长双精度

### 2.8

```c++
#include <iostream>

int main()
{
    std::cout << "\062\115\012";
    std::cout << "\062\t\115\012";
}
```

### 2.9

(a) 错误，声明不能放在输入语句中

(b) 错误，没有类型转换，丢失信息

(c) 如果wage之前定义了那就是正确，否则错误

(d) 正确，但是会丢失部分信息

### 2.10

global_str 全局变量 初始化为空字符串；global_int 全局变量 初始化为0；

local_str 局部变量 初始化为空字符串；local_int 局部变量 没有定义的初始化值；注意两者不同

### 2.11 

定义 定义 声明

### 2.12

a c d无效

### 2.13

程序的值：j为100

### 2.14

合法，100 50

### 2.15

下面的哪个定义是不合法的：

b 初始化必须是一个对象，d 引用必须首先被定义

### 2.16

均合法，a赋值，b会自动转换，c自动转换但是丢失信息，d自动转换但是丢失信息

### 2.17

输出：10 10

### 2.18

编写程序改变指针的值以及指针所指对象的值

```c++
int a=1,b=2;
int *p1=&a,*p2=b;
//修改指针的值；
p1=&b;
//修改指针所指对象的值
*p2=a;
```

### 2.19

指针与引用的区别

指针的值是对象的地址，引用时对象的另一个名字

### 2.20

叙述代码的作用

对i定义及赋值，定义指针p1，对p1指向的值重新赋值

### 2.21

判断以下定义是否合法

非法 非法 合法

### 2.22

判断p是否是一个空指针；

判断p是否指向一个0值

### 2.23

不能，需要更多信息来判断指针是否有效

### 2.24

因为*void可以保存任何类型的地址

### 2.25

说明变量的类型和值

ip是指向整型数据的指针，i是整型值，r是i的引用；

i是整型值，ip是空指针

ip是指向整型数据的指针，ip2是整型值

### 2.26

判断是否合法

第一个不合法，因为没有初始化const类型值；

++sz不合法，因为不能对const类型值做修改

### 2.27

a不合法，引用的必须是对象；f不合法，引用不可以是const类型

### 2.28

前四均不合法，因为const类型值需要初始化

### 2.29

合法 其余不合法

### 2.30

 判断顶层底层const

```c++
const int v2 = 0; int v1 = v2;//v2顶层
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;//p2底层，p3最左边的是底层，最右边的顶层，r2是底层
```

### 2.31

```c++
//根据上一题的程序判断
r1 = v2; // legal, top-level const in v2 is ignored.
p1 = p2; // illegal, p2 has a low-level const but p1 doesn't.
p2 = p1; // legal, we can convert int* to const int*.
p1 = p3; // illegal, p3 has a low-level const but p1 doesn't.
p2 = p3; // legal, p2 has the same low-level const qualification as p3.
```

### 2.32

修改：

```c++
int null = 0, *p = nullptr;
```

### 2.33

判断语句的运行结果

```c++
a=42;//正确a是一个整数，同样b c也正确
d=42;//d是一个整型指针，即指向整数的指针。应该修改为*d=42;
e=42;//e是一个指向整数常量的指针，改为e=&c;
g=42;//g是一个整型常量引用
```

### 2.35

判断类型

```c++
const int i = 42;//i是const int
auto j = i;//j是int
const auto &k = i;//k是const int &
auto *p = &i;//p是int*
const auto j2 = i, &k2 = i;//j2是const int, k2是const int &
```

### 2.36

c是int型，d是a的引用。结束后均为4

### 2.37

c是int型，d是int&型，四个值分别为3 4 3 3

### 2.38

decltype是通过给定的表达式判断对象的类型

```c++
int i = 0, &r = i;
// same
auto a = i;
decltype(i) b = i;
// different
auto c = r;
decltype(r) d = r;
```

### 2.39

返回应输入分号的错误

### 2.40

```c++
struct Sales_data
{
	int num;
	double price;
	std::string name;
	std::string province;
};
```

### 2.41

```c++
#include<iostream>
#include<string>
//#include"Sales_item.h"

struct Sales_data
{
	std::string bookNo;
	unsigned units_sold=0;
	double revenue = 0;
};
int main() {
	Sales_data item;
	double price = 0;
	std::cin >> item.bookNo>>item.units_sold>>price;
	item.revenue = item.units_sold*price;
	std::cout << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << price;
	std::cout << std::endl;
	return 0;
}
```

### 2.42

根据自己的理解重写一个Sales_data.h头文件

```c++
#include<iostream>
#include<string>

struct salesdata
{
    /* data */
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;

    void CalcRevenue(double price);
    double CalcAveragePrice();
    void SetData(salesdata data);
    void AddData(salesdata data);
    void print();
};

void salesdata::CalcRevenue(double price){
    revenue=units_sold*price;
}

double salesdata::CalcAveragePrice(){
    if(units_sold!=0)
        return revenue/units_sold;
    else
        return 0.0;    
}

void salesdata::SetData(salesdata data){
    bookNo= data.bookNo;
    units_sold=data.units_sold;
    revenue=data.revenue;
}

void salesdata::AddData(salesdata data){
    if(bookNo!=data.bookNo)
        return ;
    else{
        units_sold+=data.units_sold;
        revenue+=data.revenue;
    }
}

void salesdata::print(){
    std::cout<<bookNo<<" "<<units_sold<<" "<<revenue<<" ";
    double averagePrice=CalcAveragePrice();
    if(averagePrice!=0)
        std::cout<<averagePrice<<std::endl;
    else
        std::cout<<"no sales"<<std::endl;   
}
```

