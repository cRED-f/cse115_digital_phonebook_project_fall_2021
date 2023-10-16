#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct doctor{
         char name[30];
         int id;
         char qualification[30];
         char specialist[30];
         float visiting_fees;
}doc;
doc d[100];


typedef struct patient{
 char name[100];
 int id;
 int age;
 char problem[100];
 float oxygen_level;
}pat;



int n,i;

char uname[]="Admin";
char pass[]="1234";
char user[20];
char pa[20];

void readlist();
void title();
void printoption();
void showlist();
void addlist();
void searchd();
void editlist();
void deletelist();
void sortlist();
void doctorsection();
void patientsection();
void creat();
void display();
void add();
void search();
void searchbyn();
void edit();
void deletep();
void sorting();
void sortbyn();



int main()
{
   while(1){
    title();
    printf("\n 1. Doctor Section ");
    printf("\n 2. Patient Section ");
    printf("\n 0. Exit\n ");
    printf("\n Enter Your Choice: ");
    int a;
    scanf("%d",&a);
      switch(a){
        case 0:printf("--------------Thank You-------------");
            return 0;
        case 1:doctorsection();
           break;
       case 2:
           patientsection();
           break;
       default:
         printf("\nInvalid option\n");
           break;

       }
    }
}

void doctorsection(){
    while(1){
    readlist();
    printf("\n\n             ||.........Doctor Section..........||\n\n");
    printoption();
    int a;
    scanf("%d",&a);
      switch(a){
        case 0:
            return;
        case 1:showlist();
           break;
        case 2:addlist();
        break;
        case 3:searchd();
            break;
        case 4:editlist();
            break;
        case 5:deletelist();
            break;
        case 6:sortlist();
            break;
        default:
         printf("\nInvalid option\n");
            break;
       }

    }
}


void readlist(){

    FILE *file;
    file=fopen("doctorfile.txt","r");

    if(file==NULL){
        printf("File doesn't Exist......!!!");
        return;
    }

    fscanf(file,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(file,"%s %d %s %s %f",d[i].name,&d[i].id,d[i].qualification,d[i].specialist,&d[i].visiting_fees);
    }
    fclose(file);
}

void title()
{
    printf("    \n\n    -------------------------------------------------------------\n");
    printf("    |               Hospital Management System                  |\n");
    printf("    -------------------------------------------------------------\n\n");
}

void printoption(){
   printf("\n 1. Display all the Doctors informations ");
   printf("\n 2. Add new doctors to the list ");
   printf("\n 3. Search for any Doctor ");
   printf("\n 4. Edit Doctor information ");
   printf("\n 5. Delete any particular Doctor ");
   printf("\n 6. Sort the list by Visiting Fees ");
   printf("\n 0. Back ");
   printf("\n\n Enter your Choice: ");
}

