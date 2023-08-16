// 通用设置；通用功能性函数声明

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define INCOME "收入"
#define EXPAND "支出"
#define FILENAME "D:\\AAAb\\src\\AccountBook.txt"

using namespace std;


// 通用功能性函数声明
// 绘制菜单的函数
void showMainMenu ();   // 一级菜单
void showAccountingMenu (); // 记账菜单
void showQueryMenu ();  // 查询菜单


// 读取键盘输入进行合法性校验的函数
char readMenuSelection (int options);   // 判断键盘输入的合法性
char readQuitConfirm ();        // 退出输入的合法性
int readAmount ();      // 输入金额的合法性校验
