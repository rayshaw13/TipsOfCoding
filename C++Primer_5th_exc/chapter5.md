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

