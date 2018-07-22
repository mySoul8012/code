/*
 *	enumeration.js文件
 *	2018年07月20日 02:31
 */

// 这个函数创建一个新的枚举类型，实参对象表示类的每个实例的名字和值(即传入的是一个集合,该集合是名字和值的键值对)
// 返回值是一个构造函数
// 类似于工厂函数，不过这个工厂函数加工的对象是构造函数
// 这个构造函数会抛出异常：不能使用它来创建该类型的新实例
// 返回构造函数包含名/值对的映射表
// 包括由值组成的数组，以及一个foreach()迭代器函数
function enumeration(namesToValues) {
	// 这个虚拟构造函数是返回值
	var enumeration = function(){ throw "can't Instantiate Enumerations"; };

	// 枚举值继承自这个对象
	var proto = enumeration.prototype = {
		constructor: enumeration,	// 说明该函数是由enumeration为原型创建的
		toString: function(){ return this.name; },	// 返回名字
		valueOf: function(){ return this.value; },	// 返回值
		toJSON: function(){ return this.name; },	// 转换为JSON
	};

	enumeration.values = [];	// 用来存放枚举对象的数组

	// 现在创建新类型的实例
	for (name in namesToValues) {	// for/in循环遍历每个值
		var e = Object.create(proto)	// 创建一个代表它的对象
		e.name = name;	// 给他一个名字
		e.value = namesToValues[name];	// 给他一个值
		enumeration[name] = e;	// 将它设置为构造函数的属性 
		enumeration.values.push(e);	// 将其储存到值数组中，即保存进上个创建的values的对象中
	};

	// 一个类方法，用来对类的实例进行迭代
	enumeration.foreach = function(f, c) {
		for(var i = 0; i < this.values.length; i++) f.call(c, this.values[i])	// 每次循环调用
	};

	// 返回标识这个新类型的构造函数
	return enumeration;
}