void showlist(){
    printf("\n----------------------------------------------------------------------\n");
    printf("\nSL | Name  | ID  | Qualification   |  Specialist  |  Visiting Fees |\n");
    printf("\n----------------------------------------------------------------------\n");
    for(i=0;i<n;i++){
        printf("%d. | %s  |  %d    |   %s      |     %s       |     %.2f |\n",i+1,d[i].name,d[i].id,d[i].qualification,d[i].specialist,d[i].visiting_fees);
        printf("\n--------------------------------------------------------------------\n");
    }
    return;
}
void addlist(){


    printf("\n                 .......Login First......\n\n\n");
    printf("                  Please Enter...");
    printf("\n                 -------------------------");
    printf("\n                 | User Name: |    ");
    scanf("%s",user);
    printf("                 -------------------------\n");
    printf("                 | Password:  |    ");
    scanf("%s",pa);
    printf("                 -------------------------\n");
    if(strcmp(uname,user)==0&&strcmp(pass,pa)==0){

    printf("Login Successful.\n\n");

    printf("\nEnter  New Doctor's Name: ");
    scanf("%s",d[n].name);
    printf("\nEnter ID: ");
    scanf("%d",&d[n].id);
    printf("\nEnter Qualification: ");
    scanf("%s",d[n].qualification);
    printf("\nEnter Specialist: ");
    scanf("%s",d[n].specialist);
    printf("\nEnter Visiting Fees: ");
    scanf("%f",&d[n].visiting_fees);

    n++;
    FILE *file1;
    file1=fopen("doctorfile.txt","w");
    fprintf(file1,"%d\n",n);
    for(i=0;i<n;i++){
       fprintf(file1,"%s %d %s %s %.2f\n",d[i].name,d[i].id,d[i].qualification,d[i].specialist,d[i].visiting_fees);
    }
    fclose(file1);
    }
    else{
        printf("User Name or Password wrong...!!!\n");
        printf("Please try again\n");
    }

}
void searchd(){
    int p=-1;
    char na[20];
    printf("Enter the Doctor name: ");
    scanf("%s",na);
    for(i=0;i<n;i++){
        if(strcmp(d[i].name,na)==0){
            p=i;
            break;
        }
    }
    if(p==-1){
        printf("\nSORRY!!! Doctor not found in the database");
    }
    else{
        printf("\nSearch Result: \n\n");
       printf("Name: %s \nID: %d \nQualification: %s \nSpecialist: %s \nVisiting Fees: %.2f\n",d[p].name,d[p].id,d[p].qualification,d[p].specialist,d[p].visiting_fees);
    }
}
void editlist(){
    printf("\n                 .......Login First......\n\n\n");
    printf("                  Please Enter...");
    printf("\n                 -------------------------");
    printf("\n                 | User Name: |    ");
    scanf("%s",user);
    printf("                 -------------------------\n");
    printf("                 | Password:  |    ");
    scanf("%s",pa);
    printf("                 -------------------------\n");
    if(strcmp(uname,user)==0&&strcmp(pass,pa)==0){

    printf("Login Successful.\n\n");

    int p=-1;
    char na[20];
    printf("Enter the Doctor name: ");
    scanf("%s",na);
    for(i=0;i<n;i++){
        if(strcmp(d[i].name,na)==0){
            p=i;
            break;
        }
    }
    if(p==-1){
             printf("\nSORRY!!! Doctor not found in the database");
    }
    else{
    printf("\nEnter  New Doctor's Name: ");
    scanf("%s",d[p].name);
    printf("\nEnter ID: ");
    scanf("%d",&d[p].id);
    printf("\nEnter Qualification: ");
    scanf("%s",d[p].qualification);
    printf("\nEnter Specialist: ");
    scanf("%s",d[p].specialist);
    printf("\nEnter Visiting Fees: ");
    scanf("%f",&d[p].visiting_fees);

    FILE *file1;
    file1=fopen("doctorfile.txt","w");
    fprintf(file1,"%d\n",n);
    for(i=0;i<n;i++){
       fprintf(file1,"%s %d %s %s %.2f\n",d[i].name,d[i].id,d[i].qualification,d[i].specialist,d[i].visiting_fees);
    }
    fclose(file1);
   }
    }
    else{
        printf("User Name or Password wrong...!!!\n");
        printf("Please try again\n");
    }
}

void deletelist(){

    printf("\n                 .......Login First......\n\n\n");
    printf("                  Please Enter...");
    printf("\n                 -------------------------");
    printf("\n                 | User Name: |    ");
    scanf("%s",user);
    printf("                 -------------------------\n");
    printf("                 | Password:  |    ");
    scanf("%s",pa);
    printf("                 -------------------------\n");
    if(strcmp(uname,user)==0&&strcmp(pass,pa)==0){

    printf("Login Successful.\n\n");


    FILE *file2;
    file2=fopen("doctorfile.txt","w");
    char na[20];
    printf("\nEnter Name For Delete: ");
    scanf("%s",na);
    int p=-1;
    for(i=0;i<n;i++){
        if(strcmp(d[i].name,na)==0){
            p=i;
            break;
        }
    }
     if(p==-1){
        printf("\nSORRY!!! Doctor not found in the database");
        fprintf(file2,"%d\n",n);
    }
    else{
     n--;
    fprintf(file2,"%d\n",n);
    n++;
    printf("\nSuccessfully Delete......");
    }

    for(i=0;i<n;i++){
        if(i==p){
          continue;
        }
        else{
          fprintf(file2,"%s %d %s %s %.2f\n",d[i].name,d[i].id,d[i].qualification,d[i].specialist,d[i].visiting_fees);
        }
    }
    fclose(file2);
    }
    else{
        printf("User Name or Password wrong...!!!\n");
        printf("Please try again\n");
    }
}

