
#include "stack.h"
#include <iostream>
#include <cassert>

int main() {
    Stack<int> stack;

    // Test empty stack
    assert(stack.empty());
    assert(stack.size() == 0);

    // Test push
    stack.push(1);
    assert(!stack.empty());
    assert(stack.size() == 1);
    assert(stack.top() == 1);

    // Test push more elements
    stack.push(2);
    stack.push(3);
    assert(stack.size() == 3);
    assert(stack.top() == 3);

    // Test pop
    stack.pop();
    assert(stack.size() == 2);
    assert(stack.top() == 2);

    // Test pop until empty
    stack.pop();
    stack.pop();
    assert(stack.empty());
    assert(stack.size() == 0);

    // Test exception on pop from empty stack
    try {
        stack.pop();
        assert(false); // Should not reach here
    } catch (const std::underflow_error& e) {
        assert(true); // Exception caught
    }

    // Test exception on top from empty stack
    try {
        stack.top();
        assert(false); // Should not reach here
    } catch (const std::underflow_error& e) {
        assert(true); // Exception caught
    }

    std::cout << "all tests passed!" << std::endl;
    return 0;
}