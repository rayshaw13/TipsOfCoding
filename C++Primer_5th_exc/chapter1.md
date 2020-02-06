习题

### 1.3

关键点：标准输出

```c++
int main(){
std::cout<<"Hello, World"<<std::endl;
}
```

### 1.4

关键词 乘法运算符 标准输出

```c++
#include<iostream>
int main(){
	int a1=0,a2=0;
	std::cout<<"please enter two number:"<<std::endl;
	std::cin<<a1;
	std::cin<<a2;	
	std::cout<<"the * result is: "<<a1*a2<<std::endl;
	return 0;
}
```

### 1.6

程序的合法性？

错误，应该移除前两条语句中的分号。

```c++
std::cout<<"The sum of "<<v1
		 <<" and "<<v2
		 <<" is "<<v1+v2<<std::endl;
```

### 1.7 

不正确的嵌套注释，实际上注释界定符不能嵌套。

### 1.8

关于注释与输出语句的结合，程序改写为：

```c++
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";//在这里加上了一个后双引号
std::cout << /* "*/" /* "/*" */;
```

### 1.9

while循环实现50到100的相加

```c++
int num=50,sum=0;
while(num!=101){
	sum+=num;
	++num;
}
```

### 1.10

递减运算符的使用

```c++
int num=10;
while(num>=0){
	std::cout<<num<<" ";
	num--;
}
std::cout<<std::endl;
```

### 1.11

输出两个整数范围内的所有整数

```c++
//输出两个整数范围内的所有整数
//首先要判断两个整数的大小，是否进行交换
int i=0,j=0,k=0;
std::cout<<"enter two numbers:"<<std::endl;
std::cin>>i>>j;
if(i>j){
	k=i;i=j;j=k;
}
while(i<=j){
	std::cout<<i<<",";
	++i;
}
std::cout<<std::endl;
```

### 1.12

程序实现的功能是 从-100加到+100

### 1.13

for循环替换while循环

````c++
//通过for循环实现之前while循环的功能
int sum=0;
for(int i=50;i<=100;++i){
	sum+=i;
}

for(int j=10;i<=0;--j){
	std::cout<<j<<" ";
}

int i=0,j=0,k=0;
std::cout<<"enter two numbers:"<<std::endl;
std::cin>>i>>j;
if(i>j){
	k=i;i=j;j=k;
}
for(;i<=j;++i){
	std::cout<<i<<",";
}
std::cout<<std::endl;
````

### 1.14

for循环与while循环的优缺点

1 在for循环中,循环控制变量的初始化和修改都放在语句头部分,形式较简洁,且特别适用于循环次数已知的情况。

2 在while循环中,循环控制变量的初始化一般放在while语句之前,循环控制变量的修改一般放在循环体中,形式上不如for语句简洁,但它比较适用于循环次数不易预知的情况(用某一条件控制循环)。

### 1.16

使用输入流，从cin读入一组数计算其和

```c++
int main() {
	int val = 0,sum=0;
	while (std::cin >> val) {
		sum += val;
	}
	std::cout << "输入所有的数的和为：" << sum << std::endl;
	return 0;
}
```

以上程序中，需要在想要结束输入时按ctrl+z，然后enter才会出现结果。当然也可以在while条件处加入新的条件，如while (std::cin >> val&&val!=0)，即当val的输入等于0时表示结束读取。

### 1.20

读取销售记录，标准输出

```c++
#include<iostream>
#include"Sales_item.h"

int main() {
	Sales_item item;
	while (std::cin >> item) {
		std::cout << item << std::endl;
	}
	return 0;
}
```

### 1.21

读取两个ISBN相同的对象，输出他们的和

```c++
#include<iostream>
#include"Sales_item.h"

int main() {
	Sales_item item1,item2;
	std::cin >> item1 >> item2;
	if (item1.isbn()==item2.isbn()) {
		std::cout << item1+item2 << std::endl;
		return 0;
	}
	else {
		std::cerr << "error,the isbn is not equal" << std::endl;
		return -1;
	}
}
```

### 1.22

读取多个具有相同ISBN的销售记录，输出所有记录的和

```c++
#include<iostream>
#include"Sales_item.h"

int main() {
	Sales_item total;
	if (std::cin >> total) {
		Sales_item trans;
		while (std::cin >> trans) {
			if (trans.isbn() == total.isbn()) {
				total += trans;
			}
			else {
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
		return 0;
	}
	else {
		std::cerr << "error,no data in" << std::endl;
		return -1;
	}
}
```

### 1.23

```c++
#include<iostream>
#include"Sales_item.h"

int main() {
	Sales_item eveValue;
	if (std::cin >> eveValue) {
		int cnt = 1;
		Sales_item curValue;
		while (std::cin >> curValue) {
			if (eveValue.isbn() == curValue.isbn()) {
				++cnt;
			}
			else {
				std::cout <<"isbn等于"<<eveValue.isbn()<<"的item数目为："<< cnt << std::endl;
				eveValue=curValue;
			}
		}
		std::cout << "isbn等于" << eveValue.isbn() << "的item数目为：" << cnt << std::endl;
		return 0;
	}
	else {
		std::cerr << "error,no data in" << std::endl;
		return -1;
	}
}
```

