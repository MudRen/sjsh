// xintai 2/7/2001
// copied a lot of useful functions from "/d/npc/npc.c"��

#include <ansi.h>

inherit NPC;
void pre_leave();
void leave();

void create()
{
  string name, id;


  set_name("�ٱ�", ({ "guan bing", "bing" }) );
  set("gender", "����" );
  set("long", "��»ɽ����ʿ����������Բ����Ŀ������\n"
     );
  set("title", "��ǲ����");
  set("age", 35+random(10));
  set("attitude", "peaceful");
  set("str", 30);
  set("int", 30);
  set_skill("spear", 70);
  set_skill("force", 70);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set_skill("yanxing-steps", 70);
  set_skill("bawang-qiang", 70);
  set_skill("lengquan-force", 70);
  set_skill("unarmed", 70);
  set_skill("changquan", 70);
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 500);
  set("eff_sen", 500);
  set("sen", 500);
  set("max_kee", 800);
  set("eff_kee", 800);
  set("kee", 800);
  set("force", 800);
  set("max_force", 400);
  set("mana", 800);
  set("max_mana", 400);
  set("force_factor", 20);
  set("combat_exp", 80000);
  set("daoxing",80000);
  set("chat_msg", ({
     (: random_move :)
  }));
  
  setup();
  carry_object("/d/obj/weapon/spear/changqiang")->wield();
  carry_object("/d/obj/cloth/bingfu")->wear();
}

void init()
{
    object me=this_object();
    int t=query("stay_time");

    ::init();
    
    if(t && time()>(t+360)) {
        remove_call_out("leave");
        call_out("leave",1);
        return;
    }

    if(t && time()>t) {
        remove_call_out("pre_leave");
        call_out("pre_leave",360);
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

int copy_status(object me, object ob)
{
  object *inv;
  mapping hp_status, skill_status, map_status;
  string *skillnames, *mapnames;
  int i;

  hp_status = ob->query_entire_dbase();

  me->set("str", hp_status["str"]);
  me->set("per", hp_status["per"]);
  me->set("int", hp_status["int"]);
  me->set("age", hp_status["age"]);

  me->set("gin",         hp_status["gin"]);
  me->set("max_kee",     hp_status["max_kee"]);
  me->set("eff_kee",     hp_status["eff_kee"]);
  me->set("kee",         hp_status["kee"]);
  me->set("max_sen",     hp_status["max_sen"]);
  me->set("eff_sen",     hp_status["eff_sen"]);
  me->set("sen",         hp_status["sen"]);
  me->set("max_force",   hp_status["max_force"]);
  me->set("force",       hp_status["force"]);
  me->set("max_mana",    hp_status["max_mana"]);
  me->set("mana",        hp_status["mana"]);
  me->set("gender",      hp_status["gender"]);
  me->set("daoxing",     hp_status["daoxing"]);
  me->set("combat_exp",  hp_status["combat_exp"]);
  me->set("actions",     hp_status["actions"]);

  me->set("eff_kee", me->query("max_kee"));
  me->set("kee",     me->query("max_kee"));
  me->set("eff_sen", me->query("max_sen"));
  me->set("sen",     me->query("max_sen"));
  me->set("force",   me->query("max_force")*2);
  me->set("mana",    me->query("max_mana")*2);
  
  skill_status = me->query_skills();
  if ( mapp(skill_status) )
  {
    skillnames  = keys(skill_status);

    for(i=0; i<sizeof(skillnames); i++) {
      me->delete_skill(skillnames[i]);
    }
  }

  skill_status = ob->query_skills();
  if ( mapp(skill_status) )
  {
    skillnames  = keys(skill_status);

    for(i=0; i<sizeof(skillnames); i++) {
      me->set_skill(skillnames[i], skill_status[skillnames[i]]+random(50));
    }
  }
  
  me->set("force_factor",query("max_force")/20);
  me->set("mana_factor",query("max_mana")/20+1);
  me->set("daoxing",query("daoxing")+random(query("daoxing")*2));
  me->set("combat_exp",query("combat_exp")+random(query("combat_exp")*2));
    
  if ( mapp(map_status = me->query_skill_map()) ) {
    mapnames = keys(map_status);

    for(i=0; i<sizeof(mapnames); i++) {
      me->map_skill(mapnames[i]);
    }
  }

  map_status = ob->query_skill_map();
  if ( mapp(map_status) ) 
  {
    mapnames  = keys(map_status);

    for(i=0; i<sizeof(mapnames); i++) {
      me->map_skill(mapnames[i], map_status[mapnames[i]]);
    }
  }
  command ("unwield qiang");
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
  me->set("have_bian",1);// ��ֹplayer��ν�ɱ���weapon,armor��
  me->set("owner",ob);// �����ڽ�����ʱ���жϣ���ֹplayer���ס�
  reset_eval_cost();
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();
  
  if (!me->query("have_bian") )
  {
    copy_status(me, ob);
    message_vision ("$N��Ц����˳���߲�������������\n",me);
  }  
  ::kill_ob(ob);
}


void pre_leave()
{
        object me=this_object();
        if(me->is_fighting() || me->is_busy())
        return;
        leave();
}

void leave()
{
      if(this_object()) {
        if(environment())
{
        command("say �ٺ٣���ô��û�˸������������������ˡ�����");
        message("vision",HIB + name() + 
                " С�ܲ����ˡ�" NOR,environment());
}
        destruct(this_object());
      }
      return;
}
