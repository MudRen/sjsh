//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
void create ()
{
  set ("short","��ʾ�����´�");
  set ("long", @LONG

���;�ʾ�������С����ĵط�����������һ������ģ�����ˣ�������
��������������㡣
LONG);
   set("exits", ([      
       "west" : __DIR__"jingshiting",
       "north" : __DIR__"woshi",
  ]));
   set("objects", ([ 
      __DIR__"npc/zhaitengyi" : 1,
       ]));

  setup();
}









