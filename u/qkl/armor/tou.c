//  No Copyright Message (6.17.1997)

#include <mudlib.h>
#include <ansi.h>
#include <room.h>
#include <armor.h>
#include <command.h>
#include <net/dns.h>

inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;

string inputstr,verb;

void create()
{
  seteuid(getuid());

set("long",@LONG

    ����һ��͵Ȩս�¡�

    ����<help tou-cloth>�Ի�ø������Ѷ��

LONG
);

  set("unit","��");
  set("no_get", 1);
  set("no_drop", 1);
  set("no_sell", 1);

  set("material", "cloth");
  set("armor_prop/armor", 100);
	set_weight(10);
  setup();
}

void init()
{
  object me;                   
  seteuid(geteuid());

  me = this_player();
  if (me && present(this_object(), me))
	set_name (me->name(1)+ "��͵Ȩս��", ({ "tou-cloth" }));
  else
    set_name ("͵Ȩս��", ({ "tou-cloth" }));

  if (me && present(this_object(), me)) {
    add_action("help","help");
//  add_action("full","full");
//  add_action("remov","xie");
    add_action("wave","yao");
//  add_action("steal","tou");
//  add_action ("whereis", "whereis");
//  add_action ("pk_mob", "pk");
//   add_action ("do_give", "give");
//  add_action ("do_wakeup", "wakeup");
//  add_action ("force_quit", "fquit");
//  add_action ("do_say", "ss");
//  add_action ("do_who", "userlist");
//  add_action ("do_look", "lookhere");
	}
}

int help(string str)
{

  if (str!="tou-cloth") return 0;

write(@Help

    �����ʹ�����µļ�������:

       % localcmd, stat, call, data, score, skills, �ȵ�
         ���� help wizcmds ȡ�ý�һ������

       yao <number> <type>		<<ȡ������Ǯ�ҵĶ�����Ŀ>
Help

);

  return 1;
}



int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[MYST]: wave <����Ǯ> <Ǯ������>\n");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("��ҡ�˰���ȴʲôҲû�г�����\n");
        if( amount < 1 )
                return notify_fail("��ҡ�˰���ȴʲôҲû�г�����\n");

        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf("$Nʹ�����Ϳڴ���ͻȻ�Ӵ������ͳ�%s%s%s��\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                this_player());
        return 1;
}



