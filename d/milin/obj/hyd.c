// ������ by Calvin

#include <ansi.h>
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
set_name(HIG"���굤"NOR, ({"duanhun dan","dan"}));
set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
  set("long", "һ�����صĵ�ҩ��\n");
 set("unit", "��");
 set("value", 0);
        }
}
int do_eat(string arg)
{
  object me = this_player();
if (arg!="dan") return 0;
                this_player()->set("daoxing", this_player()->query("daoxing")*1001/1000);
       this_player()->set("combat_exp", this_player()->query("combat_exp")*1001/1000);
      this_player()->set("potential", this_player()->query("potential")*1005/1000);
       this_player()->set("office_number", this_player()->query("office_number")*1001/1000);
          this_player()->set("bellicosity", this_player()->query("bellicosity")*1050/1000);
me->set("eff_sen", (int)me->query("max_sen"));
me->set("eff_kee", (int)me->query("max_kee"));
me->set("eff_sen", (int)me->query("sen"));
me->set("eff_kee", (int)me->query("kee"));
me->set("mana", (int)me->query("max_mana"));
me->set("force", (int)me->query("max_force"));
me->set("mana", (int)me->query("mana"));
me->set("force", (int)me->query("force"));
message_vision(HIG "\n$N����һ�����굤��Ӳ�ǴӺ��޳��������ѣ�����˰���С����\n\n", me);
  destruct(this_object());
  return 1;
}
