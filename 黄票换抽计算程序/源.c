//一个黄票换抽的计算程序(V1.1)
#include<stdio.h>
int main(void)
{
	//各阶段需消耗的黄票数
	int PHASE[6] = { 0,1 * 10,2 * 9,5 * 8,10 * 7,20 * 6 };
	//各阶段可换的抽数
	int PULLS[6] = { 0,1 * 1,2 * 1,5 * 1,1 * 10,2 * 10 };
	int Distinction_Certificate, //黄票数
		pulls, //抽数
		Headhunting_Permit, //单抽数
		Ten_roll_Headhunting_Permit;//十连数
	int status_1, status_2, i;
	printf("欢迎使用高级凭证兑换寻访凭证的计算程序（输入字母可退出程序）。\n");
	printf("请输入您的高级凭证数量：");
	while (scanf_s("%d", &Distinction_Certificate) == 1)//读取用户的输入并检测返回值是否为1
	{
		int phase = 1;//将阶段初始化为1
		pulls = 0;//将抽数初始化为0
		Headhunting_Permit = 0;//将单抽数初始化为0
		Ten_roll_Headhunting_Permit = 0;//将十连数初始化为0
		while (Distinction_Certificate >= PHASE[phase])//检测剩余的黄票是否多于当前阶段需消耗的黄票数（是否买得起）
		{
			pulls += PULLS[phase];//加上当前阶段可换的抽数
			if (phase < 4)//检测阶段是否小于4（是否可换十连）
			{
				Headhunting_Permit = pulls;
			}
			else
			{
				Ten_roll_Headhunting_Permit += (PULLS[phase] / 10);//计算十连数
			}
			Distinction_Certificate -= PHASE[phase];//减去当前阶段需消耗的黄票数（购买后扣除黄票）
			if (phase < 5)//检测阶段是否小于5
			{	
				phase++;//加1阶段
			}	
			else
			{	
				break;//跳出循环
			}	 
		}
		status_1 = printf("您这个月总共可以换取%d抽（%d次单抽和%d次十连）", pulls, Headhunting_Permit, Ten_roll_Headhunting_Permit);
		status_2 = printf("，剩余%d张高级凭证。\n", Distinction_Certificate);
		for (i = 1;i < (status_1 + status_2);i++)
			printf("-");//根据printf()的返回值打印分割线
		printf("\n请输入您的高级凭证数量：");
	}
	printf("程序已结束，感谢您的使用！\n");
	return 0;
}
