#pragma once
#include "Course.h"
#include "Interface.h"
#include "User.h"
#include<Windows.h>
#include<string>
#include<vector>
#include<conio.h>
#include<iomanip>
#include<graphics.h>
#include<fstream>

using namespace std;

typedef vector<User> TypeUse;   //定义用户类容器
typedef vector<Course> TypeCourse;   //定义课程类容器



void gotoxy(int x, int y);   //屏幕光标定位函数

void WelcomeImage();   //绘制欢迎界面

void UserLogin();   //初始化登录函数

void WriteUserMessage(TypeUse AllUse);   //用户信息写入函数

TypeUse ReadUserFromFile();   //用户信息读取函数

void WriteCourseMessage(TypeCourse AllCourse);   //课程信息写入函数

TypeCourse ReadCourseFromFile();   //课程信息读取函数

string InputPassword();   //密码输入函数

int CheckUserLogin(char *ID, string password);   //检测密码函数
