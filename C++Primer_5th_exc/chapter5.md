第五章 练习题

### 5.1

空语句只含有一个单独的分号。如果在程序的某个地方，语法上需要一条语句但是逻辑上不需要，应该使用空语句。

### 5.2

块是指用花括号括起来的（可能为空的）语句和声明的序列，也被称为复合语句。如果在程序的某个地方，语法上需要一条语句，但是逻辑上需要多条语句实现，则应该使用复合语句（或称为块）。

### 5.3

使用逗号运算符重写while循环，使其不再需要块。

```c++
//原语句块
while(val<=20){
	sum+=val;
	++val;
}
//逗号运算符修改
while(val<=10){
	sum+=val,++val;
}
//可读性降低
```

### 5.4

程序的含义若存在问题进行修改

```c++
//(a)
while (string::iterator iter!=s.end())!=s.end()) {/*...*/}
//以上程序中iter没有指向任何元素，应该改为：
string::iterator iter=s.begin();
while(iter!=s.end()){/*...*/}
//(b)
while (bool status = find(word)) {/*...*/}
    if(!status) {/*...*/}
//以上程序中if语句不应该缩进以免造成if语句在while语句内的假象，同时应该对status定义，因此修改如下
bool status;
while (status = find(word)) {/*...*/}
if(!status) {/*...*/}
```

### 5.5

写一段自己的程序，使用if-else语句实现将数字成绩转换为字母成绩的要求

```c++
int main()
{
	std::cout << "请输入你的成绩（0~100）：" << std::endl;
	int score;
	while (std::cin >> score) {
		std::cout << "你的成绩等级为：";
		if (score == 100)
			std::cout << "A++";
		else if(score>89)
			std::cout << "A";
		else if(score>79)
			std::cout << "B";
		else if(score>69)
			std::cout << "C";
		else if(score>59)
			std::cout << "D";
		else
			std::cout << "F";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
```

### 5.6

使用条件运算符替换上面程序中的if-else语句

```c++
int main()
{
	std::cout << "请输入你的成绩（0~100）：" << std::endl;
	int score;
	while (std::cin >> score) {
		std::cout << "你的成绩等级为：";
		std::cout << (score == 100 ? "A++" : score > 89 ? "A" : score > 79 ? "B" : score > 69 ? "C" : score > 59 ? "D" : "F");
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
```

### 5.7

改正程序的错误

```c++
//修改后的程序为：
if(ival1!=ival2)
	ival1=ival2;
else ival1=ival2=0;

if(ival<minval){
	minval=ival;
	occurs=1;
}

int ival;
if(ival=get_value())
	cout<<"ival="<<ival<<endl;
if(!ival)
	cout<<"ival=0\n";

if(ival==0)
	ival=get_value();
```

### 5.8

什么是悬垂else，C++如何处理else子句？

当一个if语句嵌套在另一个if语句内部时，很可能if会多于else，这种情况就是悬垂else。

用花括号处理，强迫if-else的配对。

### 5.9

编写程序使用一系列if语句统计cin读入的文本中有多少元音字符

```c++
int main()
{
	std::cout << "请输入你的文本：" << std::endl;
	char ch;
	int acnt = 0, ecnt = 0, icnt = 0, ocnt = 0, ucnt = 0,othercnt=0;
	while (std::cin >> ch) {
		if (ch == 'a')
			++acnt;
		else if (ch == 'e')
			++ecnt;
		else if (ch == 'i')
			++icnt;
		else if (ch == 'o')
			++ocnt;
		else if (ch == 'u')
			++ucnt;
		else
			++othercnt;
	}
	std::cout << "a出现的次数为：" << acnt << std::endl;
	std::cout << "e出现的次数为：" << ecnt << std::endl;
	std::cout << "i出现的次数为：" << icnt << std::endl;
	std::cout << "o出现的次数为：" << ocnt << std::endl;
	std::cout << "u出现的次数为：" << ucnt << std::endl;
	std::cout << "其他字符出现的次数为：" << othercnt << std::endl;
	std::cout << std::endl;
	return 0;
}
```

### 5.10

编写程序统计元音字母，不区分大小写

```c++
int main()
{
	std::cout << "请输入你的文本：" << std::endl;
	char ch;
	int acnt = 0, ecnt = 0, icnt = 0, ocnt = 0, ucnt = 0,othercnt=0;
	while (std::cin >> ch) {
		switch (ch)
		{
		case('a'):case('A'):
			++acnt;
			break;
		case('e'):case('E'):
			++ecnt;
			break;
		case('i'):case('I'):
			++icnt;
			break;
		case('o'):case('O'):
			++ocnt;
			break;
		case('u'):case('U'):
			++ucnt;
			break;
		default:
			++othercnt;
			break;
		}
	}
	std::cout << "a出现的次数为：" << acnt << std::endl;
	std::cout << "e出现的次数为：" << ecnt << std::endl;
	std::cout << "i出现的次数为：" << icnt << std::endl;
	std::cout << "o出现的次数为：" << ocnt << std::endl;
	std::cout << "u出现的次数为：" << ucnt << std::endl;
	std::cout << "其他字符出现的次数为：" << othercnt << std::endl;
	std::cout << std::endl;
	return 0;
}
```

