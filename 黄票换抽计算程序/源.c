//һ����Ʊ����ļ������(V1.1)
#include<stdio.h>
int main(void)
{
	//���׶������ĵĻ�Ʊ��
	int PHASE[6] = { 0,1 * 10,2 * 9,5 * 8,10 * 7,20 * 6 };
	//���׶οɻ��ĳ���
	int PULLS[6] = { 0,1 * 1,2 * 1,5 * 1,1 * 10,2 * 10 };
	int Distinction_Certificate, pulls, Headhunting_Permit, Ten_roll_Headhunting_Permit;
	int status_1, status_2, i;
	printf("��ӭʹ�ø߼�ƾ֤�һ�Ѱ��ƾ֤�ļ������������ĸ���˳����򣩡�\n");
	printf("���������ĸ߼�ƾ֤������");
	while (scanf_s("%d", &Distinction_Certificate) == 1)//��ȡ�û������벢��ⷵ��ֵ�Ƿ�Ϊ1
	{
		int phase = 1;//���׶γ�ʼ��Ϊ1
		pulls = 0;//��������ʼ��Ϊ0
		Headhunting_Permit = 0;//����������ʼ��Ϊ0
		Ten_roll_Headhunting_Permit = 0;//��ʮ������ʼ��Ϊ0
		while (Distinction_Certificate >= PHASE[phase])//���ʣ��Ļ�Ʊ�Ƿ���ڵ�ǰ�׶������ĵĻ�Ʊ�����Ƿ������
		{
			pulls += PULLS[phase];//���ϵ�ǰ�׶οɻ��ĳ���
			if (phase < 4)//���׶��Ƿ�С��4���Ƿ�ɻ�ʮ����
			{
				Headhunting_Permit = pulls;
			}
			else
			{
				Ten_roll_Headhunting_Permit += (PULLS[phase] / 10);//����ʮ����
			}
			Distinction_Certificate -= PHASE[phase];//��ȥ��ǰ�׶������ĵĻ�Ʊ���������۳���Ʊ��
			if (phase < 5)//���׶��Ƿ�С��5
				phase++;//��1�׶�
			else
				break;//����ѭ��
		}
		status_1 = printf("��������ܹ����Ի�ȡ%d�飨%d�ε����%d��ʮ����", pulls, Headhunting_Permit, Ten_roll_Headhunting_Permit);
		status_2 = printf("��ʣ��%d�Ÿ߼�ƾ֤��\n", Distinction_Certificate);
		for (i = 1;i < (status_1 + status_2);i++)
			printf("-");//����printf()�ķ���ֵ��ӡ�ָ���
		printf("\n���������ĸ߼�ƾ֤������");
	}
	printf("�����ѽ�������л����ʹ�ã�\n");
	return 0;
}