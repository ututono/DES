#include"pch.h"
#include"Auftrag1.h"
#include"Auftrag2.h"


void Help()
{
	printf("\n\n\n\n\n\n\n                                              请选择序号:\n");
	printf("                               -----------------------------------------\n");
	printf("                               |                                       |\n");
	printf("                               |             1     DES源码实现         |\n");
	printf("                               |             2     差分分析            |\n");
	printf("                               |             3     改变明文            |\n");
	printf("                               |             4     改变秘钥            |\n");
	printf("                               |             5     差分攻击            |\n");
	printf("                               |             6     退出                |\n");
	printf("                               -----------------------------------------\n");
	printf("                                           请输入您的选择：");
}



int main()
{
	srand((unsigned)time(NULL)*10);
	int output[64] = { 0 };
	char MIN[9] = { 0 };
	char MI[9] = { 0 };
	int choosenum = 4;
	extern void  DES_Efun(char input[8], char key_in[8], int output[64]);
	extern void  DES_Dfun(int input[64], char key_in[8], char output[8]);

	while (choosenum!=5)
	{
		Help();
		scanf_s("%d", &choosenum);
		switch (choosenum)
		{
		case 1:
		{
			rewind(stdin);
			printf("请输入明文(8字节)\n");
			gets_s(MIN);
			printf("请输入秘钥(8字节)\n");
			gets_s(MI);
			DES_Efun(MIN, MI, output);
			printf("密文如下:\n");
			for (int i = 0; i < 64; i++)
			{
				printf("%d", output[i]);
				if ((i + 1) % 4 == 0)
					printf("\n");
			}
			printf("\n");
			printf("解密功能\n");
			DES_Dfun(output, MI, MIN);
			printf("明文如下:\n");
			for (int i = 0; i < 8; i++)
			{
				printf("%c", MIN[i]);
			}
			printf("\n\n");
			
		}
		break;
		case 2:
		{
			char tmpstr[7] ;
			int inputH[6];
			printf("input：输入差分：");
			scanf("%s", tmpstr);
			for (int i = 0; i <6;  i++)
			{
				if (tmpstr[i] != '0')
					inputH[i] = 1;
				else inputH[i] = 0;
			}
			Auftrag1_main(inputH);
			
		}
		break;
		case 3:
		{
			char stext[9] = "12345678";
			char key[9] = "12345678";
			int changebits=1;
			printf("\n");
			printf("输入8位明文：");
			scanf("%s", stext);
			printf("\n");
			printf("输入8位密钥：");
			scanf("%s", key);
			printf("\n");
			printf("明文改变的位数：");
			scanf("%d", &changebits);
			printf("\n");
			Auftrag2_main(stext, key, changebits);
			
		}
		break;
		case 4:
		{
			char stext[9]="12345678";
			char key[9]="12345678";
			int changebits = 1;
			printf("\n");
			printf("输入8位明文：");
			scanf("%s", stext);
			printf("\n");
			printf("输入8位密钥：");
			scanf("%s", key);
			printf("\n");
			printf("密钥改变的位数：");
			scanf("%d", &changebits);
			printf("\n");
			Auftrag3_main(stext, key, changebits);
		}
		break;
		case 5:
		{
			char tmpstr[7]="010101";
			char tmpstr2[7]="010100";
			char key[7];
			int inputH[6];
			int input2H[6];
			int keyH[6];
			printf("input：密钥：");
			scanf("%s", key);
			for (int i = 0; i < 6; i++)
			{
				if (key[i] != '0')
					keyH[i] = 1;
				else keyH[i] = 0;
			}
			Auftrag5_main(keyH);
		}
		break;
		default:
			break;
		}		//switch_End
		system("pause");
		system("cls");
	}

	return 0;
}
