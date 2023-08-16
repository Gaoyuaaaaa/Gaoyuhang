#pragma once

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 100


struct Student {
    string m_Name;      // 姓名
    string m_Num;       // 学号
    int m_CLange;       // C成绩
    int m_Algo;         // 算法
    int m_Database;     // 数据库成绩
    int m_Sum;          // 总成绩
};


struct Stu {
    struct Student data[MAX];    // 数组存储
    int m_Size = 0;               // 当前个数
};


// 菜单
void menu() {

    cout << "********* 学生管理系统 *************" << endl;
    cout << "********* 1.输入学生信息 ***********" << endl;
    cout << "********* 2.删除学生信息 ***********" << endl;
    cout << "********* 3.修改学生信息 ***********" << endl;
    cout << "********* 4.统计学生总数 ***********" << endl;
    cout << "********* 5.显示所有信息 ***********" << endl;
    cout << "********* 0.退出系统 ***************" << endl;
    cout << "************************************" << endl;

    cout << "请选择(0 - 7): ";
}


// 增加
void addStudent(Stu *p) {

    if (p->m_Size == MAX) {
        cout << "添加人数已满" << endl;
        return;
    } else {
        cout << "请输入姓名：" << endl;
        string name; cin >> name;
        p->data[p->m_Size].m_Name = name;

        cout << "请输入学号：" << endl;
        string num; cin >> num;
        p->data[p->m_Size].m_Num = num;

        cout << "请输入C语言成绩: " << endl;
        int clange; cin >> clange;
        p->data[p->m_Size].m_CLange = clange;

        cout << "请输入算法成绩：" << endl;
        int algo; cin >> algo;
        p->data[p->m_Size].m_Algo = algo;

        cout << "请输入数据库成绩：" << endl;
        int database; cin >> database;
        p->data[p->m_Size].m_Database = database;

        cout << "添加成功" << endl;  
        p->m_Size ++;
    }
}


// 检测联系人
int isExit(Stu *ppp, string name) {
    for (int i = 0; i < ppp->m_Size; i++)
        if (ppp->data[i].m_Name == name) 
            return i;
    
    return -1;
}

// 删除
void deleteStudent(Stu *p) {
    cout << "请输入您要删除的联系人：";
    string name; cin >> name;

    int ret = isExit(p, name);
    if (ret != -1) {
        for (int i = ret; i < p->m_Size; i++) {
            p->data[i] = p->data[i + 1];            // 删除
            p->m_Size --;                           // 更新人数
            cout << "删除成功" << endl;
        }
    } else cout << "查无此人" << endl;
}


// 修改
void modifyStudent(Stu *p) {
    cout << "请输入修改前的姓名：" << endl;
    string name; cin >> name;

    int ret = isExit(p, name);
    if (ret != -1) {
        cout << "请输入新的姓名：" << endl;
        string name; cin >> name;
        p->data[p->m_Size].m_Name = name;

        cout << "请输入新的学号：" << endl;
        string num; cin >> num;
        p->data[p->m_Size].m_Num = num;

        cout << "请输入新的C语言成绩: " << endl;
        int clange; cin >> clange;
        p->data[p->m_Size].m_CLange = clange;

        cout << "请输入新的算法成绩：" << endl;
        int algo; cin >> algo;
        p->data[p->m_Size].m_Algo = algo;

        cout << "请输入新的数据库成绩：" << endl;
        int database; cin >> database;
        p->data[p->m_Size].m_Database = database;
    } else cout << "查无此人" << endl;
}




// 统计
void totalStudent(Stu *p) {
    int total;
    if (p->m_Size == 0) cout << "没有学生" << endl;
    else { 
        for (int i = 0; i < p->m_Size; i++) total += i; 
               
        cout << "学生总人数：" << (total + 1) << endl;
    }
    
}


// 显示所有
void showStudent(Stu *p) {
    if (p->m_Size == 0) cout << "还没有学生信息" << endl;
    else {
        for (int i = 0; i < p->m_Size; i++) {
            p->data[i].m_Sum = p->data[i].m_CLange + 
                                   p->data[i].m_Algo + 
                                   p->data[i].m_Database;

            cout << "姓名：" << p->data[i].m_Name << "\t\t"
                 << "学号：" << p->data[i].m_Num << "\t\t"
                 << "C语言成绩: " << p->data[i].m_CLange << "\t\t"
                 << "算法成绩：" << p->data[i].m_Algo << "\t\t"
                 << "数据库成绩：" << p->data[i].m_Database << "\t\t"
                 << "总成绩：" << p->data[i].m_Sum << endl;
        }
    }
}



