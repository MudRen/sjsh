#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIC"С������"NOR,({"ruyi"}));
set("long","һ�������������СŮ����Լ����ʮ������ӣ�
Ц��������ģ����˾��ú�������ۡ�\n");
set("title",HIC"���������MM"NOR);
set("gender","Ů��");
set("per",30);
set("age",19);
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
"ruyi": "������վ�ġ�С�����⡱���Ǻǣ�����ϲ������ͷ�������ʱҲ����������ͨ����Ϊ�˵������߲ŷ�����.....xixi\n",
"С������": "������վ�ġ�С�����⡱���Ǻǣ�����ϲ������ͷ�������ʱҲ����������ͨ����Ϊ�˵������߲ŷ�����.....xixi\n",
"age": "��19�꣬mudage�������е�ageһ������^_*......\n",
]));
setup();
carry_object("/u/rainy/obj/feicui")->wear();
}

