// huoji.c

inherit NPC;

void create()
{
  set_name("���", ({"huoji"}));
  set("long","һ�����ε����ӡ�\n");
  set("gender", "����");
  set("age", 18);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("combat_exp",600);
  setup();
  carry_object("/d/obj/����/������")->wear();
}