### 5.11

修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量

```c++
int main()
{
	std::cout << "请输入你的文本：" << std::endl;
	char ch;
	int acnt = 0, ecnt = 0, icnt = 0, ocnt = 0, ucnt = 0,othercnt=0,spacecnt=0,tcnt=0,ncnt=0;
	while (std::cin>> std::noskipws >> ch) {
		switch (ch)
		{
		case('a'):case('A'):
			++acnt;
			break;
		case('e'):case('E'):
			++ecnt;
			break;
		case('i'):case('I'):
			++icnt;
			break;
		case('o'):case('O'):
			++ocnt;
			break;
		case('u'):case('U'):
			++ucnt;
			break;
		case(' '):
			++spacecnt;
			break;
		case('\t'):
			++tcnt;
			break;
		case('\n'):
			++ncnt;
			break;
		default:
			++othercnt;
			break;
		}
	}
	std::cout << "a出现的次数为：" << acnt << std::endl;
	std::cout << "e出现的次数为：" << ecnt << std::endl;
	std::cout << "i出现的次数为：" << icnt << std::endl;
	std::cout << "o出现的次数为：" << ocnt << std::endl;
	std::cout << "u出现的次数为：" << ucnt << std::endl;
	std::cout << "空格出现的次数为：" << spacecnt << std::endl;
	std::cout << "制表符出现的次数为：" << tcnt << std::endl;
	std::cout << "换行符出现的次数为：" << ncnt << std::endl;
	std::cout << "其他字符出现的次数为：" << othercnt << std::endl;
	std::cout << std::endl;
	return 0;
}
```

注意以上程序中while处有一个std::noskipws，其作用是不忽略任意地方的空格。

### 5.12

修改以上程序，使其能够统计以下含有两个字符的字符序列的数量：ff和fl和fi

```c++
int main()
{
	std::cout << "请输入你的文本：" << std::endl;
	char ch,prech='\0';
	int acnt = 0, ecnt = 0, icnt = 0, ocnt = 0, ucnt = 0, othercnt = 0, spacecnt = 0, tcnt = 0, ncnt = 0, ficnt = 0,ffcnt=0,flcnt=0;
	while (std::cin>> std::noskipws >> ch) {
		switch (ch)
		{
		case('a'):case('A'):
			++acnt;
			break;
		case('e'):case('E'):
			++ecnt;
			break;
		case('i'):
			if (prech == 'f')
				++ficnt;
		case('I'):
			++icnt;
			break;
		case('o'):case('O'):
			++ocnt;
			break;
		case('u'):case('U'):
			++ucnt;
			break;
		case(' '):
			++spacecnt;
			break;
		case('\t'):
			++tcnt;
			break;
		case('\n'):
			++ncnt;
			break;
		case('f'):
			if (prech == 'f')
				++ffcnt;
			break;
		case('l'):
			if (prech == 'f')
				++flcnt;
			break;
		default:
			++othercnt;
			break;
		}
		prech = ch;
	}
	std::cout << "a出现的次数为：" << acnt << std::endl;
	std::cout << "e出现的次数为：" << ecnt << std::endl;
	std::cout << "i出现的次数为：" << icnt << std::endl;
	std::cout << "o出现的次数为：" << ocnt << std::endl;
	std::cout << "u出现的次数为：" << ucnt << std::endl;
	std::cout << "空格出现的次数为：" << spacecnt << std::endl;
	std::cout << "制表符出现的次数为：" << tcnt << std::endl;
	std::cout << "换行符出现的次数为：" << ncnt << std::endl;
	std::cout << "fi出现的次数为：" << ficnt << std::endl;
	std::cout << "fl出现的次数为：" << flcnt << std::endl;
	std::cout << "ff出现的次数为：" << ffcnt << std::endl;
	std::cout << "其他字符出现的次数为：" << othercnt << std::endl;
	std::cout << std::endl;
	return 0;
}
```

### 5.13

(a) 缺少break

(b) ix的定义位置不对

(c) 多条case语句写在一起时格式不对

(d) case语句必须是一个常量表达式

### 5.14

标准输入中读取若干string对象并查找连续重复出现的单词

```c++
int main()
{
	std::cout << "请输入你的字符串：" << std::endl;
	std::string curStr,preStr="",maxStr="";
	int curNum = 0,preNum=0,maxNum=0;
	while (std::cin >> curStr) {
		if (curStr == preStr) {
			++curNum;
		}
		else {
			preStr = curStr;
			curNum = 1;
		}
		if (maxNum < curNum) {
			maxNum = curNum;
			maxStr = preStr;
		}
	}
	std::cout << "连续出现次数最多的字符串是：" << maxStr << "，出现次数是：" << maxNum << std::endl;
	return 0;
}
```

