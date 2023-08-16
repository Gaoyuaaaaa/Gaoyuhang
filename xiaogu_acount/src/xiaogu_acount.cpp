/*
    主体函数

    功能：记账、查询、退出
    数据存储在文本文件中

    记账：收入 和 指出
    查询：查询所有账目，统计总收支，查询全部账目、查询收入和支出

    分级菜单，每一级都有 返回主菜单 功能

*/


#include "common.h"
#include "account_item.h"



int main () {
    // 1.加载文件中的账目数据放到vector中
    vector<AccountItem> items;
    loadDataFromFile(items);
    
    bool quit = false;
    while (!quit) {
        
        showMainMenu();     // 2.显示主菜单

        char key = readMenuSelection(3);     // 3.读取键盘选择，并作合法性校验

        switch (key) {
            case '1':   // 1 - 记账
                showAccountingMenu();  // 显示当前记账菜单(二级菜单)
                accounting(items);  // 追加账目
                break;
            case '2':   // 2 - 查询
                showQueryMenu(); 
                query(items);   // 查询账目
                break;
            case '3':   // 3 - 退出
                cout << "\n是否确认退出?(Y/N): " << endl;
                if (readQuitConfirm() == 'Y') quit = true;  
                break;
            default:
                break;
        }

        cout << endl;
    }


    return 0;
}
