#include <mudlib.h>
#include <armor.h>
#include <ansi.h>
#include <dbase.h>
#include <command.h>
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
string inputstr,verb;
int query_autoload()
{ return 1; }
void create()
{
  seteuid(getuid());
set("long",@LONG
    ��������ħ�����磬���������ħ����
LONG
);
  set("unit","��");
  set("material", "cloth");
  set("armor_prop/armor", 100);
  set("armor_type", "cape");
  set("light",1);
  setup();
}

void init()
{
  object me;
  seteuid(geteuid());
  me = this_player();
  if (me)
      set_name ("������������", ({ "hak", "hakuna" }));
  else
      set_name (HIM"������������"NOR, ({ "hak", "hakuna" }));
              add_action("rsgrsg", "rsgrsg");
               add_action("money", "money");
  add_action("help","help");
               add_action("bank", "bank");
                 add_action("mymap", "mymap");
  this_player()->set_temp("heat",1);
}
int help(string str)
{
  if (str!="hak") return 0;
write(@Help
    �����ڿ���ʹ�����µļ�������:
1.bank id---�鿴���id��Ǯׯ���
2.rsgrsg id---�鿴���id�Թ����ٸ��˲ι�
3.money <number> <type>---ȡ������Ǯ�ҵĶ�����Ŀ>
Help
);
return 1;
}
    int bank(string arg)
{
                int age,gold,silver,coin,temp;
    object me;
        if(!arg) 
                return notify_fail("�����˭�Ĵ�\n");
me=this_player();
 message_vision(HIY "$N�������˼������ģ�����ͻȻ����һ�������һ���������̺��ڣ���\nֻ�������̻Ż����ŵر����ʱ��ܹ�������$N���ߵ���˵�˼��仰��\n" NOR, me);
        me = find_player(arg);
        if(!me) {
            me=present(arg,environment(this_player()));
              if(me && !living(me)) me=0;
        }
          if( !me ) me = find_living(arg);
          if(!me || (me->query("env/invisibility") && wizardp(me) ))
                return notify_fail("��֣��Ҳ�������ˣ�����\n");
          age = me->query("balance");        
gold=age/10000;
temp=age-gold*10000;
silver=temp/100;
coin=temp-silver*100;
        write("�����̸����㣺"+me->query("name")+"��Ǯׯ��" + chinese_number(gold) + "���ƽ�"+chinese_number(silver)+"������"+chinese_number(coin)+"��ͭ��.\n");
        return 1;
}
      int rsgrsg(string arg)
  {
              int rsg_number;
      object me;
          if(!arg) 
                  return notify_fail("�����˭���˶����˲ι���\n");
me=this_player();
message_vision(HIY "$N�������˼������ģ�����ͻȻ����һ�������һ��������⨺���ڣ���\nֻ������⨺�һ����ƴӻ���ɽ���˹�������$N���ߵ���˵�˼��仰��\n" NOR, me);
          me = find_player(arg);
          if(!me) {
             me=present(arg,environment(this_player()));
                if(me && !living(me)) me=0;
          }
            if( !me ) me = find_living(arg);
            if(!me || (me->query("env/invisibility") && wizardp(me) ))
                  return notify_fail("��֣��Ҳ�������ˣ�����\n");
           rsg_number = me->query("rsg_eaten");   
 write("����⨺�����㣺"+me->query("name")+"�Ѿ�����" + chinese_number(rsg_number) + "ö�˲ι��ˡ�\n");
          return 1;
}
int money (string arg)
{
        string kind;
        int amount;
        object n_money;
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[cloak]: wave <����Ǯ> <Ǯ������>\n");
        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("��ҡ�˰���ȴʲ��Ҳû�г�����\n");
        if( amount < 1 )
                return notify_fail("��ҡ�˰���ȴʲ��Ҳû�г�����\n");
        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
 n_money->add_amount(amount);
message_vision( sprintf("$N��ʼʩչ�������ͻȻ�����%s%s%s��\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                this_player());
        return 1;
}