### 5.15

循环的含义，改正错误

(a) 循环实现ix的递增。ix在for循环中定义，无法在if语句中继续使用。

(b) for循环缺少初始值

(c) sz将会一直增加，ix追不上sz，无限循环

### 5.16

```c++
// while idiomatic
int i;
while ( cin >> i )
    // ...

// same as for
for (int i = 0; cin >> i;)
    // ...

// for idiomatic
for (int i = 0; i != size; ++i)
    // ...
    
// same as while
int i = 0;
while (i != size)
{
    // ...
    ++i;
}
```

### 5.17

检验一个vector对象是否是另一个的前缀

```c++
int main()
{
	std::vector<int> ivec1 = { 0,1,1,2 };
	std::vector<int> ivec2 = { 0,1,1,2,7,8,9 };
	bool same=true;
	for (int i = 0; i < ivec1.size(); ++i) {
		if (ivec1[i] != ivec2[i]) {
			same = false;
			break;
		}
	}
	if (same)
		std::cout << "bingo";
	else
		std::cout << "not same";
	std::cout << std::endl;
	return 0;
}
```

### 5.18

理解以下循环的含义并修改错误

```c++
do{
	int v1.v2;
	//...
}while(cin);

int val;
do{
	//...
}while(val=get_response());

int ival=get_response();
do{
	ival=get_response();
}while(ival);
```

### 5.19

编写程序，使用do-while执行：首先提示用户输入两个string对象，然后选出较短的那个输出

```c++
int main()
{
	std::string strFlag;
	do {
		std::string str1, str2;
		std::cout << "please enter two string:" << std::endl;
		std::cin >> str1 >> str2 ;
		if (str1.size() < str2.size())
			std::cout << "较短的字符串为：" << str1 << std::endl;
		else
			std::cout << "较短的字符串为：" << str2 << std::endl;
		std::cout << "if you want to continue? y/n " << std::endl;
		std::cin >> strFlag;
	} while (strFlag=="y");
	std::cout << std::endl;
	return 0;
}
```

### 5.20

编写程序，标准输入读取string对象的序列直到连续出现两个相同的单词或者所有单词都读完为止。

```c++
int main()
{
	std::string str, prestr = "";
	while (std::cin >> str) {
        if(!)
		if (str == prestr) {
			break;
		}
		else
			prestr = str;
	}
	if (std::cin.eof())
		std::cout << "no same element";
	else
		std::cout << "the same element is: " << str;
	std::cout << std::endl;
	return 0;
}
//注：cin.eof()的作用是判断输入是否结束，当win系统下ctrl+z控制输入结束后，cin.eof()会返回true
```

### 5.21

修改5.5.1练习题程序，使其找到的重复单词必须以大写字母开头

```c++
int main()
{
	std::string str, prestr = "";
	while (std::cin >> str) {
		if (!isupper(str[0])) {
			prestr = "";
			continue;
		}
		if (str == prestr) {
			break;
		}
		else
			prestr = str;
	}
	if (std::cin.eof())
		std::cout << "no same element";
	else
		std::cout << "the same element is: " << str;
	std::cout << std::endl;
	return 0;
}
```

### 5.22

for循环代替goto语句

```c++
//源程序
begin:
	int sz=get_size();
	if(sz<=0){
		goto begin;
	}
//修改
for(int sz=get_size();sz<=0;sz=get_size())
	;
```

### 5.23

编写程序，标准输入两个整数，输出第一个数除以第二个数的结果

```c++
int main()
{
	int num1, num2;
	std::cin >> num1 >> num2;
	std::cout << "result is: " << static_cast<double>(num1) / num2;
	std::cout << std::endl;
	return 0;
}
//static_cast实现强制类型转换
```

### 5.24

先不使用catch子句，实现除数为0时抛出异常

```c++
int main()
{
	int num1, num2;
	std::cin >> num1 >> num2;
	if (num2 == 0) throw std::runtime_error("the second number is zero!!!");
	std::cout << "result is: " << static_cast<double>(num1) / num2;
	std::cout << std::endl;
	return 0;
}
```

### 5.25

try语句捕获异常，catch子句输出提示信息，询问是否重新输出并执行try语句

```c++
int main(void)
{
    int a, b;
    cout << "Input two integers: ";
    while (cin >> a >> b) {
        try {
            if (b == 0) throw runtime_error("divisor is 0");
            cout << static_cast<double>(a) / b << endl;
            cout << "Input two integers: ";
        }
        catch (runtime_error err) {
            cout << err.what() ;
            cout << "\nTry Again? Enter y or n:" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
            else
                cout << "Input two integers: ";
        }
    }

    return 0;
}
```

