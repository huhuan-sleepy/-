#include "AllHead.h"

void gotoxy(int x, int y)   //光标屏幕定位函数
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_ERROR_HANDLE), coord);
}

void WelcomeImage()   //绘制欢迎界面
{	
	TCHAR s1[] = _T("欢迎来到课表管理系统");
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

void WriteUserMessage(TypeUse AllUse)   //用户信息写入函数
{
	std::ofstream SaveUser("./UserInfo.ini", ios::out | ios::trunc);   //创建指定路径,存储用户信息，建立输出流
	TypeUse::iterator ite;     //为容器建立迭代器，用于遍历
	//如果输出流为空，则返回
	if (!SaveUser)
	{
		cout << "输出流建立失败";
		return;
	}
	//如果容器为空亦返回

	int count = 0;   //计数
	
	SaveUser << setiosflags(ios::left) << setw(10) << "姓名" << setw(10) << "ID" << setw(10) << "密码"
		<< setw(10) << "等级" << "通知" << endl;
	for (ite = AllUse.begin(); ite != AllUse.end(); ite++)
	{
		SaveUser << setiosflags(ios::left) << setw(10) << ite->GetName() << setw(10) << ite->GetID()
			<< setw(10) << ite->GetPass() << setw(10) << ite->GetDegree() << ite->Getflag() << endl;
	}
	SaveUser.close();   //关闭输出流
}

TypeUse ReadUserFromFile()   //用户信息读取函数
{
	TypeUse AllUse;
	ifstream infileUse("./UserInfo.ini", ios::in);     //建立文件输入流
	if (!infileUse)
	{
		cout << "文件输入流为空！";
		return AllUse;    //流创建失败则返回值为空
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
	infileUse.close();   //关闭输入流
	return AllUse;   //返回读取的用户类容器
}

string InputPassword() 
{
	string password;   ///密码
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
		else if (c == 32) //如果输入为空格
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

	//   AllUse容器的下标访问方式，意欲返回容器中的用户
	for (AllUse[i]; i < AllUse.size(); i++)
	{
		if ((strcmp(ID, AllUse[i].GetID()) == 0) && (strcmp((char *)p, AllUse[i].GetPass()) == 0))
		{
			flag = AllUse[i].GetDegree();
		}
	}
	return flag;
}

void WriteCourseMessage(TypeCourse AllCourse)   //课程信息写入函数
{
	std::ofstream SaveCourse("./CourseInfo.ini", ios::out|ios::trunc);   //创建指定路径,存储课程信息，建立输出流
	TypeCourse::iterator ite;   //为容器创建迭代器，用于遍历
	if (!SaveCourse)
	{
		cout << "输出流建立失败";
		return;
	}
	
	int count = 0;   //计数

	SaveCourse << setiosflags(ios::left) << setw(10) << "课程名" << setw(10) << "教师ID" << setw(10) 
		<< "课程ID" << setw(10)<< "周次" <<  "节次"<<endl;
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
	SaveCourse.close();   //关闭输出流
}

TypeCourse ReadCourseFromFile()   //课程信息读取函数
{
	TypeCourse AllCourse;
	ifstream infileUse("./CourseInfo.ini", ios::in);     //建立文件输入流
	if (!infileUse)
	{
		cout << "文件输入流为空！";
		return AllCourse;    //流创建失败则返回值为空
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
	infileUse.close();    //关闭输入流
	return AllCourse;

}

void UserLogin()   //初始化登录函数
{
	char ID[20];   //用来保存输入的ID
	string password;   //用来保存输入的密码
	system("color F9");   //更改屏显配色

	//使用光标定位，与输出流，绘制医药管理系统界面
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
	puts("密码 :");

	gotoxy(25, 6);   //获取输入的用户名
	cin >> ID;

	gotoxy(25, 8);
	password = InputPassword();  //获取输入的密码

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
		puts("   您输入的用户名与密码不符");
		Sleep(3000);
	}

}