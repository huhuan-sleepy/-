#pragma once
#include<string.h>

//课程类
class Course
{
public:
	void SetID(const char* ID) { strcpy(CourseID, ID); }   //设置ID
	void SetCourseName(const char *Name) { strcpy(CourseName, Name); }   //设置课程名
	void SetCourseTeacherID(const char *ID) { strcpy(CourseTeacherID, ID); }   //设置课程教师编号
	void SetCourseTime(int time) { CourseTime = time; }   //设置课程时间
	void SetCourseSession(int session) { CourseSession = session; }   //设置课程节次

	char* GetCourseID() { return CourseID; }

	char CourseID[20];   //课程ID
	char CourseName[20];   //课程名
	int CourseTime;   //课程时间(周几)
	int CourseSession;   //课程节次，如第一节、第四节
	char CourseTeacherID[20];   //课程教师编号
};