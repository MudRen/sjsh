// Room: /u/cnd/workroom.c
inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short", HIY "������" NOR);
         set ("long", @LONG

���滷��,��������,ݺ�����䲻���ڶ�,������ƫ�������һ���µ�,
���Ϸ羰����,û���κ���Ϊ�ӹ����ĺۼ�,��������һ��С��,����
ͣЪ�Ÿ���Ǩ�㾭�˵ķ���,���԰�����һ������,Զ��������������
��������"��Ϊ��,��Ϊ��,��Ϊ����,������ձ,�����֮����,���ҹ�
��Ƥ��.....
LONG);

            set("exits", ([
                  "out" :  "/d/city/center",
		    "in"  :  "/d/wiz/wizroom",
                "down"  :  "u/yushu/workroom",
            ]));   


       set("no_fight",1);
       set("no_sleep", 1);
       set("valid_startroom", 1);

	set("no_clean_up", 0);
       setup();
	replace_program(ROOM);
}


