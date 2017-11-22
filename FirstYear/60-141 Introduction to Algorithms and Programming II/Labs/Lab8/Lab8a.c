//
//  main.c
//  Lab8
//
//  Created by Marcus Toldo on 2017-03-17.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>

struct employee {
    char firstname[40];
    char lastname[40];
    
    int id;
    int GPA;
};
typedef struct employee Employee;

int InputEmpRecord(Employee *EmpList);
int PrintEmpList(Employee *EmpList);
int SaveEmpList(Employee *EmpList, const char *FileName);

int main(void) {
    
    Employee EmpList[4];
    
    InputEmpRecord(EmpList);
    PrintEmpList(EmpList);
    SaveEmpList(EmpList, "employee.dat");
    
    
    return 0;
}

int InputEmpRecord(Employee *EmpList) {
    
    for (int i = 0; i < 4; i++) {
        printf("Enter the employee's first name: ");
        scanf("%s", EmpList[i].firstname);
        
        printf("Enter the employee's last name: ");
        scanf("%s", EmpList[i].lastname);
        
        printf("Enter the employee id for %s %s: ", EmpList[i].firstname, EmpList[i].lastname);
        scanf("%d", &EmpList[i].id);
        
        printf("Enter the employee's GPA: ");
        scanf("%d", &EmpList[i].GPA);
        printf("\n\n");
    }
    
    return 0;
}

int PrintEmpList(Employee *EmpList) {
    
    printf("%s %s %s %s", "ID", "FIRST NAME", "LAST NAME", "GPA\n");
    
    for (int i = 0; i < 4; i++) {
        printf("%d %s %s %d\n", EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
    }
    
    return 0;
}

int SaveEmpList(Employee *EmpList, const char *FileName) {
    
    FILE *fp = fopen(FileName, "w");
    
    fprintf(fp, "%s %s %s %s", "ID", "FIRST NAME", "LAST NAME", "GPA\n");
    
    for (int i = 0; i < 4; i++) {
            fprintf(fp, "%d %s %s %d\n", EmpList[i].id,EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
    }
    
    return 0;
}
