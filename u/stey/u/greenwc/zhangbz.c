inherit NPC;

void create()
{
           set_name("�Ű�֥", ({"zhang bai zhi","zhang", "zhi"}));
set("long","��ķ��ϵĴ����ǣ���������������˽�������ˣ�\n");
       set("gender", "Ů��");
set("title","����˽������");
       set("age", 24);
        set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
        set_skill("dodge", 200);
        set_skill("moondance", 200);
        set_skill("sword", 200);
        set_skill("snowsword", 200);
        map_skill("dodge", "moondance");
        map_skill("sword", "snowsword");
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 50);
        set("combat_exp", 1200000);
  set("daoxing", 5000000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("mana_factor", 50);
        setup();
        add_money("gold", 5);
}
