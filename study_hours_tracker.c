#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 10
#define NAME_LEN 40

int main(void) {
    int n;
    char subjects[MAX_SUBJECTS][NAME_LEN];
    float week1[MAX_SUBJECTS] = {0.0f};
    float week2[MAX_SUBJECTS] = {0.0f};
    float goal = 0.0f;

    // 1) How many subjects
    printf("How many subjects do you want to track? (1-%d): ", MAX_SUBJECTS);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SUBJECTS) {
        printf("Invalid number of subjects.\n");
        return 1;
    }

    // Clear leftover newline from the buffer (before using fgets)
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { /* discard */ }

    // 2) Subject names (using fgets directly in main; no custom functions)
    for (int i = 0; i < n; i++) {
        printf("Enter name for subject %d: ", i + 1);
        if (fgets(subjects[i], NAME_LEN, stdin) == NULL) {
            // If reading fails, fall back to a default name
            snprintf(subjects[i], NAME_LEN, "Subject%d", i + 1);
        } else {
            // Strip trailing newline if present
            size_t k = strlen(subjects[i]);
            if (k > 0 && subjects[i][k - 1] == '\n') {
                subjects[i][k - 1] = '\0';
            }
            // If user just pressed Enter, assign a default name
            if (subjects[i][0] == '\0') {
                snprintf(subjects[i], NAME_LEN, "Subject%d", i + 1);
            }
        }
    }

    // 3) Weekly goal
    printf("Weekly study goal (hours): ");
    if (scanf("%f", &goal) != 1 || goal < 0) {
        printf("Invalid goal.\n");
        return 1;
    }

    // 4) Hours for Week 1
    printf("\n-- WEEK 1 --\n");
    for (int i = 0; i < n; i++) {
        printf("%s hours: ", subjects[i]);
        if (scanf("%f", &week1[i]) != 1 || week1[i] < 0) {
            printf("Invalid input for %s (Week 1).\n", subjects[i]);
            return 1;
        }
    }

    // 5) Hours for Week 2
    printf("\n-- WEEK 2 --\n");
    for (int i = 0; i < n; i++) {
        printf("%s hours: ", subjects[i]);
        if (scanf("%f", &week2[i]) != 1 || week2[i] < 0) {
            printf("Invalid input for %s (Week 2).\n", subjects[i]);
            return 1;
        }
    }

    // 6) Totals
    float total1 = 0.0f, total2 = 0.0f;
    for (int i = 0; i < n; i++) {
        total1 += week1[i];
        total2 += week2[i];
    }

    // 7) Output breakdown and goal checks
    printf("\nStudy Hours Breakdown\n");
    printf("---------------------\n");
    printf("WEEK 1:\n");
    for (int i = 0; i < n; i++) {
        printf("  %-20s : %6.2f\n", subjects[i], week1[i]);
    }
    printf("  %-20s : %6.2f\n", "TOTAL", total1);
    printf("  Goal (%6.2f): %s\n", goal, (total1 >= goal) ? "Met" : "Not met");

    printf("\nWEEK 2:\n");
    for (int i = 0; i < n; i++) {
        printf("  %-20s : %6.2f\n", subjects[i], week2[i]);
    }
    printf("  %-20s : %6.2f\n", "TOTAL", total2);
    printf("  Goal (%6.2f): %s\n", goal, (total2 >= goal) ? "Met" : "Not met");

    // 8) Compare totals
    printf("\nTotal Comparison (Week 1 vs Week 2):\n");
    if (total2 > total1) {
        printf("  Overall: Increased (+%.2f)\n", total2 - total1);
    } else if (total2 < total1) {
        printf("  Overall: Decreased (-%.2f)\n", total1 - total2);
    } else {
        printf("  Overall: No change (%.2f)\n", total1);
    }

    // 9) Per-subject comparison
    printf("\nPer-Subject Changes (Week 1 -> Week 2):\n");
    for (int i = 0; i < n; i++) {
        if (week2[i] > week1[i]) {
            printf("  %-20s : Increased (+%.2f)\n", subjects[i], week2[i] - week1[i]);
        } else if (week2[i] < week1[i]) {
            printf("  %-20s : Decreased (-%.2f)\n", subjects[i], week1[i] - week2[i]);
        } else {
            printf("  %-20s : No change (%.2f)\n", subjects[i], week1[i]);
        }
    }

    return 0;
}
