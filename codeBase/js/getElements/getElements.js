/*
 *	函数接收任意多的字符串参数
 *	每个参数将当做元素的id传给document.getElementById()
 *	返回一个对象，它把这些id映射到对应的Element对象
 *	如果一个id未定义，将会抛出一个Error对象
 */
function getElements(/*ids...*/) {
	var elements = {};	// 开始是一个空map映射对象
	for (var i = 0; i < arguments.length; i++) {	// 循环每个参数
		var id = arguments[i];
		var elt = document.getElementById(id);	// 进行查找元素
		if (elt == null)
			throw new Error("No element with id:" + id);	// 抛出异常
		elements[id] = elt;	// 完成映射关系
	};
	return elements;
};
