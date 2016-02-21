/* ����֮�� 2.0 */
// by happ 2000.9.14


#include <ansi.h>
inherit NPC;
int random_go(object me, string* dirs,int i);
mapping maps;

string *first_name = ({ "����","����","����","����","����","����" });
string *last_name  = ({ "ħ��ɱ��","ħ��̿�" });

void create()
{
   string name;
        name = COLOR_D->random_color()+first_name[random(sizeof(first_name))];
        name += COLOR_D->random_color()+last_name[random(sizeof(last_name))]+NOR;
        set_name(name, ({"sha shou"}));
  set("age", 25 + random(10) );
  set("max_kee", 500*(1+random(5)) );
  set("kee",query("max_kee"));
  set("max_sen", 500*(1+random(5)) );
  set("sen",query("max_sen"));
  set("max_force", 500*(1+random(5)) );
  set("force_factor", 20*(1+random(5)) );
  set("force", 800);
  set("combat_exp", 200000*(7+ random(7)) );
  set("daoxing", 200000*(5+ random(5)) );
  set_skill("sword", 25*(random(10)+1));
  set_skill("snowsword", 25*(random(10)+1));
  set_skill("unarmed",25*(random(10)+1));
  set_skill("parry",25*(random(10)+1));
  set_skill("dodge",25*(random(10)+1));
  set_skill("balei",25*(random(10)+1));
  set_skill("huxiaoquan",25*(random(10)+1));
  map_skill("sword", "snowsword");
  map_skill("unarmed","boxing");
  map_skill("parry", "snowsword");
  map_skill("dodge", "balei");  
        set("chat_chance",90);
        set("chat_msg", ({ 
                (: random_move :)
                }));

  setup();
  carry_object("/d/obj/stey/sttt")->wield();
}

void init()
{
   object ob=this_player(), me=this_object();
   ::init();
                   remove_call_out("greeting");
                   call_out("greeting",30*60);
}
void greeting()
{
        object me=this_object();
        tell_room(environment(me),"ֻ��ħ��ɱ��˲������˾��죬���������У�\n");

        destruct(me);
}

int random_go(object me, string* dirs,int i)
{
        int j,k,m;
        object  newob;
        mixed*  file;

        me=this_object();

        if( !sizeof(dirs) )  return 1;

        file = get_dir( dirs[i]+"*.c",-1);
        if( !sizeof(file) )             return 1;

        k = sizeof(file);

      while(1)  {
           j = random(k);
           if( file[j][1] > 0 )         break;     
                  }

     if( (newob=find_object(dirs[i]+file[j][0])) ) 
        j = random(k);

     if( (newob=find_object(dirs[i]+file[j][0])) )

          {
                me->move( newob );
          }

        else  {
                seteuid(getuid(me));
                newob = new(dirs[i]+file[j][0]);
                if (newob)   
                        me->move(newob);
        else   {
                        tell_object(me, "Error.\n");
                }
        }  
        return 1;

}

void kill_ob(object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

void die()
{
       object ob=this_object()->query_temp("my_killer");
        if(ob) {
        ob->add("combat_exp",500);
        ob->add("daoxing",500);
        ob->add("potential",150);
        }
//added by kissess for solving bugs
        if( environment() ) {
        message("sound", BLINK HIB"ɱ�ֶ�ݺݵĽе����һ������ģ�\n\n"NOR, environment());
        }
        destruct(this_object());
}
