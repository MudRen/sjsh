#include <ansi.h>
inherit ITEM;
void create()
{
set_name("����", ({ "table" }) );
set_weight(500000);
set("unit", "��");
set("long", "�񹬴���ƽʱ���������������������������飬�����(list)������ʲô����Կ���\n");
set("value", 0);
setup();
}
void init()
{
add_action("do_list","list");
add_action("do_base","base");
add_action("do_watch","watch");
add_action("do_rsg","rsg");
add_action("do_life","life");
}
int do_list(string arg)
{
object who=this_player();
message_vision("
  $N���������󷭷��ҷ������ҵ��㶫����\n
  base : �鿴ĳ��ҵ����л������ԡ�\n
  cha : �鿴ĳ��ҵ�����״̬��\n
  rsg : �鿴ĳ��ҵĳԹ�������\n
  life : �鿴ĳ��ҵ����١�\n
",who);
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
