第三章的练习题

### 3.2

标准输入一次读入一行，修改程序一次读入一个词

```c++
int main() {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::cout << line << std::endl;
	}
	return 0;
}
//
int main() {
	std::string word;
	while (std::cin>>word) {
		std::cout << word << std::endl;
	}
	return 0;
}
```

### 3.3

string的输入运算符以及getline函数处理空白字符

string的输入运算符跳过空白运算符，getline保留，遇到换行符才换行

### 3.4

字符串的比较

```c++
//大小比较
int main() {
	std::string str1,str2;
	std::cin >> str1 >> str2;
	if (str1 > str2)
		std::cout <<"更大的字符串是：" <<str1;
	else
		std::cout <<"更大的字符串是："<< str2;
	std::cout << std::endl;
	return 0;
}
//长度比较
int main() {
	std::string str1,str2;
	std::cin >> str1 >> str2;
	if (str1.size() > str2.size())
		std::cout <<"更长的字符串是：" <<str1;
	else
		std::cout <<"更长的字符串是："<< str2;
	std::cout << std::endl;
	return 0;
}
```

### 3.5

标准输入多个字符串并将它们连接在一起，输出连接成的大字符串；修改，用空格将多个字符串分割

```c++
//part1
int main() {
	std::string str1;
	std::string strOut;
	while (std::cin >> str1) {
		strOut += str1;
	}
	std::cout<<strOut << std::endl;
	return 0;
}
//part2
int main() {
	std::string str1;
	std::string strOut;
	while (std::cin >> str1) {
		if(strOut.empty())
			strOut += str1;
		else {
			strOut += " ";
			strOut += str1;
		}
	}
	std::cout<<strOut << std::endl;
	return 0;
}
```

### 3.6

编程，范围for语句将字符串的所有字符替换为X

```c++
int main() {
	std::string strOut;
	std::cin >> strOut;
	for (auto &c : strOut) {
		c = 'X';//注意在循环语句中使用了引用
	}
	std::cout<<strOut << std::endl;
	return 0;
}
```

### 3.7

将上一题中的auto 换为char后，结果没有变化。因为，在这里auto&获取的类型就是char&

### 3.8

分别用while和传统的for循环重写3.6的程序

```c++
int main() {
	std::string strOut1,strOut2;
	std::cin >> strOut1>>strOut2;
    //while循环
	decltype(strOut1.size()) length = 0;
	while (length < strOut1.size()) {
		strOut1[length] = 'X';
		++length;
	}
	std::cout << strOut1 << std::endl;
	//传统for循环
	for (decltype(strOut2.size()) length = 0; length < strOut2.size(); ++length)
		strOut2[length] = 'Y';
	std::cout << strOut2 << std::endl;
	return 0;
}
```

### 3.9

判断程序是否合法

不合法，因为s是空字符串

### 3.10

编程删除字符串中的标点符号，输出剩余部分

```c++
int main() {
	std::string str;
	std::cout << "输入一行包含标点符号的字符串：";
	while (std::getline(std::cin, str)) {
		for (auto c : str) {
			if (!ispunct(c))
				std::cout << c;
		}
		std::cout << std::endl;
	}
	return 0;
}
```

### 3.11

判断是否合法

看情况，因为s是常量字符串，同时c是引用，所以如果不改变c的值那么合法，如果改变c的值就是非法的

### 3.12

判断定义的合法性

正确，向量ivec的元素是vector<int>型

错误，类型不同

正确，svec包含10个"null"

### 3.13

(a) 空向量 (b) 10个元素均为0 (c) 10个元素均为42 

(d) 一个元素为10 (e) 两个元素，10和42 (f) 10个元素，均为空字符串 (g) 10个元素，均为“hi”

### 3.14

编写一段程序，cin读入一组整数并将其存入到vector对象

```c++
int main() {
	std::vector<int> ivec;
	int num = 0;
	while (std::cin >> num) {
		ivec.push_back(num);
	}
	return 0;
}
```

### 3.15

