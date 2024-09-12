#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leapyear[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int normalyear[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    bool isleapyear(int year){
        if(year % 100 == 0){
            if(year % 400 == 0){
                return true;
            }
        }else{
            if(year%4 == 0){
                return true;
            }
        }return false;
    }
    int dayOfYear(string date) {
        int res = 0;
        int year = 0;
        for(int i = 0 ; i < 4 ; i++){
            year += (int)(date[i] - '0') * pow(10,(3-i));
        }int month = 0;
        for(int i = 5 ; i < 7 ; i++){
            month += (int)(date[i] - '0') * pow(10,6-i);
        }int day = 0;
        for(int i = 8 ;i < 10 ;i++){
            day += (int)(date[i] - '0') * pow(10, (9-i));
        }if(isleapyear(year)){
            for(int i = 0 ; i < month-1 ; i++){
                res += leapyear[i];
            }
        }else{
            for(int i = 0 ; i< month-1 ; i++){
                res += normalyear[i];
            }
        }
        res += day;
        return res;
    }
};

int main(){
    return 0;
}