// �������� by Calvin
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����԰");
  set ("long", @LONG

�����ǻʹ��ĺ�Ժ - "����԰",�����ļ�����,���������۵ľ���
��԰�м���ǿ�"ǧ����(qianzi teng)",����������,һ�ۿ�����
��.��˵����������������,����û��һ��ͷ�����,��������Ҳ��
�˺ö���,������Ҳ������������ȥ,��˵����õ�������ϵ�һ
�����ﲢ�����ʵ۵Ļ����Եõ��ʹ�,�����ʹ��(climb)���� ...
������Ǹ���������Ҳ����Ҳ��������֮�䷢��ʲô...
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yuhuayuan",
]));

        set("objects", 
        ([ //sizeof() == 1
              "/d/longzhu/npc/king" : 1,
        ]));

  set("outdoors", 1);

  setup();
}

void init()
{
        add_action("do_wa", "wa");
}

int do_wa()
{
        object  me, horse;
	me = this_player();
/*        
	if(me->query_temp("ridee")){
		horse=me->query_temp("ridee");
		me->command_function("dismount "+horse->query("id"));
	}
*/

message_vision(HIY "$Nʹ�����ڰ���,�۵���ͷ�Ǻ�����Ȼֻ��$N���һ���ڹ�,֮��Ͳ�������Ӱ��\n" NOR, me);
        me->move("/d/milin/qy/duanyang");
        message_vision(HIY "ֻ��$N�������,�Ǳ��ĵ���������\n" NOR, me);
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        return 1;
}




