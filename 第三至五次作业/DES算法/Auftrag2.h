#pragma once
#include"pch.h"

//输出改变前密文，改变后的密文
void Auftrag2_main(char stext[], char key[], int changebits);

//返回两个输入数组的位数变化值
int Compare(int VorC[], int DannC[],int bits);

//
void Auftrag3_main(char stext[], char key[], int changebits);
