//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
void create ()
{
  set ("short","����");
  set ("long", @LONG

һ��ɾ���������ң������м�Ĵ�������һ����ɫ�԰׵�
�������͡�
LONG);
   set("exits", ([      
              "west" : __DIR__"woshi",
  ]));
   set("objects", ([ 
      __DIR__"npc/zongsi" : 1,
       ]));

  setup();
}









