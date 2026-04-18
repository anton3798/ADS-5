// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int Maxsize>
class TStack {
 private:
    T data[MaxSize];
    int topIndex;

 public:
    TStack() : topIndex(0) {}
    void push(const T& value) {
        if (topIndex < MaxSize) {
            data[topIndex++] = value;
        }
    }
    T pop() {
        if (topIndex > 0) {
            return data[--topIndex];
        }
        return T();
    }
    T& top() {
        if (topIndex > 0) {
            return data[topIndex - 1];
        }
        static T l = T();
        return l;
    }
    bool isEmpty() const {
        return topIndex == 0;
    }
    void clear() {
        topIndex = 0;
    }
};
#endif  // INCLUDE_TSTACK_H_
