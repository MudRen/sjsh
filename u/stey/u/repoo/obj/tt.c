// jianglidan1.c ������
#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init();
void init()
{
if (!wizardp(this_player())) {
set("no_get", "�ٺ٣����ΰ�! \n");
  set("no_drop","��ô����Ķ�������������! \n");
}
add_action("do_eat", "eat");
}
void create()
{
set_name(HIG "pk��" NOR, ({"pk dan", "dan"}));
set_weight(20);
if (clonep())
set_default_object(__FILE__);
else {
set("unit", "��");
 set("long", "һ��PK���������ָܻ�����,���ѵõ��鵤��ҩ!\n");
set("value", 100);
}
set("is_monitored", 1);
    call_out("announce",random(10),this_player());
setup();
}
int do_eat(string arg)
{
object victim = this_player();
/*
if( (int)victim->query("combat_exp")+(int)victim->query("daoxing") > 0 )
{
message_vision(HIG "\n$N����һ��������,��Ȼ�е�һ��θ���Ͳ�û�ѳ���Ҳ���³���!\n\n" NOR, victim);
destruct(this_object());
return 1;
}
*/
if (!id(arg))
return notify_fail("��Ҫ��ʲô��\n");
 victim->set("combat_exp", 10000);
if( (int)victim->query("potential") > (int)victim->query("learned_points"))
victim->add("potential",
(int)victim->query("potential") - (int)victim->query("learned_points")+10000 );
victim->skill_death_recover();
  victim->set("daoxing",5000000);
    victim->set("max_force",5000);
  victim->set("max_mana",5000);
 victim->set("maximum_mana",5000);
 victim->set("maximum_force",5000);
victim->set("combat_exp",4000000);
victim->set("force",10000);
victim->set("mana",10000);
victim->save();
if( userp(victim) ) log_file("RECOVER", sprintf("%s(%s) Got recovered on %s.\n", victim->name(1), geteuid(victim), ctime(time()) ) );
 message_vision(WHT "\n$N����һ��PK��,������һ����Ϣ����ȫ��,��ʱ�������,��������!\n\n" NOR, victim);
destruct(this_object());
return 1;
}
void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "system", 
            who->query("name")+"�õ���"+name()+"��\n");
}
