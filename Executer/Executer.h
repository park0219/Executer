#pragma once
#ifndef __EXECUTR_H__
#define __EXECUTR_H__

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define defaultpath "D:\\exelist.txt"

struct Program {
	char exelistName[1000];
	char exelistPath[1000];
} pro[40];

int checkpath(char* path, int count);
int collectingList(char* path, int count);

#endif // !__EXECUTR_H__
