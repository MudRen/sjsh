//by repoo
#include <ansi.h>
inherit ROOM;
void create ()
{
          set ("short",BLINK HIM"����"NOR+HIW"������"NOR);
        set ("long", @LONG
������ϵͳ����Ա�����ࣩΪ�Լ�������ѧϰ���޽��Ĺ����ҡ�
��Ŀ�����µĻ��ݳ����������ķ��䡣
LONG);
        set("exits", 
        ([ //sizeof() == 3
                "kz" : "/d/city/kezhan",
           "wizroom" :  "/d/wiz/wizroom",
           "room" :  "/u/yiq/love",
                        ]));
        set("no_death", 1);
	 set("no_fight", 1);
        set("no_kill", 1);
        set("no_time", 1);
        set("sleep_room", 1);
        set("no_clean_up", 0);
  set("valid_startroom", 1);
        setup();
}
void init()
{
        object me = this_player();
        tell_room( environment(me), WHT"����"+HIM"��"+WHT"��˵�������Ỷӭ��\n"NOR);
}
