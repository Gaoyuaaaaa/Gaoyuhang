// ͨ�����ã�ͨ�ù����Ժ�������

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define INCOME "����"
#define EXPAND "֧��"
#define FILENAME "D:\\AAAb\\src\\AccountBook.txt"

using namespace std;


// ͨ�ù����Ժ�������
// ���Ʋ˵��ĺ���
void showMainMenu ();   // һ���˵�
void showAccountingMenu (); // ���˲˵�
void showQueryMenu ();  // ��ѯ�˵�


// ��ȡ����������кϷ���У��ĺ���
char readMenuSelection (int options);   // �жϼ�������ĺϷ���
char readQuitConfirm ();        // �˳�����ĺϷ���
int readAmount ();      // ������ĺϷ���У��
