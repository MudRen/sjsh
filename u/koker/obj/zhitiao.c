//by koker@sjsh 2002/01/14 �������� 
//�������64�����գ�������64��������

#include <ansi.h>
inherit ITEM;
void create()
{
set_name("ֽ��", ({ "zhi tiao" }) );
set_weight(5);
set("unit", "��");
set("long", "һ��͸����ֽ���������(list)�����ϱ���ʲô���Կ��Ķ�����\n");
set("value", 0);
setup();
}
void init()
{
 if (!wizardp(this_player())) {
    set("no_get",1);
    set("no_give",1);
    set("no_drop",1);
    set("no_sell",1);
  }                                    
add_action("do_list","list");
add_action("do_base","base");
call_out ("becoming_old",600);

}

void becoming_old ()
{
  object me = this_object();
  object who = this_player();
  tell_object(who,HIW"ֻ����Զ������������64����������ڴ��ڵ�ֽ��ͻȻ����һ���׹ⲻ���ˡ�\n"NOR);
  destruct (me);
}

int do_list(string arg)
{
object who=this_player();
message_vision("
  $N���Ź���������ֽ�����ҵ��㶫����\n
  base : �鿴�Լ������л������ԡ�\n
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