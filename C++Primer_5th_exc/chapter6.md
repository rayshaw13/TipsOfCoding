第六章 练习题

### 6.1

形参与实参的区别。形参在函数的列表中声明，实参是形参的初始值。

### 6.2

函数程序修改如下：

```c++
//a
string f(){
	string s;
	//
	return s;
}
//b
void f2(int i){
	/*...*/
}
//c
int calc(int v1,int v2){
	/*...*/
}
//d
double square(double x){
	return x*x;
}
```

### 6.3

编写自己的fact函数，并验证

```c++
int fact(int num) {
	int ret = 1;
	for (int i = 1; i <= num; ++i) {
		ret *= i;
	}
	return ret;
}

int main()
{
	int num = 5;
	std::cout << "the result is: " << fact(num);
	std::cout << std::endl;
	return 0;
}
```

### 6.4

编写与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数

```c++
int fact(int num) {
	if (num == 0 || num == 1)
		return 1;
	else
		return num*fact(num - 1);
}

void fact_input() {
	for (int val = 0; std::cout << "enter a number in [0,12]:", std::cin>>val;) {
		if (val < 0 || val>12) continue;
		else
			std::cout << val <<"的阶乘为："<< fact(val) << std::endl;
	}
}

int main()
{
	fact_input();
	std::cout << std::endl;
	return 0;
}
```

### 6.5

编写函数输出其实参的绝对值

```c++
template<typename T>
T abs(T i){
	return i>=0?i:-i;
}
```

### 6.6

形参 局部变量 局部静态变量的区别，编写函数说明。

```c++
int absGet(int num) {
	static int crr = 0;
	return abs(num+(++crr));
}
//num是形参，表示在函数体中的输入；crr是局部静态变量，第一次调用函数时crr值变为1，第二次时将保持为1并在输出后转化为2，即当函数结束调用时局部静态变量仍然可以使用，直到程序终止才会被销毁。
int main()
{
	int num=0;
	while (num < 10) {
		std::cout << absGet(-3) << ",";
		++num;
	}
	std::cout << std::endl;
	return 0;
}
//main函数中的num是一个局部变量
```

### 6.7

编写函数，当第一次调用时返回0，以后每次调用返回值都加一

```c++
int absGet() {
	static int crr = 0;
	return (crr++);
}

int main()
{
	int num=0;
	while (num < 10) {
		std::cout << absGet() << ",";
		++num;
	}
	std::cout << std::endl;
	return 0;
}
```

### 6.8

编写一个头文件，包含函数的声明

```c++
int fact(int num);
void fact_input();
template<typename T> T abs(T i);
```

### 6.10

编写函数，使用指针形参交换两个整数的值，在代码种调用该函数并输出交换后的结果。

```c++
void resetVal(int *val1, int *val2) {
	int temp=0;
	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

int main()
{
	int num1 = 3, num2 = 5;
	resetVal(&num1, &num2);
	std::cout << "num1= " << num1 << ", num2= " << num2;
	std::cout << std::endl;
	return 0;
}
```

### 6.11

编写并验证reset函数，使其作用于引用类型的参数

```c++
void reset(int& i){
	i=0;
}
int main(){
	int i=42;
	reset(i);
	std::cout<<i<<std::endl;
	return 0;
}
```

### 6.12

改写6.10的程序，使用引用而非指针交换两个整数的值。

```c++
void resetVal(int &val1, int &val2) {
	int temp=0;
	temp = val1;
	val1 = val2;
	val2 = temp;
}

int main()
{
	int num1 = 3, num2 = 5;
	resetVal(num1, num2);
	std::cout << "num1= " << num1 << ", num2= " << num2;
	std::cout << std::endl;
	return 0;
}
```

### 6.13

说明void f(T)和void f(&T)的区别

第一种当调用函数时，T是实参数值的拷贝，T的改变不会影响实参的数值。

第二种当调用函数时，T是实参的引用，T的改变会使得实参一同改变。

### 6.15

说明find_char函数的三个形参为什么是现在的类型？

s是常量引用的原因：函数用来统计s的长度，不会影响s的值，因此将其设置为常量

occurs是普通引用的原因：occurs在循环过程中值会改变，因此是普通引用

s和occurs是引用类型而c不是引用类型的原因：s的长度比较大，如果只是普通类型那就是实参的拷贝，会占用更多的空间，当occurs是引用类型时才可以在函数调用结束后仍可以使用。如果s是普通引用的话通常情况下没有影响，但是s可以在函数中被改变。occurs如果是常量引用的话就是一个固定值不会被改变，这将是错误的。

### 6.16

指出函数的局限性并进行改进

```c++
bool is_empty(string &s) {return s.empty();}
//修改为以下程序
bool is_empty(const string &s) {return s.empty();}
//原因：如果不加const的话，就不能应用在常量字符串上
```

### 6.17

编写两个函数，其一实现判断string对象是否含有大写字母，其二实现将string对象全部改为小写形式。比较使用的形参类型

```c++
bool haveUpper(const std::string &s) {
	for (auto i : s) {
		if (isupper(i))
			return true;
	}
	return false;
}

void toLower(std::string &s) {
	for (auto &i : s) {
		if (isupper(i))
			i=tolower(i);
	}
}

int main()
{
	std::string s1 = "Hello  World";
	std::string s2= "HEllo  World";
	if (haveUpper(s1))
		std::cout << "有大写";
	else
		std::cout << "没有大写";
	std::cout << std::endl;
	toLower(s2);
	std::cout << "s2转换为全部小写后为：" << s2;
	return 0;
}
```

