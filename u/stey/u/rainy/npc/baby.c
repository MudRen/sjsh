#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIY"С����"NOR,({"xiao rainy"}));
set("long","�ֺ�����СѾͷ��С�������������ѣ�ϲ�������Ц��\n");
set("title",HIY"���ⱦ��"NOR);
set("gender","����");
set("per",30);
set("age",5);
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
"baby": "����Ӥ����Ư��������������.��..��.....xixi\n",
"����": "����Ӥ����Ư��������������.��..��.....xixi\n",
"age": "�ҽ����������ˣ�fool......\n",
]));
setup();
carry_object("/u/rainy/obj/feicui")->wear();
}

