一、运算符重载
	1、下标操作 [] 一般用于容器型对象。
		
	2、函数操作符 (),重载此运算符，对象可以当作函数使用。
	
	3、解引用和间接成员访问运算符,*,->,重载此运算符，对象可以当作指针使用。
		
	4、智能指针与auto_ptr
		常规指针的缺点：一般一个指针变量离开它的作用域时，只有该指针所占用的内存空间才被释放（４字节或８字节），而指针所指向的内存空间不会释放。在某些特殊情况下，free/delete／delete[]可能调用不到，形成内存泄漏。
		
		智能指针与常规指针的一致性：智能指针其实就是对象，是通过运算符重载(*,->)，让对象与指针从用法上感觉一样。
		
		智能指针与常规指针不一致性：任何时候，一个对象只能有一个智能指针持有它的地址，否则该对象会被多个智能指针析构多次，智能指针的拷贝构造和赋值构造需要做深拷贝处理。
		
	练习：实现出一个简化的智能指针，不需要显示的释放内存。
		int类
		int*类
		
	标准库中的auto_ptr,实现了智能指针的基本功能。
		auto_ptr<目标类型>　智能指针对象（new 目标对象）；
		
	auto_ptr的局限性：
		不能跨作用域使用，不能放入标准容器中，不能指向对象数据。
	
	５、new和delete运算符
		在C++中new和delete虽然是关键字，但依然是运算符，因此可以重载，但一般一建议，在重载newdelete函数中，不需要显式调用构造和析构函数，编译器会自动生成调用代码。
		
二、运算符重载的限制
	１、不能重载的运算符
		作用域限定符(::)
		直接成员访问运算符(.)
		条件表达式运算符(?:)
		字节长度运算符(sizeof)
		类型信息运算符(typeid)
	２、基本类型的运算符无法重载
		int a,b;
		a+b;
		
		int operator+(int&a ,int& b)
		{
			return a+b;
		}
		
	３、无法通过重载来改变运算符的优先级。
		
	４、不能改变操作数的个数。
	
	５、不能发明新的运算符。
	
	注意：运算符的重载要注重一致性（与默认的运算规则一致）、可读性（运算符的重载是为提高代码的可读性、便捷性、要有意义，而不是自找麻烦）。
	
三、类的继承
	１、共性与个性
		共性表达了不同的事物之间共有的属性和行为。
		个性则表达每种类型事物特有的属性和行为。
		
		教师　学生
		
	２、超集与子集
		超集体现了基于共性的一般。
		子集体现了针对个性的特殊。
		
	３、基类与子类
		基类表示超集，体现共性，描述共有的属性和行为。
		子类表示子集，体现个性，描述特有的属性和行为。
		
	４、继承与派生
		子类继承自基类
		基类派生出子类
		
四、继承的基本语法
	１、继承表
		C++中一个子类可以有多个基类，因为需要以表的形式体现。
		每个基类的继承方式都可以不同。
		
		class 基类
		{
		
		};
		
		class 子类 : 继承方式　基类１,继承方式　基类2,...
		{
		
		};
		１、子类会继承父类的所以属性和行为。
		２、子类的同名成员会隐藏父类的同名成员。
		３、子类的同名函数与父类的同名函数不会构成重载（但会构成隐藏）。
		４、如何访问基类隐藏成员。
			一个把子类对象强制转换成基类对象。
			使用基类引用或指针指向子类对象。
			使用域限定符，子类对象.基类::成员。
				
		练习：定义一个基类，里面有三个成员，访问属性分别是 public,private,protected，然后定义一个子类继承基类，分别试验不同的继承方式对成员访问权限的影响。
		
五、继承的基本特点
	１、逻辑结构
		子类对象任何时候都可以当作基类类型的对象。
		子类的逻辑空间小于基类。
		子类对象与 基类对象　是　is a。
	２、物理结构
		子类的物理空间大于基类
		子类对象中的基类对象与通常意义上的基类对象没有本质区别。
		
	类型转换
		从子类对基类　ok
		子类的指针或引用可以隐式转换为基类的指针或引用，这种操作编译器认为是安全的。
		
		从基类到子类　no
		基类的指针或引用不可以隐式转换成子类的指针或引用，这种操作在编译器看是类型扩大，是危险的。
		
		注意：编译器会对类型做安全检查，但仅仅检查指针或引用的数据类型，而不检查目标，不实际的类型无关。
		
	
	
