#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void		realMain();																//����
void		printContents(FILE* readContents_fp);									//���Ͽ� ����� �޸� ���
void		saveContents(FILE* saveContents_fp);									//���Ͽ� �޸� ����
wchar_t* ConverCtoWC(char* str);
static int		SetRegistry(LPCWSTR IpValueName, LPCWSTR IpExeFile);					//���� ������Ʈ���� ���

int main()
{
	realMain();

	return 0;
}

//����
void realMain()
{
	char    ch;																	//�Էµ� ��ɾ�
	LPCWSTR route = ConverCtoWC("C:\\Users\\dsm2017\\Desktop\\text.ext");		//exe������ ���

																				//�б������� ���� ����
	FILE* readContents_fp = fopen("text.txt", "r");

	printContents(readContents_fp);

	fclose(readContents_fp);

	printf("�޸� �߰��Ϸ��� �ƹ��ų� �Է�! ���� : x\n");
	while (1)
	{
		if (kbhit())
		{
			if (getch() == 'x')h
			{
				//���α׷� ����
				return;
			}

				//�޸� �ۼ�
				//���������� ���� ����
			FILE* saveContents_fp = fopen("text.txt", "w");

			saveContents(saveContents_fp);
			SetRegistry(ConverCtoWC("memoP"), route);

			fclose(saveContents_fp);

			return;
		}
	}

	return;
}

//���Ͽ� �ִ°� �о� ȭ�鿡 ���
void printContents(FILE* readContents_fp)
{
	char ch;						//�޸� ��½ÿ� ���

	ch = fgetc(readContents_fp);
	if (ch == NULL)
	{
		printf("�޸�� ������ �����ϴ� !");
	}
	else
	{
		printf("�޸�� ����\n");

		//������ ������ �˻�
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = fgetc(readContents_fp);
		}
	}
	printf("\n\n\n");

	return;
}

//�Է��Ͽ� ���Ͽ� ����
void saveContents(FILE* saveContents_fp)
{
	char saveContentsArr[300];		//���Ͽ� ������ ���ڿ�

	printf("�޸��� ������ �Է��ϼ��� ! (����� '?' �Է�)\n");
	scanf("%[^?]s", saveContentsArr);
	fprintf(saveContents_fp, "%s", saveContentsArr);
}

//char������ w_char������ �ٲ�
wchar_t* ConverCtoWC(char* str)
{
	wchar_t* res;														//wchar�� ����
	int strSize = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, NULL);  //��Ƽ����Ʈ ũ�� ��� ����

																		//�޸� �Ҵ�
	res = new WCHAR[strSize];

	//����ȯ
	MultiByteToWideChar(CP_ACP, 0, str, strlen(str) + 1, res, strSize);

	return res;
}

//������Ʈ���� ����ϴ� �Լ�
//��ó : whiteat.com/WhiteAT_c/3288
//
//Parameters
//	IpValueName : ������ ���� �̸�
//  IpExeFile   : ����� exe������ ���
//
//ReturnValue
//	0 : Fail
//  1 : Success
//
static int SetRegistry(LPCWSTR IpValueName, LPCWSTR IpExeFile)
{
	HKEY hKey;		//������Ʈ�� ������ �� �� �ڵ鰪�� ������ ��
	long lRes;		//������Ʈ�� ��Ͽ� ���Ǵ� ����

					//���ڰ� NULL�̸� Fail
	if (IpValueName == NULL || IpExeFile == NULL)
	{
		return 0;
	}
	if (RegOpenKeyEx(HKEY_CURRENT_USER, ConverCtoWC("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce"), 0, KEY_WRITE, &hKey) != ERROR_SUCCESS)
	{
		printf("fail\n");
		return 0;
	}

	lRes = RegSetValueEx(hKey, IpValueName, 0, REG_SZ, (BYTE*)IpExeFile, lstrlen(IpExeFile));
	RegCloseKey(hKey);

	if (lRes != ERROR_SUCCESS)
	{
		return 0;
	}

	return 1;
}