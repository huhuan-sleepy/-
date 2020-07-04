#pragma once
#include<string.h>
#include<iostream>


//用户类
class User
{
public:

	virtual void Login();   //因为不同的用户实现不同的登录界面，所以使用虚函数
	void Setflag(int i) { flag = i; }

	void SetUserName(char *s) { strcpy(Name, s); }   //设置用户名
	void SetID(char *i) { strcpy(ID, i); }   //设置ID
	void SetPassword(char *p) { strcpy(password, p); }   //设置密码
	void SetDegree(int i) { Degree = i; }   //设置身份等级

	char* GetName() { return Name; }
	char* GetID() { return ID; }
	char* GetPass() { return password; }
	int GetDegree() { return Degree; }
	int Getflag() { return flag; }
private:
	char Name[20];   //用户姓名
	char ID[20];  //用户ID
	char password[20];   //用户密码
	int Degree;   //用户等级
	int flag;   //用来表明是否有改课通知
};



//学生类
class Student:public User,public QueryInterface
{
public:
	virtual void Login();   //学生登录函数

	//接口内函数声明
	void Query_StudentMessage();   //查看学生自身信息
	void Query_CourseTimetable();   //学生获取自己的课表
	void Query_Subject();   //学生查询特定课程
	void Check_ClassMessage();   //学生查看消息
};

//教师类
class Teacher:public User,public ChargedInterface
{
public:
	virtual void Login();   //教师登录函数

	//接口内函数声明
	void Add();   //增加课程
	void Delete();   //删除课程
	void Modify();   //修改课程（名字或时间）
};

