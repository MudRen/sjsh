inherit NPC;


int test_player (object me);

void create()
{
  set_name("�ƽ����Ӽ�", ({"man", "man", "man"}));
  set("long", "������Т�ĸ��ˡ�\n");
  set("gender", "����");
  set("age", 36);
  set("per", 18);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 2000);
  set_skill("unarmed", 10);
  set_skill("dodge", 10);
  set_skill("parry", 10);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",200);
  set("max_mana",200);
  set("force_factor",12);
  set("inquiry", ([
        "��":   (: test_player :),
        "armor": (: test_player :),
        "�ƽ����Ӽ�": (: test_player :),
      ]));

  setup();

}

int test_player (object me)
{
  object who = this_player();

  if (who->query("combat_exp")>100000)
  {
    me->command_function("shake");
    return 1;
  }  

  me->command_function("nod");
  call_out ("give_armor",2,me,who);
  return 1;
}

void give_armor (object me, object who)
{
  object armor = new ("/d/obj/armor/jinjia.c");

  armor->move(me);
  me->command_function ("give "+who->query("id")+" armor");
}
