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

