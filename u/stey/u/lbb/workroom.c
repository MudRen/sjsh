inherit ROOM;

void create ()
{
  set ("short", "�㳡");
  set ("long", @LONG

˭Ҳ�벻��������ļҾ�Ȼ������һ���㳡�ϣ��㲻�ɵÿ�ʼ�������������
�Ľ���ѿ�֮�ƣ��϶�������������˶�û�˦���㣬���ǣ�
��ӿ��˽Ų���
LONG);

    set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"workroom.c",
  "west" : __DIR__"workroom.c",
  "south" : __DIR__"workroom.c",
  "north" : __DIR__"gate.c",
]));

  setup();
}
