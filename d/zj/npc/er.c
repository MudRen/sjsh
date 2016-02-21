// ���� by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
  set_name(HIC"����"NOR, ({ "ruo lan", "ruo", "lan", "er", "tianshen" }));
  set("title", HIW"¥������"NOR);
  set("gender", "Ů��");
  set("age", 3000);
  set("str", 40);
  set("per", 40);
  set("int", 30);
  set("cor", 50);
  set("cps", 50);
  set("long", "����һ���˼��޳�����������\n");
  set("combat_exp", 3000000);
  set_skill("literate", 350);
  set_skill("spear", 3350);
  set_skill("force", 350);
  set_skill("dodge", 350);
  set_skill("parry", 350);
  set_skill("xuanyuan-archery",350);
  set_skill("mace", 350);
  set_skill("archery", 350);
  set_skill("wusi-mace", 350);
  set_skill("yanxing-steps", 350);
  set_skill("bawang-qiang", 350);
  set_skill("lengquan-force", 350);
  set_skill("unarmed", 350);
  set_skill("changquan", 350);
  map_skill("mace", "wusi-mace");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("archery", "xuanyuan-archery");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 5000);
  set("max_kee", 5000);
  set("force", 2400);
  set("max_force", 1800);
  set("force_factor", 80);
  set("inquiry", ([
                   "name": "С�ɱ���¥�����ӡ�",
                   "here": "�������¥����",
                   ]) );

  create_family("������", 1, "��");
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
                (: perform_action, "spear", "qiangjian" :),
  }) );
  setup();
carry_object("/d/zj/weapon/kulou")->wield();
           carry_object("/d/zj/armor/jiezhi")->wear();
}

int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);
  if ((int)me->query("combat_exp")< 1000000)
    {
      command("say ��λ"+myname+"������ȥ�������ҽ��������ɣ�");
      return 0;
    }
  command("jump");
  command("say �ܺã�ʱ����������֮�ʣ�"+myname+"���Ŭ�������ձض��гɡ�\n");
  command("recruit " + me->query("id") );
  return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_respect(me);
  if (me->query("combat_exp") < 1500000)
    {
      command("emote ������üͷ��˵����"+myname+"��Ƿ������С������"+myname+"����������⡣");
      return 1;
    }
  return 0;
}
