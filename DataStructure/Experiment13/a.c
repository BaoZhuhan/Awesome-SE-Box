#include <stdio.h>  
#define N 5  
#define K 3  
void calculateTotal(float scores[N][K], float totals[N]);
void sortByTotal(float totals[N], float scores[N][K]);
void displayScores(float scores[N][K], float totals[N]);

int main(){
    float scores[N][K];
    float totals[N];
    for(int i = 0; i < N; i++){
        printf("请输入第%d个同学的语文成绩: ", i + 1);
        scanf("%f", &scores[i][0]);
        printf("请输入第%d个同学的数学成绩: ", i + 1);
        scanf("%f", &scores[i][1]);
        printf("请输入第%d个同学的英语成绩: ", i + 1);
        scanf("%f", &scores[i][2]);
    }
    calculateTotal(scores, totals);
    sortByTotal(totals, scores);
    displayScores(scores, totals);

    return 0;
}

void calculateTotal(float scores[N][K], float totals[N]){
    for(int i = 0; i < N; i++){
        totals[i] = scores[i][0] + scores[i][1] + scores[i][2];
    }
}

void sortByTotal(float totals[N], float scores[N][K]){
    float temp;
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N - i - 1; j++){
            if(totals[j] < totals[j + 1]){
                temp = totals[j];
                totals[j] = totals[j + 1];
                totals[j + 1] = temp;
                for(int k = 0; k < K; k++){
                    float tempScore = scores[j][k];
                    scores[j][k] = scores[j + 1][k];
                    scores[j + 1][k] = tempScore;
                }
            }
        }
    }
}

void displayScores(float scores[N][K], float totals[N]){
    printf("\n排序后的成绩如下:\n");
    printf("序号\t语文\t数学\t英语\t总分\n");
    for(int i = 0; i < N; i++){
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\n", i + 1, scores[i][0], scores[i][1], scores[i][2], totals[i]);
    }
}