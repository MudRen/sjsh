inherit NPC;
inherit F_MASTER;
inherit SSERVER;

void create()
{
  set_name("��ɮ", ({ "tang seng", "tangseng", "tang", "seng" }));
  set("gender", "����");
  set("attitude", "peaceful");
  set("str", 10);
  set("per", 30);
  set("combat_exp", 10000);
  set("daoxing", 10000000);

  set("max_kee", 8000);
  set("max_sen", 8000);
   set("max_mana", 10000);
   set("mana", 10000);
  set("mana_factor", 300);
  set_skill("spells", 200);
  set_skill("fofa", 200);
  set_skill("literate",200);
  map_skill("spells", "fofa");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
     (: cast_spell, "onlyu" :),
                           }) );
    set("chat_chance",10);
    set("chat_msg",({
    "��ɮ����������һ������е��������������ˣ�������·��ˣ�\n",
    "��ɮ̾�˿��������������Ǳ���������ӣ����ӻ���Ⱦ�����ġ�\n",
    "��ɮ����������ĵ�Ȱ��������Ҫ��˵���㲻˵����ô֪������Ҫ�أ�\n",
    "��ɮ����̾����������һ������������ҳ����׸�ġ�\n",
    "��ɮ����ĺ��ţ�Only-you- Can����ȡ����~~~\n",
    "��ɮһ��������˵������Щ��������ң�ֻ��һ�����룬��û�����ʵ�������ǳ����ң����ǲ��ܱ���\n",
    "��ɮ���Ϻ��ޱ����˵����GO���������á�\n",
  }));

        create_family("����Ԫ˧��", 1, "ʦ��");
  setup();
  //carry_object("/d/obj/drug/tangsengrou");
}

void attempt_apprentice(object ob)
{
    if( (int)ob->query_skill("fofa",1) > 99 ) {
        command("smile");
        command("say �������ѽ��\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
        command("say �������������ġ�\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("say ��������������\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("say ��ʵֻҪ��һ�����˵���\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("say ����Ϳ��Բ�����\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("say �Ǿ�������\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("say ����������ͽ�ܶ���������\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("say ������������\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("recruit " + ob->query("id") );
        return;
            }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "tianpeng");
                ob->set("title", "����ȡ����");
        }
}
