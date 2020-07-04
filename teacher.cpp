#include "AllHead.h"

void Teacher::Login()   //教师登录函数
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
		puts("  ---            教师用户界面                     ");
		puts("  ---                                             ");
		puts("  ---              1.增加课程                     ");
		puts("  ---              2.删除课程                     ");
		puts("  ---              3.修改课程                     ");
		puts("  ---              0.退出                         ");
		puts("  ---                                             ");
		puts("  ---                                             ");
		puts("	------------------------------------------------");
		cout << "您的选择是:";
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
			puts("请输入数字0-3");
			Sleep(2500);
		}
	}
}

void Teacher::Add()  //增加课程
{
	char CourseID[20];   //课程ID
	char CourseName[20];   //课程名
	int CourseTime;   //课程时间(周几)
	int CourseSession;   //课程节次，如第一节、第四节
	char CourseTeacherID[20];   //课程教师编号
	TypeCourse AllCourse;
	AllCourse = ReadCourseFromFile();
	Course c;
	cout << "请输入课程名：";
	cin >> CourseName;
	cout << "请输入教师ID：";
	cin >> CourseTeacherID;
	cout << "请输入课程ID：";
	cin >> CourseID;
	cout << "请输入课程时间：";
	cin >> CourseTime;
	cout << "请输入课程节次：";
	cin >> CourseSession;

	//设置新课程各项属性
	c.SetCourseName(CourseName);
	c.SetCourseTeacherID(CourseTeacherID);
	c.SetID(CourseID);
	c.SetCourseTime(CourseTime);
	c.SetCourseSession(CourseSession);

	AllCourse.push_back(c);
	WriteCourseMessage(AllCourse);
	cout << "加课成功" << endl;
	cout << AllCourse[2].CourseName;
}

void Teacher::Delete()  //删除课程
{
	int flag = 0;   //是否删除的标志
	char ID[100];   //要删除课程的ID
	cout << "请输入要删除课程的ID：";
	cin >> ID;
	TypeCourse AllCourse;
	AllCourse = ReadCourseFromFile();
	TypeCourse::iterator ite;
	for (ite = AllCourse.begin(); ite != AllCourse.end(); ite++)
	{
		if (!strcmp(ite->GetCourseID(), ID))
		{
			AllCourse.erase(ite);
			puts("删课成功");
			flag = 1;
			break;
		}
	}
	if (flag = 0)
	{
		puts("未找到课程");
	}
	WriteCourseMessage(AllCourse);
}

void Teacher::Modify()   //修改课程（名字或时间)
{
	int flag = 0;
	char ID[100];
	int CourseTime, CourseSession;   //能修改的属性
	TypeCourse AllCourse;
	TypeUse AllUse;
	AllUse = ReadUserFromFile();
	AllCourse = ReadCourseFromFile();
	TypeCourse::iterator ite;
	TypeUse::iterator ite1;
	cout << "请输入要修改的课程ID：";
	cin >> ID;
	for (ite = AllCourse.begin(); ite != AllCourse.end(); ite++)
	{
		if (strcmp(ite->CourseID, ID) == 0)
		{
			cout << "请输入修改后的课程时间：";
			cin >> CourseTime >> CourseSession;
			ite->CourseTime = CourseTime;
			ite->CourseSession = CourseSession;
			cout << "修改成功";
			flag = 1;
			break;
		}
	}
	WriteCourseMessage(AllCourse);
	if (!flag)
	{
		cout << "未找到课程";
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