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

### 4.25

机器上int占32位，char占8位，用的的Latin-1字符集，其中'q'的二进制形式是01110001，求表达式'q'<<6的值：

64

### 4.26

如果使用unsigned int作为quiz1的类型会出现什么情况：

位数不够

### 4.27

表达式的结果：

```c++
unsigned long ul1=3,ul2=7;//0011,0111
ul1&ul2//0011 3
ul1|ul2//0111 7
ul1&&ul2//true
ul1||ul2//true
```

### 4.28

编写程序，输出每一种内置类型所占空间的大小

```c++
int main()
{
	std::cout << "bool\t\tis " << sizeof(bool) << "bytes." << std::endl;
	std::cout << "char\t\tis " << sizeof(char) << "bytes." << std::endl;
	std::cout << "wchar_t\t\tis " << sizeof(wchar_t) << "bytes." << std::endl;
	std::cout << "char16_t\tis " << sizeof(char16_t) << "bytes." << std::endl;
	std::cout << "char32_t\tis " << sizeof(char32_t) << "bytes." << std::endl;
	std::cout << "short\t\tis " << sizeof(short) << "bytes." << std::endl;
	std::cout << "int\t\tis " << sizeof(int) << "bytes." << std::endl;
	std::cout << "long\t\tis " << sizeof(long) << "bytes." << std::endl;
	std::cout << "long long\tis " << sizeof(long long) << "bytes." << std::endl;
	std::cout << "float\t\tis " << sizeof(float) << "bytes." << std::endl;
	std::cout << "double\t\tis " << sizeof(double) << "bytes." << std::endl;
	std::cout << "long double\tis " << sizeof(long double) << "bytes." << std::endl;
	std::cout << std::endl;
}
```

### 4.29

推断以下代码的输出结果并实际运行

```c++
int main()
{
	int x[10];
	int *p = x;
	std::cout << sizeof(x) / sizeof(*x) << std::endl;//10,表示数组元素数目
	std::cout << sizeof(p) / sizeof(*p) << std::endl;//64位机器时为2，32位机器为1
	std::cout << sizeof(p) << std::endl;//8
	std::cout << sizeof(*p) << std::endl;//4
	std::cout << std::endl;
}
```

### 4.30

表达式适当位置加上括号，保持表达式含义不变

```c++
(sizeof x)+y
sizeof (p->mem[i])
(sizeof a)<b
sizeof f()
```

### 4.31

如果相使用后置递增递减的话，不需要做其他修改。两个版本的运算符在循环中是一样的，但是在实际使用过程中推荐使用前置版本，因为当使用后置版本时需要开辟额外的内存空间存储元素递增递减前的原值，如果对原值不做操作的话这一步完全可以使用前置版本。

### 4.32

解释循环的意义

ptr和ix最终所起的作用是一样的。可以选择指针ptr作为循环条件，也可以选择ix即下标作为循环条件。

### 4.33

解释表达式含义：

```c++
somevalue? ++x,++y:--x.--y;
//以上表达式中逗号的优先级最低，因此可以写成
(somevalue? ++x,++y:--x).--y;
//以上表达式的含义时if somevalue==true,then ++y and result->++y->--y,即结果为y,否则then--x,同时result->--y
//注意逗号运算符的结果是逗号右侧的表达式结果
```

### 4.34

说明表达式将发生什么样的类型转换

(a) if(fval)  fval从float提升到bool

(b) dval=fval+ival ival提升到fval，相加后结果提升到double

(c) dval+ival*cval cval提升到ival，相乘后结果提升到double与dval相加

### 4.35

指出是否发生隐式类型转换：

```c++
char cval;
int ival;
unsigned int ui;
float fval;
double dval;
cval='a'+3;//'a'提升为int,然后相加后提升为char
fval=ui-ival*1.0;//ival提升为double,ui提升为double,相减的结果提升为float
dval=ui*fval;//ui提升为float，相乘后提升为double
cval=ival+fval+dval;//ival和fval分别提升为double，相加后提升为char
//注意，当double->float或者double->char时会有数据的损失
```

### 4.36

假设i是int类型，d是double类型，书写表达式i*=d使其执行整数类型的乘法而非浮点类型的乘法

使用强制类型转换static_cast：i*=static_cast<int>(d)

### 4.37

使用命名的强制类型转换改写下列旧式的转换语句

```c++
int i;
double d;
const string *ps;
char *pc;
void *pv;
pv=(void*)ps;//pv=const_cast<string*>(ps);
i=int(*pc);//i=static_cast<int>(*pc);
pv=&d;//pv=static_cast<void*>(&d);
pc=(char*)pv;//pc=reinterpret_cast<char*>(pv);
```

### 4.38

表达式含义：

```c++
double slope=static_cast<double>(j/i);
//j/i经计算后是int型，通过static_cast<double>将结果强制转换为double型
```