void sortlist(){
    doc t1;
    for(i=0;i<n;i++){
        for(int j=1+i;j<n;j++){
            if(d[i].visiting_fees<d[j].visiting_fees){
                      t1=d[i];
                      d[i]=d[j];
                      d[j]=t1;
            }

        }
    }
    printf("\n\nSort in Descending Order:\n\n");
    showlist();
}

void patientsection(){
    int n,x,a,b;


       do{
   printf("\n\n             ||.........Patient Section..........||\n\n");
   printf("\n 1. Creat new patients file ");
   printf("\n 2. Display all the patients informations ");
   printf("\n 3. Add new patients to the list ");
   printf("\n 4. Search for any patient by ID ");
   printf("\n 5. Search for any patient by Name ");
   printf("\n 6. Edit patient information ");
   printf("\n 7. Delete any particular patient ");
   printf("\n 8. Sort all patients by ID ");
   printf("\n 9. Sort all patients by Name ");
   printf("\n 0. Back");
   printf("\nEnter your preference: ");
   scanf("%d",&n);
   switch (n)
   {
    case 0:{
         return;}
    break;
    case 1:
         creat();
    break;
    case 2:
         display();
    break;
    case 3:
         add();
    break;
    case 4:
         search();
         break;
    case 5:
         searchbyn();
    break;
    case 6:
         edit();
    break;
    case 7:
         deletep();
         break;
    case 8:
         sorting();
    break;
    case 9:
         sortbyn();
    break;
    default:
         printf("\nInvalid option\n");
    break;
   }
   }while(n!=0);
}









void creat()
{
    printf("\n                 .......Login First......\n\n\n");
    printf("                  Please Enter...");
    printf("\n                 -------------------------");
    printf("\n                 | User Name: |    ");
    scanf("%s",user);
    printf("                 -------------------------\n");
    printf("                 | Password:  |    ");
    scanf("%s",pa);
    printf("                 -------------------------\n");
    if(strcmp(uname,user)==0&&strcmp(pass,pa)==0){

    printf("Login Successful.\n\n");
 pat *x;

 FILE *fp;
 fp = fopen("PROJECT.H.txt","w");
 int i,n;

 printf("\nEnter how many patients you want: ");
 scanf("%d",&n);
 x = (pat*)calloc(n,sizeof(pat));

 for(i=0;i<n;i++){
   fflush(stdin);
printf("\nEnter patient Name: ");
fflush(stdin);
gets(x[i].name);
fflush(stdin);
printf("\nEnter patient ID: ");
scanf("%d",&x[i].id);
printf("\nEnter patient Age: ");
scanf("%d",&x[i].age);
printf("\nEnter patient Problem: ");
fflush(stdin);
gets(x[i].problem);
fflush(stdin);
printf("\nEnter patient Oxygen_level: ");
scanf("%f",&x[i].oxygen_level);

 fwrite(&x[i],sizeof(pat),1,fp);
 }

fclose(fp);
}
    else{
        printf("User Name or Password wrong...!!!\n");
        printf("Please try again\n");
    }
}

void display()
{
 FILE *f;
 f = fopen("PROJECT.H.txt","r");
 pat x;
 if(f!=NULL)
 {printf("\nPatients informations are as following >>>\n");}
 while(fread(&x,sizeof(pat),1,f)){
   if(f==NULL)
   {
     printf("\nSorry currently there are no patients in database to display!!\n");
   }
   printf("_________________________________________________________________________________________");
   printf("\n| Name: %s | ID: %d | Age: %d | Problem: %s | Oxygen level: %.2f |\n",x.name,x.id,x.age,x.problem,x.oxygen_level);
 }
  printf("_________________________________________________________________________________________");
 printf("\n");
 fclose(f);


}

