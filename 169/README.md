# 169 Majority Element    

## TAG
* 水题

## 需要注意的点
无

## 解法
可以使用hash_map去记录每个元素出现的次数，然后返回符合条件的即可。如果用的是C++，应该使用`unordered_map`而不是`map`，因为这里不需要排序，所以unordered_map性能更好。