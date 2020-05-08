///DAVID PREFONTAINE
///4/22/20

///MAY NEED TO USE C++11 TO USE CHRONO

///FOR PROBLEM THREE OF TEST TWO

///THIS IS CALLING LARGE ARRAYS MANY TIMES
///ONE DECLARED AS STATIC
///ONE DECLARED ON STACK
///ONE DECLARED DYNAMICALLY OR ON HEAP

#include <iostream>
#include <chrono>

#define A_BIG_NUMBER 4000
#define REALLY_BIG_NUMBER 18000000

void staticArrExample(){
    static int staticArr[5000];
}

void stackArrExample(){
    int stackArr[5000];
}

void dynamicArrExample(){
    int* heapArr = new int[5000];
    delete heapArr;
}

int main(int args, char* argv[]){
    int i;
    std::chrono::milliseconds base_result = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    std::chrono::milliseconds time_result_static;
    std::chrono::milliseconds time_result_stack;
    std::chrono::milliseconds time_result_dynamic;

    ///TESTING STATIC DECLARATIONS
    std::cout << "Declaring static arrays many times..." << std::endl;

    for (i = 0; i < REALLY_BIG_NUMBER; i++)
        staticArrExample();

    time_result_static = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    std::cout << "The many static array declarations took " << time_result_static.count() - base_result.count() << " milliseconds to execute" << std::endl;

    ///TESTING STACK DECLARATIONS
    std::cout << "Declaring arrays on stack many times..." << std::endl;

    for (i = 0; i < REALLY_BIG_NUMBER; i++)
        stackArrExample();

    time_result_stack = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    std::cout << "The many stack array declarations took " << time_result_stack.count() - time_result_static.count() << " milliseconds to execute" << std::endl;

    ///TESTING ARRAY DECLARATIONS
    std::cout << "Declaring arrays on heap many times..." << std::endl;

    for (i = 0; i < REALLY_BIG_NUMBER; i++)
        dynamicArrExample();

    time_result_dynamic = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    std::cout << "The many heap array declarations took " << time_result_dynamic.count() - time_result_stack.count() << " milliseconds to execute" << std::endl;

    return 0;
}