函数一中字符串不会被改变因此设置为const，函数二中字符串会被改变，因此不能使用const

### 6.18

编写函数声明，推测函数具有的功能

```c++
//名为compare的函数，返回函数值，两个参数都是matrix类的引用
bool compare(const matrix &m1,const matrix &m1)
//名为change_val的函数，返回vector<int>的迭代器，有两个参数：一个是int，另一个是vector<int>的迭代器，有两个参数：一个是int，另一个是vector
const vector<int>::iteratir change_val(int num,vector<int>::iteratir)
```

函数一是比较两个matrix，其数值或者内容不会被改变所以使用const，函数二对迭代器做出了改变因此形参不适用const

### 6.19

只有a是非法的，因为形参数目不匹配

### 6.20

如果在函数中不会对参数进行改变的话，应该将引用形参设定为常量引用。

### 6.21

编写函数，接收两个参数，一个int型的数，一个int指针。函数比较int的值和int指针指向的值，返回较大的那个，在函数中指针的类型应该是什么？

```c++
int compare(int num1, const int* const num2) {
	return (num1 > *num2) ? num1 : *num2;
}

int main()
{
	int val1 = 3;
	int val = 8;
	int *val2=&val;
	std::cout << "输出较大的数字：" << compare(val1, val2) << std::endl;
	return 0;
}
```

### 6.22

编写函数，令其交换两个int指针

```c++
void swapPointer(const int*& p1, const int*& p2) {
	auto p = p1;
	p1 = p2;
	p2 = p;
}
//注 形参的类型中*表示指针，&表示指针的引用，因为函数返回类型为void，所以利用引用直接修改/交换地址
int main()
{
	const int val1 = 3, val2 = 8;
	const int* p1=&val1;//注意要对应上一语句设置为const，当然也可以写作auto p1=&val1;
	const int* p2 = &val2;
	swapPointer(p1, p2);
	std::cout << "交换之后指针指向的数值为：*p1=" << *p1 <<", *p2= "<< *p2 << std::endl;
	return 0;
}
```

### 6.23

参考本节的print函数，编写自己的版本，依次调用每个函数使其输入下面定义的i和j

int i=0, j[2]={0,1};

```c++
void print(int* const pi)
{
    if (pi) cout << *pi << endl;
}

void print(const char* p)
{
    if (p)
        while (*p) cout << *p++;
    cout << endl;
}

void print(const int* beg, const int* end)
{
    while (beg != end) cout << *beg++ << " ";
    cout << endl;
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) cout << ia[i] << " ";
    cout << endl;
}

void print(const int (&arr)[2])
{
    for (auto i : arr) cout << i << " ";
    cout << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    char ch[5] = "pezy";

    print(ch);
    print(begin(j), end(j));
    print(&i);
    print(j, end(j) - begin(j));
    print(const_cast<const int(&)[2]>(j));
}
```

### 6.24

描述函数行为，如果代码有问题，指出并改正

```c++
void print(const int ia[10]){
	for(size_t i=0;i!=10;++i)
		cout<<ia[i]<<endl;
}
//分析：函数的意思是传入数组并依次输出数组元素。但是在形参中输入数组时其实输入的是数组第一个元素的地址（即指针），因此以上函数中形参列表等于const int*，传入的[10]并不起作用，在main函数中可以输入iarray[3]也可以输入iarray[100]，因此错误。如果非要在形参中确定数组空间的话，可以这样：
void print2(const int (&ia)[10]){/**/}//ia是具有10个整数的整型数组的引用
```

### 6.25&6.26

编写程序main函数，令其接收两个实参，将实参的内容连接成一个string对象并输出

```c++
int main(int argc, char** argv) {
	std::string s;
	for (int i = 1; i < argc; ++i) {
		s += argv[i];
		s += " ";
	}
	std::cout << s << std::endl;
	return 0;
}
//当使用argv中的实参时，要记得argv[0]保存的是程序名，所以要从argv[1]开始
```

### 6.27

编写函数，它的参数是initializer_list<int>类型的对象，函数的功能是计算列表中所有元素的和

```c++
int sum(initializer_list<int> il){
	int sum=0;
	for(auto i=il.begin();i!=il.end();++i)
		sum+=*i;
	return sum;
}
```

### 6.32

函数的合法性

合法，将0-9赋值给数组

### 6.33

编写一个递归函数，实现vector对象中内容的输出

```c++
void pushVec(std::vector<int>::iterator beg,std::vector<int>::iterator end) {
	if (beg != end) {
		std::cout << *beg << " ";
		pushVec(std::next(beg), end);
	}
}

int main() {
	std::vector<int> ivec = { 1,2,3,4,5,6 };
	pushVec(ivec.begin(), ivec.end());
	std::cout << std::endl;
	return 0;
}
```

### 6.34

对于factorial函数，如果停止条件为*if(val!=0)*的话，当输入val是正整数，不会出现问题将正常计算，如果输入val是一个负数，将会无限计算下去。

### 6.35

对于以下程序，为什么使用的是val-1而不是val--

```c++
int factorial(int val){
	if(val>1)
		return factorial(val-1)*val;
	return 1;
}
```

如果使用val--的话，是后置递减，那就会先调用factorial(val)*val再执行减一，但是根据循环，factorial()的参数将会一直是最初的val.

