// bianshi dan.c ��ʬ��

inherit ITEM;
inherit F_LIQUID;
int do_drink(string);
void init();

void init()
{
    if(this_player()==environment())
add_action("do_eat", "eat");
}
void create()
{
set_name("��ʬ��", ({"bianshi dan","dan"}));
set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
  set("long", "����������ħǱ�����͵Ĺ�ҩ,��ʳ���档\n");
set("unit", "��");
 set("value", 0);
	}
}
int do_eat(string arg)
{
  object me = this_player();
if (arg!="dan") return 0;
 me->set("eff_sen", (int)me->query("max_sen")*2);
me->set("eff_kee", (int)me->query("max_kee")*2);
me->set("eff_sen", (int)me->query("sen")*2);
me->set("eff_kee", (int)me->query("kee")*2);
me->set("mana", (int)me->query("max_mana")*2);
me->set("force", (int)me->query("max_force")*2);
me->set("mana", (int)me->query("mana")*2);
me->set("force", (int)me->query("force")*2);
me->set("force", (int)me->query("maximum_force")*2);
me->set("mana", (int)me->query("maximum_mana")*2);
me->set("food", (int)me->max_food_capacity()*20);
me->set("water", (int)me->max_water_capacity()*20);
me->set("bellicosity", (int)me->query_kar()*1000);
me->set("office_number", (int)me->query_office_number()*2);
me->set_skill("literate",500);
me->set_skill("dodge",500);
me->set_skill("force",500);
me->set_skill("spells",500);
me->set_skill("parry",500);
me->set_skill("ningxie-force",500);
me->set_skill("dengxian-dafa",500);
me->set_skill("throwing",500);
me->set_skill("unarmed",500);
me->set_skill("xiaoyaoyou",500);
me->set_skill("sword",500);
me->set_skill("bainiao-jian",500);
me->set_skill("moonshentong",500);
me->set_skill("moondance",500);
me->set_skill("moonforce",500);
me->set_skill("whip",500);
me->set_skill("jueqingbian",500);
me->set_skill("stick",500);
me->set_skill("qianjun-bang",500);
message_vision("$N������һ�ű�ʬ��,ʱ����˿��ܻ�����Ϊ��ʬ��\n", me);
  destruct(this_object());
  return 1;
}
