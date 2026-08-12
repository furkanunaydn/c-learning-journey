#include <stdio.h>

struct contestant
{
    char name[100], lastname[100];
    float scores[10], performance;
};
float calculateScore(float scores[10], int scoreCount)
{
    float maxScore = scores[0];
    float minScore = scores[0];
    float result = 0;
    for (int i = 0; i < scoreCount; i++)
    {
        if (scores[i] > maxScore)
            maxScore = scores[i];
        if (scores[i] < minScore)
            minScore = scores[i];
        result += scores[i];
    }
    result = result - maxScore - minScore;
    result = result / (scoreCount - 2);
    return result;
}
int main()
{
    struct contestant contestants[10];
    int size, firstPlaceIndex = 0;
    printf("Yarismacilarin sayisini giriniz: ");
    scanf("%d", &size);
    printf("Yarismacilarin isim ve soyisimlerini giriniz:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d. yarismacinin ismi: ", i + 1);
        scanf("%s", contestants[i].name);
        printf("%d. yarismacinin soyismi: ", i + 1);
        scanf("%s", contestants[i].lastname);
    }
    printf("\nYarismacilarin puanlarini giriniz:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d. yarismacinin puanlari:\n", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("%d. hakemin puani: ", j + 1);
            scanf("%f", &contestants[i].scores[j]);
        }
    }
    for (int i = 0; i < size; i++)
    {
        contestants[i].performance = calculateScore(contestants[i].scores, 10);
    }
    printf("\nYarismacilarin performanslari:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d. yarismacinin performansi: %.2f\n", i + 1, contestants[i].performance);
    }
    for (int i = 1; i < size; i++)
    {
        if (contestants[i].performance > contestants[firstPlaceIndex].performance)
        {
            firstPlaceIndex = i;
        }
    }
    printf("\nBirinci gelen yarismaci: %s %s (%.2f puan)\n",
           contestants[firstPlaceIndex].name,
           contestants[firstPlaceIndex].lastname,
           contestants[firstPlaceIndex].performance);
    return 0;
}
