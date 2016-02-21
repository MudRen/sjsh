 // Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���������ţ��Ѿ����Կ���һ�����칬�����߲�ϼ�⣬��������
����������֮�С�������м������������ϲ����Ž���ҫ�ճ���
����һ�����������������������죬�������߸���һ����
Ҳ��֪�Ǹ�ʲô�õģ��������Լ�������ߵ���������֮������
���˲��١�

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"nantian",
  "north" : __DIR__"caihongqiao",
  "west" : __DIR__"caifengdian",
  "east" : __DIR__"jinlongdian",
]));

  create_door("south", "������", "north", DOOR_CLOSED);
        set("no_clean_up", 0);

  setup();
}
void init()
{
       add_action("do_shen", "sheng");
}

int do_shen(string arg)
{
   object me;
	string s;
	int my_exp,my_level,temp,price,afford;

	me = this_player();
	my_exp=me->query("combat_exp");
	my_level=me->query("level");
	temp=(my_level+1)*(my_level+1)*100;
	if(my_exp>=temp)
	{
		price=10*10000*(my_level+1);		  
		if( afford = me->can_afford(price) ) {
			me->pay_money(price, 0);
			                                                                    temp=me->query("scorepoint")+(my_level/10+100)*100;
			me->set("level",my_level+1);
			me->set("scorepoint",temp);
			me->set("kee",me->query("max_kee"));
			me->set("mana",me->query("max_mana"));
			message_vision("$N�����ı����۾�����ͻȻ�Ե��������������\n", me);
			printf(HIW "��ļ���õ���������\n" NOR);
		}
		else
		{
			printf(HIW"��û���㹻��Ǯ��Ϊ�����츣��������" HIY "%d" HIW "���ľ���Ϊ" HIM "%d" HIW "��\n "NOR,
				my_level+1,price/10000);
		}
	}
	else
		printf(HIW "�����ѧ����ѵ����" HIY "%d" HIW "������Ҫ�����ѧ�ﵽ" HIM "%d" HIW "���У�\n" NOR,
				my_level+1,temp);
	return 1;
}

 
