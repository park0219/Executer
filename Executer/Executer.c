#include "Executer.h"

int checkpath(char* path, int count) {

	int checkdot = 0;
	int checkc = 0;
	int i;
	for (i = 0; i < count; i++) {
		char a = path[i];
		if (isspace(a) || isalpha(a) || isdigit(a) || a == '\\' || a == ' ' || a == '-' || a == '_' || a == '(' || a == ')') {
		}
		else if (a == '.') {
			checkdot = 1;
		}
		else if (a == ':') {
			checkc = 1;
		}
		else {
			return -1;
		}

	}

	if (checkdot == 1 && checkc == 1 && path[count - 1] == 'e' && path[count - 2] == 'x' && path[count - 3] == 'e' && path[count - 4] == '.' && path[1] == ':') {
		return 1;
	}
	return -1;
}


int collectingList(char *path, int count) {

	int i, c = 0, namecount = 0, pathcount = 0, chk = 0;


	if (count == 0) {
		return 0;
	}

	if (path[0] != '{' || path[count - 1] != '}') {
		return -1;
	}

	for (i = 0; i < count; i++) {
		char a = path[i];
		if (a == '}') {
			c++;
			chk = 0;
			namecount = 0;
			pathcount = 0;
		}
		else if (a == '{') {

		}
		else if (a == ',') {
			chk = 1;
		}
		else {
			if (chk == 0) {
				pro[c].exelistName[namecount] = a;
				namecount++;
			}
			else {
				pro[c].exelistPath[pathcount] = a;
				pathcount++;
			}
		}
	}
	return c;
}
