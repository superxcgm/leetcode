# 448 Find All Numbers Disappeared in an Array    

## TAG
无

## 需要注意的点
无

## 解法
这个题目我没有想到不用额外的空间的解法。Discuss里面的解法很妙。利用元素的值作为下标进行翻转，如果某个下标的数大于0，即没被翻转过，立即推，这就是一个没出现过的数。