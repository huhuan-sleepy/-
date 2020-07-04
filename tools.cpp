#include "AllHead.h"

void gotoxy(int x, int y)   //�����Ļ��λ����
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_ERROR_HANDLE), coord);
}

void WelcomeImage()   //���ƻ�ӭ����
{	
	TCHAR s1[] = _T("��ӭ�����α����ϵͳ");
	TCHAR s2[] = _T("Developed by HuHuan");
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	rectangle(160, 120, 480, 360);
	settextcolor(RED);
	outtextxy(240, 180, s1);
	setlinecolor(BLACK);
	line(240, 300, 320, 300);
	outtextxy(330, 300, s2);
	_getch();
	closegraph();
}

void WriteUserMessage(TypeUse AllUse)   //�û���Ϣд�뺯��
{
	std::ofstream SaveUser("./UserInfo.ini", ios::out | ios::trunc);   //����ָ��·��,�洢�û���Ϣ�����������
	TypeUse::iterator ite;     //Ϊ�������������������ڱ���
	//��������Ϊ�գ��򷵻�
	if (!SaveUser)
	{
		cout << "���������ʧ��";
		return;
	}
	//�������Ϊ���෵��

	int count = 0;   //����
	
	SaveUser << setiosflags(ios::left) << setw(10) << "����" << setw(10) << "ID" << setw(10) << "����"
		<< setw(10) << "�ȼ�" << "֪ͨ" << endl;
	for (ite = AllUse.begin(); ite != AllUse.end(); ite++)
	{
		SaveUser << setiosflags(ios::left) << setw(10) << ite->GetName() << setw(10) << ite->GetID()
			<< setw(10) << ite->GetPass() << setw(10) << ite->GetDegree() << ite->Getflag() << endl;
	}
	SaveUser.close();   //�ر������
}

TypeUse ReadUserFromFile()   //�û���Ϣ��ȡ����
{
	TypeUse AllUse;
	ifstream infileUse("./UserInfo.ini", ios::in);     //�����ļ�������
	if (!infileUse)
	{
		cout << "�ļ�������Ϊ�գ�";
		return AllUse;    //������ʧ���򷵻�ֵΪ��
	}
	char ch_Name[100];
	char ch_ID[100];
	char ch_Password[100];
	char ch_Degree[100];
	char ch_flag[100];

	char Name[20];
	char ID[20];
	char Password[20];
	int Degree;
	int flag;
	infileUse >> ch_Name >> ch_ID >> ch_Password >> ch_Degree >> ch_flag;
	while (!infileUse.eof())
	{
		infileUse >> Name;
		infileUse >> ID;
		infileUse >> Password;
		infileUse >> Degree;
		infileUse >> flag;
		if (Degree == 0)
		{
			Student s;
			s.SetUserName(Name);
			s.SetID(ID);
			s.SetPassword(Password);
			s.SetDegree(Degree);
			s.Setflag(flag);
			AllUse.push_back(s);
		}
		else
		{
			Teacher t;
			t.SetUserName(Name);
			t.SetID(ID);
			t.SetPassword(Password);
			t.SetDegree(Degree);
			t.Setflag(flag);
			AllUse.push_back(t);
		}
	}
	infileUse.close();   //�ر�������
	return AllUse;   //���ض�ȡ���û�������
}

string InputPassword() 
{
	string password;   ///����
	char c;
	int i = 0;
	while ((c = getch()) != '\r')
	{
		if (c == '\b')
		{
			if (password == "")
				continue;
			password.erase(password.size() - 1, 1);
			cout << "\b \b";
		}
		else if (c == 32) //�������Ϊ�ո�
		{
			continue;
		}
		else {
			cout << '*';
			password += c;
			i++;
		}
	}
	return password;

}

int CheckUserLogin(char *ID, string password)
{
	TypeUse AllUse = ReadUserFromFile();
	User user;
	const char *p = password.c_str();
	int flag=0;
	int i = 0;

	//   AllUse�������±���ʷ�ʽ���������������е��û�
	for (AllUse[i]; i < AllUse.size(); i++)
	{
		if ((strcmp(ID, AllUse[i].GetID()) == 0) && (strcmp((char *)p, AllUse[i].GetPass()) == 0))
		{
			flag = AllUse[i].GetDegree();
		}
	}
	return flag;
}

