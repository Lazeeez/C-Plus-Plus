#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cassert>

std::queue<int> reverseQueue(std::queue<int> myQueue) {
    std::stack<int> myStack;
    uint64_t size = myQueue.size();
    for (unsigned int iterator = 0; iterator < size; iterator++) {
        myStack.push(myQueue.front());
        myQueue.pop();
    }
    std::queue<int> newQueue;
    for (unsigned int iterator2 = 0; iterator2 < size; iterator2++) {
        newQueue.push(myStack.top());
        myStack.pop();
    }
    return newQueue;
}

static void test1() {
    
    std::queue<int> myQueue;
    std:vector<int> test1_input = ""
    std::string test1_input = "1, 2, 3, 4, 5";
    std::string expected_ans; 
    uint64_t size = test1_input.size();

    for(auto iterator = size - 1; iterator >= 0; --iterator) {
        expected_ans.push_back(test1_input[iterator]);
    }

    std::queue<int> derived_ans = reverseQueue(myQueue);
    std::string derived_ans_str;
    derived_ans_str += (derived_ans.front());
    std::cout << "Test #1: ";
    assert(derived_ans == expected_ans);
    std::cout << "Passed!" << std::endl;


    
    bool digit = true;

}


int main() {
    std::queue<int> myQueue;
    std::string input;
    bool digit = true;

    std::cout << "To stop the insertion, please enter any non-number" << std::endl;
    std::cout << "Enter numbers to insert into the queue: " << std::endl;

    std::cin >> input;
    uint64_t size = input.size();
    for (unsigned int iterator3 = 0; iterator3 < size; iterator3++) {
        if (!isdigit(input[iterator3])) {
            digit = false;
        }
    }
    while (digit) {
        myQueue.push(stoi(input));
        std::cin >> input;
        for (unsigned int iterator4 = 0; iterator4 < size; iterator4++) {
            if (!isdigit(input[iterator4])) {
                digit = false;
            }
        }
    }

    std::queue<int> newQueue = reverseQueue(myQueue);
    std::cout << "Your queue: " << std::endl;
    uint64_t myQueue_size = myQueue.size();
    for (unsigned int iterator5 = 0; iterator5 < myQueue_size; iterator5++) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;
    std::cout << "Reversed queue: " << std::endl;
    for (unsigned int iterator6 = 0; iterator6 < myQueue_size; iterator6++) {
        std::cout << newQueue.front() << " ";
        newQueue.pop();
    }
}