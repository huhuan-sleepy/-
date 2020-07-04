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

typedef vector<User> TypeUse;   //�����û�������
typedef vector<Course> TypeCourse;   //����γ�������



void gotoxy(int x, int y);   //��Ļ��궨λ����

void WelcomeImage();   //���ƻ�ӭ����

void UserLogin();   //��ʼ����¼����

void WriteUserMessage(TypeUse AllUse);   //�û���Ϣд�뺯��

TypeUse ReadUserFromFile();   //�û���Ϣ��ȡ����

void WriteCourseMessage(TypeCourse AllCourse);   //�γ���Ϣд�뺯��

TypeCourse ReadCourseFromFile();   //�γ���Ϣ��ȡ����

string InputPassword();   //�������뺯��

int CheckUserLogin(char *ID, string password);   //������뺯��
