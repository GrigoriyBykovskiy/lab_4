
// library_text_massive.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "malloc.h"
char *read_string(FILE *name) {
	char *tmp, *R = NULL;
	char ch;
	int lenght = 0;
	while (((ch = fgetc(name))!='\n')&&(!feof(name))){
		tmp = (char*)realloc(R, (lenght+1)*(sizeof(int)));
		if (tmp == NULL) {
			free(R);
			return NULL;
		}
		else {
			R = tmp;
			R[lenght] = ch;
			lenght++;
		}
	}
		tmp = (char*)realloc(R, (lenght+1)*(sizeof(int)));
		if (tmp == NULL) {
			free(R);
			return NULL;
		}
		else {
			R = tmp;
			R[lenght] = '\0';
		}
		return R;
}
int format_l(char *name, char *widht) {
	FILE *input = fopen(name, "r");
	if (input != NULL) {
		char *str;
		while ((str = read_string(input)) != NULL) {
			printf("str: %d \n", strlen(str));
			int str_lenght = strlen(str);
			int field_widht = atoi(widht);
			int count = 0;
			while (str[count] != '\0') {
				int count_t = 1;
				while ((str[count] == ' ') && (str[count] != '\0')) {
					if (count_t == field_widht) {
						printf("\n");
						count_t = 0;
					}
					count++;
					count_t++;
				}
				count_t = count;
				for (int i = 0; (count_t != str_lenght) && (i < field_widht); i++) {
					printf("%c", str[count_t]);
					count_t++;
				}
				count = count_t;
				printf("\n");
			}
			if (feof(input)) break;
		}
		if (str = NULL) return NULL;
		return 1;
	}
	else printf("Error. Can not open the FILE!\n");
}
int  format_k(char  *name, char  *widht) {
	return -1;
}
int  format_c(char  *name, char  *widht) {
	return -1;
}
int  format_w(char  *name, char  *widht) {
	return -1;
}
int format_C(char  *name, char  *widht) {
	return -1;
}
int main(int argc, char **argv)
{
	if (argc != 4) printf("Error! Only 3 parameters are required!");// 1 - path to programm
	else {
		char *err = "Not Avaliable. Mod is under construction\0";
		char *keys[5] = { "l","k","c","w","C" };
		int(*print_text)(char *arg1, char *arg2);
		for (int i = 0; i < 5; i++) {
			if (strcmp(keys[i], argv[2]) == 0) {
				{
					switch (i)
					{
					case 0:
						print_text = format_l;
						if (print_text(argv[1], argv[3]) == NULL) printf("Problem with FILE or low of memory!");
						break;
					case 1:
						print_text = format_k;
						if ((print_text(argv[1], argv[3]) != 1)) printf("%s\n", err);
						break;
					case 2:
						print_text = format_c;
						if ((print_text(argv[1], argv[3]) != 1)) printf("%s\n", err);
						break;
					case 3:
						print_text = format_w;
						if ((print_text(argv[1], argv[3])) != 1) printf("%s\n", err);
						break;
					case 4:
						print_text = format_C;
						if ((print_text(argv[1], argv[3])) != 1) printf("%s\n", err);
						break;

					default:
						break;
					}
				}
			}
		}
	}
	return 0;
}

