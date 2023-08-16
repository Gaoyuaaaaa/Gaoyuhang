// 读取输入函数

#include "common.h"


// 读取键盘输入的菜单选项，进行合法性校验
char readMenuSelection (int options) {
    string str;
    
    // 进行校验
    while (true) {
        getline(cin, str);
        if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options)   // 字符串可以当成字符数组使用
            cout << "输入错误，请从新选择：";
        else 
            break;
    }

    return str[0];  //输入合法，返回当前选择的字符
}


// 读取确认退出信息，并作校验
char readQuitConfirm () {
    string str;
    
    // 进行校验，逻辑与优先级高于逻辑或，进行大小与转换，大小写的y都可以
    while (true) {
        getline(cin, str);
        if (str.size() != 1 || toupper(str[0]) != 'Y' && toupper(str[0]) != 'N') 
            cout << "输入错误，请从新输入(Y/N): ";
        else break;
    }

    return toupper(str[0]);
}


// 读取键盘输入的金额，并作合法性校验
int readAmount () {
    int amount;
    string str;
    while (true) {
        getline(cin, str);
        
        try {
            amount = stoi(str); // 校验，将字符传换成int型
            break;
        } catch (invalid_argument e) {      // invalid_argument - 非法的参数
            cout << "输入错误，请正确输入数字：";
        }
    }
    return amount;
}

