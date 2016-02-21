#define NAME_D   __DIR__"random_name"

inherit NPC;

void create()
{
   mapping name;
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
   set("age",30+random(30));
   set("attitude", "peaceful");
   set("quest_npc",1);
   set("str", 25);
   set("con", 30);
   set("int", 30);
   set("spi", 30);
   set("combat_exp",1000);      
   set("chat_chance",80);
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
}

void init()
{
    ::init();
    call_out("dest",900+random(300));
}

void dest()
{
      object me = this_object();
      tell_room(environment(me),me->query("name")+"�Ҵ��뿪��\n");  
      destruct(me);
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        command("say ����ô����Ķ��֣�\n");
}

void die()
{
  set("eff_kee", 2200);
  set("eff_gin", 2200);
  set("eff_sen", 2200);

  set("kee", 2200);
  set("gin", 2200);
  set("sen", 2200);
  set("force", 1200);
  set("mana", 2500);
}

void unconcious()
{
  die ();
}

