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
set_name(HIC"������"NOR, ({"duanyang dan","dan"}));
set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
  set("long", "һ����ֵĵ�ҩ��\n");
set("unit", "��");
 set("value", 0);
        }
}
int do_eat(string arg)
{
  object me = this_player();
if (arg!="dan") return 0;
                this_player()->set("daoxing", this_player()->query("daoxing")*95/100);
                this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                this_player()->set("potential", this_player()->query("potential")*50/100);
                this_player()->set("office_number", this_player()->query("office_number")*90/100);
                this_player()->set("bellicosity", this_player()->query("bellicosity")*1/100);
message_vision("$N�Ѷ�����������һ��,���Ӹɴ��������Ĳ������ٻ��ˡ�\n", me);
  destruct(this_object());
  return 1;
}
