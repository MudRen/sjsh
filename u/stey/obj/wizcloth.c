#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
//inherit F_CLEAN_UP;
inherit F_COMMAND;
string replace_color(string,int);
int help(object);
int wiz_set(string,string,string,int);
string inputstr,verb;
int main(object me, string arg);

void create()
{
       seteuid(getuid());
       set_name(HIW"��ʹ֮��Ĺ�����"NOR,({"angell suit","suit" }));
       set("long",@LONG
��������������������������������������������������������
��  ��  ��  ��    ��       ��   ��    ˵        ��    ��
��������������������������������������������������������
��yao       ��yao <genre><valu> ������ƾ��ȡǮ        ��
��bianxing  ��bianxing <id>     ����������������      ��
��xing      ��xing <id>         ����ĳ������          ��
��hun       ��hun  <id>         ����ĳ���ε�          ��
��feng      ��feng <id>         ���ⶳĳ��            ��
��jiefeng   ��jiefeng <id>      �����ĳ��            ��
��qshs      ��qshs <id>         ����������            ��
��age       ��age <id> <s>      ���޸�����            ��
��skill     ��skill <id><msg><s>���޸�������书�ȼ�  ��
��exp       ��exp <id> <s>      ���޸�������书�ȼ�  ��
��������������������������������������������������������
LONG
       );
       if(clonep())
           set_default_object(__FILE__);
       else{
           set("unit","��");
           seteuid(geteuid());
           set("material", "cloth");
           set("armor_prop/armor", 10000);
           set("no_get",1);
           set("no_drop",1);
           }
       setup();
}
// ����ֱ��
void init()
{
       if( wizardp(environment()) ) {
       add_action("qshs","qshs");
       add_action("quanjia","quanjia");
       add_action("daoxing","dao");
       add_action("yao","yao");
       add_action("xing","xing");
       add_action("combat_exp","exp");       
       add_action("hun","hun");
       add_action("bx","bianxing");
       add_action("fengplayer","feng");
       add_action("jiefengplayer","jiefeng");
       add_action ("pk", "pk");
       add_action ("skill", "skill");
       add_action ("age", "age");              
      add_action("max_force","force"); 
       add_action("max_mana","mana"); 
       add_action("jizhu","jizhu");
       add_action("jiaban","jb");
       add_action("detect", "level");       
       add_action("jianting","jt");
       this_player()->set_temp("heat",1);
      }
}

