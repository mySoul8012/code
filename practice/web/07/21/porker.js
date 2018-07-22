/*
 *	使用enumeration()工厂方法实现一个洗牌程序，其中Card为玩牌的类
 *	proker.js
 *	时间：2018/07/21 01:16
 */

// 定义一个表示玩牌的类
function Card(suit, rank) {
	this.suit = suit; // 每张牌都有花色
	this.rank = rank; // 每张牌的点数
};

// 使用枚举类型定义花色和点数
Card.Suit = enumeration({Cluds: 1, Diamonds: 2, Hearts: 3, Spades: 4});
Card.Rank = enumeration({Two: 2, Three: 3, Four: 4, Five: 5, Six: 6, Seven: 7, Eight: 8, Nine: 9, Ten: 10, Jack: 11, Quee: 12, king: 13, Ace: 14});

// 定义用以描述牌面的文本
Card.prototype.toString = function () {
	return this.rank.toString() + ' of ' + this.suit.toString();
};
// 比较扑克牌中两张牌的大小
Card.prototype.compareTo = function (that) {
	if (this.rank < that.rank) return -1;
	if (this.rank > taht.rank) return 1;
	return 0;
};

// 以扑克牌的玩法规则对牌进行排序的函数
Card.orderByRank = function (a, b) {
	return a.compareTo(b);
};

// 以桥牌的玩法规则对扑克牌进行排序的函数
Card.orderBySuit = function (a, b) {
	if (a.suit < b.suit) return -1;
	if (a.suit > b.suit) return 1;
	if (a.rank < b.rank) return -1;
	if (a.rank > b.rank) return 1;
	return 0;
};

// 定义用以表示一副标准扑克牌的类
function Deck() {
	var cards = this.cards = [];	// 一副牌就是由牌组成的数组(这里有个小命名规范，类不加s，而具体的实例加s)
	Card.Suit.foreach(function (s) {	// 初始化这个数组
		Card.Rank.foreach(function (s){		// 其中foreach为其工厂类的一个自定义的一个类方法，这个类方法为一个迭代的方法，其中s为迭代方法中的this.values[i]的值
			Card.Rank.foreach(function (r) {	// 同理r也是，只不过会先将其父的函数存放入栈中
				cards.push(new Card(s, r));	// 将结果推入该对象的cards属性中的数组
			})
		} )		
	})
};

// 洗牌
Deck.prototype.shuffle = function() {
	// 先使用for循环进行遍历，在生成随机数，将遍历到的和随机数进行随机交换
	var deck = this.cards, len = deck.length;	// 先进行数据总的汇总
	for (var i = len - i; i > 0; i--) {
		var r = Math.floor(Math.random() * (i + 1)), temp;	// 随机数的生成
		temp = deck[i], deck[i] = deck[r], deck[r] = temp;
	}
	return this;	// 返回洗牌的程序
};

// 发牌方法，返回牌的数组
Deck.prototype.deal = function (n) {
	if (this.cards.length < n) throw "Out of cards";
	return this.cards.splice(this.cards.length - n, n);
};



