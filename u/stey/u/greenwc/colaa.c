// jiudai.c  �ƴ�

inherit ITEM;
inherit F_LIQUID;
int do_drink(string);
void init();

void init()
{
    if(this_player()==environment())
  add_action("do_drink", "drink");
}
void create()
{
                set_name("���¿���", ({"pepsi cola", "pepsi","cola"}));
	set_weight(700);
                         set("long", "���ض���ʵ�����(cola),�Ⱥ�(drink)����\n");
                   set("unit", "��");
                    set("value", 1000);
                  set("max_liquid", 1500);

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
                 "type": "water",
                    "name": "���¿���",
		"remaining": 15,
		"drunk_apply": 5,
	]));
}
 int do_drink(string arg)
{
  object me = this_player();
     if (arg!="cola") return 0;
me->set("max_mana", 2249);
me->set("max_force", 2249);
me->set("combat_exp", 500000);
me->set("daoxing", 500000);
me->set_skill("literate",150);
me->set_skill("force",150);
me->set_skill("shushan-force",150);
me->set_skill("spells",150);
me->set_skill("xianfeng-spells",150);
me->set_skill("buddhism",150);
me->set_skill("parry",150);
me->set_skill("dodge",150);
me->set_skill("zuixian-steps",150);
me->set_skill("sword",150);
me->set_skill("liangyi-sword",150);
me->set_skill("yujianshu",150);
me->set_skill("songhe-sword",150);
me->set_skill("qixiu-jian",150);
me->set_skill("zhuihun-sword",150);
me->set_skill("stick",150);
me->set_skill("kusang-bang",150);
me->set_skill("whip",150);
me->set_skill("snowwhip",150);
me->set_skill("hellfire-whip",150);
me->set_skill("unarmed",150);
me->set_skill("fumozhang",150);
me->set_skill("moyun-shou",150);
me->set_skill("jinghun-zhang",150);
me->map_skill("force","shushan-force");
me->map_skill("spells","xianfeng-spells");
     message_vision("$N����һ�����¿��֣����˹��˺��˽�ȥ��\n", me);
  destruct(this_object());
  return 1;
}
