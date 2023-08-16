// 结构体定义；涉及账目操作的函数声明
#pragma once

#include "common.h"


struct AccountItem
{
    string itemType;    // 账目数据是什么类型，收入还是支出
    int amount;     // 金额
    string detail;  // 备注详情
};



// 针对账目数据进行操作的函数声明
void loadDataFromFile (vector<AccountItem>& items); // 加载账目数据

void accounting (vector<AccountItem>& items);   // 记账
void insertIntoFile (const AccountItem& item);  // 写入文件
void income (vector<AccountItem>& items);   // 记录一笔收入
void expand (vector<AccountItem>& items);   // 记录一笔支出


void query (const vector<AccountItem>& items);  // 查询
void printItem(AccountItem &item);  // 打印输出
void queryItems(const vector<AccountItem>& items);  // 查询账目功能
void queryItems(const vector<AccountItem>& items, const string itemType);   // 重载


