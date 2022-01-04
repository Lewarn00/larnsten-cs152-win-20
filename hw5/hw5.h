#ifndef HW5_H
#define HW5_H

typedef unsigned int uint;

typedef struct {
	char *str;
	uint allocated_length;
} safe_string;

safe_string* make_empty_string();
safe_string* make_string(char *str);

void safe_str_cpy(safe_string *dest, safe_string *src);
void safe_str_cat(safe_string *dest, safe_string *src);

char *safe_strchr(safe_string *s, char c);
int safe_strcmp(safe_string *s1, safe_string *s2);

#endif