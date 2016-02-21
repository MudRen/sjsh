//by koker@sjsh 20020107..
#include <weapon.h>
#include <dbase.h>
#include <ansi.h>

inherit F_UNIQUE;
//inherit NECK;
inherit SWORD;
object offensive_target(object me);
void create()
{
        set_name(HIG"���׽�"NOR, ({ "jinglei sword","sword","jian"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIG"������ɽ�ɵ���ɽ����֮һ��\n"NOR);
                set("material", "force");
        }
        init_sword(600);
       setup();
}
int init()
{
   add_action("do_wear","wield");
   add_action("do_remove","unwield");
      remove_call_out("do_melt");
      call_out("do_melt", 1);
}

void do_melt()
{
	if(this_object()) call_out("melt", 10+random(10));
}

void melt()
{
	object env;

	if(!this_object()) return;

	env=environment(this_object());

	if( env->is_character() )
	{//a player or a NPC.
		if( (int)env->query_skill("zixia-shengong", 1) < 100 )
		{
			if(environment(env))
				message_vision(HIW"�����ϼ�񹦻������죬���׽�ͻȻ����һ���׹�������������ˡ�\n", env);
			destruct(this_object());
			return;
		}
	}

	else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
	{//a room.
		if( (string)env->query("outdoors") != "shushan" )
		{
			tell_object(env,HIW"�����ϼ�񹦻������죬���׽�ͻȻ����һ���׹�������������ˡ�\n");
			destruct(this_object());
			return;
		}
	}
}

int do_wear(string arg)
{
   string str,name;
     if (arg!="ice sword"&&arg!="sword"&&arg!="jian")
                  return 0;
    name=this_object()->query("name");
          str="$N�������������Ƽ�ͻȻ���һ����ʵ�"+name+"\n";
  this_object()->set("wield_msg",str);
    remove_call_out("cool");
    call_out("cool",1,this_object());
    return 0;
}
int do_remove(string arg)
{
   string str,name;
     if (arg!="ice sword"&&arg!="sword"&&arg!="jian")
                  return 0;
    name=this_object()->query("name");
    str="$Nһ����,����������"+name+"˲����ʧ�ڿ���.\n";
    this_object()->set("unwield_msg",str);
  remove_call_out("cool");
   return 0;
}
void cool(object who,object ob)
{
     object target;
     int ap,dp,damage;
     string msg;
          
string type;
type = ob->query("armor_type");
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
  if( who->is_fighting())
     {
        target = offensive_target(who);
  if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        msg = HIR"$N�ľ��׽�����Ȼ���䣬ɲʱ�����׵�������ɽ�����ѣ�\n"NOR;
//divid by 10;

                ap = 5000000;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap + dp) > dp )
                 {
                        damage = 500+random(300);
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) 
                        {
                                msg += HIC "���$n��ܲ��������׵��������ţ��ֱ��ػ��յ�Ƥ�����á�\n
��ɽʯ�ҵ�Ƥ��Ѫ��������������˫�ۣ��ֱ�ˮ����͸�������������ѡ�\n" NOR;

                                target->receive_damage("sen", damage*8/5);
                                target->receive_wound("sen", damage*2/3);
                                target->receive_damage("kee", damage*8/5);
                                target->receive_wound("kee", damage/2);
                                target->start_busy(5);
                        } 
            else
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note damage<0.
                msg += HIC "\n˭֪$n���޷�Ӧ��\n" NOR;   
                }
                else
                        msg += "���Ǳ�$n�㿪�ˡ�\n";

                message_vision(msg, who, target); 
        }
call_out("cool",7,who,ob);
}
