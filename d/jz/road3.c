#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "�ٵ�");
  set ("long", @LONG

  ����һ������������Ĺٵ����������ߵ��˲��࣬��Ϊ·��
�������˻������µĺۼ���
LONG);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road2",
]));
  set("outdoors", 1);
  setup();
}
void init()
{
add_action("do_guibai","guibai");
}
int do_guibai(string arg)
{
object ob = this_player();
if( ! arg || arg != "tian" )
return notify_fail("��Ҫ��ʲô��\n");
message_vision(HIW"$N�������Ϲ��°��˼��ݣ��������һ����������һ���ſڡ�\n"NOR,ob);
set("exits/enter", __DIR__"room");
remove_call_out("close");
call_out("close", 3, this_object());
return 1;
}
void close(object room)
{
message("vision",HIW"����һ�������ֲ����ˡ�\n"NOR, room);
room->delete("exits/enter");
}
