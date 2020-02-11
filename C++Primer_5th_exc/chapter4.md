第四章练习题

### 4.1

表达式的值为105，主要考察运算符优先级

### 4.2

根据4.12的表，在表达式的合理位置添加括号，使其与添加括号前一致

```c++
//原
*vec.begin();
*vec.begin()+1;
//添加括号
*(vec.begin());
(*(vec.begin()))+1;//注意加号运算符的优先级低于解引用运算符*
```

### 4.3

这种权衡是很有必要的，因为速度一直都是C++的优势，不能放弃。同时我们可以在设计程序尽量避免写出带有缺陷的代码

### 4.4

表达式中添加括号，说明求值过程及最终结果

```c++
//原
12/3*4+5*15+24%4/2
//添加括号
((12/3)*4)+(5*15)+((24%4)/2)
```

### 4.5

表达式的求值结果

-86，-18，0，-2

### 4.6

写出表达式确定一个整数是奇数还是偶数

```c++
num % 2 == 0 ? "偶数" : "奇数"
```

### 4.7

溢出的含义，写出导致溢出的表达式

```c++
//溢出是指计算的结果超出该类型所能表示的范围
short svalue = 32767; ++svalue; // -32768
unsigned uivalue = 0; --uivalue;  // 4294967295
unsigned short usvalue = 65535; ++usvalue;  // 0
```

### 4.8

说明逻辑与、逻辑或及相等性运算符中运算对象求值的顺序

X&&Y  只有当X为true时才会去检查Y的bool值

X||Y  只有当X为false时才会去检查Y的bool值

X==Y  只有当X与Y的值相等时，才会返回true，否则为false

### 4.9

解释if语句中条件部分的判断过程

```c++
const char *cp="hello world";
if(cp&&*cp)
    //判断过程：首先判断cp是一个const char指针，不是空指针（nullptr），因此为true；其次判断*cp，其值为"hello world"，是一个非零值，因此为true；所以true&&true->true
```

### 4.10

为while循环写一个条件，使其从标准输入读取整数，遇到42停止

```c++
int val=0;
while((std::cin>>val)&&val!=42){
	pass;
}
```

### 4.11

一条语句确保a大于b，b大于c，c大于d

```c++
(a>b)&&(b>c)&&(c>d)
```

### 4.12

i j k是三个整数，说明*i!=j<k*的含义

根据优先级可以改写为*i!=(j<k)*，那么i会跟后面表达式的结果即bool值作比较，因为三者都是整数，可以改写为*i!=j&&j<k*

### 4.13

赋值完成后i和d的值分别是什么

(a) i是3，d是3.0

(b) d是3.5，i是3

### 4.14

非法，合法

### 4.15

不能将指针值赋值给int，应该改为：

```c++
double dval;int ival;int *pi;
dval=ival=0;
pi=0;
```

### 4.16

实际行为与预期不一样的原因，造成歧义

```c++
//(a)
if((p=getPtr())!=0)
//(b)
if(i==1024)
```

### 4.17

说明前置递增运算符和后置递增运算符的区别

```c++
++a//先将a加一作为a的新值，调用的时候用的是a的新值
a++//将a加一作为a的新值，调用的时候用的是a的旧值
```

### 4.18

pbeg向前移动一个位置，并输出新位置上的元素值。最终会输出v.end()，这是尾后迭代器，对其值的输出不一定有意义。

### 4.19

(a) 检查ptr不是一个空指针，检查ptr指向的值非0

(b) 检查ival不是0，检查ival+1是否为0

(c) 非法，未定义的行为。应该改为*vec[ival]<=vec[ival+1]*.原因运算符两侧都有ival，同时左侧的表达式会影响右侧的值。

### 4.20

iter的类型为*vector<string>::iterator*，说明以下表达式是否合法

```c++
*iter++;//解引用优先级低于++,因此会先++,然后调取原迭代器指向的值，合法
(*iter)++;//先解引用，得到迭代器指向的值，然后该值加一，但是值为string，不存在加一，非法
*iter.empty()//对于指针类型的对象应该使用iter->empty()或者写为(*iter).empty(),非法
iter->empty();//合法
++*iter;//非法，string无法加一
iter++->empty();//首先iter->empty(),然后执行++
```

### 4.21

使用条件运算符从vector<int>中找到哪些元素的值是奇数，然后将这些奇数翻倍

```c++
int main()
{
	std::vector<int> ivec = { 1,2,3,4,5,6,7,8,9 };
	for (int &item : ivec) {
		item = (item % 2 == 0) ? item * 2 : item;
	}
	for (int &item : ivec) {
		std::cout << item << " ";
	}
	std::cout << std::endl;
	return 0;
}num%2==0?num*=2:;
```

### 4.22

两个版本的程序（一使用条件运算符，而使用if语句）实现成绩的层级划分

```c++
int main()
{
	int grade = 0;
	while (std::cin >> grade) {
		//使用条件运算符
		std::cout << "条件运算符结果：" << std::endl;
		std::cout << ((grade > 90) ? "hight pass"
			: (grade > 75) ? "pass" : (grade > 60) ? "low pass" : "fail");
		std::cout << std::endl;
		//使用if语句
		std::cout << "if语句的结果：" << std::endl;
		if (grade > 90)
			std::cout << "hight pass" << std::endl;
		else if (grade > 75)
			std::cout << "pass" << std::endl;
		else if (grade > 60)
			std::cout << "low pass" << std::endl;
		else
			std::cout << "fail" << std::endl;
	}
	return 0;
}
```

### 4.23

以下表达式无法通过编译的原因：

```c++
string s="word";
string pl=s+s[s.size()-1]=='s'?"":"s";//改为
string pl=s+(s[s.size()-1]=='s'?"":"s");
```

### 4.24

如果条件运算符满足左结合律，那么求值过程是：

```c++
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";//源程序，当满足左结合律时类似于：
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";//注意括号的位置
//当输入grade>90时，结果将会一直是fail
```

