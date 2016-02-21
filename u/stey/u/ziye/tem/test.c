// weapond.c
// keenness Ϊ����������

#include <ansi.h>
#include <combat.h>

void remove_broken_weapon(object ob);
int sharpless(object obj);

mapping weapon_actions = ([
        "slash": ([
                "damage_type":  "����",
                "action":               "$N�Ӷ�$w��ն��$n��$l",
                "parry":                20,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "slice": ([
                "damage_type":  "����",
                "action":               "$N��$w��$n��$l��ȥ",
                "dodge":                20,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "chop": ([
                "damage_type":  "����",
                "action":               "$N��$w����$n��$l������ȥ",
                "parry":                -20,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "hack": ([
                "action":               "$N����$w����׼$n��$lһ���ҿ�",
                "damage_type":  "����",
                "damage":               30,
                "dodge":                30,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "thrust": ([
                "damage_type":  "����",
                "action":               "$N��$w��$n��$l��ȥ",
                "dodge":                15,
                "parry":                -15,
                ]),
        "pierce": ([
                "action":               "$N��$w��$n��$l�ݺݵ�һͱ",
                "damage_type":  "����",
                "dodge":                -30,
                "parry":                -30,
                ]),
        "wave": ([
                "action":               "$Nһ��$w����$n��$lһ��",
                "damage_type":  "����",
                "dodge":                -20,
                "parry":                30,
                ]),
        "whip": ([
                "action":               "$N��$wһ���$n��$l��ȥ",
                "damage_type":  "����",
                "dodge":                -20,
                "parry":                30,
                ]),
        "impale": ([
                "action":               "$N��$w��$n��$lֱ����ȥ",
                "damage_type":  "����",
                "dodge":                -10,
                "parry":                -10,
                ]),
        "rake": ([
                "action":               "$N�߾�$w����$n��$l����һ��",
                "damage_type":  "����",
                "dodge":                -15,
                "parry":                15,
                ]),
        "strike": ([
                "action":               "$Nһ�����������$w������$n��$l����һ��",
                "damage_type":  "����",
                "dodge":                -10,
                "parry":                -10,
                ]),
        "bash": ([
                "action":               "$N����$w����$n��$l����һ��",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "crush": ([
                "action":               "$N�߸߾���$w����$n��$l��ͷ����",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "slam": ([
                "action":               "$N����$w����¶�׹⣬�͵ض�׼$n��$l���˹�ȥ",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "throw": ([
                "action":               "$N��$w��׼$n��$l���˹�ȥ",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                ]),
        "shoot": ([
                "action":               "$N�乭�����ֻ����ಡ���һ����$w�ѵ�$n��$l",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                ]),
]);

varargs mapping query_action()
{
        string verb, *verbs;
        object me, wp1, wp2;

        verbs = previous_object()->query("verbs");

        // 4/27/98 mon changed following 4 "hit" to "impale"
        // as "hit" is not defined in weapon_actions.
        if( !pointerp(verbs) ) return weapon_actions["impale"];
        else {
                verb = verbs[random(sizeof(verbs))];
                if( !undefinedp(weapon_actions[verb]) ) return weapon_actions[verb];
                else return weapon_actions["impale"];
        }       
}

varargs mapping query_apply_action()
{
        string verb, *verbs;
        object me, wp1, wp2;

        verbs = previous_object()->query("apply/verbs");

        if( !pointerp(verbs) ) return weapon_actions["impale"];
        else {
                verb = verbs[random(sizeof(verbs))];
                if( !undefinedp(weapon_actions[verb]) ) return weapon_actions[verb];
                else return weapon_actions["impale"];
        }       
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
        if( objectp(weapon) ) {
                if( (int)weapon->query_amount()==1 ) {
                        weapon->unequip();
                        tell_object(me, "\n���" + weapon->query("name") + "�����ˣ�\n\n");
                }
                weapon->add_amount(-1);
        }
}

void bash_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp, z1, z2;
              string sharp1, sharp2;
        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon") ) {
                  sharp1=weapon->query("material");
                  switch (sharp1)
                  {case "wood" : z1=5 ; break;
                  case "iron" :  z1=10 ; break;
                  case "cuprum" : z1=15 ; break;
                  case "steel" : z1=20 ; break;
                  case "blacksteel" : z1=25 ; break;
                   case "silver" : z1=30 ;break;
                  case "crimsonsteel" : z1=35 ; break;
                  case "purplegold" :z1=40 ; break;
                  case "diamond" : z1=200 ; break;
                  default : z1=0 ;break;
                   }   
                  sharp2=ob->query("material");
                  switch (sharp2)
                  {case "wood" :z2=5 ; break;
                  case "iron" :  z2=10 ; break;
                  case "bronze" : z2=15 ; break;
                  case "steel" : z2=20 ; break;
                  case "blacksteel" : z2=25 ; break;
                  case "silver" : z2=30 ; break ;
                  case "crimsonsteel" : z2=35 ; break;
                  case "purplegold" : z2=40 ; break;
                  case "diamond" : z2=200 ; break;
                  default : z2=0 ;break;
                   }   
                wap = (int)weapon->weight() / 500
                                          +z1
                        + (int)me->query("str");
                wdp = (int)ob->weight() / 500
                        +z2
                        + (int)victim->query("str");
                wap = random(wap);
                if( wap > 2 * wdp ) {
                        message_vision(HIW "$Nֻ��������" + ob->name() + "�ѳֲ��������ַɳ���\n" NOR,
                                victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision("$Nֻ��������" + ob->name() + "һ����Щ���֣�\n",
                                victim);
                } else if( wap > wdp / 2 ) {
                        message_vision(HIW "ֻ������ž����һ����$N���е�" + ob->name()
                                + "�Ѿ���Ϊ���أ�\n" NOR, victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "�ϵ���" + ob->query("name"));
                        //ob->set("value", (int)ob->query("value") / 20);
                        ob->set("value", 0);
                        //so can't sell broken weapon.
                        //otherwise may have problem in pawn shop
                        //when the broken weapon disappeared.
                        ob->set("weapon_prop", 0);
                        ob->set("armor_prop", 0);
                        call_out("remove_broken_weapon",
                          random(300)+60,ob);
                        //added by mon 10/27/97
                        victim->reset_action();
                } else {
                        message_vision("$N��" + weapon->name() + "��$n��" + ob->name()
                                + "�����ð�����Ļ��ǡ�\n", me, victim);
                }
        }
}

void fleshings_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp, z1, z2, onfall;
              string sharp1, sharp2;
        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon") ) {
                  sharp1=weapon->quary("material");
                  switch (sharp1)
                  {case "wood" : z1=5 ; break;
                  case "iron" :  z1=10 ; break;
                  case "bronze" : z1=15 ; break;
                  case "steel" : z1=20 ; break;
                  case "blacksteel" : z1=25 ; break;
                  case "silver" : z1=30 ; break;
                  case "crimsonsteel" : z1=35 ; break;
                  case "purplegold" : z1=40 ; break;
                  case "diamond" : z1=200 ; break;
                  default : z1=0 ;break;
                   }   
                  sharp2=ob->query("material");
                  switch (sharp2)
                  {case "wood" :z2=5 ; break ;
                  case "iron" :  z2=10 ; break;
                  case "bronze" : z2=15 ; break;
                  case "steel" : z2=20 ; break;
                  case "blacksteel" : z2=25 ; break;
                  case "silver" : z2=30 ; break;
                  case "crimsonsteel" : z2=35 ; break;
                  case "purplegold" : z2=40 ; break;
                  case "diamond" : z2=200 ; break;
                  default : z2=0 ;break;
                   }   
                    if (z1> 50)
                       z1=50;
                   onfall=   (int)me->query("str")
                              -(int)victim->query("str");
                     if (onfall>20)
                           onfall=20;
                     else 
                        {if (onfall<0)
                            onfall=5;}
           {
                wap = (int)weapon->keenness()
                                          + z1
                        + (int)me->query("str");
                wdp = (int)ob->weight() / 500
                                          + z2
                        + (int)victim->query("str");
                wap = random(wap);
                if( wap > wdp / 2 ) 
                 {

                        if (ob->query("weapon_prop/damage")>20)
                             {
                                            message_vision(HIW "$Nֻ��������" + ob->name() + "�Aॵ�����ԭ���Ǳ�����һ�ڡ�\n" NOR, 
                              victim);
                              ob->unequip();
                              ob->add("weapon_prop/damage", -onfall);
                              ob->add("weight", -200);
                              ob->wield ();
                             }
                        else
                            {
                                            message_vision(HIW "$Nֻ��������" + ob->name() + "һ�ᣬԭ���Ǳ�����������?\n" NOR,
                              victim);
                              ob->unequip();
                              ob->move(environment(victim));
                              ob->set("name", "�ϵ���" + ob->query("name"));
                              ob->set("value", 0);
                              ob->set("weapon_prop", 0);
                              ob->set("armor_prop", 0);
                              call_out("remove_broken_weapon",
                              random(300)+60,ob);
                              victim->reset_action();
                            }
                                           
                } 
                  else     {
                        message_vision("$N��" + weapon->name() + "��$n��" + ob->name()
                                + "�����ð�����Ļ��ǡ�\n", me, victim);
                            }
          }  }
}


void remove_broken_weapon(object ob)
{
  if(ob && environment(ob)) {
    tell_object(environment(ob),
      "һ��΢�紵����"+ob->name()+"��ΪƬƬ��������ʧ�����ˡ�\n");
    destruct(ob);
  }
}


