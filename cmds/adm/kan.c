// ��ע������!����������֮�ݺ�������(202.103.98.74-5555)
// �� ���� ��С����(xhm)������ƽ(tianping)  
// blockade.c

#include <login.h>

inherit F_CLEAN_UP;
string time_period(int timep);

int main(object me, string arg)
{
        int i, j, tim, sum=0;

        i = LOGIN_D->get_dienpc();
        j = LOGIN_D->get_madlock();
	tim = F_DISASTER->query_hj_startT();
	tim = time() - tim;
	sum += F_DISASTER->query_children("/d/haojie/npc/pker9.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker8.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker7.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker6.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker5.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker4.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker3.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker2.c");
	sum += F_DISASTER->query_children("/d/haojie/npc/pker1.c");
	write(" ��ɱNPC������"+i+"\n");
	write("ϵͳ����״̬��"+j+"\n");
	write("��������ʱ�䣺"+time_period(tim)+"\n");
	write("��ǰɱ��������"+sum+"\n");
        return 1;
}

string time_period(int timep)
{
	int t, d, h, m, s;
	string time;
	if ( timep>=1800 ) return "�ѳ�ʱ";
	t = timep;
	s = t % 60;	t /= 60;
	m = t % 60;	t /= 60;
	h = t % 24;	t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";
	return time;
}
