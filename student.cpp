#include "AllHead.h"

void User::Login()
{
	std::cout << "��ӭʹ�ÿα����ϵͳ��";
}

void Student::Login()   //ѧ����¼����
{
	system("color F5");
	system("cls");
	string CourseName;   //��ѯ�γ�ʱ�Ŀγ�����
	Student s;
	Course course;
	while (1)
	{
		system("cls");
		char choose;
		cout << endl;
		puts("	------------------------------------------------");
		puts("  ---            ѧ���û�����                     ");
		puts("  ---                                             ");
		puts("  ---              1.������Ϣ                     ");
		puts("  ---              2.�α���Ϣ                     ");
		puts("  ---              3.�γ���Ϣ                     ");
		puts("  ---              4.�ռ���                       ");
		puts("  ---              0.�˳�                         ");
		puts("  ---                                             ");
		puts("	------------------------------------------------");
		cout << "����ѡ����:";
		cin >> choose;
		switch (choose)
		{
		case('1'):
			s.Query_StudentMessage();
			getch();
			break;
		case('2'):
			s.Query_CourseTimetable();
			getch();
			break;
		case('3'):
			s.Query_Subject();
			getch();
			break;
		case('4'):
			s.Check_ClassMessage();
			getch();
			break;
		case('0'):
			system("cls");
			return;
			break;
		default:
			puts("����������0-4");
			Sleep(2500);
		}
	}
}

void Student::Query_StudentMessage()   //��ѯ������Ϣ
{
	int i = 0;
	string ID;   //Ҫ��ѯ��ID
	cout << "���������ID:";
	cin >> ID;
	TypeUse AllUse;
	AllUse = ReadUserFromFile();
	TypeUse::iterator ite;
	for (ite = AllUse.begin(); ite != AllUse.end(); ite++)
	{
		if (strcmp(ite->GetID(), ID.c_str()) == 0)
		{
			cout << setiosflags(ios::left) << setw(10) << "����" << setw(10) << "ID" << setw(10) << "����"
				<< setw(10) << "���" << endl;
			cout << setiosflags(ios::left) << setw(10) << ite->GetName() << setw(10) << ite->GetID() << setw(10) << ite->GetPass()
				<< setw(10) << ite->GetDegree() << endl;
			break;
		}
	}

}

void Student::Query_CourseTimetable()   //ѧ����ȡ�Լ��Ŀα�
{
	int i = 0;   //����
	TypeCourse AllCourse;
	AllCourse = ReadCourseFromFile();
	TypeCourse::iterator ite;
	for (ite = AllCourse.begin(); ite != AllCourse.end(); ite++)
	{
		i++;
		if(i!=AllCourse.size())
			cout << setiosflags(ios::left) << setw(10) << ite->CourseName << setw(10) << ite->CourseTeacherID << setw(10)
			<< ite->CourseID << setw(10) << ite->CourseTime <<  ite->CourseSession<<endl;
		else
			cout << setiosflags(ios::left) << setw(10) << ite->CourseName << setw(10) << ite->CourseTeacherID << setw(10)
			<< ite->CourseID << setw(10) << ite->CourseTime <<  ite->CourseSession;
	}
}

void Student::Query_Subject()   //ѧ����ѯ�ض��γ�
{
	int flag = 0;   //�Ƿ��ҵ��ض��γ̵ı�־
	string CourseID;
	cout << "������γ���:";
	cin >> CourseID;
	TypeCourse AllCourse;
	AllCourse = ReadCourseFromFile();
	TypeCourse::iterator ite;
	for (ite = AllCourse.begin(); ite != AllCourse.end(); ite++)
	{
		if (strcmp(ite->GetCourseID(), CourseID.c_str())==0)
		{
			cout << setiosflags(ios::left) << setw(10) << ite->CourseName << setw(10) << ite->CourseTeacherID << setw(10)
				<< ite->CourseID << setw(10) << ite->CourseTime << ite->CourseSession;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "δ�ҵ��γ�";
	}
}

void Student::Check_ClassMessage()   //ѧ���鿴��Ϣ
{
	char ID[100];
	int i;
	cout << "����������ID:";
	cin >> ID;
	TypeUse AllUse;
	AllUse = ReadUserFromFile();
	TypeUse::iterator ite;
	for (ite = AllUse.begin(); ite != AllUse.end(); ite++)
	{
		if (strcmp(ite->GetID(), ID) == 0)
		{
			i = ite->Getflag();
			if (i == 1)
			{
				cout << "�иĿ�֪ͨ���뾡��鿴";
				ite->Setflag(0);   //��֪ͨ����Ϊ0
				//cout << ite->Getflag();
				break;
			}
			if(i == 0)
			{
				cout << "�޵���֪ͨ";
				//cout<<i;
				break;
			}
		}
	}
	WriteUserMessage(AllUse);   
}