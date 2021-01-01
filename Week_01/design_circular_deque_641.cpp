class MyCircularDeque
{
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : _array{new int[k+1]}, size{k+1}
    {
        head = 0;
        next = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            _array[head] = value;
            next = (next + 1 + size) % size;
            return true;
        }
        for (int i = (next - 1 + size) % size; i != (head - 1 + size) % size; i = (i - 1 + size) % size)
        {
            _array[(i + 1 + size) % size] = _array[i]; //移动元素
        }
        _array[head] = value;
        next = (next + 1 + size) % size;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (isFull())
            return false;
        else
        {
            _array[next] = value;
            next = (next + 1 + size) % size;
            return true;
        }
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (isEmpty())
            return false;
        else
        {
            head = (head + 1 + size) % size;
            return true;
        }
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (isEmpty())
            return false;
        else
        {
            next = (next - 1 + size) % size;
            return true;
        }
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if(isEmpty())
            return -1;
        return _array[head];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if(isEmpty())
            return -1;
        return _array[(next - 1 + size) % size];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return head == next;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        if ((next + 1 + size) % size == head)
            return true;
        else
            return false;
    }

private:
    int *_array;
    int size;
    int head, next;
};