// COMBAT_EXP �޸ľ���
int combat_exp(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("combat sb. exp\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("combat_exp",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ľ���ֵ������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("combat sb. exp\n");
}
int daoxing(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("daoxing sb. dao\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("daoxing",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ĵ���������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("daoxing sb. dao\n");
}
// AGE ����
int max_force(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("max sb. force\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("max_force",i);
        write("�޸�"+WHT+target->query("name")+NOR"������������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("max sb. force\n");
}
int max_mana(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("max sb. mana\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("max_mana",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ķ���������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("max sb. mana\n");
}
int age(string str)
{
        object me,target;
        string name;
        int level;
        me=this_player();
        if(!str) return notify_fail("age sb ���ӵ����.\n");
        if(sscanf(str,"%s %d",name,level)==2)   {
        if(!(target=present(name,environment(me))))
                return notify_fail("û��û����ô���ˡ�\n");
        target->add("mud_age",86400*level);
        target->add("age",level);
        write("�޸�"+WHT+target->query("name")+NOR+"���������"+HIR+(string)level+NOR+"�ꡣ\n",this_object());
        return 1;
        }
        else
        return notify_fail("age sb. ���ӵ���͡�\n");
}
//  SKILL �书
int skill(string str)
{
        object me;
        object target;
        string name,skills;
        int level;
        if(!str)        return notify_fail("skill ĳ�� ���� �ȼ�\n");
        me=this_player();
        if(sscanf(str,"%s %s %d",name,skills,level)==3)         {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->set_skill(skills,level);
        write("�޸�"+WHT+target->query("name")+NOR"��"+YEL+to_chinese(skills)+NOR+"�书Ϊ"+HIR+(string)level+NOR"����\n",this_object());
        return 1;
        }
        else
        return notify_fail("skill ĳ�� ���� �ȼ�\n");
}
// QSHS ��������������
int qshs (string str)
{
  object ob;
  if (!str) return notify_fail("qshs <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("����û������˰�?\n");
  if (ob->is_ghost()) 
           tell_object(ob,HIC"�������ȫ������...\n"NOR);
       else 
           return notify_fail("����˺����ǻ�ģ���������������\n");
  tell_object(ob,HIC"�����ϣ����ǹ�!��Ҫ���㸴��ұ����ϴε�һ�С�\n"NOR);
  tell_room(environment(ob),HIG"һ��"HIY"���"HIG"ͻȻ��������£�������"+
       (string)ob->query("name")+"����Χ��\n"NOR, ob);
  tell_object(ob,HIR"ͻȻһ����������������𣬡������....��������\n��ʼ���ٲ��ǻ���ˡ�����ͻȻ�е�һ�����...\n"NOR);
  ob->reincarnate();
  ob->query_temp("last_damage_from");  
  tell_object(ob,HIR"�ܺã����ָ����ˣ�\n"NOR);
  return 1;    
}
// ���˷�ס
int fengplayer (string str)
{
  object ob;
  if(str=="kittt") return notify_fail("���ǲ�����������\n");
  if (!str) return notify_fail("feng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("���������?\n");
  tell_object(ob,"����۾�ͻȻһƬģ��������������ס����...\n");
  ob->set_temp("block_msg/all",1);
  ob->disable_player(HIR "<ʧȥ֪����>" NOR);      
  return 1;    
}
// ���˽��
int jiefengplayer (string str)
{
  object ob;
  if (!str) return notify_fail("jiefeng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("���������?\n");   
  ob->set_temp("block_msg/all",0);
  ob->enable_player(); 
  tell_object(ob,"���˺���˵��������ϲ���ơ��������ڿ���...\n");
  return 1;
}
//  XING ʹ������
int xing (string str)
{
  object who;
  if (!str) return notify_fail ("xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("û��"+str+"ѽ��\n");}
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}
// HUN ʹ�˻赹
int hun (string str)
{
  object who;
  if (!str) return notify_fail ("����ˣ����Լ�Ū�Σ�\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("û��"+str+"ѽ��\n");}
  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
  return 1;
}
//  BX ��������
int bx(string arg)
{
  object bxid,me;
  me=this_player();
  if(arg=="kittt") return notify_fail("�����̵���������\n");
  if (arg!=NULL_VALUE){
    bxid = LOGIN_D->find_body(arg);
    if (!bxid) return notify_fail("�����Ϻ���û�����ѽ��\n");
    }
  if (arg) {
    if(arg=="kittt") return notify_fail("����������\n");
    if(bxid->query("gender")=="Ů��") bxid->set( "gender", "����" );
    else bxid->set( "gender", "Ů��" );
    message("shout", HIM "��ҥ�ԡ�ĳ�ˣ���˵"+me->query("name")+"�ɹ��Ķ�" 
    +bxid->query("name")+"������һ�α���������\n" NOR,users());
    bxid->save();
    return 1;
  }
}
//  YAO ȡǮ
int yao (string arg)
{
        string kind;
        int amount;
        object n_money;
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("usage: yao <����Ǯ> <Ǯ������>\n");
        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail("����û������Ǯѽ��ҡ��ƨѽ��\n");
        if( amount < 1 )
                return notify_fail("�Ǻǣ�����û�С�\n");
        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);
 message_vision( sprintf(HIY "$Nʹ�������Լ��Ŀڴ���ͻȻ�Ӵ������ͳ�%s%s%s��\n" NOR,
        chinese_number(amount),n_money->query("base_unit"),n_money->query("name")),
        this_player());return 1;
}
string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        if(flag) arg+=NOR;
        return arg;
}
int query_autoload()
{
   if (wizardp(this_player())) return 1;
   else return 0;
}
