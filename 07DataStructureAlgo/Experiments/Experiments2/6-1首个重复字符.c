// 纯暴力?
/* 返回第1个重复出现的字符 */
char findFirstRepeat(char* pStr){
    for(int i = 0; pStr[i] != '\0'; i++){
        for(int j = 0; j < i; j++){
            if(pStr[i] == pStr[j]){
                return pStr[i];
            }
        }
    }
    return '\0';
}