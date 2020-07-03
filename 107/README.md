# 107 Binary Tree Level Order Traversal II    

## TAG
* 水题
* 数据结构
* 二叉树

## 需要注意的点
无

## 解法
遍历二叉树的时候，记一下当前在第几层，然后放到对应的vector里就好了。

如：root属于第0层，放在`vector[0]`，最后再反转一下数组就行。