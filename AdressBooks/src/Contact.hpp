#include <iostream>
#include <string>

using namespace std;

#define MAX 1000


// 联系人结构体
struct People
{
    string m_Name;  // 姓名
    int m_Age;      // 年龄
    int m_Sex;   // 1男 2女 
    string m_Phone; // 电话
    string m_Address;   // 地址
};

// 通讯录结构体
struct AdressBooks
{
    struct People personArray[MAX]; // 保存的联系人的数组
    int m_Size; // 当前联系人个数
};


// 菜单
void showMenu () {
    cout << "********************" << endl;
    cout << "*** 0.退出通讯录 ***" << endl;
    cout << "*** 1.添加联系人 ***" << endl;
    cout << "*** 2.显示联系人 ***" << endl;
    cout << "*** 3.删除联系人 ***" << endl;
    cout << "*** 4.查找联系人 ***" << endl;
    cout << "*** 5.修改联系人 ***" << endl;
    cout << "*** 6.清空联系人 ***" << endl;
    cout << "********************" << endl;
}


// 添加联系人
void AddContact (AdressBooks * p) {
    if (p->m_Size == MAX) {
        cout << "通讯录已满，无法添加" << endl;
        return;
    } else {
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        p->personArray[p->m_Size].m_Name = name;   // 

        int age;
        cout << "请输入年龄：" << endl;
        while (1) {
            cin >> age;
            if (age > 0 && age <= 120) {
                p->personArray[p->m_Size].m_Age = age;
                break;
            }
            cout << "输入有误，请从新输入" << endl;
        }

        int sex = 0;
        cout << "请输入性别：" << endl;
        cout << "1.男" << " " << "2.女" << endl;
        while (1) {     // 输入1或2可以退出循环，输入有误就从新输入
            cin >> sex;
            if (sex == 1 || sex == 2) {
                p->personArray[p->m_Size].m_Sex = sex;
                break;;
            }
            cout << "输入有误，请从新输入" << endl;
        }

        string phone;
        cout << "请输入联系电话：" << endl;
        cin >> phone;
        p->personArray[p->m_Size].m_Phone = phone;

        string address;
        cout << "请输入家庭住址：" << endl;
        cin >> address;
        p->personArray[p->m_Size].m_Address = address;
        
        p->m_Size ++;   // 更新通讯录人数
        cout << "添加成功" << endl;

        system("pause");    // 请按任意键继续
        system("cls");      // 清屏操作
    }
}


// 显示联系人
void ShowContact (const AdressBooks *p) {
    if (p->m_Size == 0) {
        cout << "当前通讯录为空" << endl;
        return;
    } else {
        for (int i = 0; i < p->m_Size; i++) {
            cout << "姓名：" << p->personArray[i].m_Name << " ";
            cout << "年龄" << p->personArray[i].m_Age << " ";
            cout << "性别：" << (p->personArray[i].m_Sex == 1 ? "男" : "女") << " ";    
            cout << "电话：" << p->personArray[i].m_Phone << " ";
            cout << "住址：" << p->personArray[i].m_Address << endl;
        }
    }

    system("pause");
    system("cls");
}


// 检测联系人是否存在，若存在，返回联系人所在位置，不存在返回-1
// 传递通讯录数组 和 人名
int isExist (AdressBooks *pppp, string name) {
    for (int i = 0; i < pppp->m_Size; i++) {
        if (pppp->personArray[i].m_Name == name) return i;     // 找到，返回下标
    }
    return -1;      // 没找到返回-1
} 


// 删除联系人
void DeleteContact (AdressBooks *p) {
    cout << "请输入您要删除的联系人：" << endl;
    string name; cin >> name;

    int ret = isExist(p, name);

    if (ret != -1) {
        for (int i = ret; i < p->m_Size; i++) 
            p->personArray[i] = p->personArray[i + 1];  // 数据前移
        p->m_Size --;   // 更新人数
        cout << "删除成功" << endl;
    }
    else cout << "查无此人" << endl;

    system("pause");
    system("cls");
}


// 查找
void FindContact (AdressBooks *p) {
    cout << "请输入您要查找的联系人：" << endl;
    string name; cin >> name;

    int ret = isExist(p, name);

    if (ret != -1) {
        cout << "姓名：" << p->personArray[ret].m_Name << " ";
        cout << "年龄" << p->personArray[ret].m_Age << " ";
        cout << "性别：" << (p->personArray[ret].m_Sex == 1 ? "男" : "女") << " ";    
        cout << "电话：" << p->personArray[ret].m_Phone << " ";
        cout << "住址：" << p->personArray[ret].m_Address << endl;
    } else cout << "查无此人" << endl;

    system("pause");
    system("cls");
}


// 修改
void ModifyContact (AdressBooks *p) {
    cout << "请输入您要修改的联系人：" << endl;
    string name; cin >> name;

    int ret = isExist(p, name);

    if (ret != -1) {
        
        cout << "请输入新的姓名：" << endl;
        string name; cin >> name;
        p->personArray[ret].m_Name = name;

        int age;
        cout << "请输入新的年龄：" << endl;
        while (true) {
            cin >> age;
            if (age > 0 && age <= 120) {
                p->personArray[ret].m_Age = age;
                break;
            }
            cout << "输入有误，请从新输入" << endl;
        }

        int sex = 0;
        cout << "请输入新的性别：" << endl;
        cout << "1.男" << " " << "2.女" << endl;
        while (true) {     // 输入1或2可以退出循环，输入有误就从新输入
            cin >> sex;
            if (sex == 1 || sex == 2) {
                p->personArray[ret].m_Sex = sex;
                break;;
            }
            cout << "输入有误，请从新输入" << endl;
        }

        string phone;
        cout << "请输入新的联系电话：" << endl;
        cin >> phone;
        p->personArray[ret].m_Phone = phone;

        string address;
        cout << "请输入新的家庭住址：" << endl;
        cin >> address;
        p->personArray[ret].m_Address = address;

    } else cout << "查无此人" << endl;

    system("pause");
    system("cls");
}


// 清空
// 只需将通讯录记录的人数置为0，做逻辑清空即可
void CleanContact (AdressBooks *p) {
    p->m_Size = 0;
    cout << "联系人已清空" << endl;

    system("pause");
    system("cls");
}

