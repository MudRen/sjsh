inherit NPC;

void create()
{
   set_name("��֩��", ({"du zhizhu", "zhizhu"}) );
        set("combat_exp", 200000);
        set("daoxing", 200000);
   set_skill("dodge", 100)
   set_skill("unamred", 100)
   set_skill("cuixin-zhang", 100)
   set_skill("xiaoyaoyou", 100)
   set_skill("force", 100)
   set_skill("ningxie-force", 100)
   set_skill("spells", 100)
   set_skill("dengxian-dafa", 100)
        map_skill("dodge", "xiaoyaoyou");
        map_skill("spells", "dengxian-dafa");
        map_skill("force", "ningxie-force");
        map_skill("unarmed", "cuixin-zhang");
   set("max_kee", 2000);
   set("kee", 2000);
