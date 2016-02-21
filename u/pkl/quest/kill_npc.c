#include <ansi.h>

inherit NPC;
#include <ansi.h>
#define NAME_D    __DIR__"random_name"
void _leave();
void leave();
int announced=0;
string *color_title = ({"�ս�ɱ��","���ֿտ�",});

void create()
{
        mapping name;
   object weapon;
        int i=random(10);

        if( i > 5 )
          name = NAME_D->man_name();
        else
          name = NAME_D->woman_name();
        set_name(name["name"],({name["id"]}));
        if( i > 5 )
          set("gender", "����" );
        else
          set("gender", "Ů��" );
        set("title", color_title[random(sizeof(color_title))]);
        set("long", "��������ɫ��װ����������һ��ڲ���ֻ¶��һ˫�۾����������䡣\n");
        set("age", random(20)+25);      
        set("str", 20+random(5));
        set("int",20+random(5));  
        set("con",20+random(5));     
        set("combat_exp",5000);
        set("attitude", "heroism");
        set_skill("dodge",50);
        set_skill("moshenbu",50);
        set_skill("unarmed",50);
        set_skill("force",50);
        set_skill("dao",50);
        map_skill("dodge","moshenbu");
        map_skill("force","dao");
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }));
        setup();
  if( i > 5 )
   {
    carry_object("/d/obj/cloth/linen")->wear();
    carry_object("/d/obj/cloth/buxie")->wear();
   }
  else
   {
    carry_object("/d/obj/cloth/skirt")->wear();
    carry_object("/d/obj/cloth/shoes")->wear();
    }
        if (random(7))
           weapon=new("/d/obj/weapon/hammer/jingua");
        else if (random(6))
           weapon=new("/d/obj/weapon/sword/qingfeng");
        else if (random(5))
           weapon=new("/d/obj/weapon/stick/xiangmo");
        else if (random(4))
           weapon=new("/d/obj/weapon/axe/huafu");
        else if (random(3))
           weapon=new("/d/obj/weapon/spear/changqiang");
        else if (random(2))
          weapon=new("/d/obj/weapon/staff/budd_staff");
        else 
           weapon=new("/d/obj/weapon/blade/jindao");
        weapon->move(this_object());
        command("wield all");
}

void init()
{
    object me=this_object();
    object who=this_player();
    int type;
    int t=query("stay_time");

    ::init();
    
    if(t && time()>(t+900)) {
        remove_call_out("leave");
        call_out("leave",1);
        return;
    }

    if(t && time()>t) {
        remove_call_out("_leave");
        call_out("_leave",300);
    }
    
    if(!living(this_object())) return;
    if(!living(who)) return;
    if( who->query("id") != query("target_id"))
    return;
    type=query("type");
    switch (type) {
        case 0:{
            object leader=query_leader();
            if(leader && present(leader, environment(me))) {
                break;
            }
            set_leader(who);
            message_vision("$N����$n������ֱ����ˮ���ٺ٣�����\n",
                    this_object(), who);
            break;
            }
        case 1:
                if(!announced) {
                  message_vision("$N����$n�����һ���������������������⣡\n",
                        this_object(), who);
                  announced=1;
                }
                if(random(4)>0)
                {
                    set_leader(who);
                }
                else
                {
                    set_leader(0);
                }
            break;
        case 2:
        {
            add_action("do_block","",1);
            break;
            }
    }
    remove_call_out("check_room");
    call_out("check_room",2);
}

void check_room()
{
    object me=this_object();
    object env=environment(me);
    
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
                env->query("no_magic"))) {
        random_move();
    }
}

void copy_status(object me,object ob)
{
        object *inv;
        mapping skill_status,map_status;
        string *sname,*mname;
        int i, eff_dx, nk_factor;

        me->set("str",ob->query("str"));
        me->set("int",ob->query("int"));
        me->set("con",ob->query("con"));
        me->set("per",ob->query("per"));
        me->set("cor",ob->query("cor"));
        me->set("spi",ob->query("spi"));
        me->set("cps",ob->query("cps"));
        me->set("kar",ob->query("kar"));

        me->set("max_kee",ob->query("max_kee"));
        me->set("eff_kee",ob->query("eff_kee"));
        me->set("kee",ob->query("kee"));

        me->set("max_gin",ob->query("max_gin"));
        me->set("eff_gin",ob->query("eff_gin"));
        me->set("gin",ob->query("gin"));

        me->set("max_sen",ob->query("max_sen"));
        me->set("eff_sen",ob->query("eff_sen"));
        me->set("sen",ob->query("sen"));

       me->set("max_force",ob->query_skill("force") / 2);
          me->set("force",ob->query("max_force")*2);
        me->set("force_factor",ob->query("force_factor"));

        me->set("max_mana",ob->query("max_mana"));
          me->set("mana",ob->query("max_mana") * 2);
       me->set("mana_factor",((int)ob->query("max_mana") / 20)+1);

        me->set("combat_exp",ob->query("combat_exp") * 6/5);

        if (skill_status=ob->query_skills())
        {
        sname=keys(skill_status);
        for(i=0;i<sizeof(skill_status);i++) {
                me->set_skill(sname[i],skill_status[sname[i]]+random(10));
        }
        }

        if (map_status = ob->query_skill_map())
        {
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++) {
                me->map_skill(mname[i], map_status[mname[i]]);
        }
        }
        inv = all_inventory(ob);
        for(i=0; i<sizeof(inv); i++)
        {
                if( inv[i]->query("weapon_prop") 
                &&  inv[i]->query("equipped")
                &&  !inv[i]->query_unique() ) {
                        carry_object(base_name(inv[i]))->wield();
                }
                else if( inv[i]->query("armor_prop") 
                &&  inv[i]->query("equipped") 
                &&  !inv[i]->query_unique() ) {
                        carry_object(base_name(inv[i]))->wear();
                }
        }

        me->set("stay_time",time()+600+random(60));
        me->set("nk_gain", 100+random(50));
        eff_dx = ob->query("combat_exp");
        if(eff_dx>1500000) 
        nk_factor = 9;
        else if(eff_dx>1000000)
        nk_factor = 8;
        else if(eff_dx>600000)
        nk_factor = 7;
        else if(eff_dx>300000)
        nk_factor = 6;
        else if(eff_dx>100000)
        nk_factor = 5;
        else if(eff_dx>50000)
        nk_factor = 4;
        else if(eff_dx>20000)
        nk_factor = 3;
        else if(eff_dx>10000)
        nk_factor = 2;
        else nk_factor = 1;
        me->set("nk_factor", nk_factor);
        me->set("type", random(3));
        reset_eval_cost();
}

