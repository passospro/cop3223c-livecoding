#include <stdio.h>

const double C_TO_F_SCALE  = 9.0 / 5.0;
const double C_TO_F_OFFSET = 32.0;
const double MI_TO_KM      = 1.60934;
const double LB_TO_KG      = 0.453592;

void convert_temperature(void);
void convert_distance(void);
void convert_weight(void);
void convert_speed(void);

int get_validated_int(int min, int max, const char *prompt, const char *err);

int main(void) {
    int choice;

    do {
        printf("\n= Unit Conversion Station =\n");
        printf("1. Temperature  (Celsius <-> Fahrenheit)\n");
        printf("2. Distance     (Miles <-> Kilometers)\n");
        printf("3. Weight       (Pounds <-> Kilograms)\n");
        printf("4. Speed        (MPH <-> KPH)\n");
        printf("5. Quit\n");

        choice = get_validated_int(1, 5, "Enter choice (1-5): ", "Invalid choice. Try again.");

        switch (choice) {
            case 1: convert_temperature(); break;
            case 2: convert_distance();    break;
            case 3: convert_weight();      break;
            case 4: convert_speed();       break;
            case 5: printf("Goodbye!\n");  break;
        }

    } while (choice != 5);

    return 0;
}

void convert_temperature(void) {
    int choice;
    double temp, result;

    printf("\n--- Temperature ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");

    choice = get_validated_int(
        1,
        2,
        "Enter direction (1-2):  ",
        "Invalid choice."
    );

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius:   ");
            scanf("%lf", &temp);

            result = temp * C_TO_F_SCALE + C_TO_F_OFFSET;

            printf("%.2f°C = %.2fF\n", temp, result);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit:    ");
            scanf("%lf", &temp);

            result = (temp - C_TO_F_OFFSET) / C_TO_F_SCALE;

            printf("%.2f°F = %.2f°C\n", temp, result);
            break;
    }
}

void convert_distance(void) {
    int choice;
    double distance, result;

    printf("\n--- Distance ---\n");
    printf("1. Miles to Kilometers\n");
    printf("2. Kilometers to Miles\n");

    choice = get_validated_int(
        1,
        2,
        "Enter direction (1-2):  ",
        "Invalid choice."
    );

    switch(choice) {
        case 1:
            printf("Enter miles:  ");
            scanf("%lf", &distance);
            result = distance * MI_TO_KM;
            printf("%.2f mi = %.2f km\n", distance, result);
            break;

        case 2:
            printf("Enter kilometers:  ");
            scanf("%lf", &distance);
            result = distance / MI_TO_KM;
            printf("%.2f km = %.2f mi\n", distance, result);
            break;
    }
}

void convert_weight(void) {
    int choice;
    double weight, result;

    printf("\n--- Weight ---\n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");

    choice = get_validated_int(
        1,
        2,
        "Enter direction (1-2):  ",
        "Invalid choice."
    );

    switch(choice) {
        case 1:
            printf("Enter pounds:  ");
            scanf("%lf", &weight);
            result = weight * LB_TO_KG;
            printf("%.2f lb = %.2f kg\n", weight, result);
            break;

        case 2:
            printf("Enter Kilograms:  ");
            scanf("%lf", &weight);
            result = weight / LB_TO_KG;
            printf("%.2f kg = %.2f lb\n", weight, result);
            break;
    }
}

void convert_speed(void) {
    int choice;
    double speed, result;

    printf("\n--- Speed ---\n");
    printf("1. MPH to KPH\n");
    printf("2. KPH to MPH\n");

    choice = get_validated_int(
        1,
        2,
        "Enter direction (1-2):  ",
        "Invalid choice."
    );

    switch(choice) {
        case 1:
            printf("Enter MPH:  ");
            scanf("%lf", &speed);
            result = speed * MI_TO_KM;
            printf("%.2f MPH = %.2f KPH\n", speed, result);
            break;

        case 2:
            printf("Enter KPH:  ");
            scanf("%lf", &speed);
            result = speed / MI_TO_KM;
            printf("%.2f KPH = %.2f MPH\n", speed, result);
            break;
    }
}

int get_validated_int(int min, int max, const char *prompt, const char *err) {
    int value;

    printf("%s", prompt);
    scanf("%d", &value);

    while (value < min || value > max) {
        printf("%s\n", err);

        printf("%s", prompt);
        scanf("%d", &value);
    }

    return value;
}