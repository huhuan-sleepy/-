#pragma once
#include "Course.h"

//定义具有改变课程权限的虚类
class ChargedInterface
{
public:
	virtual void Add() = 0;   //增加课程
	virtual void Delete() = 0;   //删除课程
	virtual void Modify() = 0;   //修改课程（名字或时间）
};

//定义具有查询课程权限的虚类
class QueryInterface
{
public:
	virtual void Query_StudentMessage() = 0;   //查看学生自身信息
	virtual void Query_CourseTimetable() = 0;   //获取自己的课表
	virtual void Query_Subject() = 0;   //查询特定课程
};