int invocation(object ob)
{
        object me=this_object();
        copy_status(me,ob);
        return 1;
}

int do_block(string arg)
{
    object me=this_object();
    object who=this_player();
    string verb=query_verb();
    int t;
    
    if(wizardp(who) && !visible(who)) return 0;
    if(me->is_fighting()) return 0;

    if(verb!="go" &&
            verb!="fly" &&
            !(environment() && environment()->query("exits/" + verb)))
        return 0;

    if(who->query_temp("songxin_quest/allow_to_go")) {
        who->delete_temp("songxin_quest/allow_to_go");
        who->delete_temp("songxin_quest/leave_time");
        return 0;
    }
    t=who->query_temp("songxin_quest/leave_time");
    if(t>0 && time()>t) {
        who->delete_temp("songxin_quest/leave_time");
        message_vision("$n��$Nһ����ע�⣬��æ���˹�ȥ��\n",me,who);
        return 0;
    }
    if(t==0) {
        t=time()+30+random(90);
        who->set_temp("songxin_quest/leave_time",t);
        message_vision("$N�͵�����������$n��ǰ�������е���\n"+
                "          ��ɽ���ҿ������������ԣ�\n"+
                "          Ҫ���·����������·�ƣ�\n\n",me,who);
    } 
    
    tell_object(who,me->name()+"һ��ץס���㣡\n");
    return 1;
}

int accept_object (object who, object ob)
{
  object me;
  me = this_object();

  if ((! ob) ||
       ob->value() < 100000)
  {
    message_vision ("$Nһ���ۣ�����㶫����������ˣ�����\n", me);
    return 1;
  }
  who->set_temp("songxin_quest/allow_to_go", 1);
  message_vision ("$N�ٺٺټ�����Ц���������ˣ������"
          +"�ɱ������ٿ����㣡\n",me);
  return 1;
}

varargs int receive_damage(string type, int damage, object who)
{
  object me=this_object();
  call_out("exertheal",1,me);
  return ::receive_damage(type,damage,who);
}

void exertheal(object me) 
{
  me->command("exert recover");
}

void die()
{
        object ob;
        ob = query_temp("last_damage_from");

        if (!ob)
        {
                leave();
                return; 
        }

       if ( userp(ob) && ob->query("id") == query("target_id") )
        {
         ob->add_temp("npc_kill",1);
         ob->delete_temp("kill_target_name");
         ob->delete_temp("kill_target_id");
         ob->delete_temp("kill_where");  

         if (present("secret letter", this_object()))
           this_object()->command_function("drop secret letter");
        }

        message_vision("$N���ˡ�\n",this_object());
        destruct(this_object());

}

void unconcious()
{
  if (query("kee")<0 || query("sen")<0) die();
   else ::unconcious();
}

void heart_beat()
{
        if (!query_temp("weapon") && !query_temp("added"))
        {
        set_temp("added", 1);
        set("force_factor",100);
          set("force",query("max_force")*3/2);
        }
        if (query("eff_kee")<query("max_kee"))
        {
        if (random(10))
        call_out("exertheal",1,this_object());
        }

        ::heart_beat();
}


void _leave()
{
        object me=this_object();
        if(me->is_fighting() || me->is_busy())
        return;
        leave();
}

void leave()
{
      if(this_object()) 
      {
        if(environment())
          {
          command("say �ٺ٣���ô�ò��������������������ˡ�����");
          message("vision",HIB + name() + 
                  "����һ��......\n" NOR,environment());
          }
        destruct(this_object());
      }
      return;
}

int attack()
{
        object opponent;
        clean_up_enemy();
        opponent = select_opponent();
        if( objectp(opponent) ) {
        if(opponent->query("id") == query("target_id")
                        && userp(opponent)
                        && !living(opponent)
                        && environment()==environment(opponent)) {
                    call_out("leave",1);
                    return 0;
                }
                set_temp("last_opponent", opponent);
                COMBAT_D->fight(this_object(), opponent);
                return 1;
        } else
                return 0;
}
