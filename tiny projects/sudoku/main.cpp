
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <time.h>
using namespace std;

class Menu      //菜单类
{
public:
    string number;
    string name;
    string price;
    string discount;
    Menu(string a,string b,string c,string d) {number=a,name=b,price=c,discount=d;}
    void out_file(string file_name);
    void cout_menu();
    bool operator < (const Menu& a) const{
        return atoi(number.c_str())<atoi((a.number).c_str());
    }
};

class Base_orders   //订单基类
{
public:
    string order_number;
    string dish_number;
    string dish_name;
    string dish_price;
    string dish_discount;
    int amount;
    double total_price=0;
    void out_file_eachDish(string file_name);
    void cout_orders();
};

class Takeaway_orders:public Base_orders    //外卖订单类
{
public:
    string takeaway_time,takeaway_place,takeaway_phone;
    int takeaway_delivery_fee=10;
    Takeaway_orders(string a,string b,string c,string d,string e,int j) {order_number=a,dish_number=b,dish_name=c,dish_price=d,dish_discount=e,amount=j;}
    bool operator < (const Takeaway_orders& a) const{
        return atoi(dish_number.c_str())<atoi((a.dish_number).c_str());
    }
};

class Atshop_orders:public Base_orders      //在店消费订单类
{
public:
    int atshop_room_fee=0;
    string atshop_table;
    Atshop_orders(string a,string b,string c,string d,string e,int h) {order_number=a,dish_number=b,dish_name=c,dish_price=d,dish_discount=e,amount=h;}
    bool operator < (const Atshop_orders& a) const{
        return atoi(dish_number.c_str())<atoi((a.dish_number).c_str());
    }
};

class Interface     //交互界面类
{
public:
    static int choose();
    static void administrator_show();
    static void customer_show();
};

class Customer      //顾客类
{
private:
    vector<Takeaway_orders> vec_Takeaway_orders;
    vector<Atshop_orders> vec_Atshop_orders;
public:
    string order_number;
    void order();
};

class Administrator //管理员类
{
private:
    vector <Menu> vec_menu;
    vector<Takeaway_orders> total_Takeaway_orders;
    vector<Atshop_orders> total_Atshop_orders;
public:
    void find_orders();
    void modify_orders();
    void delete_orders();
    void import_menu();
    void add_menu();
    void modify_menu();
    void delete_menu();
    void find_menu();
    void sales_statistics();
};

class Manage    //系统类
{
private:
    Customer customer;
    Administrator administrator;
public:
    void manage();
};




#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <time.h>
//#include <windows.h>
#include <iomanip>
#include <algorithm>


void Manage::manage()
{
    administrator.import_menu();    //菜单全部从文件写入到vector容器中
    int today_order_number=0;       //记录日销售编号，后面生成订单编号有用
    for(;;)
    {
        int Return=Interface::choose();
        if(Return==1)
        {
            Interface::administrator_show();
            int admin_op;
            cin>>admin_op;
            if(admin_op==1)
                administrator.find_orders();
            if(admin_op==2)
            {
                administrator.modify_orders();
                remove("temp.txt");
            }
            if(admin_op==3)
            {
                administrator.delete_orders();
                remove("temp.txt");
            }
            if(admin_op==4)
                administrator.add_menu();
            if(admin_op==5)
                administrator.modify_menu();
            if(admin_op==6)
                administrator.delete_menu();
            if(admin_op==7)
                administrator.find_menu();
            if(admin_op==8)
                administrator.sales_statistics();
            if(admin_op==9)
                Interface::customer_show();
        }

        else if(Return==2)
        {
            today_order_number++;
            if(today_order_number<10)
                customer.order_number="00"+to_string(today_order_number);
            else if(today_order_number>=10&&today_order_number<100)
                customer.order_number="0"+to_string(today_order_number);
            else if(today_order_number>=100&&today_order_number<1000)
                customer.order_number=to_string(today_order_number);

            Interface::customer_show();
            customer.order();
        }

        int manage_op;
        cout<<"是否继续：1.继续    2.退出"<<endl;
        cin>>manage_op;
        cout<<endl;
        if(manage_op==2)
            break;
    }

    //当天结束创建当天的菜单，最后统计历史菜品销售情况需要用到
    SYSTEMTIME st = {0};
    GetLocalTime(&st);
    int date=((st.wYear*100+st.wMonth)*100+st.wDay);

    string file_name=to_string(date)+"_menu.txt";
    ifstream fin("menu.txt");
    ofstream out(file_name,ios::app);
    string str;
    while(getline(fin,str))
    {
        out<<str<<endl;
    }
}

