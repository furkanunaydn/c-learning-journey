#include <stdio.h>

struct student
{
    int schoolNo;
    char studentanswers[10];
    float netScore;
};
float CalculateScore(char studentAnswers[10], char actualAnswers[10])
{
    int correct = 0, wrong = 0;
    for (int i = 0; i < 10; i++)
    {
        if (studentAnswers[i] == actualAnswers[i])
            correct++;
        else
            wrong++;
    }
    float netScore = correct - (wrong / 4.0);
    return netScore;
}

int main()
{
    struct student students[10];
    int size, i, topStudent = 0;
    char actualAnswers[10];
    printf("Ogrencilerin sayisini giriniz: \n");
    scanf("%d", &size);
    printf("Sinav sorularinin dogru cevaplarini giriniz: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d. sorunun dogru cevabi: \n", i + 1);
        scanf(" %c", &actualAnswers[i]);
    }
    printf("Ogrencilerin okul numaralarini ve cevaplarini giriniz:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d. ogrencinin okul numarasi: \n", i + 1);
        scanf("%d", &students[i].schoolNo);
        printf("%d. ogrencinin cevaplari: \n", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("  %d. sorunun cevabi: \n", j + 1);
            scanf(" %c", &students[i].studentanswers[j]);
        }
    }
    for (int i = 0; i < size; i++)
    {
        students[i].netScore = CalculateScore(students[i].studentanswers, actualAnswers);
    }

    printf("Ogrencilerin sonuclari\n");
    for (i = 0; i < size; i++)
    {
        printf("%d. ogrencinin neti : %f\n", i + 1, students[i].netScore);
    }
    for (i = 1; i < size; i++)
    {
        if (students[i].netScore > students[topStudent].netScore)
        {
            topStudent = i;
        }
    }
    printf("En iyi neti yapan ogrenci numarasi : %d\n", students[topStudent].schoolNo);

    return 0;
}
