//  ����֮��  ������
//  by happ@YSZZ 2000.04.09
//  /d/sky/npc/leigong.c �׹�
// updated by xintai@ty 2/25/2001

inherit NPC;
#include <ansi.h>
int do_drop(object, object);

void create()
{
       set_name("�׹�", ({"lei gong", "lei", "gong"}));
       set("long", "һ������ܳ��Ĺ��ˣ����г�һ��������\n");
       set("gender", "����");
       set("age", 70);
       set("attitude", "friendly");
       set("per", 30);
       set("max_kee",8000);
       set("max_sen", 8000);
       set("force", 5000);
       set("max_force", 5000);
       set("force_factor", 80);
       set("max_mana", 1200);
       set("mana", 2300);
       set("mana_factor", 20);
       set("combat_exp", 1200000);

       set("eff_dx", 250000);
       set("nkgain", 400);
       set("class","taoist");
       set_skill("literate", 90);
       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("parry", 120);
       set_skill("stick", 120);
       set_skill("spells", 120);
       set_skill("dao", 120);
       set_skill("puti-zhi", 120);
       set_skill("wuxiangforce", 120);
       set_skill("force", 120);
       set_skill("qianjun-bang", 120);
       set_skill("jindouyun", 120);
       map_skill("spells", "dao");
       map_skill("unarmed", "puti-zhi");
       map_skill("force", "wuxiangforce");
       map_skill("stick", "qianjun-bang");
       map_skill("parry", "qianjun-bang");
       map_skill("dodge", "jindouyun");
       set("chat_chance_combat", 40);
       set("chat_msg_combat", ({
          (: cast_spell, "thunder" :),
                "�׹�ŭ�������������ҵ�������ġ�\n"
        }) );

        set("inquiry", ([
           "������" : "�����ҵı�����",
]) );

	setup();

        carry_object("/d/lingtai/obj/xiangpao")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
      	    carry_object("/d/obj/baowu/leizhu");

}


int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

/*void die()
{
        object ob = query_temp("my_killer");

        message_vision(HIM"ֻ��$N��һ���������ݽ��������졣\n"NOR,this_object());
        message_vision(HIM"$N���һ������ȥҲ��\n"NOR,this_object());
	zhu->move(ob);
        destruct(this_object());
}*/

void die()
{
        int i;
        string file;
        object *inv;

        if( environment() ) {
        message("sound", "\n\nֻ���׹���һ���������ݽ��������졣\n", environment());
        command("sigh");
        message("sound", "\n�׹����һ������ȥҲ��\n", environment());
        inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("no_drop")) continue;
                do_drop(this_object(), inv[i]);
//              if (stringp(file = find_command("drop")) && 
//                      call_other(file, "do_drop", this_object(), inv[i])) ;
        }
        }

        destruct(this_object());
}

int do_drop(object me, object obj)
{
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
            else {
                 message_vision( sprintf("$N����һ%s$n��\n",
                 undefinedp(obj->query_temp("unit"))?
                         "��":obj->query_temp("unit")
                         ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
           else {
             message_vision( sprintf("$N����һ%s$n��\n", obj->query("unit")),
                     me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ���
                   ��\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}


void unconcious()
{
        die();
}
