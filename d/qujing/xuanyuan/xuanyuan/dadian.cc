inherit ROOM;
#include <room.h>
void create()
{
set("short","���");
set("long",@LONG
�����ǹ�Ĺ�Ĵ��,��һ̧ͷ�ͷ���槼�����
��������̫ʦ����.
LONG);
set("exits", ([
         "north" : __DIR__"nei2",
     //  "west" : __DIR__"road4",
     //  "north": __DIR__"chufang",
       "south":__DIR__"mishi",
]));
set("objects", ([
  __DIR__"npc/daji" : 1,
]) );
//  create_door("south", "����", "north", DOOR_CLOSED);

setup();

}
int valid_leave(object me, string dir)
{
    if (dir == "south" ) {
{ if (((string)me->query("family/family_name")=="��ԯĹ")
//   ||   wizardp(me)
   ||   me->query_temp("gumu_answer")) {
     return ::valid_leave(me, dir);
           }
}
return notify_fail("ֻ��槼���������Ų��ܹ�ȥ����͹�Ĺ����ԨԴ���ܹ�ȥ��\n");  
}
if (dir == "north")
{ return ::valid_leave(me,dir);}
}