int Interface::choose()
{
    int op1;
    string account_number;
    string password;
    ifstream fin("account_number&password.txt");
    cout<<"请选择身份：1.管理员    2.顾客"<<endl;
    cin>>op1;
    if(op1==1)
    {
        string file_account_number;
        string file_password;
        string str;
        getline(fin,str);
        getline(fin,file_account_number);
        getline(fin,str);
        getline(fin,file_password);

        cout<<"请输入账号：";
        cin>>account_number;
        cout<<"请输入密码：";
        cin>>password;

        if(file_account_number==account_number&&file_password==password) //通过和文件中的用户名和密码对照
        {
            return 1;
        }
        else
        {
            cout<<"账号或密码输入错误"<<endl;
        }
    }
    else if(op1==2)
    {
        return 2;
        //顾客直接进入点餐界面
    }
    return 0;
}

void Interface::administrator_show()
{
    cout<<"请选择操作（菜单修改请务必在每天营业前）："<<endl;
    cout<<"1.查找订单             2.修改订单             3.删除订单"<<endl;
    cout<<"4.菜品/价格/折扣增加   5.菜品/价格/折扣修改   6.菜品/价格/折扣删除   7.菜品/价格/折扣查找"<<endl;
    cout<<"8.销售情况统计"<<endl;
    cout<<"9.菜单展示"<<endl;
    cout<<"0.退出"<<endl;
}

void Interface::customer_show()
{
    ifstream fin("menu.txt");
    string str;
    cout<<"菜单："<<endl;
    cout<<std::left<<setw(15)<<"number\t"<<std::left<<setw(21)<<"name\t"<<std::left<<setw(16)<<"price"<<std::left<<setw(15)<<"discount"<<endl;
    while(getline(fin,str))
        cout<<str<<endl;
    fin.close();
}

void Menu::out_file(string file_name)
{
    ofstream out(file_name,ios::app);
    out<<std::left<<setw(15)<<number<<"\t";
    out<<std::left<<setw(20)<<name<<"\t";
    out<<std::left<<setw(15)<<price<<"\t";
    out<<std::left<<setw(15)<<discount<<endl;
}

void Menu::cout_menu()
{
    cout<<std::left<<setw(15)<<number;
    cout<<std::left<<setw(20)<<name;
    cout<<std::left<<setw(15)<<price;
    cout<<std::left<<setw(15)<<discount<<endl;
}

void Base_orders::out_file_eachDish(string file_name)
{
    ofstream out(file_name,ios::app);
    out<<std::left<<setw(15)<<dish_number<<"\t";
    out<<std::left<<setw(20)<<dish_name<<"\t";
    out<<std::left<<setw(15)<<dish_price<<"\t";
    out<<std::left<<setw(15)<<dish_discount<<"\t";
    out<<std::left<<setw(15)<<amount<<endl;
}

void Base_orders::cout_orders()
{
    cout<<std::left<<setw(15)<<dish_number<<"\t";
    cout<<std::left<<setw(20)<<dish_name<<"\t";
    cout<<std::left<<setw(15)<<dish_price<<"\t";
    cout<<std::left<<setw(15)<<dish_discount<<"\t";
    cout<<std::left<<setw(15)<<amount<<endl;
}

