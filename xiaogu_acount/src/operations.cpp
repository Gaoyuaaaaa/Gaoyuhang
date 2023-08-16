// 涉及账目操作的函数

#include "common.h"
#include "account_item.h"


// 读取文件中的账目数据
void loadDataFromFile (vector<AccountItem>& items) {
    ifstream input(FILENAME);  // 针对文件的输入流对象

    // 逐行读取每一条账目，包装成AccountItem
    AccountItem item;   // 创建结构体
    while (input >> item.itemType >> item.amount >> item.detail)    // 逐字符读取数据，将数据放在结构体中
        items.push_back(item);

    input.close();  // 关闭当前流
}   



// 将一条账目写入到文件中
void insertIntoFile (const AccountItem& item) {
    // 创建ofstream对象，不写第二个参数的话，是进行覆盖，不是写入
    // 以追加的方式对文件进行写入
    ofstream output(FILENAME, ios::out | ios::app);    

    output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;  // 将数据写入到文件中

    output.close();
}


// 记录一笔收入
void income (vector<AccountItem>& items) {
    
    AccountItem item;   // 新建一个AccountItem对象

    item.itemType = INCOME;     // 类型已经确定，就是收入

    // 键盘输入金额和交易信息
    cout << "本次收入金额：";
    item.amount = readAmount();

    cout << "备注：";
    getline(cin, item.detail);

    items.push_back(item);  // 添加到vector容器中

    insertIntoFile(item);    // 写入文件做持久化保存

    cout << "============= 记账成功 =============" << endl;
    cout << "请按回车键返回" << endl;

    string line;
    getline(cin, line);     // 不做任何操作，相当于直接退出
}


// 记录一笔支出
void expand (vector<AccountItem>& items) {
    AccountItem item;   // 新建一个AccountItem对象

    item.itemType = EXPAND;     // 类型已经确定，就是收入

    // 键盘输入金额和交易信息
    cout << "本次支出金额：";
    item.amount = - readAmount();   // - 一元运算符，应用在int数据类型前面相当于直接取反

    cout << "备注：";
    getline(cin, item.detail);

    items.push_back(item);  // 添加到vector容器中

    insertIntoFile(item);    // 写入文件做持久化保存

    cout << "============= 记账成功 =============" << endl;
    cout << "请按回车键返回" << endl;

    string line;
    getline(cin, line);     // 不做任何操作，相当于直接退出
}


// 记账
void accounting (vector<AccountItem>& items) {

        char key = readMenuSelection(3);     // 读取键盘选择，并作合法性校验

        switch (key) {
            case '1':   // 1 - 收入
                income(items);
                break;
            case '2':   // 2 - 支出
                expand(items);
                break;
            default:    // 返回主菜单
                break;
        }
}


// 打印输出一条账目信息
void printItem(AccountItem &item) {
    cout << item.itemType << "\t\t" << item.amount << "\t\t" << item.detail << endl;
}


// 查询账目功能函数
void queryItems(const vector<AccountItem>& items) {
    cout << "------------- 查询结果 -------------" << endl;
    cout << "类型\t\t金额\t\t备注" << endl;

    // 遍历所有账目并统计总收支
    int total = 0;
    for (auto item : items) {
        printItem(item);
        total += item.amount;
    }

    // 输出信息
    cout << "===============================================================" << endl;
    cout << "总收支：" << total << endl;
    cout << "请按回车键返回" << endl;

    string line;
    getline(cin, line);     // 不做任何操作，相当于直接退出
}


// 函数重载
void queryItems(const vector<AccountItem>& items, const string itemType) {
    cout << "------------- 查询结果 -------------" << endl;
    cout << "类型\t\t金额\t\t备注" << endl;

    // 遍历所有账目并统计总收支
    int total = 0;
    for (auto item : items) {
        if (item.itemType == itemType) {
            printItem(item);
            total += item.amount;
        } 
    }

    // 输出信息
    cout << "===============================================================" << endl;
    cout << ((itemType == INCOME) ? "总收支：" : "总支出") << total << endl;
    cout << "请按回车键返回" << endl;

    string line;
    getline(cin, line);     // 不做任何操作，相当于直接退出
}

// 查询账目
void query (const vector<AccountItem>& items) {
    char key = readMenuSelection(4);     // 读取键盘选择，并作合法性校验

        switch (key) {
            case '1':   // 1 - 查询所有账目并统计总收支
                queryItems(items);
                break;
            case '2':   // 2 - 查询收入，统计总收入
                queryItems(items, INCOME);
                break;  
            case '3':   // 3 - 查询支出，统计总支出
                queryItems(items, EXPAND);
                break;
            default:    // 返回主菜单
                break;
        }
}

