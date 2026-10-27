#include <iostream>
int sumOfTwoNum(int FNum, int Snum);

int main(){
    std::cout<<"The sum of two num is: " <<sumOfTwoNum(6,9)<<std::endl;
}
int sumOfTwoNum(int FNum, int SNum){
    return FNum + SNum;
}