void WriteCourseMessage(TypeCourse AllCourse)   //�γ���Ϣд�뺯��
{
	std::ofstream SaveCourse("./CourseInfo.ini", ios::out|ios::trunc);   //����ָ��·��,�洢�γ���Ϣ�����������
	TypeCourse::iterator ite;   //Ϊ�������������������ڱ���
	if (!SaveCourse)
	{
		cout << "���������ʧ��";
		return;
	}
	
	int count = 0;   //����

	SaveCourse << setiosflags(ios::left) << setw(10) << "�γ���" << setw(10) << "��ʦID" << setw(10) 
		<< "�γ�ID" << setw(10)<< "�ܴ�" <<  "�ڴ�"<<endl;
	for (ite = AllCourse.begin(); ite != AllCourse.end(); ite++)
	{
		count++;
		if (count != AllCourse.size())
		{
			SaveCourse << setiosflags(ios::left) << setw(10) << ite->CourseName << setw(10) << ite->CourseTeacherID
				<< setw(10) << ite->CourseID << setw(10) << ite->CourseTime << ite->CourseSession << endl;
		}
		else
		{
			SaveCourse << setiosflags(ios::left) << setw(10) << ite->CourseName << setw(10) << ite->CourseTeacherID
				<< setw(10) << ite->CourseID << setw(10) << ite->CourseTime << ite->CourseSession;
		}
	}
	SaveCourse.close();   //�ر������
}

TypeCourse ReadCourseFromFile()   //�γ���Ϣ��ȡ����
{
	TypeCourse AllCourse;
	ifstream infileUse("./CourseInfo.ini", ios::in);     //�����ļ�������
	if (!infileUse)
	{
		cout << "�ļ�������Ϊ�գ�";
		return AllCourse;    //������ʧ���򷵻�ֵΪ��
	}
	char ch_CourseName[100];
	char ch_CourseTeacherID[100];
	char ch_CourseID[100];
	char ch_CourseTime[100];
	char ch_CourseSession[100];

	char CourseName[100];
	char CourseTeacherID[100];
	char CourseID[100];
	int CourseTime;
	int CourseSession;

	infileUse >> ch_CourseName >> ch_CourseTeacherID >> ch_CourseID >> ch_CourseTime >> ch_CourseSession;
	while (!infileUse.eof())
	{
		infileUse >> CourseName;
		infileUse >> CourseTeacherID;
		infileUse >> CourseID;
		infileUse >> CourseTime;
		infileUse >> CourseSession;
		Course c;
		c.SetCourseName(CourseName);
		c.SetCourseTeacherID(CourseTeacherID);
		c.SetID(CourseID);
		c.SetCourseTime(CourseTime);
		c.SetCourseSession(CourseSession);
		AllCourse.push_back(c);
	}
	infileUse.close();    //�ر�������
	return AllCourse;

}

void UserLogin()   //��ʼ����¼����
{
	char ID[20];   //�������������ID
	string password;   //�����������������
	system("color F9");   //����������ɫ

	//ʹ�ù�궨λ���������������ҽҩ����ϵͳ����
	gotoxy(8, 2);
	puts("---------------------------------------------");
	gotoxy(8, 3);
	puts("|                                          |");
	gotoxy(8, 4);
	puts("|                                          |");
	gotoxy(8, 5);
	puts("|                                          |");
	gotoxy(8, 6);
	puts("|                                          |");
	gotoxy(8, 7);
	puts("|                                          |");
	gotoxy(8, 8);
	puts("|                                          |");
	gotoxy(8, 9);
	puts("|                                          |");
	gotoxy(8, 10);
	puts("|                                          |");
	gotoxy(8, 11);
	puts("|                                          |");
	gotoxy(8, 12);
	puts("---------------------------------------------");
	gotoxy(18, 6);
	puts(" ID :");

	gotoxy(18, 8);
	puts("���� :");

	gotoxy(25, 6);   //��ȡ������û���
	cin >> ID;

	gotoxy(25, 8);
	password = InputPassword();  //��ȡ���������

	int flag = CheckUserLogin(ID, password);
	if (flag == 1)
	{
		Student s;
		s.Login();
	}
	else if (flag == 2)
	{
		Teacher t;
		t.Login();
	}
	else
	{
		gotoxy(9, 10);
		puts("   ��������û��������벻��");
		Sleep(3000);
	}

}