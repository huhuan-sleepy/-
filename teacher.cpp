#include "AllHead.h"

void Teacher::Login()   //��ʦ��¼����
{
	system("color F5");
	system("cls");
	Teacher t;
	while (1)
	{
		system("cls");
		char choose;
		cout << endl;
		puts("	------------------------------------------------");
		puts("  ---            ��ʦ�û�����                     ");
		puts("  ---                                             ");
		puts("  ---              1.���ӿγ�                     ");
		puts("  ---              2.ɾ���γ�                     ");
		puts("  ---              3.�޸Ŀγ�                     ");
		puts("  ---              0.�˳�                         ");
		puts("  ---                                             ");
		puts("  ---                                             ");
		puts("	------------------------------------------------");
		cout << "����ѡ����:";
		cin >> choose;
		switch (choose)
		{
		case('1'):
			t.Add();
			getch();
			break;
		case('2'):
			t.Delete();
			getch();
			break;
		case('3'):
			t.Modify();
			getch();
			break;
		case('0'):
			system("cls");
			return;
			break;
		default:
			puts("����������0-3");
			Sleep(2500);
		}
	}
}

void Teacher::Add()  //���ӿγ�
{
	char CourseID[20];   //�γ�ID
	char CourseName[20];   //�γ���
	int CourseTime;   //�γ�ʱ��(�ܼ�)
	int CourseSession;   //�γ̽ڴΣ����һ�ڡ����Ľ�
	char CourseTeacherID[20];   //�γ̽�ʦ���
	TypeCourse AllCourse;
	AllCourse = ReadCourseFromFile();
	Course c;
	cout << "������γ�����";
	cin >> CourseName;
	cout << "�������ʦID��";
	cin >> CourseTeacherID;
	cout << "������γ�ID��";
	cin >> CourseID;
	cout << "������γ�ʱ�䣺";
	cin >> CourseTime;
	cout << "������γ̽ڴΣ�";
	cin >> CourseSession;

	//�����¿γ̸�������
	c.SetCourseName(CourseName);
	c.SetCourseTeacherID(CourseTeacherID);
	c.SetID(CourseID);
	c.SetCourseTime(CourseTime);
	c.SetCourseSession(CourseSession);

	AllCourse.push_back(c);
	WriteCourseMessage(AllCourse);
	cout << "�ӿγɹ�" << endl;
	cout << AllCourse[2].CourseName;
}

void Teacher::Delete()  //ɾ���γ�
{
	int flag = 0;   //�Ƿ�ɾ���ı�־
	char ID[100];   //Ҫɾ���γ̵�ID
	cout << "������Ҫɾ���γ̵�ID��";
	cin >> ID;
	TypeCourse AllCourse;
	AllCourse = ReadCourseFromFile();
	TypeCourse::iterator ite;
	for (ite = AllCourse.begin(); ite != AllCourse.end(); ite++)
	{
		if (!strcmp(ite->GetCourseID(), ID))
		{
			AllCourse.erase(ite);
			puts("ɾ�γɹ�");
			flag = 1;
			break;
		}
	}
	if (flag = 0)
	{
		puts("δ�ҵ��γ�");
	}
	WriteCourseMessage(AllCourse);
}

void Teacher::Modify()   //�޸Ŀγ̣����ֻ�ʱ��)
{
	int flag = 0;
	char ID[100];
	int CourseTime, CourseSession;   //���޸ĵ�����
	TypeCourse AllCourse;
	TypeUse AllUse;
	AllUse = ReadUserFromFile();
	AllCourse = ReadCourseFromFile();
	TypeCourse::iterator ite;
	TypeUse::iterator ite1;
	cout << "������Ҫ�޸ĵĿγ�ID��";
	cin >> ID;
	for (ite = AllCourse.begin(); ite != AllCourse.end(); ite++)
	{
		if (strcmp(ite->CourseID, ID) == 0)
		{
			cout << "�������޸ĺ�Ŀγ�ʱ�䣺";
			cin >> CourseTime >> CourseSession;
			ite->CourseTime = CourseTime;
			ite->CourseSession = CourseSession;
			cout << "�޸ĳɹ�";
			flag = 1;
			break;
		}
	}
	WriteCourseMessage(AllCourse);
	if (!flag)
	{
		cout << "δ�ҵ��γ�";
	}
	if(flag == 1)
	{
		for (ite1 = AllUse.begin(); ite1 != AllUse.end(); ite1++)
		{
			ite1->Setflag(1);
		}
		WriteUserMessage(AllUse);
	}
}