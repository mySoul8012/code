/*
 *	这个函数解析url查询串中的name=value字符串
 *	它将 name=value 对储存在一个对象的属性中，并返回该对象
 *	使用方法
 *
 *	var args = urlArgs();	// 调用定义好的函数，进行解析
 *  var q = args.q || "";	// 一个判断，如果参数存在使用参数，否则使用""
 *
 */

function urlArgs() {
	var args = {};
	var query = location.search.substring(1); 	// 获得问号后面的内容
	var pairs = query.split("&");	// 将字符串进行分割 按照& 即进行分项
	for(var i = 0; i < pairs.length; i++){	// 进行依次遍历
		var pos = pairs[i].indexOf('=');	// 进行查找是否有= 没有返回-1 有返回等号所在的索引
		if (pos == -1) {	// 如果没有 ‘=’
			continue;	// 跳过循环
		};
		var name = pairs[i].substring(0, pos);	// 因为后一个是不包括，所以返回=前面的内容
		var value = pairs[i].substring(pos+1);	// 返回等号后的结果
		args[name] = value;	// 对键值对进行存储 
	};
	return args;	// 返回数组
};