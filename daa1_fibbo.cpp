#include<iostream>

using namespace std;


int recursive_fibbo(int a){
    if (a<=1){
        return a;
    }
    return (recursive_fibbo(a-1)+recursive_fibbo(a-2));
}

int iterative_fibbo(int a) {
    if (a<=1) return a;
    else {
        int prePreNum, preNum=0, currNum=1;
        for (int i=1; i<a; i++){
            prePreNum = preNum;
            preNum = currNum;
            currNum = prePreNum + preNum;
            
        }
        return currNum;

    }
}

int main() {
    int till=0;
    cout<<endl<<"Enter the step: ";
    cin>>till;
    cout<<endl<<"The fibbo number is: "<<iterative_fibbo(till);


    return 0;
}