void Customer::order()
{
    int consume_op;
    int room_op;
    string atshop_tab;
    string takeaway_tim,takeaway_plac,takeaway_phon;
    double total_pric=0;
    double atshop_room_fe=0;
    double takeaway_delivery_fe=0;
    int date;
    string dish_num;
    int dish_amount;
    string dish_nam;
    string dish_pri;
    string dish_disc;

    SYSTEMTIME st = {0};
    GetLocalTime(&st);
    date=((st.wYear*100+st.wMonth)*100+st.wDay);
    order_number=to_string(date)+order_number;

    string file_name=to_string(date)+".txt";
    ifstream fin("menu.txt");
    ofstream out(file_name,ios::app);

    cout<<"请选择消费方式：1.在店消费  2.外卖"<<endl;
    cin>>consume_op;

    cout<<"请输入所选择的菜品序号和份数（操作指南：输入'0 0'表示完成点餐）："<<endl;
    vec_Takeaway_orders.clear();
    vec_Atshop_orders.clear();

    string str;

    for(;;)
    {
        cin>>dish_num>>dish_amount;
        int i=0;
        int flag=0;
        ifstream fin2("menu.txt");
        while(fin2>>str)
        {
            i++;
            if(i==1)
            {
                if(dish_num==str)
                    flag=1;
            }
            if(flag==1)
            {
                if(i==2)
                    dish_nam=str;
                if(i==3)
                    dish_pri=str;
                if(i==4)
                {
                    dish_disc=str;
                    if(consume_op==1)
                    {
                        Atshop_orders atshop_ord(order_number,dish_num,dish_nam,dish_pri,dish_disc,dish_amount);
                        vec_Atshop_orders.push_back(atshop_ord);
                        sort(vec_Atshop_orders.begin(),vec_Atshop_orders.end());
                    }
                    else if(consume_op==2)
                    {
                        Takeaway_orders takeaway_ord(order_number,dish_num,dish_nam,dish_pri,dish_disc,dish_amount);
                        vec_Takeaway_orders.push_back(takeaway_ord);
                        sort(vec_Takeaway_orders.begin(),vec_Takeaway_orders.end());
                    }
                    flag=0;
                }
            }
            if(i==4)
                i=0;
        }
        if(dish_num=="0"&&dish_amount==0)
            break;
    }

    if(consume_op==1)
    {
        cout<<"请选择餐桌号："<<endl;
        cin>>atshop_tab;
        cout<<"是否包厢：1.是     2.否"<<endl;
        cin>>room_op;
        if(room_op==1)
            atshop_room_fe=100;
    }
    else if(consume_op==2)
    {
        takeaway_delivery_fe=10;
        cout<<"请输入送餐时间、送餐地点、手机号："<<endl;
        cin>>takeaway_tim>>takeaway_plac>>takeaway_phon;
    }

    total_pric=atshop_room_fe+takeaway_delivery_fe;

    if(consume_op==1)
    {
        for(int i=0;i<vec_Atshop_orders.size();i++)
        {
            vec_Atshop_orders[i].atshop_table=atshop_tab;
            vec_Atshop_orders[i].atshop_room_fee=atshop_room_fe;
            total_pric+=atof((vec_Atshop_orders[i].dish_price).c_str())*atof((vec_Atshop_orders[i].dish_discount).c_str())*vec_Atshop_orders[i].amount;
        }
        for(int i=0;i<vec_Atshop_orders.size();i++)
        {
            vec_Atshop_orders[i].total_price=total_pric;
        }
        out<<"编号："<<endl;
        out<<order_number<<endl;
        out<<"所点菜单："<<endl;
        out<<std::left<<setw(23)<<"number\t"<<std::left<<setw(21)<<"name\t"<<std::left<<setw(22)<<"price\t"<<std::left<<setw(25)<<"discount\t"<<std::left<<setw(16)<<"amount"<<endl;
        for(int i=0;i<vec_Atshop_orders.size();i++)
            vec_Atshop_orders[i].out_file_eachDish(file_name);
        out<<"餐桌号： "<<atshop_tab<<endl;
        if(room_op==1)
            out<<"是否有包厢费： 是"<<endl<<"包厢费： "<<atshop_room_fe<<endl;
        if(room_op==2)
            out<<"是否有包厢费： 否"<<endl;
        out<<"总价： "<<setiosflags(ios::fixed)<<setprecision(2)<<total_pric<<endl<<endl;

        cout<<endl<<"编号："<<endl;
        cout<<order_number<<endl;
        cout<<"所点菜单："<<endl;
        cout<<std::left<<setw(15)<<"number\t"<<std::left<<setw(21)<<"name\t"<<std::left<<setw(16)<<"price"<<std::left<<setw(16)<<"discount"<<std::left<<setw(16)<<"amount"<<endl;
        for(int i=0;i<vec_Atshop_orders.size();i++)
            vec_Atshop_orders[i].cout_orders();
        cout<<"餐桌号： "<<atshop_tab<<endl;
        if(room_op==1)
            cout<<"是否有包厢费： 是"<<endl<<"包厢费： "<<atshop_room_fe<<endl;
        if(room_op==2)
            cout<<"是否有包厢费： 否"<<endl;
        cout<<"总价： "<<setiosflags(ios::fixed)<<setprecision(2)<<total_pric<<endl<<endl;
    }
    else if(consume_op==2)
    {
        for(int i=0;i<vec_Takeaway_orders.size();i++)
        {
            vec_Takeaway_orders[i].takeaway_time=takeaway_tim;
            vec_Takeaway_orders[i].takeaway_place=takeaway_plac;
            vec_Takeaway_orders[i].takeaway_phone=takeaway_phon;
            total_pric+=atof((vec_Takeaway_orders[i].dish_price).c_str())*atof((vec_Takeaway_orders[i].dish_discount).c_str())*vec_Takeaway_orders[i].amount;
        }
        for(int i=0;i<vec_Takeaway_orders.size();i++)
        {
            vec_Takeaway_orders[i].total_price=total_pric;
        }

        out<<"编号："<<endl;
        out<<order_number<<endl;
        out<<"所点菜单："<<endl;
        out<<std::left<<setw(23)<<"number\t"<<std::left<<setw(21)<<"name\t"<<std::left<<setw(22)<<"price\t"<<std::left<<setw(25)<<"discount\t"<<std::left<<setw(16)<<"amount"<<endl;
        for(int i=0;i<vec_Takeaway_orders.size();i++)
            vec_Takeaway_orders[i].out_file_eachDish(file_name);
        out<<"送餐时间： "<<takeaway_tim<<endl;
        out<<"送餐地点： "<<takeaway_plac<<endl;
        out<<"联系电话： "<<takeaway_phon<<endl;
        out<<"外卖服务费： "<<takeaway_delivery_fe<<endl;
        out<<"总价： "<<setiosflags(ios::fixed)<<setprecision(2)<<total_pric<<endl<<endl;

        cout<<endl<<"编号："<<endl;
        cout<<order_number<<endl;
        cout<<"所点菜单："<<endl;
        cout<<std::left<<setw(15)<<"number\t"<<std::left<<setw(21)<<"name\t"<<std::left<<setw(16)<<"price"<<std::left<<setw(16)<<"discount"<<std::left<<setw(16)<<"amount"<<endl;
        for(int i=0;i<vec_Takeaway_orders.size();i++)
            vec_Takeaway_orders[i].cout_orders();
        cout<<"送餐时间： "<<takeaway_tim<<endl;
        cout<<"送餐地点： "<<takeaway_plac<<endl;
        cout<<"联系电话： "<<takeaway_phon<<endl;
        cout<<"外卖服务费： "<<takeaway_delivery_fe<<endl;
        cout<<"总价： "<<setiosflags(ios::fixed)<<setprecision(2)<<total_pric<<endl<<endl;
    }
};

