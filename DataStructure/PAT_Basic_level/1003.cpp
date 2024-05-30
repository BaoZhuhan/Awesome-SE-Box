    #include <bits/stdc++.h>
    using namespace std;

    void run(){
        string s;
        getline(cin, s);
        int locP = s.find('P');
        int locT = s.find('T');
        int flag = true;
        if(locP > s.size() or locT > s.size() or (locP + 1 > locT)){
            flag = false;
        }
        //extra char error
        for(int i = 0; i < s.size() and flag == true; i++){
            if(s[i] != 'A' and (s[i] == 'P' and i != locP) and (s[i] == 'T' and i != locT)){
                flag = false;
                break;
            }
        }
        //check A
        if(flag == true){
            flag = false;
            for(int i = locP; i < locT; i++){
                if(s[i] == 'A'){
                    flag = true;
                    break;
                }
            }
        }
        //xPATx
        if(flag == true and s[locP + 1] == 'A' and locP + 2 == locT){
            if(locP != s.size() - locT - 1) {
                flag = false;
            }
        }
        //aPbATca
        cout << (flag == true ? "YES\n" : "NO\n");
    }
    int main(){
        int T;
        cin >> T;
        string tmp;
        getline(cin, tmp);
        while(T--) run();
    }