```c++
int main() {
	std::vector<std::string> svec;
	std::string str;
	while (std::cin >> str) {
		svec.push_back(str);
	}
	return 0;
}
```

### 3.16

编写程序，输出上面程序中对象的容量和内容

```c++
int main() {
	std::vector<std::string> svec;
	std::string str;
	while (std::cin >> str) {
		svec.push_back(str);
	}
	std::cout << "the size is:" << svec.size() << std::endl;
	for (decltype(svec.size()) i = 0; i < svec.size(); ++i) {
		if (i < svec.size() - 1) {
			std::cout << svec[i] << ",";
		}
		else
			std::cout << svec[i];
	}
	std::cout << std::endl;
	return 0;
}
```

### 3.17

cin读入一组词存入vector，所有词转换为大写并输出，每个词一行

```c++
int main() {
	std::vector<std::string> svec;
	std::string str;
	while (std::cin >> str) {
		svec.push_back(str);
	}
	std::cout << "the size is:" << svec.size() << std::endl;
	for (decltype(svec.size()) i = 0; i < svec.size(); ++i) {
		for (auto &x : svec[i])
			x = toupper(x);
		std::cout << svec[i] << std::endl;
	}
	//std::cout << std::endl;
	return 0;
}
//注意，toupper只能对单个字符，不能对字符串产生作用
```

### 3.18

非法，因为ivec没有初始化，是空的。应该对ivec进行初始化之后才可以调用ivec[0]

### 3.19

定义10个元素的vector对象的三种实现方法

```c++
std::vector<int> ivec1(10, 42);
std::vector<int> ivec2{ 42,42,42,42,42,42,42,42,42,42 };
std::vector<int> ivec3;
for (int i = 0; i < 10; ++i) {
	ivec3.push_back(42);
}
```

### 3.20

将每对相邻整数的和输出出来

```c++
int main() {
	std::vector<int> ivec;
	int num,total;
	while (std::cin >> num) {
		ivec.push_back(num);
	}
	for (int i = 0; i < ivec.size() - 1; ++i) {
		total = ivec[i] + ivec[i + 1];
		if (i == ivec.size() - 2) {
			std::cout << total;
		}
		else
			std::cout << total<<",";
	}
	std::cout << std::endl;
	return 0;
}
```

将首尾元素持续相加后输出

```c++
int main() {
	std::vector<int> ivec;
	int num,total;
	while (std::cin >> num) {
		ivec.push_back(num);
	}
	for (int i = 0; i < ivec.size()/2; ++i) {
		total = ivec[i] + ivec[ivec.size()-i-1];
		if (i == ivec.size()/2 - 1) {
			std::cout << total;
		}
		else
			std::cout << total<<",";
	}
	std::cout << std::endl;
	return 0;
}
```

### 3.21

迭代器重做练习题

```c++
int main() {
	std::vector<std::string> svec;
	std::string str;
	while (std::cin >> str) {
		svec.push_back(str);
	}
	std::cout << "the size is:" << svec.size() << std::endl;
	for (auto iter=svec.begin(); iter !=svec.end(); ++iter) {
		if (iter < svec.end() - 1) {
			std::cout << *iter << ",";
		}
		else
			std::cout << *iter;
	}
	std::cout << std::endl;
	return 0;
}
```

### 3.22

修改输出text第一段的程序，全部改成大写后输出

```c++
int main() {
	std::vector<std::string> svec;
	std::string str;
	while (std::getline(std::cin, str)) {
		svec.push_back(str);
	}
	std::cout << "the size is:" << svec.size() << std::endl;
	for (auto iter=svec.begin(); iter !=svec.end(); ++iter) {
		for (auto &item : *iter) {
			item = toupper(item);
		}
		std::cout << *iter<<std::endl;
	}
	std::cout << std::endl;
	return 0;
}
```

### 3.23

创建包含10个整数的vector对象，使用迭代器将所有元素变成原来的两倍。输出

