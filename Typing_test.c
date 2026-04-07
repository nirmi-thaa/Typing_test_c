#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int n;

const char *words[80] = {
    "Y1@Lx%Vp", "W4$Nr!Qm", "M*ObJ7Cz", "R+F2zXq", "Tz&9DkL",
    "P3wG$8Wb", "QxL7K+Mi", "T!sPoBf", "Uv@4U+Kh", "Y1r8*Nl",
    "D9W#iZc", "P$qF8Te", "M0Xx*Jl", "Yp*3tCv", "T!H2JwD",
    "Q7oZ+Rm", "K9v*LxQ", "P!3NxBd", "W0YbMv5$", "Jk1Z+pTz",
    "O#P7kL9", "M0QwY!J", "FpB@2Vm", "KxW8uR3", "N1zXyL+",
    "T6Cr@Jh", "Vp!4qFb", "Mz8Lw+R", "K2Xh#Yn", "TjL1Wf&V",
    "ZxQ+P9o", "W8YbT!3v", "R0MwY6", "N$GvLq", "J7TpX2",
    "Z9Dk*Jm", "B1K+YrF", "Qz4Xw8", "T0Nj5y@", "M8VfLsH",
    "Fz+7U3p", "W!QkVm", "X4DqNz", "Rb9J6p2", "Z*8KtL",
    "T1Wf5L", "Pq!0Nc", "M3Xy8F", "Lz@B9v", "QxJ7Rk+",
    "H6tCzM", "Y8NpWb", "WqLzF3M", "Q1F*Rt", "0JkXv9",
    "L#7YpZ", "T8Wz!Cn", "P3Xr0f", "F9Lq1B", "Tz9RmW",
    "L7oX4K+", "J5YtLp", "B6vY@zN", "X0Nf3W", "P2Qm9Y",
    "Z8TnLs", "A1Rk7F", "S0JvQ9", "L3NpYm", "Kx8WvL",
    "J9R2Q3", "M6F!bT", "Z7H*Xp", "P4YjL", "V1ZpS#",
    "X9LwR5", "Q3JhN", "T0Xp9", "F8Yl2K", "Wz4MvX"
};

typedef struct information 
{
    char name[2000];
    double time_taken;
    double accuracy;
    double wpm;
} info;

info user;
info y;

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void save(info* user) {
    FILE *fp = fopen("data.txt", "ab");   // FIX: binary append
    if (fp != NULL) {
        fwrite(user, sizeof(info), 1, fp);
        fclose(fp);
        printf("Data Saved\n");
    } else {
        printf("Failed to open file\n");
    }
}

void test(char TEXT[], info *user) {
    char input[1000];
    time_t start, end;
    int correct = 0;

    printf("\nThis program will find your typing accuracy and speed (WPM).\n");
    printf("The text to type is:\n\n%s\n\n", TEXT);
    printf("Press Enter to start...");
    getchar();   // FIX: wait properly

    time(&start);
    printf("Start typing: ");
    fgets(input, sizeof(input), stdin);
    time(&end);

    input[strcspn(input, "\n")] = '\0';

    int len_text = strlen(TEXT);
    int len_input = strlen(input);

    for (int i = 0; i < len_text && i < len_input; i++) {
        if (TEXT[i] == input[i])
            correct++;
    }

    double time_taken = difftime(end, start);

    // FIX: avoid divide by zero
    if (time_taken == 0) time_taken = 1;

    double accuracy = ((double)correct / len_text) * 100.0;
    double wpm = ((double)len_input / 5.0) / (time_taken / 60.0);

    printf("\n######## RESULTS ########\n");
    printf("Time Taken: %.2f seconds\n", time_taken);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing Speed: %.2f WPM\n", wpm);

    user->time_taken = time_taken;
    user->accuracy = accuracy;
    user->wpm = wpm;

    save(user);
}

void random_words(int n)   // FIX: renamed (random is risky name)
{
    for (int j = 0; j < n; j++) 
    {
        int index = rand() % 80;
        test((char *)words[index], &user);
        printf("Press Enter for next word...\n");
        getchar();   // FIX
    }
}

void search_name(info *y)
{
    int found = 0;
    char search[2000];

    printf("Enter the name to search: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = '\0';

    FILE *fp = fopen("data.txt", "rb");   // FIX: binary read

    if (fp != NULL) 
    {
        while (fread(y, sizeof(info), 1, fp) == 1)
        {
            if (strcmp(y->name, search) == 0)
            {
                printf("\n##### RECORD FOUND #####\n");
                printf("Name      : %s\n", y->name);
                printf("Time Taken: %.2f sec\n", y->time_taken);
                printf("Accuracy  : %.2f%%\n", y->accuracy);
                printf("WPM       : %.2f\n", y->wpm);
                found = 1;
            }
        }
        fclose(fp);

        if (!found)
            printf("No such name\n");
    }
    else 
    {
        printf("Could not open file.\n");
    }
}

int main() {
    srand(time(0));

    printf("Enter your name: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0';

    while (1) {
        printf("\nMenu:\n");
        printf("1. Type test (fixed sentence)\n");
        printf("2. Random words typing test\n");
        printf("3. Show existing data\n");
        printf("4. Exit\n");
        printf("Choice: ");

        char ch = getchar();
        clear_input();  

        if (ch == '1') {
            char TEXT[] = "The quick brown fox jumps over the lazy dog";
            test(TEXT, &user);
        } 
        else if (ch == '2') 
        {
            printf("How many random words do you want to try? ");
            scanf("%d", &n);
            clear_input();
            random_words(n);
        } 
        else if (ch == '3')
        {
            search_name(&y);
        }
        else if (ch == '4') 
        {
            printf("Goodbye!\n");
            break;
        }
        else 
        {
            printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}