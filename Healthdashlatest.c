#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define DAILY_CALORIE_BURN_GOAL 3000 // Set a goal of 500 calories burned per day


typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char name[50];
    int age;
    char gender[10];
    float weight;
    float height; // Height in meters
    int exercise_minutes;
    char exercise_type[50]; // Type of exercise
    int calories_consumed;
    int calories_burned;
    int water_intake; // Water intake in glasses
    int sleep_duration; // Sleep duration in hours
      float protein_consumed; // Protein consumed in grams
} HealthRecord;

HealthRecord records[MAX_ENTRIES];
int record_count = 0;

void addRecord() {
    if (record_count >= MAX_ENTRIES) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    HealthRecord record;

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%10s", record.date);

    printf("Enter name: ");
    scanf("%49s", record.name);

    printf("Enter age: ");
    scanf("%d", &record.age);

    printf("Enter gender (Male/Female/Other): ");
    scanf("%9s", record.gender);

    printf("Enter weight (kg): ");
    scanf("%f", &record.weight);

    printf("Enter height (m): ");
    scanf("%f", &record.height);

    printf("Enter exercise minutes: ");
    scanf("%d", &record.exercise_minutes);

    printf("Enter type of exercise: ");
    scanf("%49s", record.exercise_type);

    printf("Enter calories consumed: ");
    scanf("%d", &record.calories_consumed);

    printf("Enter calories burned: ");
    scanf("%d", &record.calories_burned);

    printf("Enter water intake (in glasses): ");
    scanf("%d", &record.water_intake);

    printf("Enter sleep duration (in hours): ");
    scanf("%d", &record.sleep_duration);
    printf("Enter protein consumed today (grams): ");
    scanf("%f", &record.protein_consumed);

    records[record_count++] = record;
    printf("Record added successfully!\n\n");
}

void viewRecords() {
    if (record_count == 0) {
        printf("No records available.\n\n");
        return;
    }

    printf("\nHealth Records:\n");
    printf("Date       | Name       | Age | Gender    | Weight (kg) | Height (m) | Exercise (min) | Exercise Type       | Calories Consumed | Calories Burned | Water (glasses) | Sleep (hours)\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < record_count; i++) {
        printf("%10s | %10s | %3d | %9s | %11.2f | %9.2f | %14d | %18s | %17d | %14d | %15d | %13d\n",
               records[i].date, records[i].name, records[i].age, records[i].gender, records[i].weight, records[i].height, records[i].exercise_minutes,
               records[i].exercise_type, records[i].calories_consumed, records[i].calories_burned, records[i].water_intake, records[i].sleep_duration);
    }
    printf("\n");
}

void updateRecord() {
    char date[11];
    printf("Enter the date of the record to update (YYYY-MM-DD): ");
    scanf("%10s", date);

    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].date, date) == 0) {
            printf("Updating record for %s:\n", date);

            printf("Enter new name: ");
            scanf("%49s", records[i].name);

            printf("Enter new age: ");
            scanf("%d", &records[i].age);

            printf("Enter new gender (Male/Female/Other): ");
            scanf("%9s", records[i].gender);

            printf("Enter new weight (kg): ");
            scanf("%f", &records[i].weight);

            printf("Enter new height (m): ");
            scanf("%f", &records[i].height);

            printf("Enter new exercise minutes: ");
            scanf("%d", &records[i].exercise_minutes);

            printf("Enter new type of exercise: ");
            scanf("%49s", records[i].exercise_type);

            printf("Enter new calories consumed: ");
            scanf("%d", &records[i].calories_consumed);

            printf("Enter new calories burned: ");
            scanf("%d", &records[i].calories_burned);

            printf("Enter new water intake (in glasses): ");
            scanf("%d", &records[i].water_intake);

            printf("Enter new sleep duration (in hours): ");
            scanf("%d", &records[i].sleep_duration);

            printf("Record updated successfully!\n\n");
            return;
        }
    }
    printf("Error: Record for date %s not found.\n\n", date);
}

void deleteRecord() {
    char date[11];
    printf("Enter the date of the record to delete (YYYY-MM-DD): ");
    scanf("%10s", date);

    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].date, date) == 0) {
            for (int j = i; j < record_count - 1; j++) {
                records[j] = records[j + 1];
            }
            record_count--;
            printf("Record deleted successfully!\n\n");
            return;
        }
    }
    printf("Error: Record for date %s not found.\n\n", date);
}

void calculateBMI() {
    char date[11];
    printf("Enter the date to calculate BMI (YYYY-MM-DD): ");
    scanf("%10s", date);

    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].date, date) == 0) {
            if (records[i].height <= 0) {
                printf("Error: Height must be greater than 0 to calculate BMI.\n\n");
                return;
            }

            float bmi = records[i].weight / (records[i].height * records[i].height);
            printf("BMI for %s: %.2f\n\n", date, bmi);
            return;
        }
    }
    printf("Error: Record for date %s not found.\n\n", date);
}

