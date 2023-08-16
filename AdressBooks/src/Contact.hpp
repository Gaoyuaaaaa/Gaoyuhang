#include <iostream>
#include <string>

using namespace std;

#define MAX 1000


// ��ϵ�˽ṹ��
struct People
{
    string m_Name;  // ����
    int m_Age;      // ����
    int m_Sex;   // 1�� 2Ů 
    string m_Phone; // �绰
    string m_Address;   // ��ַ
};

// ͨѶ¼�ṹ��
struct AdressBooks
{
    struct People personArray[MAX]; // �������ϵ�˵�����
    int m_Size; // ��ǰ��ϵ�˸���
};


// �˵�
void showMenu () {
    cout << "********************" << endl;
    cout << "*** 0.�˳�ͨѶ¼ ***" << endl;
    cout << "*** 1.�����ϵ�� ***" << endl;
    cout << "*** 2.��ʾ��ϵ�� ***" << endl;
    cout << "*** 3.ɾ����ϵ�� ***" << endl;
    cout << "*** 4.������ϵ�� ***" << endl;
    cout << "*** 5.�޸���ϵ�� ***" << endl;
    cout << "*** 6.�����ϵ�� ***" << endl;
    cout << "********************" << endl;
}


// �����ϵ��
void AddContact (AdressBooks * p) {
    if (p->m_Size == MAX) {
        cout << "ͨѶ¼�������޷����" << endl;
        return;
    } else {
        string name;
        cout << "������������" << endl;
        cin >> name;
        p->personArray[p->m_Size].m_Name = name;   // 

        int age;
        cout << "���������䣺" << endl;
        while (1) {
            cin >> age;
            if (age > 0 && age <= 120) {
                p->personArray[p->m_Size].m_Age = age;
                break;
            }
            cout << "�����������������" << endl;
        }

        int sex = 0;
        cout << "�������Ա�" << endl;
        cout << "1.��" << " " << "2.Ů" << endl;
        while (1) {     // ����1��2�����˳�ѭ������������ʹ�������
            cin >> sex;
            if (sex == 1 || sex == 2) {
                p->personArray[p->m_Size].m_Sex = sex;
                break;;
            }
            cout << "�����������������" << endl;
        }

        string phone;
        cout << "��������ϵ�绰��" << endl;
        cin >> phone;
        p->personArray[p->m_Size].m_Phone = phone;

        string address;
        cout << "�������ͥסַ��" << endl;
        cin >> address;
        p->personArray[p->m_Size].m_Address = address;
        
        p->m_Size ++;   // ����ͨѶ¼����
        cout << "��ӳɹ�" << endl;

        system("pause");    // �밴���������
        system("cls");      // ��������
    }
}


// ��ʾ��ϵ��
void ShowContact (const AdressBooks *p) {
    if (p->m_Size == 0) {
        cout << "��ǰͨѶ¼Ϊ��" << endl;
        return;
    } else {
        for (int i = 0; i < p->m_Size; i++) {
            cout << "������" << p->personArray[i].m_Name << " ";
            cout << "����" << p->personArray[i].m_Age << " ";
            cout << "�Ա�" << (p->personArray[i].m_Sex == 1 ? "��" : "Ů") << " ";    
            cout << "�绰��" << p->personArray[i].m_Phone << " ";
            cout << "סַ��" << p->personArray[i].m_Address << endl;
        }
    }

    system("pause");
    system("cls");
}


// �����ϵ���Ƿ���ڣ������ڣ�������ϵ������λ�ã������ڷ���-1
// ����ͨѶ¼���� �� ����
int isExist (AdressBooks *pppp, string name) {
    for (int i = 0; i < pppp->m_Size; i++) {
        if (pppp->personArray[i].m_Name == name) return i;     // �ҵ��������±�
    }
    return -1;      // û�ҵ�����-1
} 


// ɾ����ϵ��
void DeleteContact (AdressBooks *p) {
    cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
    string name; cin >> name;

    int ret = isExist(p, name);

    if (ret != -1) {
        for (int i = ret; i < p->m_Size; i++) 
            p->personArray[i] = p->personArray[i + 1];  // ����ǰ��
        p->m_Size --;   // ��������
        cout << "ɾ���ɹ�" << endl;
    }
    else cout << "���޴���" << endl;

    system("pause");
    system("cls");
}


// ����
void FindContact (AdressBooks *p) {
    cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
    string name; cin >> name;

    int ret = isExist(p, name);

    if (ret != -1) {
        cout << "������" << p->personArray[ret].m_Name << " ";
        cout << "����" << p->personArray[ret].m_Age << " ";
        cout << "�Ա�" << (p->personArray[ret].m_Sex == 1 ? "��" : "Ů") << " ";    
        cout << "�绰��" << p->personArray[ret].m_Phone << " ";
        cout << "סַ��" << p->personArray[ret].m_Address << endl;
    } else cout << "���޴���" << endl;

    system("pause");
    system("cls");
}


// �޸�
void ModifyContact (AdressBooks *p) {
    cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
    string name; cin >> name;

    int ret = isExist(p, name);

    if (ret != -1) {
        
        cout << "�������µ�������" << endl;
        string name; cin >> name;
        p->personArray[ret].m_Name = name;

        int age;
        cout << "�������µ����䣺" << endl;
        while (true) {
            cin >> age;
            if (age > 0 && age <= 120) {
                p->personArray[ret].m_Age = age;
                break;
            }
            cout << "�����������������" << endl;
        }

        int sex = 0;
        cout << "�������µ��Ա�" << endl;
        cout << "1.��" << " " << "2.Ů" << endl;
        while (true) {     // ����1��2�����˳�ѭ������������ʹ�������
            cin >> sex;
            if (sex == 1 || sex == 2) {
                p->personArray[ret].m_Sex = sex;
                break;;
            }
            cout << "�����������������" << endl;
        }

        string phone;
        cout << "�������µ���ϵ�绰��" << endl;
        cin >> phone;
        p->personArray[ret].m_Phone = phone;

        string address;
        cout << "�������µļ�ͥסַ��" << endl;
        cin >> address;
        p->personArray[ret].m_Address = address;

    } else cout << "���޴���" << endl;

    system("pause");
    system("cls");
}


// ���
// ֻ�轫ͨѶ¼��¼��������Ϊ0�����߼���ռ���
void CleanContact (AdressBooks *p) {
    p->m_Size = 0;
    cout << "��ϵ�������" << endl;

    system("pause");
    system("cls");
}

