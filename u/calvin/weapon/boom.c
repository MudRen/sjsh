#include <ansi.h>
inherit ITEM;
void create()
{
set_name(HIR"�޵д�ը��"NOR, ({ "wudida zhadan" ,"zhadan" , "boom"}));
set_weight(0);
set("unit", "ֻ");
set("long", HIW"һ��������ը����ը˭��˭��\n"NOR);
if (clonep())
set_default_object(__FILE__);
else
{
set("material", "gold");
}
set("value", 0);
setup();
}
int query_autoload() { return 1; }
void init()
{
if (!wizardp(this_player()))
{
set("no_get",HIR"������Ķ�������Ҫ���á�\n"NOR);
set("no_give",HIR"��ô����ı�����������ˣ�\n"NOR);
set("no_drop",HIR"������������������ˣ�\n"NOR);
set("no_sell",HIR"��������֪�����ļ�ֵ�������Լ����Űɡ�\n"NOR);
}
if(this_player()==environment())
call_out("greeting", 1, this_player());
}
void greeting(object who)
{
string str;
if(who->query("id") != "immortal")
{
message_vision(HIR"ͻȻ���ȣ�����һ������¡������������̳�������\n"NOR,who);
who->set("eff_kee",-1);
who->set("max_gin",-1);
who->set("max_sen",-1);
str=who->name();
message("channel:es",HIM"��Ͷ̥ת����ת����ͯ(Zslt):"+str+"��"NOR+HIR"�޵д�ը��"NOR+HIM"ը����,��Ϊ��֪��ʧ,����ת����\n"NOR,users());
}
}
