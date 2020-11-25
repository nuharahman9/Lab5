//
// Created by Nuha Rahman on 11/5/20.
//
#include <stdexcept>
#include <iostream>

#ifndef LAB5_STACK_H
#define LAB5_STACK_H



const int MAX_SIZE = 20;

template<typename T>
class stack {
public:
    stack() {
        size_ = 0;
    }
    void push(const T &val) {
        if (MAX_SIZE == size_) {
            throw std::overflow_error("Called push on full stack.");
        }
        else {
            for (int i = size_; i >= 0; i--) {
                if (i == 0) {
                    data_[i] = val;
                }
                else {
                    data_[i] = data_[i - 1];
                }

            }
            size_++;
        }

    };

    void pop() {
        if (empty()) {
            throw std::out_of_range("Called pop on empty stack.");
        }
        else  {
            for (int i = 0; i < size_; i++) {
                data_[i] = data_[i + 1];
            }
            size_--;
        }


    };
    T top() const {
        if (empty()) {
            throw std::underflow_error("Called top on empty stack.");
        }

        return data_[0];


    };
    bool empty() const {
        if (size_ == 0) {
            return true;
        }
        return false;
    };
private:
    T data_[MAX_SIZE];
    int size_;
};





#endif //LAB5_STACK_H
