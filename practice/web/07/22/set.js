/*
 *	模块函数中的Set类
 *  时间：2018/07/22 13:15
 */

 // 声明全局变量Set, 使用一个函数返回值给其赋值
 // 函数结束后紧跟着圆括号，立即执行
 // 将其返回值赋值给Set
 // 这为函数表达式，没有创建函数变量
var Set = (function(){
	function Set() {	// 这个构造函数为局部变量
		this.values = {};	// 这个对象用来保存这个集合
		this.n = 0;	// 集合中的个数
		this.add.apply(this, arguments);	// 将所有的参数添加到集合中
	};

	// 给Set.prototype定义实例方法
	Set.prototype.contains = function(vale) {
		// 这里调用v2s
		return this.values.hasOwnProperty(v2s(value));
	};
	Set.prototype.size = function() {/*...*/}

	// 这里的为辅助函数和变量
	// 这里的变量不属于公有的api，但是都隐藏在函数的作用域内
	// 因此，不需要将其定义为Set属性，或使用下划线用来标识
	function v2s(val) {/*...*/};

	// 这个模块的共有api为Set()构造函数
	// 我们需要把这个函数从私有命名空间导出，以便在外部可使用，通过返回构造函数的方式导出
	// 它会变成构造函数所指的值
	return Set;
}());	// 定义函数后立即执行