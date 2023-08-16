// �ṹ�嶨�壻�漰��Ŀ�����ĺ�������
#pragma once

#include "common.h"


struct AccountItem
{
    string itemType;    // ��Ŀ������ʲô���ͣ����뻹��֧��
    int amount;     // ���
    string detail;  // ��ע����
};



// �����Ŀ���ݽ��в����ĺ�������
void loadDataFromFile (vector<AccountItem>& items); // ������Ŀ����

void accounting (vector<AccountItem>& items);   // ����
void insertIntoFile (const AccountItem& item);  // д���ļ�
void income (vector<AccountItem>& items);   // ��¼һ������
void expand (vector<AccountItem>& items);   // ��¼һ��֧��


void query (const vector<AccountItem>& items);  // ��ѯ
void printItem(AccountItem &item);  // ��ӡ���
void queryItems(const vector<AccountItem>& items);  // ��ѯ��Ŀ����
void queryItems(const vector<AccountItem>& items, const string itemType);   // ����


