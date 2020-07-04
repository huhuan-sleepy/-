#include "AllHead.h"

void User::Login()
{
	std::cout << "欢迎使用课表管理系统！";
}

void Student::Login()   //学生登录函数
{
	system("color F5");
	system("cls");
	string CourseName;   //查询课程时的课程名字
	Student s;
	Course course;
	while (1)
	{
		system("cls");
		char choose;
		cout << endl;
		puts("	------------------------------------------------");
		puts("  ---            学生用户界面                     ");
		puts("  ---                                             ");
		puts("  ---              1.自身信息                     ");
		puts("  ---              2.课表信息                     ");
		puts("  ---              3.课程信息                     ");
		puts("  ---              4.收件箱                       ");
		puts("  ---              0.退出                         ");
		puts("  ---                                             ");
		puts("	------------------------------------------------");
		cout << "您的选择是:";
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
			puts("请输入数字0-4");
			Sleep(2500);
		}
	}
}

void Student::Query_StudentMessage()   //查询自身信息
{
	int i = 0;
	string ID;   //要查询的ID
	cout << "请输入你的ID:";
	cin >> ID;
	TypeUse AllUse;
	AllUse = ReadUserFromFile();
	TypeUse::iterator ite;
	for (ite = AllUse.begin(); ite != AllUse.end(); ite++)
	{
		if (strcmp(ite->GetID(), ID.c_str()) == 0)
		{
			cout << setiosflags(ios::left) << setw(10) << "姓名" << setw(10) << "ID" << setw(10) << "密码"
				<< setw(10) << "身份" << endl;
			cout << setiosflags(ios::left) << setw(10) << ite->GetName() << setw(10) << ite->GetID() << setw(10) << ite->GetPass()
				<< setw(10) << ite->GetDegree() << endl;
			break;
		}
	}

}

void Student::Query_CourseTimetable()   //学生获取自己的课表
{
	int i = 0;   //计数
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

void Student::Query_Subject()   //学生查询特定课程
{
	int flag = 0;   //是否找到特定课程的标志
	string CourseID;
	cout << "请输入课程名:";
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
		cout << "未找到课程";
	}
}

void Student::Check_ClassMessage()   //学生查看消息
{
	char ID[100];
	int i;
	cout << "请输入您的ID:";
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
				cout << "有改课通知，请尽快查看";
				ite->Setflag(0);   //将通知设置为0
				//cout << ite->Getflag();
				break;
			}
			if(i == 0)
			{
				cout << "无调课通知";
				//cout<<i;
				break;
			}
		}
	}
	WriteUserMessage(AllUse);   
}