void add()
{
    printf("\n                 .......Login First......\n\n\n");
    printf("                  Please Enter...");
    printf("\n                 -------------------------");
    printf("\n                 | User Name: |    ");
    scanf("%s",user);
    printf("                 -------------------------\n");
    printf("                 | Password:  |    ");
    scanf("%s",pa);
    printf("                 -------------------------\n");
    if(strcmp(uname,user)==0&&strcmp(pass,pa)==0){

    printf("Login Successful.\n\n");
  pat *x;
FILE *fp;

 fp = fopen("PROJECT.H.txt","a");
 int i,n;

 printf("\nEnter how many new patients you want: ");
 scanf("%d",&n);
 x = (pat*)calloc(n,sizeof(pat));

 for(i=0;i<n;i++){
   fflush(stdin);
printf("\nEnter patient Name: ");
fflush(stdin);
gets(x[i].name);
//scanf("%[^\n]s",x[i].name);
fflush(stdin);
printf("\nEnter patient ID: ");
scanf("%d",&x[i].id);
printf("\nEnter patient Age: ");
scanf("%d",&x[i].age);
printf("\nEnter patient Problem: ");
fflush(stdin);
gets(x[i].problem);
//scanf("%s",x[i].problem);
fflush(stdin);
printf("\nEnter patient Oxygen_level: ");
scanf("%f",&x[i].oxygen_level);

 fwrite(&x[i],sizeof(pat),1,fp);
 }
  printf("\nNew patients have been added\n");
 fclose(fp);
 }
    else{
        printf("User Name or Password wrong...!!!\n");
        printf("Please try again\n");
    }

}

void search()
{
FILE *f;
 f = fopen("PROJECT.H.txt","r");
 pat x;
 int z,sign=0;
 printf("\nEnter ID to search: ");
 scanf("%d",&z);
 printf("Search result is given below: \n");
 while(fread(&x,sizeof(pat),1,f)){
   if(z==x.id){
     sign=1;
   printf("_________________________________________________________________________________________");
   printf("\n| Name: %s | ID: %d | Age: %d | Problem: %s | Oxygen level: %.2f |\n",x.name,x.id,x.age,x.problem,x.oxygen_level);
 }}
 if(sign==0){
   printf("\nSORRY!!! Patient not found in the database");
 }
 printf("\n");
 fclose(f);
}

void searchbyn()
{
  FILE *f;
 f = fopen("PROJECT.H.txt","r");
 pat x;
 char z[30],sign=0;
 fflush(stdin);
 printf("\nEnter Name to search: ");
 gets(z);
 fflush(stdin);
 printf("Search result is given below: \n");
 while(fread(&x,sizeof(pat),1,f)){
   if(strcmp(z,x.name)==0){
     sign=1;
   printf("_________________________________________________________________________________________");
   printf("\n| Name: %s | ID: %d | Age: %d | Problem: %s | Oxygen level: %.2f |\n",x.name,x.id,x.age,x.problem,x.oxygen_level);
 }}
 if(sign==0){
   printf("\nSORRY!!! Patient not found in the database");
 }
 printf("\n");
 fclose(f);
}

void edit(){
    printf("\n                 .......Login First......\n\n\n");
    printf("                  Please Enter...");
    printf("\n                 -------------------------");
    printf("\n                 | User Name: |    ");
    scanf("%s",user);
    printf("                 -------------------------\n");
    printf("                 | Password:  |    ");
    scanf("%s",pa);
    printf("                 -------------------------\n");
    if(strcmp(uname,user)==0&&strcmp(pass,pa)==0){

    printf("Login Successful.\n\n");

FILE *fp,*f;
f = fopen("PROJECT.H.txt","r");
fp = fopen("PROJECT.temp.txt","w");
 pat x;
 int z,sign=0;
 printf("\nEnter ID to edit: ");
 scanf("%d",&z);



 while(fread(&x,sizeof(pat),1,f)){
   if(z==x.id){
     sign=1;
fflush(stdin);
printf("\nEnter patient Name: ");
fflush(stdin);
gets(x.name);
fflush(stdin);
printf("\nEnter patient ID: ");
scanf("%d",&x.id);
printf("\nEnter patient Age: ");
scanf("%d",&x.age);
printf("\nEnter patient Problem: ");
fflush(stdin);
gets(x.problem);
fflush(stdin);
printf("\nEnter patient Oxygen_level: ");
scanf("%f",&x.oxygen_level);

 }
   fwrite(&x,sizeof(pat),1,fp);
 }
 fclose(f);
 fclose(fp);
if(sign==1)
{
f = fopen("PROJECT.H.txt","w");
fp = fopen("PROJECT.temp.txt","r");
while(fread(&x,sizeof(pat),1,fp)){
 fwrite(&x,sizeof(pat),1,f);
}
 fclose(fp);
 fclose(f);
 }
else{
   printf("\nSORRY!!! Patient not found in the database");
}
 printf("\n");
 }
    else{
        printf("User Name or Password wrong...!!!\n");
        printf("Please try again\n");
    }

}

