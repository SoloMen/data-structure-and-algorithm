/**
 * @Author: Chacha 
 * @Date: 2018-12-03 17:14:17 
 * @Last Modified by: Chacha
 * @Last Modified time: 2018-12-12 21:50:07
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Normal Queue
class MyQueue {
    private:
        // store elements
        vector<int> data;       
        // a pointer to indicate the start position
        int p_start;            
    public:
        MyQueue() {p_start = 0;}
        /** Insert an element into the queue. Return true if the operation is successful. */
        bool enQueue(int x) {
            data.push_back(x);
            return true;
        }
        /** Delete an element from the queue. Return true if the operation is successful. */
        bool deQueue() {
            if (isEmpty()) {
                return false;
            }
            p_start++;
            return true;
        };
        /** Get the front item from the queue. */
        int Front() {
            return data[p_start];
        };
        /** Checks whether the queue is empty or not. */
        bool isEmpty()  {
            return p_start >= data.size();
        }
};

/***********************************************************************************
 * Design your implementation of the circular queue. 
 * The circular queue is a linear data structure in which the operations 
 * are performed based on FIFO (First In First Out) principle and 
 * the last position is connected back to the first position to make a circle. 
 * It is also called "Ring Buffer".
 * Your implementation should support following operations:
 *  1. MyCircularQueue(k): Constructor, set the size of the queue to be k.
 *  2. Front: Get the front item from the queue. If the queue is empty, return -1.
 *  3. Rear: Get the last item from the queue. If the queue is empty, return -1.
 *  4. enQueue(value): Insert an element into the circular queue. 
 *     Return true if the operation is successful.
 *  5. deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
 *  6. isEmpty(): Checks whether the circular queue is empty or not.
 *  7. isFull(): Checks whether the circular queue is full or not.
 *  
 * Example:
 *  MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
 *  circularQueue.enQueue(1);  // return true
 *  circularQueue.enQueue(2);  // return true
 *  circularQueue.enQueue(3);  // return true
 *  circularQueue.enQueue(4);  // return false, the queue is full
 *  circularQueue.Rear();  // return 3
 *  circularQueue.isFull();  // return true
 *  circularQueue.deQueue();  // return true
 *  circularQueue.enQueue(4);  // return true
 *  circularQueue.Rear();  // return 4
 * 
 * Source： https://leetcode-cn.com/explore/learn/card/queue-stack/216/queue-first-in-first-out-data-structure/865/
************************************************************************************/

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            head = 0;
        }

        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        
        if (head == tail) {
            head = -1;
            tail = -1;
            return true;
        }
        
        head = (head + 1) % size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return ((tail + 1) % size) == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */


/**
 * Implement Queue by Two Stacks
 * As the title described, you should only use two stacks to implement a queue's actions.
 * The queue should support push(element), 
 * pop() and top() where pop is pop the first(a.k.a front) element in the queue.
 * Both pop and top methods should return the value of first element.
 * LIFO + LIFO ==> FIFO
 * 
 * Example:
 *  For push(1), pop(), push(2), push(3), top(), pop(), you should return 1, 2 and 2
 */

class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;

    MyQueue() {

    }

    void push(int element) {
        stack1.push(element);
    }
    
    void adjust() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }
    
    int pop() {
        adjust();
        int temp = stack2.top();
        stack2.pop();
        return temp;
    }

    int top() {
        adjust();
        return stack2.top();
    }
};

/**
 * BFS - Template 1
 * Return the length of the shortest path between root and target node.
 * 
 * 1. As shown in the code, in each round, the nodes in the queue are the nodes which are waiting to be processed.
 * 2. After each outer while loop, we are one step farther from the root node. 
 *    The variable step indicates the distance from the root node and the current node we are visiting.
 */
int BFS(TreeNode root, TreeNode target) {
    queue<TreeNode> queue;  // store all nodes which are waiting to be processed
    int step = 0;       // number of steps neeeded from root to current node
    // initialize
    add root to queue;
    // BFS
    while (queue is not empty) {
        step = step + 1;
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node cur = the first node in queue;
            return step if cur is target;
            for (Node next : the neighbors of cur) {
                add next to queue;
            }
            remove the first node from queue;
        }
    }
    return -1;          // there is no path from root to target
}

/**
 * BFS - Template 2
 * Return the length of the shortest path between root and target node.
 * 
 * There are two cases you don't need the hash set used:
 *  1. You are absolutely sure there is no cycle, for example, in tree traversal;
 *  2. You do want to add the node to the queue multiple times.
 */
int BFS(TreeNode root, TreeNode target) {
    queue<TreeNode> queue;  // store all nodes which are waiting to be processed
    int step = 0;       // number of steps neeeded from root to current node
    // initialize
    add root to queue;
    // BFS
    while (queue is not empty) {
        step = step + 1;
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node cur = the first node in queue;
            return step if cur is target;
            for (Node next : the neighbors of cur) {
                add next to queue;
            }
            remove the first node from queue;
        }
    }
    return -1;          // there is no path from root to target
}

int main() {
    MyCircularQueue q(6);
    q.enQueue(5);
    q.enQueue(3);
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
    q.deQueue();
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
    q.deQueue();
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }
}