```c++
int main() {
	std::vector<int> ivec;
	int num;
	while (std::cin>>num) {
		ivec.push_back(num);
	}
	std::cout << "the size is:" << ivec.size() << std::endl;
	for (auto iter=ivec.begin(); iter !=ivec.end(); ++iter) {
		*iter = *iter * 2;
		if (iter < ivec.end() - 1)
			std::cout << *iter << ",";
		else
			std::cout << *iter;
	}
	std::cout << std::endl;
	return 0;
}
```

### 3.24

利用迭代器重做3.20第二问

```c++
int main() {
	std::vector<int> ivec;
	int num, total;
	while (std::cin >> num) {
		ivec.push_back(num);
	}
	int i = 0;
	for (auto bgn = ivec.begin(),end=ivec.end()-1; bgn!=end; ++bgn,--end) {
		total = *bgn + *end;
		++i;
		std::cout << total<<" ";
	}
	
	std::cout << std::endl;
	return 0;
}
```

### 3.25

利用迭代器实现划分分数段的程序

```c++
int main() {
	std::vector<int> ivec(11);
	int num;
	while (std::cin >> num) {
		if (num <= 100) {
			++*(ivec.begin() + num / 10);
		}
	}
	for (auto iter = ivec.begin(); iter != ivec.end(); ++iter) {
		std::cout << *iter << ",";
	}	
	std::cout << std::endl;
	return 0;
}
```

### 3.26

因为两个迭代器之间没有定义加法运算

### 3.27

数组定义的合法性

1非法 数组大小必须是常量，2合法，3非法 数组大小必须是常量，4非法 字符串的长度是12（包含了一个空字符）

### 3.28

string不是内置的，所以sa sa2都是空的，int是内置的，所以ia是10个0，但是ia2在函数体内因此未定义

### 3.29

主要的缺点是数组的长度固定

### 3.30

超出索引

### 3.31

```c++
int main() {
	int num[10] = {0};
	for (int i = 0; i < 10; ++i) {
		num[i] = i;
	}
	for (auto ia : num) {
		std::cout << ia<<" ";
	}
	std::cout << std::endl;
	return 0;
}
```

### 3.32

vector重写以上程序

```c++
int main() {
	int num[10] = {0};
	for (int i = 0; i < 10; ++i) {
		num[i] = i;
	}
	int num2[10] = { 0 };
	for (int i = 0; i < 10; ++i) {
		num2[i] = num[i];
	}
	std::vector<int> ivec(10, 0);
	for (auto iter = ivec.begin(); iter != ivec.end(); ++iter) {
		*iter = iter - ivec.begin();
	}
	std::vector<int> ivec2(ivec);
	for (auto iv : ivec2) {
		std::cout << iv<<" ";
	}
	std::cout << std::endl;
	return 0;
}
```

### 3.33

如果没有初始化scores,那么数组未定义，值也是未知的

### 3.34

该程序的功能是对p1加上一定的移动距离，指向数组内的另一个元素。

### 3.35

编写程序使数组内的元素置为0

```c++
int main() {
	int num[10];
	int *a = std::begin(num);
	int *b = std::end(num);
	for (int* i = a; i != b; ++i) {
		*i = 0;
	}
	for (auto item : num) {
		std::cout << item << " ";
	}
	std::cout << std::endl;
	return 0;
}
```

### 3.36

编程比较两个数组是否相等，编程比较两个vector是否相等

```c++
bool compare(int *const b1, int *const e1, int *const b2,int *const e2) {
	if ((e1 - b1) != (e2 - b2))
		return false;
	else {
		for (int *i = b1,*j = b2; (i != e1&&j != e2); ++i, ++j) {
			if (*i != *j)
				return false;
		}
	}
	return true;
}

int main() {
	int arr1[3] = { 1,2,3 };
	int arr2[3] = { 1,2,4 };
	if (compare(std::begin(arr1), std::end(arr1), std::begin(arr2), std::end(arr2)))
		std::cout << "两个数组相等" << std::endl;
	else
		std::cout << "两个数组不相等" << std::endl;

	std::vector<int> ivec1 = { 1,2,3 };
	std::vector<int> ivec2 = { 1,2,3 };
	if(ivec1==ivec2)
		std::cout << "两个向量相等" << std::endl;
	else
		std::cout << "两个向量不相等" << std::endl;
	return 0;
}
```

