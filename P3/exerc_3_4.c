#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))


typedef struct {
 char firstname[20];
 char famnamne[20];
 char pers_number[13]; // yyyymmddnnnc
}PERSON;


PERSON* create_person(char name[20], char famname[20] , char personnumber[13] ){

  PERSON *pers;
  pers = (PERSON*) malloc(sizeof(PERSON));

  strcpy(pers->firstname, name);
  strcpy(pers->famnamne, famname);
  strcpy(pers->pers_number, personnumber);

  return pers;

}

PERSON* add_person(void){

  printf("Name of person : ");
  char name[20];
  scanf("%s", name);

  printf("Family name  of person : ");
  char famname[20];
  scanf("%s", famname);

  printf("Person-number of person : ");
  char personnumber[13];
  scanf("%s", personnumber);

  return create_person(name, famname, personnumber);
}
 // Reads in a person record.
void write_new_file( PERSON *inrecord); //Creats a file and write a first record
void printfile(void); // print out all persons in the file
void search_by_firstname( char *name);// print out person if in list


//1 Create a new and delete the old file.
//2 Add a new person to the file.
//3 Search for a person in the file .
//4 Print out all in the file.
//5 Exit the program.

void printMenu(){
printf("\n");
 printf("--------------------------------\n");
 printf("--       Person database      --\n");
 printf("--            -----           --\n");
 printf("--   1. Create new Database   --\n");
 printf("--   2. Add new person        --\n");
 printf("--   3. Search for person     --\n");
 printf("--   4. Print all persons     --\n");
 printf("--   5. Exit program          --\n");
 printf("--------------------------------\n");
}


void printPerson(PERSON *person){
  printf("%s %s - %s \n" , person->firstname ,person->famnamne , person->pers_number );
}

void printAll(PERSON **database, int size){
  PERSON person;
  printf("Content of database : \n");
  int i = 0;
  for(;i < size; i++){
    if(database[i] != 0){
      printPerson(database[i]);
    }
  }
}

// appends a new person to the file
void append_file(PERSON *person){
  FILE *fp;
  fp = fopen ("database.txt","w+");
  if (fp!=NULL){
    fwrite(person, sizeof(PERSON), 1, fp);
    fclose (fp);
  }
}

void createDatabase(){
  FILE *fp;
  fp = fopen("database.txt","w+");
  if (fp!=NULL){
    fprintf(fp,"");
    fclose (fp);
    printf("Database Created \n");
  }else{
    printf("Could not create database \n");
  }
}

void readDatabase(PERSON **database){

  printf("Reading Database \n");

  PERSON **buffer = malloc(10 * sizeof(PERSON));

  FILE *fp= fopen("database.txt", "w+");

  fseek(fp, 0L, SEEK_END);
  int size = ftell(fp);
  int nr_object = size / 53;

  printf("%d persons found in database \n" , nr_object);

  if (fp != NULL) {
      fread(buffer, sizeof(PERSON), nr_object, fp);
      fclose(fp);
  }

  printAll(buffer ,NELEMS(buffer) );
  //database = buffer;
}

int main(int argc, char *argv[]){

  //: Intilizes the array.
  PERSON *database[10] = { 0 };

  readDatabase(database);

  while(1){

      printMenu();
      printf("Input a choice (1-5): ");
      int a;
      scanf("%d", &a);

      switch (a) {
        case 1:
          createDatabase();
        break;
        case 2:
          database[0] = add_person();
          append_file(database[0]);
        break;
        case 3:
        break;
        case 4:
          printAll(database , NELEMS(database));
        break;
        case 5:
          return 0;
        break;
      }
  }


}
