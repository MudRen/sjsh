// suit.c

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
       set_name(HIW"巫师工作服"NOR,({"wizard suit","suit" }));
       set("long",@LONG
※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※  命  令  ※    用       法   ※    说        明    ※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※
※yao       ※yao <genre><valu> ※可以凭空取钱        ※
※bianxing  ※bianxing <id>     ※给人做变性手术      ※
※xing      ※xing <id>         ※让某人苏醒          ※
※hun       ※hun  <id>         ※让某人晕倒          ※
※feng      ※feng <id>         ※封冻某人            ※
※jiefeng   ※jiefeng <id>      ※解封某人            ※
※age       ※age <id> <s>      ※修改年龄            ※
※skill     ※skill <id><msg><s>※修改人物的武功等级  ※
※exp       ※exp <id> <s>      ※修改人物的武功等级  ※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※
LONG
       );
       if(clonep())
           set_default_object(__FILE__);
       else{
           set("unit","件");
           seteuid(geteuid());
           set("material", "cloth");
           set("armor_prop/armor", 10000);
           set("no_get",1);
           set("no_drop",1);
           }
       setup();
}
// 命令直待
void init()
{
       if( wizardp(environment()) ) {
       add_action("quanjia","quanjia");
       add_action("yao","yao");
       add_action("xing","xing");
       add_action("combat_exp","exp");       
       add_action("hun","hun");
       add_action("bx","bianxing");
       add_action("fengplayer","feng");
       add_action("jiefengplayer","jiefeng");
       add_action("office_number","office_number");
       add_action("str","str");
       add_action("cor","cor");
       add_action("int","int");
       add_action("spi","spi");
       add_action("cps","cps");
       add_action("per","per");
       add_action("con","con");
       add_action("kar","kar");
       add_action("balance","balance");
       add_action ("skill", "skill");
       add_action("daoxing","dh");
       add_action ("age", "age");              
       add_action("letdie","letdie");
       add_action("potential","qn");
       add_action("max_mana","mana");
       add_action("detect", "level");       
       add_action("max_force","neili");
       this_player()->set_temp("heat",1);
      }
}

