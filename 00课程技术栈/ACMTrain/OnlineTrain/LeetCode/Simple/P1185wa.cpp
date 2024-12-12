#include <bits/stdc++.h>
using namespace std;
//该算法不适用2000年以前的日期计算；
class Solution {
public:
    string weekday[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int unleapcode[12] = {6,2,2,5,0,3,5,1,4,6,2,4};
    int leapcode[12] = {5,1,2,5,0,3,5,1,4,6,2,4};
    bool isLeapYear(int year){
        if(year % 100 == 0){
            if(year % 400 == 0){
                return true;
            }else{
                return false;
            }
        }else{
            if(year % 4 == 0){
                return true;
            }else{
                return false;
            }
        }
    }
    string dayOfTheWeek(int day, int month, int year) {
        int yearcode = ((int)((year%100) / 4) + (year%100)) % 7;
        int monthcode;
        if(isLeapYear(year) == true){
            monthcode = leapcode[month-1];
        }else{
            monthcode = unleapcode[month-1];
        }
        int codesum = yearcode + monthcode + day;
        return weekday[(codesum) % 7];
    }
};

int main(){
    cout << ((int)((1999%100) / 4) + (1999%100)) % 7 ;
    return 0;
}