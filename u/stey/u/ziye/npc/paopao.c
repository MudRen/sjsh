#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIW"��ˮ����"NOR,({"pao pao"}));
  set("long", "
    ��ҹ��С���ˣ���ˮ���ݣ���������Ӧ�޸���ҹ�ģ���ҹҲ\n
˵����Ҫ������ΪMUD����Ư��������������뿪�ˣ����Ҳû\n
�ܳɻ飬����ʲô��ϵ�أ���ҹ���ǰ����ŵ����Լ��ķ����\n
�����ϴ����˸���Ư�����·�����Ϊ����ļ��
                 <<<<<forever>>>>>\n"
    );
  set("title",HIR"��ҹ��С����"NOR);
  set("gender","Ů��");
  set("per",40);
  set("age",18);
  set("max_force",5000);
  set("force",10000);
  set("max_mana",5000);
  set("mana",10000);
  set_skill("dodge",700);
  set_skill("moondance",700);
  map_skill("dodge","moondance");
  set("combat_exp",50);
  set("daoxing",5000000);
  set("inquiry",([
       "name": "�ҽ���ˮ���ݣ�����������ˮ���ݡ�\n",
       "here":"��������ҹ�Ĺ�����ѽ��\n",
       "ziye":"�������������������������������æ�ģ�ûʱ�����ҡ�inn��\n",
       "love":"��֪����ҹ�����ң������ҡ���������\n",
       "photo":"�������Ƕ����ҵ���Ƭ��\n",
       "sunr" :"���Ǹ�Ư�� �ɰ��� �����������\n",
       "paopao" :"paopao�����ң���ziye�����������\n",
       "lylw" :"���Ǹ�����Ů����������\n",
       "aileen" :"��Щһ���úúú���������MUD��Ů������������\n",
        ]));
    setup();
   carry_object("/u/ziye/obj/marry/baihe")->wield ();
   carry_object("/u/ziye/obj/marry/hunsha")->wear();
   carry_object("/u/ziye/obj/marry/jiezhi")->wear ();
}
 
void die()
{
  if (environment())
    message("sound", "\n"+this_object()->query("name")+"��ô���Ƕ��۸�����?�\n\n", environment());

  set("eff_kee", 2000);
  set("eff_gin", 2000);
  set("eff_sen", 2000);
  set("kee", 2000);
  set("gin", 2000);
  set("sen", 2000);
  set("force", 2000);
  set("mana", 2000);
}
void unconcious()
{
  die();
}

void init()
{
  object ob;
  ::init();
  if( interactive(ob= this_player()))
    { remove_call_out("greeting");
      call_out("greeting", 1, ob);
    }
 }

void greeting (object ob)
 {
  if( !ob || environment(ob) != environment() ) return;
     {if(ob->query("id") == "shukai")
             say( HIW"��ˮ����"NOR HIR"˵��ԭ���Ƿ��������������������\n"NOR);
     else
           if(ob->query("id") == "repoo")
                       say( HIW"��ˮ����"NOR HIB"˵����ԭ����СҶ�����ˣ�������ɣ�����\n"NOR);
           else  if(ob->query("id") == "xuexu")
             say(HIW"��ˮ����"NOR HIY"�����������ˣ��͵����������ı��ӣ�һ����ȥ����һ���˹����������������ֻ��˹�ȥ��\n"NOR);
           else if(ob->query("id") == "fayu")
                         say(HIW"��ˮ����"NOR HIB"�Ծ�ӨЦ������Ө���úá�\n"NOR);
          else if(ob->query("id") == "ziye")                                          say(HIW"��ˮ����"NOR HIR"�������"NOR HIM"��ҹ"NOR HIR"��������һ�£����ߵص�����ͷ��\n"NOR);
          else
             say(HIW"��ˮ����"NOR HIY"��æ˵��ԭ����"+ob->query("name")+"���ˣ�����������������\n"NOR);
     }
 }

