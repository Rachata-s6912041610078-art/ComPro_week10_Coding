#include <stdio.h>
#include <string.h>

int main(void) {
    char names[3][20];
    double scores[3][3];       // scores[student][subject]
    char subjects[3][10] = {"Math", "Phy", "Chem"};
    double sum[3] = {0, 0, 0}; // ผลรวมคะแนนแต่ละวิชา

                    // รับข้อมูลนักศึกษาทีละคน ทีละวิชา
    for (int i = 0; i < 3; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", names[i]);

        for (int j = 0; j < 3; j++) {
            printf("Enter %s score of %s: ", subjects[j], names[i]);
            scanf("%lf", &scores[i][j]);
            sum[j] += scores[i][j];
        }
    }

    printf("\n");
    printf("%-20s %10s %10s %10s\n", "Student (length)", subjects[0], subjects[1], subjects[2]);
    printf("---------------------------------------------------------\n");

    // แสดงผลตาราง
    for (int i = 0; i < 3; i++) {
        char label[30];
        sprintf(label, "%s (%zu)", names[i], strlen(names[i]));

        printf("%-20s", label);
        for (int j = 0; j < 3; j++) {
            printf(" %10.2f", scores[i][j]);
        }
    printf("\n");
    }

    printf("---------------------------------------------------------\n");

    // ค่าเฉลี่ยแต่ละวิชา
    printf("%-20s", "Subject average");
    for (int j = 0; j < 3; j++) {
        printf(" %10.2f", sum[j] / 3);
    }
    printf("\n");

    return 0;
}