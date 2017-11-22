//
//  Lab8c.c
//  Lab8
//
//  Created by Marcus Toldo on 2017-03-29.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>

struct employee {
    char firstname[40];
    char lastname[40];
    int id;
    float GPA;
};
typedef struct employee Employee;

int InputEmpRecord(Employee *EmpList);
int PrintEmpList(Employee *EmpList);
int SaveEmpList(Employee *EmpList);

int main(void) {
    
    Employee EmpList[4];
    
    InputEmpRecord(EmpList);
    PrintEmpList(EmpList);
    SaveEmpList(EmpList);
    
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
        scanf("%f", &EmpList[i].GPA);
        printf("\n\n");
    }
    
    return 0;
}

int PrintEmpList(Employee *EmpList) {
    
    printf("%s %s %s %s", "ID", "FIRST NAME", "LAST NAME", "GPA\n");
    
    for (int i = 0; i < 4; i++) {
        printf("%d %s %s %f\n", EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
    }

    return 0;
}

int SaveEmpList(Employee *EmpList) {
    
    FILE *fp = fopen("employeeDA.dat", "w");
    
    
    for (int i = 0; i < 4; i++) {
        fwrite(EmpList, sizeof(Employee), 4, fp);
    }
    
    fclose(fp);
    
    return 0;
}
