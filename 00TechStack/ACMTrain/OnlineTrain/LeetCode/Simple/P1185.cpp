#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
string weekday[8] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
    string dayOfTheWeek(int day, int month, int year)
    {
        if(month == 1 or month == 2){
            month += 12;
            year -= 1;
        }
        int w = (day + 2*month + (int)(3*(month+1)/5)+ year + (int)(year/4) -(int)(year/100) + (int)(year/400) )%7;
        return weekday[w+1];
    }
};

int main()
{
    return 0;
}