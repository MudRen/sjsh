#include <ansi.h>
inherit ROOM;
void create()
{
set ("short",HIW"�� �� �� ��"NOR);
set ("long",@LONG

           ��  ��  ��  ��         Ψ  ��  ��  ��

  out : ��ȥ�ϳǿ�ջ��
  enter : ��ȥ�񹬴��ɵĿ�����
  south : ȥ�񹬴��ɵ����Ρ�

LONG);
set("exits",([
"out" : "/d/city/kezhan",
"enter" : __DIR__"parlour",
"south" : __DIR__"prison",
]));
set("outdoors", 0);
set("no_clean_up", 1);
set("valid_startroom", 1);
setup();
}
void init()
{
object who=this_player();
if( (string)who->query("gender")=="����" || (string)who->query("gender")=="Ů��" )
add_action("do_stop", "exert");
add_action("do_stop", "cast");
add_action("do_stop", "kill");
add_action("do_stop", "fight");
add_action("do_stop", "perform");
add_action("do_stop", "apply");
add_action("do_stop", "sleep");
add_action("do_stop", "exercise");
add_action("do_stop", "meditate");
{
call_out("heal_up", 9, who);
}
remove_call_out("sounding");
call_out("sounding", random(10), this_object());
}
int sounding(object where)
{
string *msgs=({
HIG"����Ʈ��������ơ�\n"NOR,
HIM"�Ų�����Χ��������Ʈ�¸���\n"NOR,
HIY"���ư���ȫ����Χ������\n"NOR,
HIC"�����ȫ������˵�������泩��\n"NOR,
});
tell_room (where,msgs[random(sizeof(msgs))]);
}
int heal_up(object who)
{
if( !who || environment(who) != this_object() )
{
return 1;
}
who->set("eff_gin", (int)who->query("max_gin"));
who->set("eff_kee", (int)who->query("max_kee"));
who->set("eff_sen", (int)who->query("max_sen"));
message_vision(HIW"��������Ʈ��$N��$N�������˼�������\n"NOR, who);
write(YEL"������Լ��ľ�����Ѫһ���Ӷ��ָ��ˡ�\n"NOR);
if( (int)who->query("food") < (int)who->max_food_capacity() )
who->set("food", (int)who->max_food_capacity());
if( (int)who->query("water")< (int)who->max_water_capacity())
who->set("water", (int)who->max_water_capacity());
return 1;
}
int do_stop(string arg)
{
object who = this_player();
object me = this_object();
message_vision(HIR"���ϴ���"NOR+HIC"�񹬴���"NOR+HIR"һ��ŭ��������������˽���صأ�����$N���ҵ��ң���\n"NOR,who);
return 1;
}
