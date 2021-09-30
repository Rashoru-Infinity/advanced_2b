#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 30

typedef struct person {
	int id;
	char name[NAME_LEN];
	int age;
	struct person *next;
} PERSON;

void showList(PERSON *person_list) {
	while (person_list) {
		if (person_list->id < 0) {
			return ;
		}
		printf("ID\t:\t%d\n", person_list->id);
		printf("Name\t:\t%s\n", person_list->name);
		printf("Age\t:\t%d\n\n", person_list->age);
		person_list = person_list->next;
	}
}

int main(void) {
	char *buf;
	PERSON *person_list = NULL;
	PERSON *eol = NULL;

	if (!(buf = malloc(sizeof(char) * NAME_LEN + 1))) {
		exit(1);
	}
	while (1) {
		memset(buf, 0, sizeof(char) * (NAME_LEN + 1));
		if (!eol) {
			if (!(person_list = malloc(sizeof(PERSON)))) {
				exit(1);
			}
			eol = person_list;
		} else {
			if (!(eol->next = malloc(sizeof(PERSON)))) {
				exit(1);
			}
			eol = eol->next;
		}
		memset(eol, 0, sizeof(PERSON));
		printf("ID : ");
		if (!fgets(buf, NAME_LEN, stdin)) {
			exit(1);
		}
		eol->id = atoi(buf);
		if (eol->id < 0) {
			break;
		}
		printf("Name : ");
		if (!fgets(eol->name, NAME_LEN, stdin)) {
			exit(1);
		}
		if (strlen(eol->name) != 0) {
			eol->name[strlen(eol->name) - 1] = 0;
		}
		memset(buf, 0, sizeof(char) * (NAME_LEN + 1));
		printf("Age : ");
		if (!fgets(buf, NAME_LEN, stdin)) {
			exit(1);
		}
		eol->age = atoi(buf);
		printf("\n");
	}
	showList(person_list);
	free(buf);
	while (person_list) {
		eol = person_list->next;
		free(person_list);
		person_list = eol;
	}
}