### 3.37

该程序的作用是输出字符数组的每一个字符

### 3.38

指针的值是地址，两个地址相加得到的结果不一定指向一个实际的值

### 3.39

比较两个string对象

```c++
int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	if (s1 == s2)
		std::cout << "equal";
	else if (s1 > s2)
		std::cout << "s1>s2";
	else
		std::cout << "s1<s2";
	std::cout << std::endl;
	return 0;
}
```

### 3.40

编程，定义两个字符数组并用字符串字面值初始化它们，定义另一个字符数组存放前两个数组连接后的结果，使用strcpy和strcat把前两个数组的内容拷贝到第三个数组中。

```c++
int main()
{
	const char s1[] = "hello";
	const char s2[] = "world";
	size_t sz = strlen(s1) + strlen(" ") + strlen(s2) + 1;
	char* cstr=new char[sz];
	strcpy(cstr, s1);
	strcat(cstr, " ");
	strcat(cstr, s2);
	std::cout << cstr << std::endl;
	delete[] cstr;
	return 0;
}
```

### 3.41

编程实现用整型数组初始化一个vector对象

```c++
int main()
{
	int a[3] = { 1,2,3 };
	std::vector<int> ivec(std::begin(a), std::end(a));
	for (auto iter : ivec) {
		std::cout << iter << " ";
	}
	std::cout << std::endl;
}
```

### 3.42

编程实现将含有整数元素的vector对象拷贝给一个整型数组。

```c++
int main()
{
	std::vector<int> ivec{1,2,3,4};
	int num[4];
	for (int *i = std::begin(num); i != std::end(num); ++i) {
		*i = ivec[i - std::begin(num)];
	}
	for (auto i : num) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
```

### 3.43

三个程序输出ia的元素，1范围for循环，2普通for循环+下标，3普通for循环+指针

```c++
int main()
{
	int ia[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//范围for循环
	for (int (&i)[4] : ia) {
		for (int &j : i) {
			std::cout << j << " ";
		}
	}
	std::cout << std::endl;
	//对以上的简略分析，ia表示第一层数组，每个元素有四个子元素，因为将引用声明为四个元素的数组。即第一层循环有三次++，每一次中用一个四元素的引用数组来表示ia的一个元素。
    
	//普通for循环+下标
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			std::cout << ia[i][j] << " ";
		}
	}
	std::cout << std::endl;

	//普通for循环+指针
	for (int(*i)[4] = ia; i != ia + 3; ++i) {
		for (int *j = *i; j != *i + 4; ++j) {
			std::cout << *j << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}
//第一层循环中声明为int(*i)[4]的原因与第一段程序中引用的声明是一样的，用一个指针数组来表示ia的一个元素中的四个子元素。
```

#### 3.44

类型别名代替循环控制变量的类型

```c++
int main()
{
	int ia[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//范围for循环
	using use_array = int[4];
	for (use_array (&i) : ia) {
		for (int &j : i) {
			std::cout << j << " ";
		}
	}
	std::cout << std::endl;

	//普通for循环+下标
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			std::cout << ia[i][j] << " ";
		}
	}
	std::cout << std::endl;

	//普通for循环+指针
	for (use_array (*i) = ia; i != ia + 3; ++i) {
		for (int *j = *i; j != *i + 4; ++j) {
			std::cout << *j << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}
```

### 3.45

auto关键字代替以上

```c++
int main()
{
	int ia[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//范围for循环
	//using use_array = int[4];
	for (auto (&i) : ia) {
		for (int &j : i) {
			std::cout << j << " ";
		}
	}
	std::cout << std::endl;

	//普通for循环+下标
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			std::cout << ia[i][j] << " ";
		}
	}
	std::cout << std::endl;

	//普通for循环+指针
	for (auto (*i) = ia; i != ia + 3; ++i) {
		for (int *j = *i; j != *i + 4; ++j) {
			std::cout << *j << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}
```