void Administrator::find_orders()
{
    string find_orders_date;
    string find_orders_number;
    cout<<"请输入要操作的日期："<<endl;
    cin>>find_orders_date;
    string file_name=find_orders_date+".txt";
    cout<<"请输入要查找的订单号："<<endl;
    cin>>find_orders_number;
    ifstream fin(file_name);
    string str;
    int flag=0;
    cout<<"编号："<<endl;
    int cout_num=0;
    while(getline(fin,str))
    {
        if(str==find_orders_number)
        {
            flag=1;
        }
        if(str=="编号：")
        {
            flag=0;
        }
        if(flag==1&&cout_num!=2)
        {
            cout<<str<<endl;
            cout_num++;
            continue;
        }
        if(cout_num==2)
        {
            cout<<std::left<<setw(15)<<"number\t"<<std::left<<setw(21)<<"name\t"<<std::left<<setw(16)<<"price"<<std::left<<setw(16)<<"discount"<<std::left<<setw(16)<<"amount"<<endl;
            cout_num++;
        }
    }
}

void Administrator::modify_orders()
{
    string find_orders_date;
    string find_orders_number;
    cout<<"请输入要操作的日期："<<endl;
    cin>>find_orders_date;
    string file_name=find_orders_date+".txt";
    cout<<"请输入要修改的订单号："<<endl;
    cin>>find_orders_number;
    ifstream fin(file_name);
    ofstream out("temp.txt",ios::app);
    string str;
    int flag=0;
    while(getline(fin,str))
    {
        if(str==find_orders_number)
        {
            out<<str<<endl;
            flag=1;
        }

        if(str=="编号：")
        {
            flag=0;
        }

        if(flag==0)
        {
            out<<str<<endl;
        }

        if(flag==1)
        {
            cout<<"请输入修改后的订单："<<endl;
            cout<<"编号："<<endl<<str<<endl;
            string modify_str;
            int exit_flag=1;
            while(exit_flag==1)
            {
                cin.ignore();
                getline(cin,modify_str);
                out<<modify_str<<endl;
                cout<<"是否继续：1.继续    2.退出"<<endl;
                cin>>exit_flag;
            }
            out<<endl;
            flag=2;
        }
    }
    fstream file(file_name, ios::out);
    ifstream fin2("temp.txt");
    ofstream out2(file_name,ios::app);
    while(getline(fin2,str))
    {
        out2<<str<<endl;
    }
}

