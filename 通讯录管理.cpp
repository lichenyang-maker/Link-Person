#include <iostream>
#include <string>

#define Max_Size 1000

using namespace std;

// 结构体

struct Person
{
    string m_name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

// 通讯录结构体

struct AddressBooks
{
    struct Person personArray[Max_Size];
    int m_Size;
};

/*
函数名： showMenu
功能：显示菜单
*/

void showMenu()
{
    cout << "*************************" << endl;
    cout << "*****  1.添加联系人  *****" << endl;
    cout << "*****  2.显示联系人  *****" << endl;
    cout << "*****  3.删除联系人  *****" << endl;
    cout << "*****  4.查找联系人  *****" << endl;
    cout << "*****  5.修改联系人  *****" << endl;
    cout << "*****  6.清空联系人  *****" << endl;
    cout << "*****  0.退出通讯录  *****" << endl;
    cout << "*************************" << endl;
}

/*
函数名：AddPerson
功能：添加联系人
*/

void AddPerson(AddressBooks *abs)
{
    // 判断通讯录是否已满
    if (abs->m_Size == Max_Size)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        // 添加具体联系人
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_name = name;
        cout << "请输入性别" << endl;
        cout << "1----男" << endl;
        cout << "2----女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
        if (sex==1 || sex==2)
        {
        abs->personArray[abs->m_Size].m_Sex = sex;
        break;
        }
        else
        {
            cout << "输入有误，请重新输入" << endl;

        }
        }
        cout << "请输入年龄" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;
        cout << "请输入电话" << endl;
        string phone;
        cin >> phone;
        abs -> personArray[abs->m_Size].m_Phone = phone;
        cout << "请输入地址" << endl;
        string addr;
        cin >> addr;
        abs -> personArray[abs->m_Size].m_Addr = addr;
        abs->m_Size++;
        cout << "添加成功" << endl;
        system("pause");//请按任意键继续
        system("cls");//清屏
    }
    return ;
}

/*
退出功能
*/

void exitSystem()
{
    system("pause");
    exit(0);
}

/*函数名 ：Show_person
功能：显示联系人
参数 ：通讯录结构体
返回值：无
*/

void Show_person (AddressBooks *abs)
{
    //判断通讯录中人数是否为0
    if (abs -> m_Size == 0)
    {
        cout <<"当前记录为0" << endl;
        cout <<"请输入数据" << endl;
    }
    else
    {
        for (int i = 0;i < abs -> m_Size;i++)
        {
            cout <<"姓名" << abs -> personArray[i].m_name << "\t";
            cout <<"性别" << (abs -> personArray[i].m_Sex == 1 ? "男":"女")<< "\t";
            cout <<"年龄" << abs -> personArray[i].m_Age << "\t";
            cout <<"电话" << abs -> personArray[i].m_Phone << "\t";
            cout <<"地址" << abs -> personArray[i].m_Addr << "\t";
        }
    }
    system("pause");
    system("cls");
    return ;
}

//检测联系人是否存在，如果存在返回联系人所在数组中的具体位置，不存在返回-1
//参数一 通讯录选择  参数二 联系人姓名
int isExit (AddressBooks *abs,string name)
{
    for (int i = 0;i < abs -> m_Size;i++)
     {
        //找到用户输入姓名
        if (abs -> personArray[i].m_name == name)
        {
            return i;
        }
     }
     return -1;
     //没找到
}

/*
函数名 ：DelPerson
功能：删除联系人
*/

void DelPerson (AddressBooks *abs)
{
    cout << "请输入要删除的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExit (abs,name);
    if (ret == -1)
    {
        cout << "查无此人"  << endl;
    }
    else
    {
        for (int i = ret;i < abs -> m_Size;i++)
        {
            abs -> personArray[i] = abs -> personArray[i + 1];
        }
    }
    abs -> m_Size--;
    cout << "删除成功" << endl;
    system("pause");
    system("cls");
    return ;
}

// 函数名 FindPerson
// 功能：查找联系人

void FindPerson(AddressBooks *abs)
{
    cout <<
}

int main()
{
    system ("chcp 65001");
    // 创建通讯录结构体变量
    AddressBooks abs;
    // 初始化通讯录中人员个数
    abs.m_Size = 0;

    int select = 0; // 创建用户选择输入的变量

    // 菜单
    showMenu();
    cin >> select;
    while (true)
    {
        switch (select)
        {
        case 1:
            // 添加联系人
            AddPerson(&abs);
            break;
        case 2:
            // 显示联系人
            Show_person(&abs);
            break;
        case 3:
            // 删除联系人
            DelPerson(&abs);
            break;
        case 4:
            // 查找联系人
            break;
        case 5:
            // 修改联系人
            break;
        case 6:
            // 清空联系人
            break;
        case 0:
            // 退出通讯录
            cout << "欢迎下次使用" << endl;
            exitSystem();
            return 0;
        }
        
    }
    return 0;
}
