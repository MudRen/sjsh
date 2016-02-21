inherit NPC;

string *names = ({
  "������",
  "�����",
  "������",
  "��ˮ��",
  "������",
  "��ڤȮ",
  "��Ǭ��",
  "������",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"guai shou", "shou"}));
  set("race", "Ұ��");
  set("age", 10);

  set_skill("dodge", 120);
  set("combat_exp", 10000);
  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));

  set("chat_chance", 1);

  set("ride/msg", "��");
  set("ride/dodge", 10+random(6));
  set_temp("apply/attack", 10);
  set_temp("apply/armor", 20);

  setup();
}
