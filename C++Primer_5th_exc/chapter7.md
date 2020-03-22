第七章练习题

### 7.1

使用2.6.1节练习定义的Sales_data类为1.6节（P21）的交易处理程序编写一个新版本。

```c++
#include"salesdata.h"

int main()
{
    salesdata total;
    if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
        salesdata trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            if (total.bookNo == trans.bookNo)
                total.AddData(trans);
            else {
                total.print();
                total = trans;
            }
        }
        total.print();
    }
    else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
```

### 7.2

曾在2.6.2节的练习中编写了一个Sales_data类，请向这个类添加combine和isbn成员。

```c++
#include<string>
struct Sales_data
{
	std::string bookNo;
	unsigned units_sold=0;
	double revenue = 0;
	
	std::string isbn(){return bookNo;}
	Sales_data& combine(Sales_data&);
};

Sales_data& Sales_data::combine(Sales_data& temp){
	units_sold+=temp.units_sold;
	revenue+=temp.revenue;
	return *this;
}
```

### 7.3

修改7.1.1的交易处理程序，令其使用以上成员

```c++
#include"ex7_02_sales_data.h"
#include<iostream>

int main(){
	Sales_data total;
	if(std::cin>>total.bookNo>>total.units_sold>>total.revenue){
		Sales_data trans;
		while(std::cin>>total.bookNo>>total.units_sold>>total.revenue){
			if(total.isbn()==trans.isbn())
				total.combine(trans);
			else{
				std::cout<<total.bookNo<<" "<<total.units_sold<<" "<<total.revenue<<std::endl;
				total=trans;
			}
		}
	std::cout<<total.bookNo<<" "<<total.units_sold<<" "<<total.revenue<<std::endl;
	}
	else{
		std::cerr<<"No data?"<<std::endl;
		return -1;
	}
	return 0;
}
```

### 7.4

编写一个person的类，使其表示人员的姓名和住址，使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征

```c++
#ifndef CP5_ex7_04_h
#define CP5_ex7_04_h
#include<string>

typedef struct Person{
	std::string name;
	std::string address;
};
#endif
```

### 7.5

在Person类中提供一些操作使其能够返回姓名和住址，这些函数是否应该是const的？解释原因

```c++
#ifndef CP5_ex7_04_h
#define CP5_ex7_04_h
#include<string>

typedef struct Person{
	std::string name;
	std::string address;
public:
	const std::string& getName() const{return name;}
	const std::string& getAddress() const{return address;}
};
#endif
```

以上应该使用const，因为函数的作用是返回姓名和地址，并不会对其进行改变。

