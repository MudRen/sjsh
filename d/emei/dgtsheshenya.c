
//Room: dgtsheshenya.c �ù�̨������
//Date: Oct. 2 1997 by That

inherit ROOM;
#include <ansi.h>

void create()
{
	  set("short","�ù�̨������");
	  set("long",@LONG
�������ֳ����������ǿ��ճ����ƺ�����⡢���֮�ء�̨���������ɣ�
�����޵ף��������ڡ���Ŀ��������������Ĵ�Сѩɽ��������Ŀ����Ϊ����
�������࣬�������棬���������ã�������������Ͷ���ƺ��������������
�������ƺ�������ãã��������Ұ��Զ����ʡ��ƺ��ᵴʱ�����ڽ𶥣���
̤���ƣ�����ƮƮ����֮�У�������Ѹ��ӿ��ʱ�������𶥶�������ǰ������
�����г�������֮�⡣��������
LONG);
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
	  "enter"	: __DIR__"woyunan",
	  "east"	 : __DIR__"duguangtai", 
	  ]));
	  set("no_clean_up", 0);
	  setup();
}
void init()
{
   add_action("do_jump","jump");
}

int do_jump(object me,object cl)
{
	         me = this_player();
                     if( (string)me->query("title")=="��ͨ����" ){                  
            cl = new("/d/emei/obj/mejian.c");
	message_vision(HIR"$N����������ҲҪ�ҵ������Լ����ǰѽ���\n"NOR, me);
	message_vision(HIR"$N��Ȼ���������£�������У������������쳹ɽ�ȣ�����$N�ĵ�����Ҳ��������������\n"NOR, me);
        if (random(2)==1)//�������ҵ����Ļ���
	{
       message_vision(HIW"\n$N�����ʱ��ͻȻ�俴���±����ж����������⣬����һ��ԭ����һ�ѽ���\n"NOR, me);
       message_vision(HIW"$N�ҵ����Լ��Ľ���\n"NOR, me);
            me->set_temp("marks/�յ�",1);
                     cl->move(me);
            me->move(__DIR__"jieyindian");
       message_vision(HIC"\n�����$N˵��:$N�ҵ��Լ��Ľ��ˣ�$N���ʸ����Ϊʦ�ˡ�\n"NOR, me);

	}
	else
	{
message("channel:rumor",HIM"��"HIW"��Ѩ����"HIM"��ĳ�ˣ���˵" + me->query("name") + "��Ϊ�˰������������Ȼ�����������£�\n"NOR,users());
             me->move(__DIR__"st0");
	me->unconcious();

	}
}
	else{
       message_vision(HIC"����˵�����������\n"NOR, me);

	}

	return 1;
}

