学习笔记
说一下自己设计的循环deque，这个题目按照我的设计思路必须要注意每次对索引进行运算都要加上size再对size取余数，要不然直接越界搞死你，我一开始写错一个检查了半天都没看出来，简直了。。。

另外接雨水是一个比较困难的问题，在题解中着重思考了**单调栈**的使用方法
单调栈模板如下：

```c++
stack<int> stk;
for(int i = 0; i < vec.size(); ++i)
{
    while(!stk.empty() && vec[stk.top()] < vec[i])//递减栈，改成大于号就是递增栈
    {
        //int i = stk.top();
        stk.pop();
        //other operations
    }
    stk.push(i);
}
```



**以及那个insertFront 数组移位的操作要背诵**

