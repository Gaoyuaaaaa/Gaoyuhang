// ��ȡ���뺯��

#include "common.h"


// ��ȡ��������Ĳ˵�ѡ����кϷ���У��
char readMenuSelection (int options) {
    string str;
    
    // ����У��
    while (true) {
        getline(cin, str);
        if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options)   // �ַ������Ե����ַ�����ʹ��
            cout << "������������ѡ��";
        else 
            break;
    }

    return str[0];  //����Ϸ������ص�ǰѡ����ַ�
}


// ��ȡȷ���˳���Ϣ������У��
char readQuitConfirm () {
    string str;
    
    // ����У�飬�߼������ȼ������߼��򣬽��д�С��ת������Сд��y������
    while (true) {
        getline(cin, str);
        if (str.size() != 1 || toupper(str[0]) != 'Y' && toupper(str[0]) != 'N') 
            cout << "����������������(Y/N): ";
        else break;
    }

    return toupper(str[0]);
}


// ��ȡ��������Ľ������Ϸ���У��
int readAmount () {
    int amount;
    string str;
    while (true) {
        getline(cin, str);
        
        try {
            amount = stoi(str); // У�飬���ַ�������int��
            break;
        } catch (invalid_argument e) {      // invalid_argument - �Ƿ��Ĳ���
            cout << "�����������ȷ�������֣�";
        }
    }
    return amount;
}

