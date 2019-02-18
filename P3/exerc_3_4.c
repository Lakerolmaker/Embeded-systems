// ====================================
// File name: exerc_3_5.c (or cpp)
// Date: 2019-02-11
// Group Number: 21
// Members That contributed:
// Jacob Olsson
// Victor Roman
// Members not present at the demonstration :
// Xxxxxxx
// Demonstration code: [<Ass code 29462> ]
// ======================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
char db_name[100] = "";

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

void printArray(char *array, int size){
    printf("Array : ");
    char *ptr = array;
    for(;ptr < &array[size]; ptr++){
        printf("%c", *ptr);
    }
    printf("\n");
}

// appends a new person to the file
void append_file(PERSON *person){

  FILE *fp;
  fp = fopen (db_name,"a");
  if (fp!=NULL){
    fwrite (person, sizeof(PERSON), 1, fp);
    fclose (fp);
  }
}

int file_exist(char *filename){
  FILE *file;
    if((file = fopen(filename,"r"))!=NULL){
      fclose(file);
      return 1;
    }else{
      return 0;
    }
}

int database_exists(){
  if(file_exist(db_name)){
    return 1;
  }else{
    return 0;
  }
}

void createDatabase(){

  while(1){
    printf("Input the name of the new Database : ");
    scanf("%s", db_name);
    if(database_exists()){
      printf("Database allready exists \n");
    }else{
      break;
    }
  }

  FILE *fp;
  fp = fopen(db_name,"wb");
  if (fp!=NULL){
    fprintf(fp,"");
    fclose (fp);
    printf("Database Created \n");
  }else{
    printf("Could not create database \n");
  }
}

void readDatabase(PERSON **database , int *index){

  printf("Reading Database \n");

  //: code for seeking thru the file to get it's size
  FILE *seeker= fopen(db_name, "rb");
  fseek(seeker, 0L, SEEK_END);
  int size = ftell(seeker);
  int nr_object = size / 53;
  *index = nr_object;

  printf("%d persons found in database \n" , nr_object);


  FILE *fp= fopen(db_name, "rb");

  static PERSON pers;
  int i = 0;
  if (fp != NULL) {
    while(fread(&pers, sizeof(PERSON), 1, fp)){
      database[i] = create_person(pers.firstname , pers.famnamne , pers.pers_number)
;
      i++;
    }
    fclose(fp);
  }
}

void clearDB(PERSON **database){
  memset(database, 0, 10 * sizeof(database));
}

void findPerson(PERSON **database , int size){
    printf("First name / Family name of person : ");
    char input[13];
    scanf("%s" , input);


    printf("People with that name : \n");
    int i = 0;
    for(; i < size; i++){
      char *firstname = database[i]->firstname;
      char *famnamne = database[i]->famnamne;

      if(!strcmp( input, firstname) || !strcmp( input, famnamne)){
          printPerson(database[i]);
      }
    }
}

void startup(PERSON **database , int *index){
  printf("Person database V.1.0 \n");
  printf("Do you wish to open a created database (y/n) : " );
  char input;
  scanf("%c" , &input);
  if(input == 'y' || input == 'Y'){
    printf("Input the name of the database to access : ");
    scanf("%s" , db_name);
    //: Reads the database from file
    readDatabase(database , index);
  }
}


void noDB(){
  printf("Error : No Database detected. \n");
}

int main(int argc, char *argv[]){

  //: Intilizes the array. with all objects being 0
  PERSON *database[10] = { 0 };
  int index = 0;

  startup(database, &index);

  while(1){

      printMenu();
      printf("Input a choice (1-5): ");
      int a;
      scanf("%d", &a);

      switch (a) {
        case 1:
          clearDB(database);
          createDatabase();
        break;
        case 2:
          if(database_exists()){
            database[index] = add_person();
            append_file(database[index]);
            index++;
          }else{
            noDB();
            break;
          }
        break;
        case 3:
          if(database_exists()){
            findPerson(database , index);
          }else{
            noDB();
            break;
          }
        break;
        case 4:
          if(database_exists()){
            printAll(database , NELEMS(database));
          }else{
            noDB();
            break;
          }
        break;
        case 5:
          return 0;
        break;
      }
  }


}
