#include <stdio.h>

struct patient{
    int number;
    char name[20];
    int age;
    char disease[20];
};
void createFile(FILE *ptr);
void newPatient(FILE *ptr);
void findPatient(FILE *ptr);
void deletePatient(FILE *ptr);
void modifyPatient(FILE *ptr);
void listAll(FILE *ptr);
int menu();

int main() {
    int choice;
    FILE *ptr;

    choice = menu();


    while(choice < 1 || choice > 7)
    {
        printf("invalid choice , please choose a number between 1-7\n");
        choice = menu();
    }

    while(choice > 0 && choice < 8)
    {
        switch (choice)
        {
            case 1:
                createFile(ptr);
                choice = menu();
                break;
            case 2:
                newPatient(ptr);
                choice = menu();
                break;
            case 3:
                findPatient(ptr);
                choice = menu();
                break;
            case 4:
                deletePatient(ptr);
                choice = menu();
                break;
            case 5:
                modifyPatient(ptr);
                choice = menu();
                break;
            case 6:
                listAll(ptr);
                choice = menu();
                break;
            case 7:
                break;
        }
        if(choice == 7)
            break;
    }

    return 0;
}

int menu()
{
    int choice;
    printf("1-Create a patient file with 100 empty records\n"
           "2-Insert a new patient record\n"
           "3-Find and retrieve patient information\n"
           "4-Delete a patient record\n"
           "5-Modify a patient record\n"
           "6-List all patients information\n"
           "7-Exit");
    printf("\n");
    printf("Choice : ");
    scanf("%d",&choice);
    return choice;
}

void createFile(FILE *ptr)
{
    struct patient empty = {0 , "-" , 0 , "-"};

    if((ptr = fopen("patients.txt" , "w")) == NULL)
    {
        printf("File couldn't open");
    }
    else
    {
        for(int i = 0 ; i < 100 ; i++)
        {
            fwrite(&empty , sizeof(struct patient) , 1 , ptr);
        }
    }
    fclose(ptr);
}

void listAll(FILE *ptr)
{
    struct patient info = {0 , "" , 0 , ""};

    if((ptr = fopen("patients.txt" , "r")) == NULL)
    {
        printf("File couldn't open");
    }
    else
    {
        while(!feof(ptr))
        {
            fread(&info , sizeof(struct patient) , 1 , ptr);
            printf("%d\t%s\t%d\t%s\n" , info.number , info.name , info.age , info.disease);
        }
    }
    printf("\n");
    fclose(ptr);
}

void newPatient(FILE *ptr)
{
    struct patient new = {0 , "-" , 0 , "-"};
    int number;
    ptr = fopen("patients.txt" , "r+");

    if((ptr = fopen("patients.txt" , "r+")) == NULL)
    {
        printf("File couldn't open\n");
    }
    else
    {
        printf("Enter the number");
        scanf("%d" , &number);

        fseek(ptr , (number - 1) * sizeof(struct patient) , SEEK_SET);
        fread(&new , sizeof(struct patient) , 1 , ptr);
        if(new.number != 0)
        {
            printf("Patient number already exists\n");
        }
        else
        {
            fseek(ptr , (number - 1) * sizeof(struct patient) , SEEK_SET);
            printf("Enter the patient name : ");
            scanf("%s" , &new.name);
            printf("Enter the patient age : ");
            scanf("%d" , &new.age);
            printf("Enter the patient disease : ");
            scanf("%s" , &new.disease);
            new.number = number;

            fseek(ptr , (number - 1) * sizeof(struct patient) , SEEK_SET);
            fwrite(&new , sizeof(struct patient) , 1 , ptr);
        }
    }
    fclose(ptr);
}

void findPatient(FILE *ptr)
{
    int number;
    struct patient info = {0 , "-" , 0 , "-"};

    if((ptr = fopen("patients.txt" , "r")) == NULL)
    {
        printf("File couldn't open\n");
    }
    else
    {
        printf("Enter the Patient number : ");
        scanf("%d" , &number);

        fseek(ptr , (number - 1) * sizeof(struct patient) , SEEK_SET);
        fread(&info , sizeof(struct patient) , 1 , ptr);

        if(info.number == 0)
        {
            printf("There is no record\n");
        }
        else
        {
            printf("%d\t%s\t%d\t%s" , info.number , info.name , info.age , info.disease);
            printf("\n");
        }
    }
    fclose(ptr);
}

void deletePatient(FILE *ptr)
{
    int number;
    struct patient empty = {0 , "-" , 0 , "-"};

    if((ptr = fopen("patients.txt" , "r+")) == NULL)
    {
        printf("File couldn't open\n");
    }
    else
    {
        printf("Enter the Patient number : ");
        scanf("%d" , &number);

        fseek(ptr , (number - 1) * sizeof(struct patient) , SEEK_SET);
        fwrite(&empty , sizeof(struct patient) , 1 , ptr);
    }
    fclose(ptr);
}

void modifyPatient(FILE *ptr)
{
    int number;
    struct patient update = {0 , "-" , 0 , "-"};

    if((ptr = fopen("patients.txt" , "r+")) == NULL)
    {
        printf("File couldn't open\n");
    }
    else
    {
        printf("Enter the Patient number : ");
        scanf("%d", &number);

        fseek(ptr, (number - 1) * sizeof(struct patient), SEEK_SET);
        printf("Enter the patient name : ");
        scanf("%s" , &update.name);
        printf("Enter the patient age : ");
        scanf("%d" , &update.age);
        printf("Enter the patient disease : ");
        scanf("%s" , &update.disease);
        update.number = number;
        fwrite(&update , sizeof(struct patient) , 1 , ptr);
    }
    fclose(ptr);
}