void Administrator::delete_orders()
{
    string find_orders_date;
    string find_orders_number;
    cout<<"请输入要操作的日期："<<endl;
    cin>>find_orders_date;
    string file_name=find_orders_date+".txt";
    cout<<"请输入要删除的订单号："<<endl;
    cin>>find_orders_number;
    ifstream fin(file_name);
    ofstream out("temp.txt",ios::app);
    string str;
    int flag=0;
    int total_orders=0;
    while(getline(fin,str))
    {
        if(str==find_orders_number)
        {
            flag=1;
        }

        if(flag==0)
        {
            out<<str<<endl;
        }

        if(str=="编号：")
        {
            total_orders++;
            flag=0;
        }
    }
    fstream file(file_name, ios::out);
    ifstream fin2("temp.txt");
    ofstream out2(file_name,ios::app);
    int out_bianhao=0;
    while(getline(fin2,str))
    {
        if(str=="编号：")
            out_bianhao++;
        if(out_bianhao==total_orders)
            continue;
        out2<<str<<endl;
    }
}

void Administrator::sales_statistics()
{
    string find_orders_date;
string find_orders_number;
int statistics_total_orders=0;
    double statistics_total_money=0,statistics_takeaway_money=0,statistics_atshop_money=0,statistics_takeaway_percent=0,statistics_atshop_percent=0;
    map<string,int> each_dish;
    cout<<"请输入要统计的日期："<<endl;
    cin>>find_orders_date;
    string file_name=find_orders_date+".txt";
    ifstream fin(file_name);
    string str;
    string each_dish_str;
    each_dish.clear();
    int flag=0;
    int flag_takeaway=0;
    int flag_atshop=0;
    int flag_each_dish=0;
    int i=0;
    while(fin>>str)
    {
        if(str=="编号：")
        {
            statistics_total_orders++;
        }

        if(flag==1&&flag_takeaway==1)
        {
            statistics_total_money+=stof(str);
            statistics_takeaway_money+=stof(str);
            flag=0;
            flag_takeaway=0;
        }

        if(flag==1&&flag_atshop==1)
        {
            statistics_total_money+=stof(str);
            statistics_atshop_money+=stof(str);
            flag=0;
            flag_atshop=0;
        }

        if(str=="总价：")
        {
            flag=1;
        }

        if(str=="送餐时间：")
        {
            flag_takeaway=1;
        }

        if(str=="餐桌号：")
        {
            flag_atshop=1;
        }

        if(flag_each_dish==1)
        {
            i++;
            if(str=="送餐时间："||str=="餐桌号：")
            {

                flag_each_dish=0;
            }
            if(i==1&&flag_each_dish==1)
            {
                each_dish_str=str;
            }
            if(i==5&&flag_each_dish==1)
            {
                each_dish[each_dish_str]+=atoi(str.c_str());
                i=0;
            }

        }

        if(str=="amount")
        {
            flag_each_dish=1;
            i=0;
        }

    }
    statistics_takeaway_percent=statistics_takeaway_money/statistics_total_money;
    statistics_atshop_percent=statistics_atshop_money/statistics_total_money;
    cout<<"销售情况："<<endl;
    cout<<"接单总数："<<statistics_total_orders<<endl;
    cout<<"总销售额："<<setiosflags(ios::fixed)<<setprecision(2)<<statistics_total_money<<endl;
    cout<<"外卖销售额占比："<<setiosflags(ios::fixed)<<setprecision(2)<<statistics_takeaway_percent<<endl;
    cout<<"在店销售额占比："<<setiosflags(ios::fixed)<<setprecision(2)<<statistics_atshop_percent<<endl;
    cout<<"各个菜品销售情况："<<endl;

    file_name=find_orders_date+"_menu.txt";
    ifstream fin2(file_name);

    i=0;

    while(fin2>>str)
    {
        i++;
        if(i==1)
        {
            cout<<std::left<<setw(16)<<str;
            each_dish_str=str;
        }

        else if(i==2)
            cout<<std::left<<setw(16)<<str;

        else if(i==3)
            cout<<std::left<<setw(16)<<str;

        else if(i==4)
        {
            cout<<std::left<<setw(16)<<str;
            cout<<each_dish[ each_dish_str ]<<endl;
            i=0;
        }
    }
}

