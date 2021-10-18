#include <iostream>
#include <string>
#include <time.h>
#include <vector>

char letter(int n){
    switch (n) {
        case 0:
            return '+';
            break;
        case 1:
            return '-';
            break;
        case 2:
            return '*';
            break;
        case 3:
            return '/';
            break;
        default:
            break;
    }
}

float rannum1(int n){
    srand((unsigned)time(NULL));
    float num=0;
    float f=0.0;
    if(n==1){
        num = rand()%100;
        return num;
    }
    if(n==2){
        num = rand();
        return num;
    }
    if(n==3){
        f = rand()+rand()/100.00;
        return f;
    }
}

float rannum2(int n){
    srand((unsigned)rand());
    float num=0;
    float f=0.0;
    if(n==1){
        num = rand()%100;
        return num;
    }
    if(n==2){
        num = rand();
        return num;
    }
    if(n==3){
        f = rand()+rand()/100.00;
        return f;
    }
}

float suan(float a, float b, int k){
    switch (k) {
        case 0:
            return a+b;
            break;
        case 1:
            return a-b;
            break;
        case 2:
            return a*b;
            break;
        case 3:
            return a/b;
            break;
        default:
            break;
    }
}

int main() {
    std::cout << "Please enter your grade" << std::endl;
    std::string grade;
    getline(std::cin,grade);
    int diff=0,n=0;
    int pool=100;
    switch (grade[6]) {
        case '1':
            diff=1;
            n=2;
            break;
        case '2':
            diff=1;
            n=2;
            break;
        case '3':
            diff=2;
            n=4;
            break;
        case '4':
            diff=2;
            n=4;
            break;
        case '5':
            diff=3;
            n=4;
            break;
        case '6':
            diff=3;
            n=4;
            break;
        default:
            diff=0;
            break;
    }

    int num=0;
    std::cout << "Please enter the number of questions" << std::endl;
    std::cin>>num;
    float qs=pool/num;
    float score=0.00;
    int i=0;
    std::vector<int> wrong;
    for( i=0; i<num; i++){
        float a=rannum1(diff),b=rannum2(diff),sum,in;
        int k= rand()%n;
        std::cout << a << letter(k)<< b << "=?" << std::endl;
        std::cin>>in;
        if(k==3&&b==0){
            i--;
        }
        sum=suan(a,b,k);
        if(in==sum){
            score+=qs;
        }else{
            wrong.push_back(i);
        }
    }

    if(!wrong.empty()){
        std::cout << "End! Wrong question:";
        for(int j=0; j<wrong.size();j++){
            std::cout <<wrong[j]+1<<",";
        }
        std::cout <<", your score is: "<<score<< std::endl;
    }
    else{
        std::cout << "End! All right, that's great! You have full score:"<<score<< std::endl;
    }
    return 0;
}
