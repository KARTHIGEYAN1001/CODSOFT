#include <iostream>

int main(){
    int num1,num2;
    char operation;
    std::cout<<"ENTER FIRST NUMBER : ";
    std::cin>>num1;
    std::cout<<"ENTER SECOND NUMBER : ";
    std::cin>>num2;
    std::cout<<"ENTER THE OPERATION (+,-,*,/) : ";
    std::cin>>operation;
    if(operation=='+'){
        std::cout<<"ANSWER = "<<num1+num2<<std::endl;
    }
    else if(operation=='-'){
        std::cout<<"ANSWER = "<<num1-num2<<std::endl;
    }
    else if(operation=='*'){
        std::cout<<"ANSWER = "<<num1*num2<<std::endl;
    }
    else if(operation=='/'){
        std::cout<<"ANSWER = "<<num1/num2<<std::endl;
    }
    else{
        std::cout<<"INVALID OPERATOR."<<std::endl<<"ENTER A VALID OPERATOR"<<std::endl;
    }




    return 0;
}