#include <stdio.h>

#define MAX 100

struct Package
{
    int id;
    float value, weight, ratio, fraction;
};

struct Package p[MAX];
int n = 0, dataEntered = 0;
float capacity = 0;

void enterDetails()
{
    int i;

    printf("\nEnter number of packages: ");
    scanf("%d", &n);

    printf("Enter vehicle capacity: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++)
    {
        p[i].id = i + 1;

        printf("\nPackage %d\n", i + 1);
        printf("Value: ");
        scanf("%f", &p[i].value);

        printf("Weight: ");
        scanf("%f", &p[i].weight);

        p[i].ratio = p[i].value / p[i].weight;
        p[i].fraction = 0;
    }

    dataEntered = 1;
}

void displayDetails()
{
    int i;

    if (!dataEntered)
    {
        printf("\nEnter package details first.\n");
        return;
    }

    printf("\nPackage\tValue\tWeight\tRatio\n");

    for (i = 0; i < n; i++)
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               p[i].id, p[i].value, p[i].weight, p[i].ratio);
}

void calculateRatio()
{
    int i;

    if (!dataEntered)
    {
        printf("\nEnter package details first.\n");
        return;
    }

    for (i = 0; i < n; i++)
        p[i].ratio = p[i].value / p[i].weight;

    printf("\nRatios calculated successfully.\n");
}

void sortPackages()
{
    int i, j;
    struct Package temp;

    if (!dataEntered)
    {
        printf("\nEnter package details first.\n");
        return;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].ratio < p[j + 1].ratio)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nPackages sorted by ratio.\n");
}

void findMaximum()
{
    int i;
    float remaining = capacity;
    float totalWeight = 0, totalValue = 0;

    if (!dataEntered)
    {
        printf("\nEnter package details first.\n");
        return;
    }

    sortPackages();

    for (i = 0; i < n; i++)
        p[i].fraction = 0;

    for (i = 0; i < n && remaining > 0; i++)
    {
        if (p[i].weight <= remaining)
        {
            p[i].fraction = 1;
            remaining -= p[i].weight;
            totalWeight += p[i].weight;
            totalValue += p[i].value;
        }
        else
        {
            p[i].fraction = remaining / p[i].weight;
            totalWeight += remaining;
            totalValue += p[i].value * p[i].fraction;
            remaining = 0;
        }
    }

    printf("\nVehicle Capacity: %.2f", capacity);
    printf("\nTotal Weight: %.2f", totalWeight);
    printf("\nMaximum Value: %.2f\n", totalValue);
}

void displaySelected()
{
    int i;

    if (!dataEntered)
    {
        printf("\nEnter package details first.\n");
        return;
    }

    printf("\nPackage\tValue\tWeight\tFraction\tWeight Used\n");

    for (i = 0; i < n; i++)
    {
        if (p[i].fraction > 0)
        {
            printf("%d\t%.2f\t%.2f\t%.2f\t\t%.2f\n",
                   p[i].id, p[i].value, p[i].weight,
                   p[i].fraction,
                   p[i].weight * p[i].fraction);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n\nSMART DELIVERY PLANNING\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: enterDetails(); break;
            case 2: displayDetails(); break;
            case 3: calculateRatio(); break;
            case 4: sortPackages(); break;
            case 5: findMaximum(); break;
            case 6: displaySelected(); break;
            case 7: printf("\nProgram ended.\n"); break;
            default: printf("\nInvalid choice.\n");
        }

    } while (choice != 7);

    return 0;
}