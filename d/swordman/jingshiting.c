//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
void create ()
{
  set ("short","���;�ʾ��");
  set ("long", @LONG

������Ƕ�孽��;�ʾ�����������䳤���Ľ��;������þ��������
ɨ�������������ˡ�
LONG);
   set("exits", ([      
       "west" : __DIR__"dalu10",
       "east" : __DIR__"workroom",
  ]));
   set("objects", ([ 
      __DIR__"npc/jingguan" : 2,
       ]));

  setup();
}









