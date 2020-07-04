#pragma once
#include<string.h>
#include<iostream>


//�û���
class User
{
public:

	virtual void Login();   //��Ϊ��ͬ���û�ʵ�ֲ�ͬ�ĵ�¼���棬����ʹ���麯��
	void Setflag(int i) { flag = i; }

	void SetUserName(char *s) { strcpy(Name, s); }   //�����û���
	void SetID(char *i) { strcpy(ID, i); }   //����ID
	void SetPassword(char *p) { strcpy(password, p); }   //��������
	void SetDegree(int i) { Degree = i; }   //������ݵȼ�

	char* GetName() { return Name; }
	char* GetID() { return ID; }
	char* GetPass() { return password; }
	int GetDegree() { return Degree; }
	int Getflag() { return flag; }
private:
	char Name[20];   //�û�����
	char ID[20];  //�û�ID
	char password[20];   //�û�����
	int Degree;   //�û��ȼ�
	int flag;   //���������Ƿ��иĿ�֪ͨ
};



//ѧ����
class Student:public User,public QueryInterface
{
public:
	virtual void Login();   //ѧ����¼����

	//�ӿ��ں�������
	void Query_StudentMessage();   //�鿴ѧ��������Ϣ
	void Query_CourseTimetable();   //ѧ����ȡ�Լ��Ŀα�
	void Query_Subject();   //ѧ����ѯ�ض��γ�
	void Check_ClassMessage();   //ѧ���鿴��Ϣ
};

//��ʦ��
class Teacher:public User,public ChargedInterface
{
public:
	virtual void Login();   //��ʦ��¼����

	//�ӿ��ں�������
	void Add();   //���ӿγ�
	void Delete();   //ɾ���γ�
	void Modify();   //�޸Ŀγ̣����ֻ�ʱ�䣩
};

