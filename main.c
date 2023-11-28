#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

float salaryValidation();
int inputValidations();
struct employee{
    char name [100];
    float salary;
    int id;
    int age;
    int insurance;
    float tax;
    float netSalary;
};

int main ()
{
    int i,j,k,m, loop=0, lenInput, count =0;
    float l;
    float avgInsurance=0, avgSalary=0, avgNetSalary=0, avgTax=0;
    float ttlInsurance = 0, ttlSalary = 0, ttlNetSalary =0, ttlTax=0;
    char tempAge[20], tempSalary[20], tempId[20], tempName[50], tempValue[20];

    printf("How many employee: ");
    gets(tempValue);
    i = inputValidations(tempValue);
    struct employee emp[i];
    system("cls");
    printf("Number Of Employee: %d\n**********************\n", i);
    for(j=0; j < i; j++)
    {
        printf("Employee: %d\n\n", j+1);
        printf("Employee Name: ");
        scanf("%s%*c", &emp[j].name);
        do{
            printf("Employee ID: ");
            gets(tempId);
            m = inputValidations(tempId);
            if(m >= 1000 && m <= 9999)
            {
                loop=0;
                emp[j].id = m;
            }else{
                printf("Range for ID only 1000 - 9999\n");
                loop = 1;
            }
        }while(loop==1);
        do{
            printf("Employee Salary: ");
            //scanf("%f%*c", &tempSalary);
            gets(tempSalary);
            l = salaryValidation(tempSalary);
            if(l >= 0 && l <= 9999)
            {
                loop=0;
                emp[j].salary = l;
            }else{
                printf("Range for Salary only 0 - 9999\n");
                loop = 1;
            }
        }while(loop == 1);
        do
        {
            printf("Employee age: ");
            gets(tempAge);
            k = inputValidations(tempAge);
            emp[j].age = k;
            switch(emp[j].age)
            {
                case 18 ... 35:
                    loop=0;
                    emp[j].insurance = 110;
                    break;
                case 36 ... 65:
                    loop=0;
                    emp[j].insurance = 160;
                    break;
                case 66 ... 99:
                loop=0;
                emp[j].insurance = 250;
                    break;
                default:
                    loop = 1;
                    printf("Invalid Age. Valid for 18 ~ 99 \n");
                    break;
            }
        }while(loop == 1);
        printf("\n");
    }
    printf("\nPayroll:\n");
    printf("Name\tID\tAge\tInsurance\tGross Salary\tTax\t\tNet Salary");
    for (j=0;j<i;j++)
    {
        if(emp[j].salary > 0 && emp[j].salary < 1000)
        {
            emp[j].tax= ((float)0/100*emp[j].salary);
            emp[j].netSalary = emp[j].salary - emp[j].insurance - emp[j].tax;
        }
        else if (emp[j].salary >= 1000.00 && emp[j].salary < 3000.00)
        {
            emp[j].tax= ((float)2.5/100*emp[j].salary);
            emp[j].netSalary = emp[j].salary - emp[j].insurance - emp[j].tax;
        }
        else if (emp[j].salary >= 3000.00)
        {
            emp[j].tax= ((float)5/100*emp[j].salary);
            emp[j].netSalary = emp[j].salary - emp[j].insurance - emp[j].tax;
        }
        ttlInsurance = ((float)ttlInsurance + emp[j].insurance);
        ttlSalary = ((float)ttlSalary + emp[j].salary);
        ttlNetSalary = ((float)ttlNetSalary + emp[j].netSalary);
        ttlTax = ((float)ttlTax + emp[j].tax);
        printf("\n%s\t%d\t%d\tRM%d.00\tRM%.2f\tRM%.2f\tRM%.2f", emp[j].name, emp[j].id,emp[j].age,emp[j].insurance,emp[j].salary,emp[j].tax, emp[j].netSalary);
    }
    avgInsurance = ((float)ttlInsurance / i);
    avgSalary = ((float)ttlSalary / i);
    avgNetSalary = ((float)ttlNetSalary / i);
    avgTax = ((float)ttlTax / i);
    printf("\n-------------------------------------------------------------------------------------");
    printf("\nAverage\t\t\tRM%.2f\tRM%.2f\tRM%.2f\tRM%.2f\n",avgInsurance, avgSalary, avgTax, avgNetSalary);
}

int inputValidations(char tempInput[20])
{
    int tempInputs, A=0, d=0, count, tempCount=0, lenInput;
    char temp[20];
    lenInput = strlen(tempInput);
    for(int j=0;j<lenInput; j++)
    {
        if(isspace(tempInput[j]) || isalpha(tempInput[j]))
        {
            count++;
            A=1;
        }
    }
    if(count==0)
    {
        for(int j=0;j < lenInput; j++)
        {
            if(isalnum(tempInput[j])==0)
            {
                A=1;
            }
        }
    }
    if(A==1)
    {
        printf("Wrong input. Input only accept Numeric: %s\n", tempInput);
        while(A==1)
        {
            printf("Enter Again: ");
            gets(temp);
            lenInput = strlen(temp);
            tempCount = 0;
            for(int j=0;j<lenInput;j++){
                if(isspace(temp[j]) || isalpha(temp[j]))
                {
                    tempCount++;
                }
            }
            if(tempCount==0)
            {
                d=0;
                for(int j=0;j < lenInput; j++)
                {
                    if(isalnum(temp[j])==0)
                    {
                        d++;
                    }
                }
                if(d==0)
                {
                    tempInputs = atoi(temp);
                    A=2;
                }
            }
        }
    }else
        tempInputs = atoi(tempInput);
    return tempInputs;
}

float salaryValidation(char tempInput[20])
{
    float tempInputs, A=0, d=0, count, tempCount=0, lenInput;
    char temp[20];
    lenInput = strlen(tempInput);
    for(int j=0;j<lenInput; j++)
    {
        if(isspace(tempInput[j]) || isalpha(tempInput[j]))
        {
            count++;
            A=1;
        }
    }
    if(count==0)
    {
        for(int j=0;j < lenInput; j++)
        {
            if(isalnum(tempInput[j])==0)
            {
                A=1;
            }
        }
    }
    if(A==1)
    {
        printf("Wrong input. Input only accept Numeric: %s\n", tempInput);
        while(A==1)
        {
            printf("Enter Salary: ");
            gets(temp);
            lenInput = strlen(temp);
            tempCount = 0;
            for(int j=0;j<lenInput;j++){
                if(isspace(temp[j]) || isalpha(temp[j]))
                {
                    tempCount++;
                }
            }
            if(tempCount==0)
            {
                d=0;
                for(int j=0;j < lenInput; j++)
                {
                    if(isalnum(temp[j])==0)
                    {
                        d++;
                    }
                }
                if(d==0)
                {
                    tempInputs = atof(temp);
                    A=2;
                }
            }
        }
    }else
        tempInputs = atof(tempInput);
    return tempInputs;
}
