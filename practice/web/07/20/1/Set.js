/*
 *
 * set.js文件，实现一个字符串到集合之间的映射，然后将字符串用作属性名
 *
*/

function Set() {  // 这是一个构造函数
  this.values = {}; // 集合的数据保存在对象的属性里
  this.n = 0; // 集合中值的个数
  this.add.apply(this, arguments);  // 把所有的参数都添加进这个集合中  add为自定义的方法
}

// 将每个参数都添加到集合中
// 实现 add 方法
Set.prototype.add = function() {
  for(var i = 0; i < arguments.length; i++) 
  { // 进行遍历操作，遍历每个参数
    var val = arguments[i]; // 这是待添加到集合中的值  
    var str = Set._v2s(val);	// 自定义方法，将遍历到的值转换为字符串
    if (!this.values.hasOwnProperty(str))
    {	// 如果不在集合中
    	this.values[str] = val;	// 将字符串和值对应起来
    	this.n++;	// 集合中的值计数器加1
    };
  };
  return this;	// 支持链式调用

};

// 从集合中删除元素，这些元素由参数制定
Set.prototype.remove = function () {
	for(var i = 0; i < arguments.length; i++) {	// 遍历每个参数
		var str = Set._v2s(arguments[i]);	// 将字符串和值对应起来
		if (this.values.hasOwnProperty(str)) {	// 如果在集合中
			delete this.values[str];	// 则删除这个属性
			this.n--;	// 将长度减去一个
		}
	}
	return this; // 让这个函数支持链式调用
}

// 如果集合包含这个值，则返回true，否则，返回false
Set.prototype.contains = function (value) {
	return this.values.hasOwnProperty(Set._v2s(value));
};
// 返回集合的大小
Set.prototype.size = function () {
	return this.n;
};

// 遍历集合中的所有元素，在指定的上下文中调用f
Set.prototype.foreach = function (f, context) {
	for(var s in this.values)	// 遍历集合中的所有的字符串。使用的是for in 语法
		if (this.values.hasOwnProperty(s))	// 将继承的属性忽视，即prototype的属性全部忽视
			f.call(context, this.values[s]);	// 以context的对象的调用方法f并传入参数values的值
};

// 这是一个内部函数，用以将任意的js的值和唯一的字符串对应起来
Set._v2s = function (val) 
{
	switch (val) 
	{
		case undefined: return 'u';	// 说明这是特殊的原始值
		case null: return 'n';	// 值为null的情况
		case true: return 't';	// 正确的值
		case false: return 'f';	// 错误的值
		default: switch (typeof val) 
		{	// 所有的条件都不匹配的情况下，执行另外一个选择，分开写的原因是因为让程序具有分层作用
			case 'number': return '#' + val;	// 如果为数字，则将所有的数字前加上#
			case 'string': return '"' + val;	// 字符串全部带上"前缀
				default: return '@' + objectId();	// 前面加上@并调用一个私有方法
		}
	}

	// 对于任意对象来说，都会返回一个字符串
	// 针对不同对象，这个函数会返回不同的字符串
	// 对于同一个对象的多次调用，总是返回相同的字符串
	function objectId(o) {
		var prop = "|**objectid**|";	// 私有属性，用来存放id，其中内容仅仅为注释
		if (!o.hasOwnProperty(prop))	// 如果传入的对象没有id，则进行id赋值
			o[prop] = Set.next++;	// 进行赋值，并完成一次自加，即先赋值，后自加
		return o[prop];	// 仅仅是返回该id
	}
};
Set._v2s.next = 100;	//设置初始值为100