void waterIntake() {
    int glasses;
    const int daily_goal = 8; // Standard daily goal in glasses

    printf("Enter the number of glasses of water you have drunk today: ");
    scanf("%d", &glasses);

    if (glasses >= daily_goal) {
        printf("Great job! You have met or exceeded your daily water intake goal.\n\n");
    } else {
        printf("You have drunk %d glasses of water. You need %d more glasses to reach the daily goal of %d glasses.\n\n",
               glasses, daily_goal - glasses, daily_goal);
    }
}
void proteinIntake() {
    float weight, consumed, daily_goal;

    printf("Enter your weight (in kg): ");
    scanf("%f", &weight);

    daily_goal = weight * 0.8; // Recommended protein intake in grams per kg of body weight

    printf("Enter the amount of protein you have consumed today (in grams): ");
    scanf("%f", &consumed);

    if (consumed >= daily_goal) {
        printf("Great job! You have met or exceeded your daily protein intake goal.\n\n");
    } else {
        printf("You have consumed %.2f grams of protein. You need %.2f more grams to reach the daily goal of %.2f grams.\n\n",
               consumed, daily_goal - consumed, daily_goal);
    }
}
void sendProgressNotifications() {
    for (int i = 0; i < record_count; i++) {
        printf("\nProgress Notification for %s on %s:\n", records[i].name, records[i].date);

        // Water intake notification
        if (records[i].water_intake >= 8) {
            printf(" - Great job! You have met your daily water intake goal.\n");
        } else {
            printf(" - You need %d more glasses of water to meet your daily goal of 8 glasses.\n", 8 - records[i].water_intake);
        }

        // Sleep duration notification
        if (records[i].sleep_duration >= 7) {
            printf(" - Excellent! You are getting enough sleep.\n");
        } else {
            printf(" - Try to get more sleep. You are %d hours short of the recommended 7 hours.\n", 7 - records[i].sleep_duration);
        }

        // Protein intake notification
        float daily_protein_goal = records[i].weight * 0.8; // Protein goal based on body weight
        float protein_deficit = daily_protein_goal - records[i].calories_consumed; // Assuming protein intake logged as calories
        if (protein_deficit <= 0) {
            printf(" - Fantastic! You have met your daily protein intake goal.\n");
        } else {
            printf(" - You need %.2f grams more protein to reach your daily goal of %.2f grams.\n",
                   protein_deficit, daily_protein_goal);
        }
    }
}
char* generateBar(int percentage);

void displayProgressChart() {
    if (record_count == 0) {
        printf("No records available to display progress charts.\n\n");
        return;
    }

    printf("\nProgress Charts:\n");
    printf("Date       | Name       | Water Intake    | Calories Burned  | Protein Intake\n");
    printf("----------------------------------------------------------------------------\n");

    for (int i = 0; i < record_count; i++) {
        // Water Intake Chart
        int water_percentage = (records[i].water_intake * 100) / 8; // Daily goal: 8 glasses
        if (water_percentage > 100) water_percentage = 100;

        // Calories Burned Chart
        int calorie_goal = 3000; // Assume a daily goal of burning 3000 calories
        int calories_percentage = (records[i].calories_burned * 100) / calorie_goal;
        if (calories_percentage > 100) calories_percentage = 100;

        // Protein Intake Chart
        float daily_protein_goal = records[i].weight * 0.8; // Daily protein goal in grams
        int protein_percentage = (records[i].calories_consumed * 100) / (int)daily_protein_goal; // Assuming protein intake in calories
        if (protein_percentage > 100) protein_percentage = 100;
        

        printf("%10s | %10s | [%-20s] %3d%% | [%-20s] %3d%% | [%-20s] %3d%%\n",
               records[i].date, records[i].name,
               generateBar(water_percentage), water_percentage,
               generateBar(calories_percentage), calories_percentage,
               generateBar(protein_percentage), protein_percentage);
    }
    printf("\n");
}

// Helper function to generate ASCII bars
char* generateBar(int percentage) {
    static char bar[21];
    int filled = (percentage * 20) / 100; // Scale to 20-character bar
    for (int i = 0; i < 20; i++) {
        bar[i] = (i < filled) ? '#' : '-';
    }
    bar[20] = '\0'; // Null-terminate the string
    return bar;
}




void showMenu() {
    printf("\nHealth and Fitness Tracker\n");
    printf("1. Add Record\n");
    printf("2. View Records\n");
    printf("3. Update Record\n");
    printf("4. Delete Record\n");
    printf("5. Calculate BMI\n");
    printf("6. Water Intake\n");
     printf("7. Protein Intake Calculator\n");
     printf("8. Send Progress Notifications\n");
      printf("9. Display Progress Chart\n");
    printf("10. Exit\n");

    printf("Choose an option: ");
}

int main() {
    int choice;

    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                calculateBMI();
                break;
            case 6:
                waterIntake();
                break;
                 case 7: proteinIntake();
                 break;
               case 8:
                sendProgressNotifications();
                break;
                case 9: displayProgressChart();
                break;

             case 10:
                printf("Exiting... Goodbye!\n");
                break;
              
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 7);

    return 0;
}
