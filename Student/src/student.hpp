#pragma once

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 100


struct Student {
    string m_Name;      // ����
    string m_Num;       // ѧ��
    int m_CLange;       // C�ɼ�
    int m_Algo;         // �㷨
    int m_Database;     // ���ݿ�ɼ�
    int m_Sum;          // �ܳɼ�
};


struct Stu {
    struct Student data[MAX];    // ����洢
    int m_Size = 0;               // ��ǰ����
};


// �˵�
void menu() {

    cout << "********* ѧ������ϵͳ *************" << endl;
    cout << "********* 1.����ѧ����Ϣ ***********" << endl;
    cout << "********* 2.ɾ��ѧ����Ϣ ***********" << endl;
    cout << "********* 3.�޸�ѧ����Ϣ ***********" << endl;
    cout << "********* 4.ͳ��ѧ������ ***********" << endl;
    cout << "********* 5.��ʾ������Ϣ ***********" << endl;
    cout << "********* 0.�˳�ϵͳ ***************" << endl;
    cout << "************************************" << endl;

    cout << "��ѡ��(0 - 7): ";
}


// ����
void addStudent(Stu *p) {

    if (p->m_Size == MAX) {
        cout << "�����������" << endl;
        return;
    } else {
        cout << "������������" << endl;
        string name; cin >> name;
        p->data[p->m_Size].m_Name = name;

        cout << "������ѧ�ţ�" << endl;
        string num; cin >> num;
        p->data[p->m_Size].m_Num = num;

        cout << "������C���Գɼ�: " << endl;
        int clange; cin >> clange;
        p->data[p->m_Size].m_CLange = clange;

        cout << "�������㷨�ɼ���" << endl;
        int algo; cin >> algo;
        p->data[p->m_Size].m_Algo = algo;

        cout << "���������ݿ�ɼ���" << endl;
        int database; cin >> database;
        p->data[p->m_Size].m_Database = database;

        cout << "��ӳɹ�" << endl;  
        p->m_Size ++;
    }
}


// �����ϵ��
int isExit(Stu *ppp, string name) {
    for (int i = 0; i < ppp->m_Size; i++)
        if (ppp->data[i].m_Name == name) 
            return i;
    
    return -1;
}

// ɾ��
void deleteStudent(Stu *p) {
    cout << "��������Ҫɾ������ϵ�ˣ�";
    string name; cin >> name;

    int ret = isExit(p, name);
    if (ret != -1) {
        for (int i = ret; i < p->m_Size; i++) {
            p->data[i] = p->data[i + 1];            // ɾ��
            p->m_Size --;                           // ��������
            cout << "ɾ���ɹ�" << endl;
        }
    } else cout << "���޴���" << endl;
}


// �޸�
void modifyStudent(Stu *p) {
    cout << "�������޸�ǰ��������" << endl;
    string name; cin >> name;

    int ret = isExit(p, name);
    if (ret != -1) {
        cout << "�������µ�������" << endl;
        string name; cin >> name;
        p->data[p->m_Size].m_Name = name;

        cout << "�������µ�ѧ�ţ�" << endl;
        string num; cin >> num;
        p->data[p->m_Size].m_Num = num;

        cout << "�������µ�C���Գɼ�: " << endl;
        int clange; cin >> clange;
        p->data[p->m_Size].m_CLange = clange;

        cout << "�������µ��㷨�ɼ���" << endl;
        int algo; cin >> algo;
        p->data[p->m_Size].m_Algo = algo;

        cout << "�������µ����ݿ�ɼ���" << endl;
        int database; cin >> database;
        p->data[p->m_Size].m_Database = database;
    } else cout << "���޴���" << endl;
}




// ͳ��
void totalStudent(Stu *p) {
    int total;
    if (p->m_Size == 0) cout << "û��ѧ��" << endl;
    else { 
        for (int i = 0; i < p->m_Size; i++) total += i; 
               
        cout << "ѧ����������" << (total + 1) << endl;
    }
    
}


// ��ʾ����
void showStudent(Stu *p) {
    if (p->m_Size == 0) cout << "��û��ѧ����Ϣ" << endl;
    else {
        for (int i = 0; i < p->m_Size; i++) {
            p->data[i].m_Sum = p->data[i].m_CLange + 
                                   p->data[i].m_Algo + 
                                   p->data[i].m_Database;

            cout << "������" << p->data[i].m_Name << "\t\t"
                 << "ѧ�ţ�" << p->data[i].m_Num << "\t\t"
                 << "C���Գɼ�: " << p->data[i].m_CLange << "\t\t"
                 << "�㷨�ɼ���" << p->data[i].m_Algo << "\t\t"
                 << "���ݿ�ɼ���" << p->data[i].m_Database << "\t\t"
                 << "�ܳɼ���" << p->data[i].m_Sum << endl;
        }
    }
}



