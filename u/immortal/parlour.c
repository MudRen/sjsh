#include <ansi.h>
inherit ROOM;
void create()
{
set ("short",HIW "ӭ �� ��" NOR);
set ("long",@LONG

           ��  ��  ��  ��         ��  ӭ  ��  ��

  out : ��ȥ�񹬴�
  south : ȥҩ����
  north : ȥ�鷿��
  west : ȥ��������
  east : ȥ����̨��
  enter : ��ȥ�񹬴��ɵ�˯����

LONG);
set("exits",([
"out" : __DIR__"workroom",
"south" : __DIR__"dispensary",
"north" : __DIR__"study",
"west" : __DIR__"drill",
"east" : __DIR__"watch",
"enter" : __DIR__"sleep",
]));
set("outdoors", 0);
setup();
}
