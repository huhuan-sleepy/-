#include "AllHead.h"

int main()
{
	WelcomeImage();   //绘制欢迎界面
	system("mode con cols=70 lines=30");
	while (1)
	{
		UserLogin();   //用户登录界面
	}
	return 0;
}