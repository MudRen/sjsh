#include <ansi.h>
inherit ROOM;

void init()
{
	add_action("do_knock", "knock");
}

int do_knock()
{
   object me,ob,*inv;
	string s;
	int i,num;

	me = this_player();

	inv = all_inventory(environment(me));
	if(sizeof(inv)>10)
	{
		printf(HIW "���϶�����������������޷�����ǽ�ڣ�\n" NOR);
		return 1;
	}
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]==me ) continue;
		if( !me->visible(inv[i]) ) continue;
		if(living(inv[i])&&!userp(inv[i]))
		{
			printf(HIW "�������һ��ǽ�ڣ��������ȥ���ֱ��������˿�����\n" NOR);
			return 1;
		}
	}
	
	s=query("where");
	num=query("beastnum");
	if(!s||num==0)return 1;
	for(i=0;i<1;i++)
	{
		ob=new(s,num,num,num);
		ob->move(environment(me));
	}
	printf(HIM "��������ǽ�ڣ�ͻȻ������ĳ����������\n" NOR);
	return 1;
}