// COMBAT_EXP 修改经验
int combat_exp(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("combat sb. exp\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("combat_exp",i);
        write("修改"+WHT+target->query("name")+NOR"的经验值增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("combat sb. exp\n");
}
int max_force(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("max sb. force\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("max_force",i);
        write("修改"+WHT+target->query("name")+NOR"的内力增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("max sb. force\n");
}
int str(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("str sb. str\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("str",i);
        write("修改"+WHT+target->query("name")+NOR"的经验值增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("str sb. str\n");
}
int cor(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("cor sb. cor\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("cor",i);
        write("修改"+WHT+target->query("name")+NOR"的经验值增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("cor sb. cor\n");
}
int spi(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("spi sb. spi\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("spi",i);
        write("修改"+WHT+target->query("name")+NOR"的经验值增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("spi sb. spi\n");
}
int cps(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("cps sb. cps\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("cps",i);
        write("修改"+WHT+target->query("name")+NOR"的经验值增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("cps sb. cps\n");
}
int per(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("per sb. per\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("per",i);
        write("修改"+WHT+target->query("name")+NOR"的经验值增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("per sb. per\n");
}
int kar(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("kar sb. kar\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("kar",i);
        write("修改"+WHT+target->query("name")+NOR"的经验值增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("kar sb. kar\n");
}
int con(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("con sb. con\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("con",i);
        write("修改"+WHT+target->query("name")+NOR"的经验值增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("con sb. con\n");
}
int balance(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("balance sb. balance\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("balance",i);
        write("修改"+WHT+target->query("name")+NOR"的经验值增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("balance sb. balance\n");
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
                return notify_fail("这儿没有这么个人。\n");
        target->add("max_mana",i);
        write("修改"+WHT+target->query("name")+NOR"的法力增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("max sb. mana\n");
}
int potential(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("potential sb. qn\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("potential",i);
        write("修改"+WHT+target->query("name")+NOR"的潜能增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("potential sb. qn\n");
}
int office_number(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("office_number sb. office_number\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("office_number",i);
        write("修改"+WHT+target->query("name")+NOR"的法力增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("office_number sb. office_number\n");
}
int daoxing(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("daoxing sb. dh\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->add("daoxing",i);
        write("修改"+WHT+target->query("name")+NOR"的道行增加了"+HIR+(string)i+NOR"点。\n",this_object());
        return 1;
        }
        else return notify_fail("daoxing sb. dh\n");
}
// AGE 年龄
int age(string str)
{
        object me,target;
        string name;
        int level;
        me=this_player();
        if(!str) return notify_fail("age sb 增加的年纪.\n");
        if(sscanf(str,"%s %d",name,level)==2)   {
        if(!(target=present(name,environment(me))))
                return notify_fail("没儿没有这么个人。\n");
        target->add("mud_age",86400*level);
        target->add("age",level);
        write("修改"+WHT+target->query("name")+NOR+"，年纪增加"+HIR+(string)level+NOR+"岁。\n",this_object());
        return 1;
        }
        else
        return notify_fail("age sb. 增加的年纪。\n");
}

//  SKILL 武功
int skill(string str)
{
        object me;
        object target;
        string name,skills;
        int level;
        if(!str)        return notify_fail("skill 某人 技术 等级\n");
        me=this_player();
        if(sscanf(str,"%s %s %d",name,skills,level)==3)         {
        if(!(target=present(name,environment(me))))
                return notify_fail("这儿没有这么个人。\n");
        target->set_skill(skills,level);
        write("修改"+WHT+target->query("name")+NOR"的"+YEL+to_chinese(skills)+NOR+"武功为"+HIR+(string)level+NOR"级。\n",this_object());
        return 1;
        }
        else
        return notify_fail("skill 某人 技术 等级\n");
}
// 把人封住
int fengplayer (string str)
{
  object ob;
  if(str=="kittt") return notify_fail("你是不是想死啊！\n");
  if (!str) return notify_fail("feng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("有这个人吗?\n");
  tell_object(ob,"你的眼睛突然一片模糊，好象有人蒙住你了...\n");
  ob->set_temp("block_msg/all",1);
  ob->disable_player(HIR "<失去知觉中>" NOR);      
  return 1;    
}
// 把人解封
int jiefengplayer (string str)
{
  object ob;
  if (!str) return notify_fail("jiefeng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("有这个人吗?\n");   
  ob->set_temp("block_msg/all",0);
  ob->enable_player(); 
  tell_object(ob,"有人很你说道：“恭喜发财”，你终于可以...\n");
  return 1;
}
//  XING 使人苏醒
int xing (string str)
{
  object who;
  if (!str) return notify_fail ("xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("没有"+str+"呀？\n");}
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}
// HUN 使人昏倒

int hun (string str)
{
  object who;
  if (!str) return notify_fail ("你疯了，把自己弄晕！\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("没有"+str+"呀？\n");}
  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
  return 1;
}
//  BX 变性手术
int bx(string arg)
{
  object bxid,me;
  me=this_player();
  if(arg=="kittt") return notify_fail("你奶奶的想死啊！\n");
  if (arg!=NULL_VALUE){
    bxid = LOGIN_D->find_body(arg);
    if (!bxid) return notify_fail("在网上好象没这个人呀！\n");
    }
  if (arg) {
    if(arg=="kittt") return notify_fail("你想死啊！\n");
    if(bxid->query("gender")=="女性") bxid->set( "gender", "男性" );
    else bxid->set( "gender", "女性" );
    message("shout", HIM "【谣言】某人：听说"+me->query("name")+"成功的对" 
    +bxid->query("name")+"进行了一次变性手术。\n" NOR,users());
    bxid->save();
    return 1;
  }
}
//  YAO 取钱
int yao (string arg)
{
        string kind;
        int amount;
        object n_money;
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("usage: yao <多少钱> <钱币种类>\n");
        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail("好象没有这种钱呀？摇个屁呀！\n");
        if( amount < 1 )
                return notify_fail("呵呵，还是没有。\n");
        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);
 message_vision( sprintf(HIY "$N使劲的掏自己的口袋，突然从袋子里掏出%s%s%s。\n" NOR,
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
