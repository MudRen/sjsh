#include <ansi.h>
inherit ROOM;
void create()
{
set ("short",HIC "�� �� ��" NOR);
set ("long",@LONG

�����˴����ñ�ɽ���꺮���������ɣ�����������֮���湦Ч�����Ҷ�ů������
�����Ĵ�С��֪����һ��˫�˴������Ҵ������໹�����˾žŰ�ʮһ����̬��
��������������꺮����������֮�ʣ����������������������һ��һ��
���񹬴������˾žŰ�ʮһ����ѪŬ�����ɡ��ɼ��񹬴���Ϊ����Ҹ������١�
LONG);
set("exits",([
"out" : __DIR__"sleep",
]));
set("outdoors", 0);
set("no_fight", 1);
set("no_magic", 1);
set("no_clean_up", 1);
set("sleep_room",1);
set("if_bed",1);
setup();
}
