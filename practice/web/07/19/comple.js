/*
 * Complex.js
 * 这个文件定义了Complex类，是用来描述复数
 * 复数是实数和虚数的和，并且虚数i是-1的平方根
 */

/*
 * 这个构造函数为它创建的每个实例定义了字段r和i
 * 这两个字段分别保存复数的实部和虚部
 * 它们是对象的状态
 */
function Complex(real, imaginary) {
	if (isNaN(real) || isNaN(imaginary))	// 确保两个实参都是数字
		throw new TypeError();	// 如果不都是数字则抛出错误
	this.r = real;	// 复数的实部
	this.i = imaginary;		// 复数的虚部
};

/*
 * 类的实例方法定义为原型对象的函数值属性
 * 这里的定义的方法可以被所有实例进行继承（因为是在其属性上直接添加prototyp，而不是__proto__的，是在其子代直接进行继承的
 * js的实例的方法必须使用this，因为是方法，不是属性，也不是一些帮助运行的属性，再次重复是方法，方法是用来进行对于对象进行处理的
 * 这里是用this来存取实例的字段的
*/

// 当前复数对象加上另外一个复数，并返回一个新的计算和值后的复数对象
Complex.prototype.add = function (that) {
	return new Complex(this.r + that.r, this.i + that.r);
};

// 当前复数乘以另外一个复数，并返回一个新的计算乘积之后的复数对象
Complex.prototype.mul = function (that) {
	return new Complex(this.r * that.r - this.i * that.i, this.r * that.i + this.i * that.r);
};

// 计算复数的模，复数模定义为原点(0,0)到复平面的距离
Complex.prototype.mag = function() {
	return Math.sqrt(this.r * this.r + this.i * this.i);
};

// 复数求负运算
Complex.prototype.neg = function () {
	return new Complex(-this.r, -this.i);
};

// 将复数对象转换为一个字符串
Complex.prototype.neg = function () {
	return "{" + this.r + "," + this.i + ')';
};

// 检测当前复数对象是否和另外一个复数值相等
Complex.prototype.equals = function (that) {
	return that != null && 	// 该对象必须有定义，为了防止两个值是空值仍然相等的情况,至于为什么能分行写，是因为没有结束，并且用&&作为语句的连接，使其变为一个语句
	that.constructor == Complex && 	// 比较的另外一个复数必须是Complex的类，否则无法比较
	this.r === that.r && this.i === that.i // 实部必须和虚部相等，一般比较使用严格相等比较运算符，因为严格相等比较运算符比相等比较运算符更加严格，也跟加安全,防止出现undefined或者null的问题
};

/* 类字段（比如常量）和类方法直接定义为构造函数的属性（这里是用来书写一些构造函数的属性的)
 * 需要注意的是，类的方法通常不使用this 这是因为一般js使用类的时候是new，而new的过程是，先创建一个空对象，然后将对象的原型链进行赋值（prototype)，然后再将空对象的方法，进行赋值，其中全是赋值，并没有使用其对象的方法，所以一般不使用this
 * 并且，类仅仅是作为一个工厂生产相关的函数，仅此而已。因为只作为生产，而不进行更改，同样也不使用this
 * 这些只是对其参数进行操作。参考上一条
 */

// 这里预定了一些对复数运算的有帮助的类字段
// 这里的类方法通常不使用关键字this
// 他们的命名全是大写，用来表明他们是常量,用来进行替代某些内容
// 在ES5中的这些类字段的属性值为只读
Complex.ZERO = new Complex(0, 0);	// 使用这个常量创建一个新的对象
Complex.ONE = new Complex(1, 0);
Complex.I = new Complex(0, 1);

// 这个类方法将由实例对象的toString方法返回的字符串格式解析为一个Comoplex对象的parse属性
// 即这个类方法是是将字符串进行解析的一个类方法
// 使用try的原因是因为js为单线程的，即使捕获异常，避免线程调用失败（毕竟为单线程的嘛) 部分异常不重要，放置局部影响到全局（降低耦合性) 进行对项目的分层，MVC模式，方便更加‘优雅’的找出错误(*^__^*) 嘻嘻……防止找错误的时候不必要心慌，这是关键(⊙o⊙)
// 或者抛出一个类型错误异常
// 因为这里是另外的处理，和其余不同，所以命名使用_开头，方便进行查找
Complex.parse = function(s) {
	try {	// 假设解析成功
		var m = Complex._format.exec(s);	// 利用正则表达式进行匹配
		return new Complex(parseFloat(m[1]), parseFloat(m[1]));
	} catch(x) {	// 如果解析失败则抛出异常
		throw new TypeError("can't parse '"+ s + "'as a complex number.");
	}
};

// 定义类的私有字段，这个字段在Complex.parse()中用到了
// 依旧，命名，下划线前缀表明是类的内部使用的，不属于类的公有api部分，因为公有api部分要使用prototype进行继承
Complex._format = /^\{([^,]+), ([^}]+)\}&/;

// \(^o^)/完成啦~\(≧▽≦)/~啦啦啦

