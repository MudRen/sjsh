#include <ansi.h>
inherit ROOM;
void create()
{
set ("short",HIM"�ɿ���������"NOR);
set ("long",@LONG

�ɿ����ľ���С�������а��費�࣬����һ��Ů���ӣ�����ʼ������ô�ؾ��š�
���������дУ�һƬ���ⰺȻ������Ϸ��˺ܶ��飬�ڹ��Ϸ��źܶ�Ĳ������
������������ῴ���ɿ������õ�΢Ц��������Ƭ�ȣ��������ĺܶ������
ʱ�������ڴ�ǰ�����������۵Ĵ�ɫ����¶΢Ц������Զ����

LONG);
set("exits",([
"moon" : "/d/moon/ontop2",
"pt" : "/d/nanhai/gate",
"kz":"/d/city/kezhan",
"kf" : "/d/kaifeng/tieta",
"fc" : "/d/lingtai/gate",
"+" : "/d/city/center",
]));
set("outdoors", 0);
set("no_clean_up", 1);
set("valid_startroom", 1);
setup();
}
