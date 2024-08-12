#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Input();
void Display();
void Search();
void Searchbyroll();
void Searchbyname();
void Modify();
void Delete();
struct student{
char name[30];
char cls[10];
int roll;
}s;
FILE*fptr;
long size=sizeof(s);
int main()
{
    int n;
    while(1)
    {
        system("cls");
        printf("*********************School Management**********************\n");
        printf("1.Take Admission\n");
        printf("2.Student Info\n");
        printf("3.Search\n");
        printf("4.Modify\n");
        printf("5.Delete\n");
        printf("6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&n);

        switch(n)
        {
        case 1:
            Input();
            break;
        case 2:
              Display();
              break;
        case 3:
              Search();
              break;
        case 4:
              Modify();
              break;
        case 5:
              Delete();
              break;
        case 6:
             exit(0);
        }
        getch();
    }
    return 0;
}
 void Input()
{
   fptr=fopen("Stud.txt","aw");
   printf("Enter student name:");
   fflush(stdin);
   gets(s.name);
   printf("Enter class:");
   fflush(stdin);
   gets(s.cls);
   printf("Enter roll:");
   scanf("%d",&s.roll);
   fwrite(&s, size, 1, fptr);
   printf("\nRecord Saved Successfully..");
   fclose(fptr);
}
void Display()
{
    system("cls");
    printf("*****************Student Info*******************\n");
    printf("%-20s %-10s %s\n","Name","Class","Roll");
    fptr=fopen("Stud.txt","r");
    while(fread(&s, size, 1, fptr)==1)
    {
        printf("%-20s %-10s %d\n",s.name,s.cls,s.roll);
    }
    fclose(fptr);
}
void Search()
{
    int n;
    system("cls");
    while(1)
    {
        printf("******Search*******\n");
        printf("1.Search by roll\n");
        printf("2.Search by name\n");
        printf("3.Back to main menu\n");
        printf("\nEnter your choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            Searchbyroll();
            break;
        case 2:
            Searchbyname();
            break;
        case 3:
            main();
            break;
        default:
            printf("Invalid Choice");
        }
        getch();
    }
}
void Searchbyroll()
{
    int roll,f=0;
    printf("Enter roll to search:");
    scanf("%d",&roll);
     printf("%-20s %-10s %s\n","Name","Class","Roll");
    fptr=fopen("Stud.txt","r");
    while(fread(&s, size, 1, fptr)==1)
    {
        if(roll==s.roll)
        {
            f=1;
        printf("%-20s %-10s %d\n",s.name,s.cls,s.roll);
        break;
        }
    }
    fclose(fptr);
    if(f==0)
    {
        printf("Record not found\n");
    }
    else
    {
        printf("Record is found\n");
    }
}
void Searchbyname()
{
    char name[30];
     int f=0;
    printf("Enter name to search:");
    fflush(stdin);
    gets(name);
     printf("%-20s %-10s %s\n","Name","Class","Roll");
    fptr=fopen("Stud.txt","r");
    while(fread(&s, size, 1, fptr)==1)
    {
        if(strcmpi(name,s.name)==0)
        {
            f=1;
        printf("%-20s %-10s %d\n",s.name,s.cls,s.roll);
        break;
        }
    }
    fclose(fptr);
    if(f==0)
    {
        printf("Record not found\n");
    }
    else
    {
        printf("Record is found\n");
    }

}
void Modify()
{
   int roll,f=0;
    printf("Enter roll to modify:");
    scanf("%d",&roll);
    fptr=fopen("Stud.txt","r+");
    while(fread(&s, size, 1, fptr)==1)
    {
        if(roll==s.roll)
        {
            f=1;
        printf("Enter student new name:");
        fflush(stdin);
        gets(s.name);
        printf("Enter new class:");
        fflush(stdin);
        gets(s.cls);
        printf("Enter new roll:");
        scanf("%d",&s.roll);
        fseek(fptr,-size,1);
        fwrite(&s,size,1,fptr);
        fclose(fptr);
        break;
        }
    }

    if(f==0)
    {
        printf("Record not found\n");
    }
    else
    {
        printf("Record Modified successfully\n");
    }
}
void Delete()
{
    int roll,f=0;
    printf("Enter roll to delete:");
    scanf("%d",&roll);

    FILE *ft;
     fptr=fopen("Stud.txt","r");
     ft=fopen("temp.txt","aw");
    while(fread(&s, size, 1, fptr)==1)
    {
        if (roll == s.roll){
            f=1;
        }else{
          fwrite(&s,size,1,ft);
        }
    }
    fclose(fptr);
    fclose(ft);
    remove("Stud.txt");
    rename("temp.txt", "Stud.txt");

     if(f==0)
    {
        printf("Record not found\n");
    }
    else
    {
        printf("Record Deleted successfully\n");
    }
}
