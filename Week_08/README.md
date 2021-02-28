学习笔记

### 161.位1的个数
这个题目比较简单。对32位的int类型的每一位进行遍历，可以用此题的代码模板
```c++
for (int i = 0; i <32; ++i){
    // operations
    n >>= 1;
}
```

### 231.2的幂
这道题只需要证明两个点：
`n > 0`
`n & (n-1) == 0`


### 各种排序算法
```c++
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
class Sort
{
private:
    vector<int> vec;
    vector<int> vec_correct;
    int size;

public:
    Sort(vector<int> &);
    ~Sort();

public:
    void print() const;
    void bubble_sort();
    void insertion_sort();
    void insertion_sort_version2();
    void insertion_sort_test();
    void select_sort();
    void print_array() const;

    void merge(int left, int middle, int right);
    void merge_sort(int left, int right);
    void merge_sort_version2(int left, int right);

    int patition(int left, int right);
    void quick_sort(int left, int right);
};

void Sort::bubble_sort()
{ //O(n^2)
    for (int i = 0; i < size - 1; ++i)
        for (int j = i; j < size - 1; ++j)
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
}

void Sort::insertion_sort()
{ //list insert: insert in front of  the ite given
    list<int> res_list;
    res_list.push_back(vec[0]);
    for (int i = 1; i < size; ++i)
    {
        auto ite = res_list.begin();
        while (vec[i] > *ite && ite != res_list.end())
        {
            ++ite;
        }
        res_list.insert(ite, vec[i]);
    }
    vec.clear();
    copy(res_list.begin(), res_list.end(), back_inserter(vec));
}

void Sort::insertion_sort_version2()
{//O(n^2)
    int t, j;

    for (int i = 1; i < size; ++i)
    {
        t = vec[i]; //t暂存vec[i]，因为后面的向后移动可能会覆盖vec[i]的数据
        for (j = i - 1; j >= 0 && t < vec[j]; --j)
        {
            vec[j + 1] = vec[j]; //向后移动，腾出vec[i]的位置用来插入
        }
        vec[j + 1] = t;
    }
}

void Sort::insertion_sort_test()
{
    int i, j, t;
    for (i = 0; i < vec.size(); i++)
    {
        t = vec[i];
        for (j = i - 1; j >= 0 && t < vec[j]; --j)
        {
            vec[j + 1] = vec[j];
        }
        vec[j + 1] = t;
    }
}

void Sort::select_sort()
{
    int min_value, swap_index;
    for (int i = 0; i < size; ++i)
    {
        min_value = vec[i];
        swap_index = i;
        //search the min
        for (int j = i + 1; j < size; ++j)
        {
            if (vec[j] < min_value)
            {
                min_value = vec[j];
                swap_index = j;
            }
        }
        swap(vec[i], vec[swap_index]);
    }
}

void Sort::merge(int left, int middle, int right)
{                               //v在left--middle和middle+1---right分别升序
    vector<int> aux(right + 1); //这个数组的空间要开的足够大，大小至少等于right(第99行可以得到这个数字)
    int i, j;
    for (i = middle + 1; i > left; --i)
        aux[i - 1] = vec[i - 1];
    for (j = middle; j < right; ++j)
        aux[middle + right - j] = vec[j + 1];

    //双指针,此时i\j已经位于需要合并的两端，可以在aux中进行双指针排序
    for (int k = left; k <= right; ++k)
        vec[k] = aux[j] < aux[i] ? aux[j--] : aux[i++];
}

void Sort::merge_sort(int left, int right)
{
    if (right <= left)
        return;
    int middle = (right + left) / 2;
    merge_sort(left, middle);
    merge_sort(middle + 1, right);
    merge(left, middle, right);
}

void Sort::merge_sort_version2(int left, int right)
{
    for (int m = 1; m < right - left; m *= 2)
    { //m为步长
        for (int i = left; i <= right - m; i += 2 * m)
        {
            merge(i, i + m - 1, min(i + m + m - 1, right));
        }
    }
}

void Sort::print() const
{
    if (vec == vec_correct)
        cout << "true";
    else
        cout << "wrong";
}

void Sort::print_array() const
{
    for (auto i : vec)
    {
        cout << i << ' ';
    }
}

Sort::Sort(vector<int> &v) : vec{v}, size{int(v.size())}
{
    vector<int> vec_copy(v);
    sort(vec_copy.begin(), vec_copy.end());
    vec_correct = move(vec_copy);
}

Sort::~Sort()
{
}

int Sort::patition(int left, int right)
{ //双指针思想
    int i = left - 1, j = right;
    int flag = vec[right];
    for (;;)
    {
        //找到第一个比flag大的下标，设置为i
        while (vec[++i] < flag)
        {
            if(i == right)
                break;
        }
        while (flag < vec[--j])
        {
            if (j == left)
                break;
        }
        if (i >= j)
            break;
        swap(vec[i], vec[j]);
    }
    swap(vec[i], vec[right]);
    return i;
}

void Sort::quick_sort(int left, int right)
{ //最差情况O(n^2),也就是每次选取的基准都是最大，所以partition都要遍历left-right+1次
    if (left >= right)
        return;
    int i = patition(left, right);
    quick_sort(left, i - 1);
    quick_sort(i + 1, right);

    //空间优化操作
    // if(i-left > right-i)
    // {
    //     quick_sort(i+1, right);
    //     quick_sort(left, i - 1);
    // }
    // else
    // {
    //     quick_sort(left, i - 1);
    //     quick_sort(i + 1, right);
    // }
}
int main()
{
    vector<int> v{2, 1, 3, -4, 2, -5, 2, 6, 8, -9};
    Sort s(v);
    // s.bubble_sort();
    // s.select_sort();
    // s.merge_sort_version2(0, v.size() - 1);
    s.quick_sort(0, v.size() - 1);
    // s.insertion_sort_test();
    s.print_array();
    return 0;
}
```