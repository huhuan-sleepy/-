#pragma once
#include "Course.h"

//������иı�γ�Ȩ�޵�����
class ChargedInterface
{
public:
	virtual void Add() = 0;   //���ӿγ�
	virtual void Delete() = 0;   //ɾ���γ�
	virtual void Modify() = 0;   //�޸Ŀγ̣����ֻ�ʱ�䣩
};

//������в�ѯ�γ�Ȩ�޵�����
class QueryInterface
{
public:
	virtual void Query_StudentMessage() = 0;   //�鿴ѧ��������Ϣ
	virtual void Query_CourseTimetable() = 0;   //��ȡ�Լ��Ŀα�
	virtual void Query_Subject() = 0;   //��ѯ�ض��γ�
};