# 函数说明
函数接受任意多的字符串参数
每个参数将当做元素的id传给document.getElementById()
将会返回一个对象，把这些id映射到对应的Element对象
如任何一个id对应的元素未定义，则会抛出一个Error对象

# 使用方法

调用函数进行解析
```
var elements = getElements(/*ids*/);	
```