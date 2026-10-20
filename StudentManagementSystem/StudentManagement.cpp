#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Student
{
    string id;
    string name;
    int chinese;
    int math;
    int english;
};
int getTotalScore(const Student& s)
{
    return s.chinese + s.math + s.english;
}
void showMenu()
{
 cout<<"\n====学生成绩管理系统 -  Git学习版 ===="<<endl;
 cout<<"1.添加学生"<<endl;
 cout<<"2.显示所有学生"<<endl;
 cout<<"3.查询学生"<<endl;
 cout<<"4.修改学生信息"<<endl;
 cout<<"5.删除学生"<<endl;
 cout<<"6.成绩统计"<<endl;
 cout<<"7.按总分排序"<<endl;
 cout << "8. 保存学生信息" << endl;
cout << "9. 读取学生信息" << endl;
cout<<"0.退出系统"<<endl;
 cout<<"请选择：";

}

void addStudent(vector<Student>&Students)
{
 Student s;
cout<<"请输入学号：";
cin>>s.id;

cout<<"请输入姓名：";
cin>>s.name;

cout<<"请输入语文成绩: ";
cin>>s.chinese;
 while (s.chinese < 0 || s.chinese > 100)
    {
        cout << "成绩不合法，请输入 0~100 之间的成绩：";
        cin >> s.chinese;
    }

    cout<<"请输入数学成绩: ";
cin>>s.math;
 while (s.math < 0 || s.math > 100)
    {
        cout << "成绩不合法，请输入 0~100 之间的成绩：";
        cin >> s.math;
    }

    cout<<"请输入英语成绩: ";
cin>>s.english;
 while (s.english < 0 || s.english > 100)
    {
        cout << "成绩不合法，请输入 0~100 之间的成绩：";
        cin >> s.english;
    }
Students.push_back(s);

cout<<"学生添加成功！"<<endl;
}

void showStudents(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "当前没有学生信息！" << endl;
        return;
    }

    cout << "\n===== 学生信息列表 =====" << endl;

    for (int i = 0; i < students.size(); i++)
    {
        cout << "学号：" << students[i].id << endl;
        cout << "姓名：" << students[i].name << endl;
        cout << "语文：" << students[i].chinese << endl;
        cout << "数学：" << students[i].math << endl;
        cout << "英语：" << students[i].english << endl;
        cout << "总分：" << getTotalScore(students[i]) << endl;
        cout << "------------------------" << endl;
    
    }
}
void findStudent(const vector<Student>& students)
{
    string targetId;

    cout << "请输入要查询的学号：";
    cin >> targetId;

    bool found = false;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == targetId)
        {
            cout << "\n===== 查询结果 =====" << endl;
            cout << "学号：" << students[i].id << endl;
            cout << "姓名：" << students[i].name << endl;
            cout << "语文：" << students[i].chinese << endl;
            cout << "数学：" << students[i].math << endl;
            cout << "英语：" << students[i].english << endl;

            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout << "没有找到该学号对应的学生！" << endl;
    }
}
void modifyStudent(vector<Student>& students)
{
    string targetId;

    cout << "请输入要修改的学生学号：";
    cin >> targetId;

    bool found = false;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == targetId)
        {
            cout << "找到学生：" << students[i].name << endl;

            cout << "请输入新的姓名：";
            cin >> students[i].name;

            cout << "请输入新的语文成绩：";
            cin >> students[i].chinese;

            cout << "请输入新的数学成绩：";
            cin >> students[i].math;

            cout << "请输入新的英语成绩：";
            cin >> students[i].english;

            cout << "学生信息修改成功！" << endl;

            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout << "没有找到该学号对应的学生！" << endl;
    }
}
void deleteStudent(vector<Student>& students)
{
    string targetId;

    cout << "请输入要删除的学生学号：";
    cin >> targetId;

    bool found = false;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == targetId)
        {
            cout << "即将删除学生：" << students[i].name << endl;

            students.erase(students.begin() + i);

            cout << "学生删除成功！" << endl;

            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout << "没有找到该学号对应的学生！" << endl;
    }
}
void scoreStatistics(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "当前没有学生信息，无法统计！" << endl;
        return;
    }

    cout << "\n===== 学生成绩统计 =====" << endl;

    for (int i = 0; i < students.size(); i++)
    {
        int total = students[i].chinese
                  + students[i].math
                  + students[i].english;

        double average = total / 3.0;

        cout << "学号：" << students[i].id << endl;
        cout << "姓名：" << students[i].name << endl;
        cout << "总分：" << total << endl;
        cout << "平均分：" << average << endl;
        cout << "------------------------" << endl;
    }
}

void sortStudents(vector<Student>& students)
{
    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b)
        {
            return getTotalScore(a) > getTotalScore(b);
        });

    cout << "学生已按总分从高到低排序！" << endl;

    showStudents(students);
}
void saveStudents(const vector<Student>& students)
{
    ofstream ofs("StudentData.txt");

    if (!ofs.is_open())
    {
        cout << "文件打开失败，保存失败！" << endl;
        return;
    }

    for (int i = 0; i < students.size(); i++)
    {
        ofs << students[i].id << " "
            << students[i].name << " "
            << students[i].chinese << " "
            << students[i].math << " "
            << students[i].english << endl;
    }

    ofs.close();

    cout << "学生信息保存成功！" << endl;
}
void loadStudents(vector<Student>& students)
{
    ifstream ifs("StudentData.txt");

    if (!ifs.is_open())
    {
        // 第一次运行时文件可能还不存在
        return;
    }

    students.clear();

    Student s;

    while (ifs >> s.id
                >> s.name
                >> s.chinese
                >> s.math
                >> s.english)
    {
        students.push_back(s);
    }

    ifs.close();

    cout << "学生信息读取成功！当前共有 "
         << students.size() << " 名学生。" << endl;
}
int main()
{
    vector<Student> students;
     loadStudents(students);
     int choice = -1;

    while (choice != 0)
    {
        showMenu();
        cin >> choice;          

        switch (choice)
        {
        case 1:
            addStudent(students);
            break;
        case 2:
            showStudents(students);
            break;
        case 3:
            findStudent(students);
            break;
        case 4:
            modifyStudent(students);
            break;;
         case 5:
            deleteStudent(students);
            break;
        
        case 6:
            scoreStatistics(students);
            break;
        case 7:
            sortStudents(students);
            break;
        case 8:
            saveStudents(students);
             break;

        case 9:
            loadStudents(students);
            break;
        case 0:
            saveStudents(students);
            cout << "退出系统。" << endl;
            break;

        default:
            cout << "输入无效，请重新选择！" << endl;
            break;
        }
    }

    
    system("pause");
    return 0;
}