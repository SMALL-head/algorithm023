学习笔记
### 236题公共祖先
这个递归实际上是比较难理解的，只要找到了某一个节点，就向上返回，如果某一时候，这个节点的左右子树（或者左右孩子）都不为空，也就是都有返回值不为nullptr的情况，那么这个节点就是公共祖先了，然后把这个公共祖先继续向上返回，所有就有题解中的解答

### 105前序中序构造二叉树
这个题需要明确递归的操作是怎么样的。对于一个给定的前序和中序数组（假定他们一定是可以构造出一个二叉树的），那么首先可以判定前序第一个一定是根节点，然后再去中序数组中去寻找这个前序结点的下标，几位root_index（这里已经暗示了二叉树结点val必须唯一，否则这个算法构造不出来或者有多个解）。有了这个root_index就可以把中序切割成root_index左右两部分，分别是构造root的左右子树中序，有个左右子树中序的序列，就可以得到长度，从而在前序中也进行左右子树的划分，然后就可以递归了。

### 77组合
主要学习了回溯法，可以看到这里回溯是一个循环里面有一个回溯递归，所以直接去思考这个过程会比较麻烦。因此我觉得可以把循环想成横向拓展，递归想成是纵向拓展，最后再加上一个pop撤销修改，从而完成了这个回溯算法

### 46排列
利用swap直接在原数组上进行操作可以减少运行时间，同时此题也是一个比较典型的回溯模板