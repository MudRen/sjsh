#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIG"С�ڶ�"NOR,({"xiao", "xiao heier"}));
set("long","��Ө���Ϲ��ڶ���\n");
set("title",HIM"��Ө���"NOR);
set("gender","����");
  set("per",40);
  set("age",22);
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
"heier":"���Ǻںڵ�˧˧�������Ĵ���үС�ڶ�������������\n",
"keren":"����,û�в�Ҷ��,��ô��?\n",
"love": "����ҵ�Ө������֪��Ө��Ҳ���ң�\n",
"�ڶ�":"���Ǻںڵ�˧˧�������Ĵ���үС�ڶ�������������\n",
"fayu": "���������Ű�����С�ڶ��ı�����Ө��\n",
"��Ө": "���������Ű�����С�ڶ��ı�����Ө��\n",
        ]));
  set("chat_chance",5);
set("chat_msg", ({
HIG"�ڶ�����������:����ϲ���ҵ����ţ�������СѾͷ��\n"NOR,
HIG"�ڶ���������:Ө������ô����������\n"NOR,
             }));
setup();
}
