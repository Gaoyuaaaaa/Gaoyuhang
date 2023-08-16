#include "Contact.hpp"


int main () {
    AdressBooks contact;     // 创建结构体变量

    contact.m_Size = 0;     // 当前通讯录的人员个数

    int select = 0; // 用户选择输入的变量

    while (true) {
        showMenu(); // 菜单

        cin >> select;

        switch (select) {
        case 1:
            AddContact(&contact);
            break;
        case 2:
            ShowContact(&contact);
            break;
        case 3: 
            // case 语句中，代码段比较长，要用 {} 括起来
            // {cout << "请输入要删除的姓名";
            // string name; cin >> name;
            // if (isExist(&contact, name) == -1) cout << "没找到";
            // else cout << "找到了";
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
            cout << "欢迎下次使用" << endl;
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
