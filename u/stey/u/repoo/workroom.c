//By REPOO 
#include <ansi.h>
inherit ROOM;
void create ()
{
        set ("short", HIB" ��Ҷ�� "NOR);
        set ("long", @LONG
 
    �������磬�����ϡ������߸������⡢��ɽ���ǣ�����������
�δ�����ľĩȥ����ʱҰ��ɳ���䡣��������ĺ���ڿ�����������
 
    �･����������������Զ����Ư����̾ʮ�����£�����ĪĪ��
�����޶������ϣ�Ǭ���ϴ����������ƻ衢���Ϳͻ�������ͷ�ǡ�
  
LONG);
        set("exits", 
        ([ //sizeof() == 3
        "kz" : "/d/city/kezhan",
          "ziye" : "/u/ziye/workroom",
         "fayu" : "/u/fayu/workroom",
        "xuexu" : "/u/xuexu/workroom",
  "wiz" : "/d/wiz/wizroom",
                        ]));
        set("no_death", 1);
	 set("no_fight", 1);
        set("no_kill", 1);
        set("no_time", 1);
        set("sleep_room", 1);
        set("no_clean_up", 0);
set("objects", ([
    __DIR__"npc/zy" : 1,
  //      "/u/repoo/mofamen/obj/guaishi" : 1,
  ]));
        setup();
}
void init()
{
        object me = this_player();
        tell_room( environment(me), CYN"��ҶƮƮ��" + me->query("title") + " "
                + me->query("name") + "(" + me->query("id") + ")" + " �����˺�Ҷ��\n"NOR);
}
