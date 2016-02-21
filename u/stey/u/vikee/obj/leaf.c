#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
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
       set("unit","Ƭ");
       set("no_get",1);
       set("no_give",1);
       set("material", "armor");
       set("armor_prop/armor", 1000);
       set("light",1);
       setup();
}

void init()
{
       seteuid(geteuid());
       set_name(HIY "һƬƮ�����Ҷ" NOR, ({ "leaf"}));
       add_action("do_change","change"); 
       add_action ("do_wakeup", "xing");  
       add_action ("do_hun","yun");       
       add_action ("do_disable_player","feng");
       add_action ("do_enable_player","jiefeng");
       add_action ("do_halt","quanjia");
       this_player()->set_temp("heat",1);
}

int do_change(string arg)
{
  object fd,me;
  me=this_player();
  if (arg!=NULL_VALUE){
    fd = LOGIN_D->find_body(arg);
    if (!fd) return notify_fail("����û�����ѽ��\n");
    }
  if (arg) {
    if(arg=="vikee") return notify_fail("�ҿ��������˰�!һҶ֪��ɲ��Ǻ��ǵ�,�����Ǽ��˿ɲ����������!\n");
    if(fd->query("gender")=="Ů��") fd->set( "gender", "����" );
    else fd->set( "gender", "Ů��" );
    message("system", HIM "����Ѩ���硿��" + HIM + "��˵" + me->query("name") + "�ɹ��Ķ�" 
       + fd->query("name") + "������һ�α���������\n" NOR,users());
    fd->save();
    write(HIC"��������ˣ�\n"NOR);
    return 1;
  }
}



int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("usage:xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("����û��"+str+"\n");
  }
  who->remove_call_out("revive");
  who->revive();
  write("Ok.\n");
  return 1;
}

int do_hun (string str)
{
  object who;

  if (!str) return notify_fail ("�����ӻ��ˣ���ô���԰��Լ�Ū�Σ�\n");
  if (str=="vikee") return notify_fail ("�����Ļ���suicide -f�����һ��!\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("����û��"+str+"\n");
  }

  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
  write("Ok.\n");
  return 1;
}


int do_disable_player (string str)
{
  object ob;
  if (!str) return notify_fail("usage: feng <id>\n");
  if (str=="vikee") return notify_fail("��ɲ����������!\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("���������?\n");
  tell_object(ob,"ͻȻ����۾�һƬģ��...\n");
  ob->set_temp("block_msg/all",1);
  write("Ok.\n");
  return 1;    
}

int do_enable_player (string str)
{
  object ob;
  if (!str) return notify_fail("usage: feng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("���������?\n");   
  ob->set_temp("block_msg/all",0);
  ob->enable_player(); 
  tell_object(ob,"�����������˵��������ټ��ټ�ܡ������ָֻ���...\n");
  write("Ok.\n");
  return 1;
}

int do_halt (string str)
{
  object ob;
  if (!str) return notify_fail("usage: quanjia <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("�����޴��ˣ�\n");       
  if( !ob->is_fighting() )
       return notify_fail("�������ڲ�û�д��С�\n");        
  tell_room(environment(ob),HIY "����к�Ȼ������һҶ֪��ߴ����Ӱ��\n���Ͱ��Ķ�"+                    
       (string)ob->query("name")+"˵�����������˴������ˣ��ҿ���λ"+RANK_D->query_respect(ob)+"�������˰ɣ���\n" NOR, ob);
  ob->remove_all_killer();
  tell_room(environment(ob),HIW "�ţ�"+                    
       (string)ob->query("name")+"˵��������˵�Ķԣ��Ҳ����ٴ��ˡ���\n" NOR, ob);
  tell_room(environment(ob), "..."+                    
       (string)ob->query("name")+"�����ܵ����٣����������ˣ�\n", ob);
  return 1;    
}
