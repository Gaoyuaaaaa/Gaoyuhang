#include "student.hpp"


int main(int argc, char *argv[])
{
    struct Stu stu;
    stu.m_Size = 0;     // 初始化个数

    int select = 0;

    while (true) {
        
        menu(); 
        
        cin >> select;

        switch (select) {
            case 1: addStudent(&stu); break;
            case 2: deleteStudent(&stu); break;
            case 3: modifyStudent(&stu); break;
            case 4: totalStudent(&stu); break;
            case 5: showStudent(&stu); break;
            case 0: exit(0); break;
            default: break;
        }

        // system("pause");
        // system("cls");
    }

    return 0;
}
