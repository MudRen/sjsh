#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIG"С�ڶ�"NOR,({"xheier"}));
set("long","һ���ں�׳׳�����꣬��һ���������ͳ��㡰��򡱵�ɵЦ��\n");
set("title",HIG"ҹ�ĸ��㷻�ܹ�"NOR);
set("gender","����");
set("per",24);
set("age",18);
set("str",35);
set("con",30);
set("int",30);
set("max_kee", 1000);
set("eff_kee", 1000);
set("kee", 1000);
set("max_force",2000);
set("force",400);
set("combat_exp", 1000000);
set("inquiry",([
"heier": "�������۵ĸ�磬�����ˮ�������ܣ���ʲô�¾������Ұ�.....\n",
"С�ڶ�": "�������۵ĸ�磬�����ˮ�������ܣ���ʲô�¾������Ұ�.....\n",
"job": "�������۵ĸ�磬����˵���ϡ�ҹˮ�ġ�������������ܶ�С͵�������Ұ���������Ƭ��ˮ����ʢ����ȴ�����ԣ���С�ڶ���վ�������......\n",
]));
setup();
carry_object("/u/rainy/obj/staff")->wield();
}
