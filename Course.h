#pragma once
#include<string.h>

//�γ���
class Course
{
public:
	void SetID(const char* ID) { strcpy(CourseID, ID); }   //����ID
	void SetCourseName(const char *Name) { strcpy(CourseName, Name); }   //���ÿγ���
	void SetCourseTeacherID(const char *ID) { strcpy(CourseTeacherID, ID); }   //���ÿγ̽�ʦ���
	void SetCourseTime(int time) { CourseTime = time; }   //���ÿγ�ʱ��
	void SetCourseSession(int session) { CourseSession = session; }   //���ÿγ̽ڴ�

	char* GetCourseID() { return CourseID; }

	char CourseID[20];   //�γ�ID
	char CourseName[20];   //�γ���
	int CourseTime;   //�γ�ʱ��(�ܼ�)
	int CourseSession;   //�γ̽ڴΣ����һ�ڡ����Ľ�
	char CourseTeacherID[20];   //�γ̽�ʦ���
};