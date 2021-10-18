#include <iostream>
#include <string>
#include <vector>
#include <random>

char letter(int n){
    switch (n) {
        case 0:
            return '+';
        case 1:
            return '-';
        case 2:
            return '*';
        case 3:
            return '/';
        default:
            break;
    }
    return 0;
}

double rannum(int n){
    std::random_device rd;
    std::default_random_engine gen = std::default_random_engine(rd());
    std::uniform_int_distribution<int> dis(0,100);
    std::uniform_int_distribution<int> disz(0,1000);
    std::uniform_int_distribution<int> disg(0,1000000);
    double num;
    double f;
    if(n==1){
        num = dis(gen);
        return num;
    } else if(n==2){
        num = disz(gen);
        return num;
    } else if(n==3){
        f = disg(gen)+disg(gen)/100.00;
        return f;
    }
    return 0;
}

double suan(double a, double b, int k){
    switch (k) {
        case 0:
            return a+b;
        case 1:
            return a-b;
        case 2:
            return a*b;
        case 3:
            return a/b;
        default:
            break;
    }
    return 0;
}

int main() {
    std::random_device rd;
    std::default_random_engine gen = std::default_random_engine(rd());
    std::cout << "Please enter your grade" << std::endl;
    std::string grade;
    getline(std::cin,grade);
    int diff,n=0;
    double pool=100;
    switch (grade[6]) {
        case '1':
        case '2':
            diff=1;
            n=2;
            break;
        case '3':
        case '4':
            diff=2;
            n=4;
            break;
        case '5':
        case '6':
            diff=3;
            n=4;
            break;
        default:
            diff=0;
            break;
    }
    float num=0;
    std::cout << "Please enter the number of questions" << std::endl;
    std::cin>>num;
    double qs=pool/num;
    double score=0.00;
    std::vector<int> wrong;
    for( int i=0; float (i)<num; i++){
        double a=rannum(diff),b=rannum(diff),sum,in;
        std::uniform_int_distribution<int> dis(0,n-1);
        int k= dis(gen);
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
        for(int j : wrong){
            std::cout <<j+1<<",";
        }
        std::cout <<", your score is: "<<score<< std::endl;
    }
    else{
        std::cout << "End! All right, that's great! You have full score:"<<score<< std::endl;
    }
    return 0;
}