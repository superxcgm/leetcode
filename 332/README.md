# 332 Reconstruct Itinerary    

## TAG
* DFS
* 深度优先搜索

## 需要注意的点
1. 机票需要全部用完。
2. 同一类型的机票可能有多张。如：有两张从`JFK`到`LGA`的机票

## 解法
存储从`出发城市`到`到达城市`的map，然后搜索就行了。