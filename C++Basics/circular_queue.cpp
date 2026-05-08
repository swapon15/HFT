#include <iostream>
#include <array>
using namespace std;

/**
 *  push, pop, front, empty, full
 * 
 * 
 */
class circular_queue {
    
    public:
    circular_queue(int capacity) : 
        mCapacity {capacity},
        mSize {0},
        head {0},
        tail {0} {
        mBuffer = new int[mCapacity];
    }

    ~circular_queue() {
        delete [] mBuffer;
    }

    void push(int num) {
        if (isFull()) {
            std::cout << "Queue is full\n";
            return;
        }
        mBuffer[tail] = num;
        tail = (tail + 1)% mCapacity;
        mSize++; 
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -999;
        }
        int res = mBuffer[head];
        mSize--;
        head = (head + 1) % mCapacity;
        return res;
    }

    int  front() const {
        if (!isEmpty()) {
            return mBuffer[head];
        }
        return -999;
    }

    bool isEmpty() const {
        return mSize == 0;
    }
    bool isFull() const {
        return mSize == mCapacity;
    }

    void print_queue() {
        for (auto i = 0; i < mSize; i++) {
            int index = (head + i) % mCapacity;
            std::cout << mBuffer[index] << " " ;
        }
    }

    private:
        int mCapacity;
        int mSize;
        int *mBuffer;
        int head;
        int tail;
};

int main() {
    circular_queue cq(5);

    for (int i = 1; i <= 5; i++) {
        cq.push(i * 10);
    }

    cq.print_queue();

    return 0;
}