void Administrator::import_menu()
{

    ifstream fin("menu.txt");
    string str;
    string number,name,price,discount;
    int i=0;
    while(fin>>str)
    {
        if(i==0)
        {
            number=str;
            i++;
        }
        else if(i==1)
        {
            name=str;
            i++;
        }
        else if(i==2)
        {
            price=str;
            i++;
        }
        else if(i==3)
        {
            discount=str;
            i=0;
            Menu menu(number,name,price,discount);
            vec_menu.push_back(menu);
        }
    }
}

void Administrator::add_menu()
{
    string number,name,price,discount;
    cout<<"请依次输入要添加的菜品的序号、名称、价格、折扣；"<<endl;
    cin>>number>>name>>price>>discount;
    Menu menu(number,name,price,discount);
    vec_menu.push_back(menu);
    sort(vec_menu.begin(),vec_menu.end());
    menu.out_file("menu.txt");
}

void Administrator::modify_menu()
{
    string modify_menu_num_str;
    int modify_menu_num_int;
    string number,name,price,discount;

    cout<<"请输入需要修改的菜品/价格/折扣序号："<<endl;
    cin>>modify_menu_num_str;
    modify_menu_num_int=atoi(modify_menu_num_str.c_str());
    vec_menu.erase(vec_menu.begin() + (modify_menu_num_int-1));

    cout<<"请输入修改后的菜品名称、价格、折扣："<<endl;
    cout<<modify_menu_num_str<<"  ";
    cin>>name>>price>>discount;
    Menu menu(modify_menu_num_str,name,price,discount);
    vec_menu.push_back(menu);

    sort(vec_menu.begin(),vec_menu.end());

    fstream file("menu.txt", ios::out);
    for(int i=0;i<vec_menu.size();i++)
    {
        vec_menu[i].out_file("menu.txt");
    }
}

void Administrator::delete_menu()
{
    string delete_menu_num_str;
    int delete_menu_num_int;
    cout<<"请输入需要删除的菜品序号："<<endl;
    cin>>delete_menu_num_str;
    delete_menu_num_int=atoi(delete_menu_num_str.c_str());

    for(int i=vec_menu.size()-1;i>=delete_menu_num_int;i--)
    {
        vec_menu[i].number=vec_menu[i-1].number;
    }

    vec_menu.erase(vec_menu.begin() + (delete_menu_num_int-1));

    sort(vec_menu.begin(),vec_menu.end());

    fstream file("menu.txt", ios::out);
    for(int i=0;i<vec_menu.size();i++)
    {
        vec_menu[i].out_file("menu.txt");
    }
}

void Administrator::find_menu()
{
    int find_menu_num_int;
    cout<<"请输入需要查找的菜品序号："<<endl;
    cin>>find_menu_num_int;
    vec_menu[find_menu_num_int-1].cout_menu();
}

main.cpp:
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
#include "system.h"
using namespace std;
int main()
{
    Manage M;
    M.manage();
    return 0;
}
