#include <stdio.h>
#include <stdlib.h>

#define NUM_MONTHS 12

// Function prototypes
void monthly_sales_report(double sales[]);
void sales_summary_report(double sales[]);
void six_month_moving_average_report(double sales[]);
void sales_report_highest_to_lowest(double sales[]);

int main() {
    double sales[NUM_MONTHS];
    FILE *file = fopen("sales.txt", "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Read the sales data from the file
    for (int i = 0; i < NUM_MONTHS; i++) {
        fscanf(file, "%lf", &sales[i]);
    }

    fclose(file);

    // Generate reports
    monthly_sales_report(sales);
    sales_summary_report(sales);
    six_month_moving_average_report(sales);
    sales_report_highest_to_lowest(sales);

    return 0;
}

// 1. Monthly Sales Report
void monthly_sales_report(double sales[]) {
    const char* months[NUM_MONTHS] = {"January", "February", "March", "April", "May", "June", 
                                      "July", "August", "September", "October", "November", "December"};
    printf("\nMonthly Sales Report\n");
    printf("---------------------\n");
    printf("%-10s %10s\n", "Month", "Sales");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-10s %10.2lf\n", months[i], sales[i]);
    }
}

// 2. Sales Summary Report
void sales_summary_report(double sales[]) {
    double min = sales[0], max = sales[0], total = 0.0;

    for (int i = 0; i < NUM_MONTHS; i++) {
        if (sales[i] < min) min = sales[i];
        if (sales[i] > max) max = sales[i];
        total += sales[i];
    }

    double average = total / NUM_MONTHS;

    printf("\nSales Summary Report\n");
    printf("---------------------\n");
    printf("Minimum sales: %.2lf\n", min);
    printf("Maximum sales: %.2lf\n", max);
    printf("Average sales: %.2lf\n", average);
}

// 3. Six-Month Moving Average Report
void six_month_moving_average_report(double sales[]) {
    printf("\nSix-Month Moving Average Report\n");
    printf("-------------------------------\n");
    for (int i = 0; i <= NUM_MONTHS - 6; i++) {
        double sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("Months %d-%d: %.2lf\n", i + 1, i + 6, sum / 6.0);
    }
}

// 4. Sales Report 
void sales_report_highest_to_lowest(double sales[]) {
    double sorted_sales[NUM_MONTHS];
    
    // Copy sales data 
    for (int i = 0; i < NUM_MONTHS; i++) {
        sorted_sales[i] = sales[i];
    }

    // Sort sales in descending order
    for (int i = 0; i < NUM_MONTHS - 1; i++) {
        for (int j = i + 1; j < NUM_MONTHS; j++) {
            if (sorted_sales[i] < sorted_sales[j]) {
                double temp = sorted_sales[i];
                sorted_sales[i] = sorted_sales[j];
                sorted_sales[j] = temp;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest)\n");
    printf("-------------------------------\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%.2lf\n", sorted_sales[i]);
    }
}