void deletep()
{
    printf("\n                 .......Login First......\n\n\n");
    printf("                  Please Enter...");
    printf("\n                 -------------------------");
    printf("\n                 | User Name: |    ");
    scanf("%s",user);
    printf("                 -------------------------\n");
    printf("                 | Password:  |    ");
    scanf("%s",pa);
    printf("                 -------------------------\n");
    if(strcmp(uname,user)==0&&strcmp(pass,pa)==0){

    printf("Login Successful.\n\n");
FILE *f,*fp;
 f = fopen("PROJECT.H.txt","r");
 fp = fopen("PROJECT.T.txt","w");
 pat x;
 int z,sign=0;
 printf("\nEnter ID to delete: ");
 scanf("%d",&z);

 while(fread(&x,sizeof(pat),1,f)){
   if(z!=x.id)
   {
     fwrite(&x,sizeof(pat),1,fp);
   }
   else sign = 1;
  }
  fclose(fp);
 fclose(f);
  if(sign==0)
  printf("\nSORRY!!! Patient not found in the database\n");

f = fopen("PROJECT.H.txt","w");
fp = fopen("PROJECT.T.txt","r");
 while(fread(&x,sizeof(pat),1,fp)){

  fwrite(&x,sizeof(pat),1,f);
 }
  if(sign==1)
  printf("\n The patient have been deleted successfully \n");
  fclose(fp);
 fclose(f);
 }
    else{
        printf("User Name or Password wrong...!!!\n");
        printf("Please try again\n");
    }
}
void sorting()
{
  pat *x,y;

 FILE *fp;
 fp = fopen("PROJECT.H.txt","r");
 int i,n,j,t;

 fseek(fp,0,SEEK_END);
 n = ftell(fp)/sizeof(pat);

 rewind(fp);

 x = (pat*)calloc(n,sizeof(pat));

  for(i=0;i<n;i++){
    fread(&x[i],sizeof(pat),1,fp);
  }
  fclose(fp);
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){

      if(x[i].id < x[j].id){

         y = x[i];
         x[i] = x[j];
         x[j] = y;
      }
    }
  }
 FILE *f;
 f = fopen("PROJECT.H.txt","w");
 for(i=0;i<n;i++){
  fwrite(&x[i],sizeof(pat),1,f);
 }
 fclose(f);
 printf("\n Sorting by ID is Successful \n");
 display();
}
void sortbyn()
{
  pat *x,y;

 FILE *fp;
 fp = fopen("PROJECT.H.txt","r");
int i,n,j,t;

 fseek(fp,0,SEEK_END);
 n = ftell(fp)/sizeof(pat);

 rewind(fp);

 x = (pat*)calloc(n,sizeof(pat));

  for(i=0;i<n;i++){
    fread(&x[i],sizeof(pat),1,fp);
  }
  fclose(fp);
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){

      if(strcmp(x[i].name,x[j].name)>0){

         y = x[i];
         x[i] = x[j];
         x[j] = y;
      }
    }
  }
 FILE *f;
 f = fopen("PROJECT.H.txt","w");
 for(i=0;i<n;i++){
  fwrite(&x[i],sizeof(pat),1,f);
 }
 fclose(f);
 printf("\n Sorting by Name is Successful \n");
 display();

}
