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
		printf("���� ������ �����ϴ�. ������ ���α׷��� ���� �������ּ���.\n\n");
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
		printf("=======================���=======================\n\n");
		for (i = 0; i < total; i++) {
			printf("%s��(��) �����߽��ϴ�\n", pro[i].exelistName);
			ShellExecuteA(NULL, NULL, pro[i].exelistPath, NULL, NULL, SW_SHOW);
		}
		printf("\n==================================================\n");
	}
	else {
		printf("���� �����Ϳ� ������ �ֽ��ϴ�. ���� ���α׷� �������� ���� ������ �ذ��ϼ���.\n\n");
		system("pause");
		return 0;
	}
	if (total > 0)
		printf("\n%d���� ���α׷��� �����߽��ϴ�.\n", total);
	else
		printf("������ ���α׷��� �����ϴ�.\n");
	printf("\n���α׷� ��� �߰�, ����, ������ ������ ���α׷����� �Ͻ� �� �ֽ��ϴ�.\n\n");
	system("pause");
	return 0;
}