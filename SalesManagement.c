#include <stdio.h>
int getvaliddays()
{
    int found = 0, days;
    while (found == 0)
    {
        printf("Enter the number of festival days. The value must be between 1 and 7.\n");
        scanf("%d", &days);
        if (days >= 1 && days <= 7)
        {
            found = 1;
        }
        else
        {
            printf("invalid input,days must be between 1 to 7\n");
        }
    }
    return days;
}

float calculateDailySales(int dayNumber)
{
    float totalsales = 0.0, avgamount = 0.0, max = 0.0, amount;
    int NoOfOrders;
    int found1 = 0;
    while (found1 == 0)
    {
        printf("Enter how many orders are there\n");
        scanf("%d", &NoOfOrders);
        if (NoOfOrders > 0)
        {
            found1 = 1;
        }
        else
        {
            printf("invalid input,Orders should be greater than 0\n");
        }
    }

    for (int i = 0; i < NoOfOrders; i++)
    {
        int found = 0;
        while (found == 0)
        {
            printf("Enter the amount for order number %d\n", i + 1);
            scanf("%f", &amount);
            if (amount > 0)
            {
                found = 1;
            }
            else
            {
                printf("invalid input,amount should be greater than 0\n");
            }
        }

        totalsales += amount;
        if (amount > max)
        {
            max = amount;
        }
    }
    avgamount = totalsales / NoOfOrders;
    printf("Total sales for day number %d is %.2f\n", dayNumber, totalsales);
    printf("Avg amount for day number %d is %.2f\n", dayNumber, avgamount);
    printf("Max amount for day number %d is %.2f\n", dayNumber, max);
    return totalsales;
}

int findHighestSalesDay(float dailySales[], int numberOfDays)
{
    float highest = dailySales[0];
    int daynumber = 0;
    for (int i = 0; i < numberOfDays; i++)
    {
        if (highest < dailySales[i])
        {
            highest = dailySales[i];
            daynumber = i;
        }
    }

    return (daynumber + 1);
}
void displayBarChart(float dailySales[], int numberOfDays)
{
    float temp;
    printf("\n=====DAILY SALES BAR CHART======\n");
    for (int i = 0; i < numberOfDays; i++)
    {
        printf("Day %d: ", &i + 1);
        temp = dailySales[i];
        for (int j = 0; j < (temp / 100); j++)
        {
            printf("*");
        }
        printf(" (RS %.2f)\n", temp);
    }
}

int main()
{
    int days, maxdayno;
    days = getvaliddays();
    float totalsales[days], EntireFestSales = 0.0;
    for (int i = 0; i < days; i++)
    {
        totalsales[i] = calculateDailySales(i + 1);
        EntireFestSales += totalsales[i];
    }
    maxdayno = findHighestSalesDay(totalsales, days);

    printf("\n=====FESTIVAL SUMMARY=======\n");
    printf("Total festival sales %.2f\n", EntireFestSales);
    printf("Day with highest sales %d\n", maxdayno);
    printf("Highest daily sales %.2f\n", totalsales[maxdayno - 1]);
    displayBarChart(totalsales, days);
}
