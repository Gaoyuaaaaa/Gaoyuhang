#include "Contact.hpp"


int main () {
    AdressBooks contact;     // �����ṹ�����

    contact.m_Size = 0;     // ��ǰͨѶ¼����Ա����

    int select = 0; // �û�ѡ������ı���

    while (true) {
        showMenu(); // �˵�

        cin >> select;

        switch (select) {
        case 1:
            AddContact(&contact);
            break;
        case 2:
            ShowContact(&contact);
            break;
        case 3: 
            // case ����У�����αȽϳ���Ҫ�� {} ������
            // {cout << "������Ҫɾ��������";
            // string name; cin >> name;
            // if (isExist(&contact, name) == -1) cout << "û�ҵ�";
            // else cout << "�ҵ���";
            // break;}
            
            DeleteContact(&contact);
            break;
        case 4:
            FindContact(&contact);
            break;
        case 5:
            ModifyContact(&contact);
            break;
        case 6:
            CleanContact(&contact);
            break;
        case 0:
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }
    
    
    system("pause");
    return 0;
}
