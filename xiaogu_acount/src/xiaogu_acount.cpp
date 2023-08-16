/*
    ���庯��

    ���ܣ����ˡ���ѯ���˳�
    ���ݴ洢���ı��ļ���

    ���ˣ����� �� ָ��
    ��ѯ����ѯ������Ŀ��ͳ������֧����ѯȫ����Ŀ����ѯ�����֧��

    �ּ��˵���ÿһ������ �������˵� ����

*/


#include "common.h"
#include "account_item.h"



int main () {
    // 1.�����ļ��е���Ŀ���ݷŵ�vector��
    vector<AccountItem> items;
    loadDataFromFile(items);
    
    bool quit = false;
    while (!quit) {
        
        showMainMenu();     // 2.��ʾ���˵�

        char key = readMenuSelection(3);     // 3.��ȡ����ѡ�񣬲����Ϸ���У��

        switch (key) {
            case '1':   // 1 - ����
                showAccountingMenu();  // ��ʾ��ǰ���˲˵�(�����˵�)
                accounting(items);  // ׷����Ŀ
                break;
            case '2':   // 2 - ��ѯ
                showQueryMenu(); 
                query(items);   // ��ѯ��Ŀ
                break;
            case '3':   // 3 - �˳�
                cout << "\n�Ƿ�ȷ���˳�?(Y/N): " << endl;
                if (readQuitConfirm() == 'Y') quit = true;  
                break;
            default:
                break;
        }

        cout << endl;
    }


    return 0;
}
