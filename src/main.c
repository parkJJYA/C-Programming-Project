#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct {
    char word[50];
    char meaning[50];
} Word;

Word words[MAX];
int count = 0;

void load_words(void)
{
    FILE* fp = fopen("dictionary.txt", "r");
    if (fp == NULL) return;

    while (fscanf(fp, "%s %s", words[count].word, words[count].meaning) == 2) {
        count++;
    }
    fclose(fp);
}

void save_words(void)
{
    FILE* fp = fopen("dictionary.txt", "w");
    int i;

    for (i = 0; i < count; i++) {
        fprintf(fp, "%s %s\n", words[i].word, words[i].meaning);
    }
    fclose(fp);
}

void add_word(void)
{
    if (count >= MAX) {
        printf("The dictionary is full.\n");
        return;
    }

    printf("English word: ");
    scanf("%s", words[count].word);
    printf("Meaning: ");
    scanf("%s", words[count].meaning);
    count++;

    save_words();
    printf("Added successfully!\n");
}

void show_words(void)
{
    int i;

    if (count == 0) {
        printf("No words have been registered.\n");
        return;
    }
    for (i = 0; i < count; i++) {
        printf("%d. %s : %s\n", i + 1, words[i].word, words[i].meaning);
    }
}

void quiz(void)
{
    int n, i, r, score = 0;
    char answer[50];

    if (count == 0) {
        printf("Please add words first.\n");
        return;
    }

    printf("Number of questions: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        r = rand() % count;   // 랜덤으로 단어 하나 고르기
        printf("\n[%d/%d] What is the meaning of \"%s\"? ", i + 1, n, words[r].word);
        scanf("%s", answer);

        if (strcmp(answer, words[r].meaning) == 0) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Wrong! The answer is: %s\n", words[r].meaning);
        }
    }
    printf("\nScore: %d / %d\n", score, n);
}

int main(void)
{
    int menu;

    srand((unsigned int)time(NULL));
    load_words();

    do {
        printf("\n===== My English Dictionary =====\n");
        printf("1. Add Word\n2. Show Words\n3. Quiz\n0. Exit\nSelect: ");
        scanf("%d", &menu);

        switch (menu) {
        case 1: add_word(); break;
        case 2: show_words(); break;
        case 3: quiz(); break;
        case 0: printf("Goodbye.\n"); break;
        default: printf("Invalid input.\n");
        }
    } while (menu != 0);

    return 0;
}
