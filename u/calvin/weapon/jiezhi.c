#include <ansi.h>
#include <armor.h>
inherit FINGER;
void create()
{
set_name(HIW"����"NOR+HIC"ħ��"NOR, ({ "shenxian mojie" ,"mojie" , "jiezhi"  , "finger" }));
set_weight(0);
set("unit", "ֻ");
set("long", HIW"����"NOR+HIC"ħ��"NOR+HIM"�������(file)������ʲô���Բ顣\n"NOR);
if (clonep())
set_default_object(__FILE__);
else
{
set("material", "gold");
set("armor_prop/armor", 65536);
set("armor_prop/dodge", 65536);
set("armor_prop/spells", 65536);
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
add_action("do_file","file");
add_action("do_base","base");
add_action("do_watch","watch");
add_action("do_rsg","rsg");
add_action("do_life","life");
}
int do_file(string arg)
{
object who=this_player();
message_vision(
  HIW"$N"NOR+HIY"������ݣ����񰡣��������������\n"NOR+
  HIW"base"NOR+HIC" : "NOR+HIM"�鿴ĳ��ҵ����л������ԡ�\n"NOR+
  HIW"watch"NOR+HIC" : "NOR+HIM"�鿴ĳ��ҵ�����״̬��\n"NOR+
  HIW"rsg"NOR+HIC" : "NOR+HIM"�鿴ĳ��ҵĳԹ�������\n"NOR+
  HIW"life"NOR+HIC" : "NOR+HIM"�鿴ĳ��ҵ����١�\n"NOR
,who);
return 1;
}
int do_base(string arg)
{
object me;
object ob;
mapping my;
string str1;
string str2;
string str3;
string str4;
string str5;
seteuid(geteuid());
me = this_player();
if(!arg) ob = me;
else
if (wizardp(me))
{
ob = present(arg, environment(me));
if (!ob) ob = find_player(arg);
if (!ob) ob = find_living(arg);
if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
}
else return notify_fail("�����ڻ����ܲ쿴���˵�״̬��\n");
if (my = ob->query_entire_dbase())
{
str1 = "  ��������  "+ob->name()+"  ���Ա�  "+ob->query("gender")+"  ���ɣġ�  "+ob->query("id");
str2 = "  ����ò��  "+ob->query("per")+"  ����ʶ��  "+ob->query("cor")+"  ��������  "+ob->query("cps")+"  ����Ե��  "+ob->query("kar");
str3 = "  �����  "+ob->query("str")+"  ����ǡ�  "+ob->query("con")+"  �����ԡ�  "+ob->query("per")+"  �����ԡ�  "+ob->query("spi");
str4 = "  ���Уˡ�  "+ob->query("PKS")+"  ���Σˡ�  "+ob->query("MKS")+"  ����·��  "+ob->query("ziyouchoose");
str5 = "  ����Ǯ��  "+(ob->query("donation")/1000000);
message_vision(HIW"$NҪ�����Ϣ����:\n"+str1+"\n"+str2+"\n"+str3+"\n"+str4+str5+"\n"NOR,me);
return 1;
}
}
int do_watch(string arg)
{
object me;
object ob;
mapping my;
string str1;
string str2;
string str3;
seteuid(geteuid());
me = this_player();
if(!arg) ob = me;
else
if (wizardp(me))
{
ob = present(arg, environment(me));
if (!ob) ob = find_player(arg);
if (!ob) ob = find_living(arg);
if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
}
else return notify_fail("�����ڻ����ܲ쿴���˵�״̬��\n");
if (my = ob->query_entire_dbase())
{
str1 = "  ����Ѫ��  "+ob->query("eff_kee")+"/"+ob->query("max_kee")+"  ������  "+ob->query("eff_sen")+"/"+ob->query("max_sen");
str2 = "  ��������  "+ob->query("force")+"/"+ob->query("max_force")+"  ��������  "+ob->query("mana")+"/"+ob->query("max_mana");
str3 = "  ����ѧ��  "+ob->query("combat_exp")+"  ��Ǳ�ܡ�  "+ob->query("potential")+"  �����С�  "+ob->query("daoxing")+"  ����ְ��  "+ob->query("office_number");
message_vision(HIW"$NҪ�����Ϣ����:\n"+str1+str2+"\n"+str3+"\n"NOR,me);
return 1;
}
}
int do_rsg(string arg)
{
object me;
object ob;
mapping my;
seteuid(geteuid());
me = this_player();
if(!arg) ob = me;
else
if (wizardp(me))
{
ob = present(arg, environment(me));
if (!ob) ob = find_player(arg);
if (!ob) ob = find_living(arg);
if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
}
else return notify_fail("�����ڻ����ܲ쿴���˵�״̬��\n");
my = ob->query_entire_dbase();
message_vision(HIW"$NҪ�����Ϣ����:\n  ���Թ���  �Ѿ�����"+chinese_number(ob->query("rsg_eaten"))+"���˲ι���\n"NOR,me);
return 1;
}
int do_life(string arg)
{
object me;
object ob;
mapping my;
seteuid(geteuid());
me = this_player();
if(!arg) ob = me;
else
if (wizardp(me))
{
ob = present(arg, environment(me));
if (!ob) ob = find_player(arg);
if (!ob) ob = find_living(arg);
if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
}
else return notify_fail("�����ڻ����ܲ쿴���˵�״̬��\n");
my = ob->query_entire_dbase();
if(ob->query("life/live_forever"))
{
message_vision(HIW"$NҪ�����Ϣ����:\n  �����١�  "+ob->name()+"���������⣬���������У�����������������ˣ�\n"NOR,me);
return 1;
}
else
message_vision(HIW"$NҪ�����Ϣ����:\n  �����١�  "+ob->name()+"��"+chinese_number(ob->query("life/life_time"))+"������٣�\n"NOR,me);
return 1;
}
void greeting(object who)
{
string str;
if(who->query("id") != "immortal")
{
message_vision(HIR"���ϴ���"NOR+HIC"�񹬴���"NOR+HIR"��һ��ŭ�������С�Ӹ�͵�ɼұ����Ҫ�ͷ��㣡��\n"NOR,who);
who->set("eff_kee",-1);
who->set("max_gin",-1);
who->set("max_sen",-1);
str=who->name();
message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+str+"��˽�������"NOR+HIW"����"NOR+HIC"ħ��"NOR+HIM"�ֽ������\n"NOR,users());
}
}
