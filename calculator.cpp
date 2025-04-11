#include "calculator.h"
#include <stdexcept>

int Calculator::add(int a, int b) {
    int result = a+b;
    if((a>0 && b>0) && result<0){
        throw std::overflow_error("overflow");
    }
    if((a<0 && b<0) && result>0){
        throw std::overflow_error("underflow");
    }
    return result;
}

int Calculator::sub(int a, int b) {
    int result = a-b;

    if(a>b && result<0){
        throw std::overflow_error("overflow");
    }
    else if(a<b && result>0){
        throw std::overflow_error("underflow");
    }
    return result;
}

int Calculator::mul(int a, int b) {
    int result = a*b;

    if((result<0) && ((a>0 && b>0) || (a<0 && b<0))){
        throw std::overflow_error("overflow");
    }
    else if((result>0) && ((a>0 && b<0) || (a<0 && b>0))){
        throw std::overflow_error("underflow");
    }
    return result;
}

int Calculator::div(int a, int b) {
    if(b==0){
        throw std::invalid_argument("division by zero");
    }
    else if(a == -2147483648 && b == -1){
        throw std::overflow_error("overflow");
    }
    return a/b;
}