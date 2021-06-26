#include "Executer.h"

int main() {

	FILE* fp;
	char from_txt[1000] = { 0, };
	int i, total = 0, check;

	fp = fopen(defaultpath, "rt");
	if (fp != NULL) {
		fgets(from_txt, 1000, fp);
		fclose(fp);
	}
	else {
		printf("설정 파일이 없습니다. 관리용 프로그램을 통해 생성해주세요.\n\n");
		system("pause");
		return 0;
	}

	if (from_txt != NULL) {
		total = collectingList(from_txt, strlen(from_txt));
	}

	check = 0;
	for (i = 0; i < total; i++) {
		if (checkpath(pro[i].exelistPath, strlen(pro[i].exelistPath)) == -1) {
			check = 1;
			break;
		}
	}

	if (check == 0) {
		printf("=======================목록=======================\n\n");
		for (i = 0; i < total; i++) {
			printf("%s을(를) 실행했습니다\n", pro[i].exelistName);
			ShellExecuteA(NULL, NULL, pro[i].exelistPath, NULL, NULL, SW_SHOW);
		}
		printf("\n==================================================\n");
	}
	else {
		printf("파일 데이터에 문제가 있습니다. 실행 프로그램 관리자을 통해 오류를 해결하세요.\n\n");
		system("pause");
		return 0;
	}
	if (total > 0)
		printf("\n%d개의 프로그램을 실행했습니다.\n", total);
	else
		printf("실행할 프로그램이 없습니다.\n");
	printf("\n프로그램 목록 추가, 수정, 삭제는 관리용 프로그램에서 하실 수 있습니다.\n\n");
	system("pause");
	return 0;
}