// �漰��Ŀ�����ĺ���

#include "common.h"
#include "account_item.h"


// ��ȡ�ļ��е���Ŀ����
void loadDataFromFile (vector<AccountItem>& items) {
    ifstream input(FILENAME);  // ����ļ�������������

    // ���ж�ȡÿһ����Ŀ����װ��AccountItem
    AccountItem item;   // �����ṹ��
    while (input >> item.itemType >> item.amount >> item.detail)    // ���ַ���ȡ���ݣ������ݷ��ڽṹ����
        items.push_back(item);

    input.close();  // �رյ�ǰ��
}   



// ��һ����Ŀд�뵽�ļ���
void insertIntoFile (const AccountItem& item) {
    // ����ofstream���󣬲�д�ڶ��������Ļ����ǽ��и��ǣ�����д��
    // ��׷�ӵķ�ʽ���ļ�����д��
    ofstream output(FILENAME, ios::out | ios::app);    

    output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;  // ������д�뵽�ļ���

    output.close();
}


// ��¼һ������
void income (vector<AccountItem>& items) {
    
    AccountItem item;   // �½�һ��AccountItem����

    item.itemType = INCOME;     // �����Ѿ�ȷ������������

    // ����������ͽ�����Ϣ
    cout << "���������";
    item.amount = readAmount();

    cout << "��ע��";
    getline(cin, item.detail);

    items.push_back(item);  // ��ӵ�vector������

    insertIntoFile(item);    // д���ļ����־û�����

    cout << "============= ���˳ɹ� =============" << endl;
    cout << "�밴�س�������" << endl;

    string line;
    getline(cin, line);     // �����κβ������൱��ֱ���˳�
}


// ��¼һ��֧��
void expand (vector<AccountItem>& items) {
    AccountItem item;   // �½�һ��AccountItem����

    item.itemType = EXPAND;     // �����Ѿ�ȷ������������

    // ����������ͽ�����Ϣ
    cout << "����֧����";
    item.amount = - readAmount();   // - һԪ�������Ӧ����int��������ǰ���൱��ֱ��ȡ��

    cout << "��ע��";
    getline(cin, item.detail);

    items.push_back(item);  // ��ӵ�vector������

    insertIntoFile(item);    // д���ļ����־û�����

    cout << "============= ���˳ɹ� =============" << endl;
    cout << "�밴�س�������" << endl;

    string line;
    getline(cin, line);     // �����κβ������൱��ֱ���˳�
}


// ����
void accounting (vector<AccountItem>& items) {

        char key = readMenuSelection(3);     // ��ȡ����ѡ�񣬲����Ϸ���У��

        switch (key) {
            case '1':   // 1 - ����
                income(items);
                break;
            case '2':   // 2 - ֧��
                expand(items);
                break;
            default:    // �������˵�
                break;
        }
}


// ��ӡ���һ����Ŀ��Ϣ
void printItem(AccountItem &item) {
    cout << item.itemType << "\t\t" << item.amount << "\t\t" << item.detail << endl;
}


// ��ѯ��Ŀ���ܺ���
void queryItems(const vector<AccountItem>& items) {
    cout << "------------- ��ѯ��� -------------" << endl;
    cout << "����\t\t���\t\t��ע" << endl;

    // ����������Ŀ��ͳ������֧
    int total = 0;
    for (auto item : items) {
        printItem(item);
        total += item.amount;
    }

    // �����Ϣ
    cout << "===============================================================" << endl;
    cout << "����֧��" << total << endl;
    cout << "�밴�س�������" << endl;

    string line;
    getline(cin, line);     // �����κβ������൱��ֱ���˳�
}


// ��������
void queryItems(const vector<AccountItem>& items, const string itemType) {
    cout << "------------- ��ѯ��� -------------" << endl;
    cout << "����\t\t���\t\t��ע" << endl;

    // ����������Ŀ��ͳ������֧
    int total = 0;
    for (auto item : items) {
        if (item.itemType == itemType) {
            printItem(item);
            total += item.amount;
        } 
    }

    // �����Ϣ
    cout << "===============================================================" << endl;
    cout << ((itemType == INCOME) ? "����֧��" : "��֧��") << total << endl;
    cout << "�밴�س�������" << endl;

    string line;
    getline(cin, line);     // �����κβ������൱��ֱ���˳�
}

// ��ѯ��Ŀ
void query (const vector<AccountItem>& items) {
    char key = readMenuSelection(4);     // ��ȡ����ѡ�񣬲����Ϸ���У��

        switch (key) {
            case '1':   // 1 - ��ѯ������Ŀ��ͳ������֧
                queryItems(items);
                break;
            case '2':   // 2 - ��ѯ���룬ͳ��������
                queryItems(items, INCOME);
                break;  
            case '3':   // 3 - ��ѯ֧����ͳ����֧��
                queryItems(items, EXPAND);
                break;
            default:    // �������˵�
                break;
        }
}

