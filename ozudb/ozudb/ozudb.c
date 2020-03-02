#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#define MAXFLDS 200   /* maximum possible number of fields */
#define MAXFLDSIZE 32 /* longest possible field + 1 = 31 byte field */

void read(person *people)
{
    people[30];
    FILE *filehandle;
    char lyne[121];

    char *item;
    int reccount = 0;
    int k;

    /* Here comes the actions! */
    /* open file */

    filehandle = fopen("People.csv", "r");

    /* Read file line by line */

    while (fgets(lyne, 120, filehandle))
    {
        item = strtok(lyne, ",");
        people[reccount].id = atoi(item);

        item = strtok(NULL, ",");
        strcpy(people[reccount].firstname, item);

        item = strtok(NULL, ",");
        strcpy(people[reccount].lastname, item);

        reccount++;
    }

    /* Close file */

    fclose(filehandle);

    /* Loop through and report on data */
}

int main(int argc, char *argv[])
{
    int counter = 4;
    int id;
    char tmp_char[18];
    person *people = 0;
    int exit = 0;
    while (exit == 0)
    {
        char x;
        scanf("%c", &x);

        switch (x)
        {
        case 'C':
            people = (person *)malloc(10 * sizeof(person));
            puts("Table succesfully created!");
            break;

        case 'R':
            if (people != 0)
            {
                read(people);
                puts("Table succesfully read!");
            }
            else
                puts("Table not created!!!");
            break;

        case 'A':

            puts("id: ");
            scanf("%d", &id);
            people[4].id = id;
            puts("firstname: ");
            scanf("%s", tmp_char);
            strcpy(people[counter].firstname, tmp_char);
            puts("lastname: ");
            scanf("%s", tmp_char);
            strcpy(people[counter].lastname, tmp_char);
            counter++;
            puts("User succesfully added!");
            break;

        case 'D':
            puts("What is the ID?");
            int delete;
            scanf("%d",&delete);
            for(int i = 0; i<counter;i++){
                if(people[i].id==delete){
                    delete = i;
                    goto delete_user;
                }
            }
            delete_user:
            for(int x = delete; x<counter-1;x++)
                people[x] = people[x+1];
            counter--;
            break;

        case 'P':
            for (int c = 0; c < counter; c++)
            {
                printf("ID %d\n", people[c].id);
                printf("NAME %s\n", people[c].firstname);
                printf("SURNAME %s\n", people[c].lastname);
            }
            break;

        case 'E':
            exit = 1;
            break;
        }
    }

    return 0;
}