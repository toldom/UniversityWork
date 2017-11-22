//
//  Lab8b.c
//  Lab8
//
//  Created by Marcus Toldo on 2017-03-23.
//  Copyright © 2017 Marcus Toldo. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct employee {
    char firstname[40];
    char lastname[40];
    
    char id[3];
    char GPA[4];
};
typedef struct employee Employee;

int WordCap(char *word);
int SaveEmpList(Employee *EmpList, const char *FileName);


int main2(void) {
    

    FILE * fp = fopen("employee.dat", "r");
    
    Employee EmployeeList[4];
    
    char junkID[5], junkFirst[10], junkName[10], junkLast[10], junkName2[10], junkGPA[5];
    
    
    fscanf(fp, "%s %s %s %s %s %s", junkID, junkFirst, junkName, junkLast, junkName2, junkGPA);
    
    for (int i = 0; i < 4; i++) {
        fscanf(fp, "%s %s %s %s", EmployeeList[i].id, EmployeeList[i].firstname, EmployeeList[i].lastname, EmployeeList[i].GPA);
    }

    for (int i = 0; i < 4; i++) {
        char letter = EmployeeList[i].firstname[0];
        EmployeeList[i].firstname[0] = toupper(letter);
        
        letter = EmployeeList[i].lastname[0];
        EmployeeList[i].lastname[0] = toupper(letter);
        
    }
    
    SaveEmpList(EmployeeList, "employee.dat");
    
    
    return 0;
}

int SaveEmpList(Employee *EmpList, const char *FileName) {
    
    FILE *fp = fopen(FileName, "w");
    
    fprintf(fp, "%s %s %s %s", "ID", "FIRST NAME", "LAST NAME", "GPA\n");
    
    for (int i = 0; i < 4; i++) {
        fprintf(fp, "%s %s %s %s\n", EmpList[i].id,EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
    }
    
    return 0;
}
