inherit NPC;
int call_moon();
 int call_wzg();
 int call_putuo();
  int call_fangcun();
int call_xueshan();
    int call_longgong();
     int call_wdd();
      int call_hell();
        int call_jjf();
int give_gift();
void create()
{
                  set_name("ħ��С����", ({"jing ling","jing", "ling"}));
   set ("long", @LONG

  һ���ɰ���С���飬�����԰���õ�����Ҫ�Ĺ���Ŷ��
�������ȥ����(ask)����
LONG);
       set("gender", "Ů��");
    set("title","������Ե");
               set("age", 9);
        set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("inquiry", ([
            "moon":(:call_moon:),
              "jjf":(:call_jjf:),
              "wzg":(:call_wzg:),
"xueshan":(:call_xueshan:),
"shushan":(:call_shushan:),
              "fangcun":(:call_fangcun:),
               "putuo":(:call_putuo:),
                "hell":(:call_hell:),
                "longgong":(:call_longgong:),
                 "wdd":(:call_wdd:),
//            "gift":(:give_gift:),
]));
        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
}
}
int call_moon()
{
  object who=this_player();
           if (this_player()->query("yudian/skills")=="got")
 {
           message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
}
who->set_skill("force",180);
who->set_skill("spells",180);
who->set_skill("literate",180);
who->set_skill("dodge",180);
who->set_skill("parry",180);
who->set_skill("unarmed",180);
who->set_skill("moonforce",180);
who->set_skill("moonshentong",180);
who->set_skill("moondance",180);
 who->set_skill("baihua-zhang",180);
who->set_skill("sword",180);
who->set_skill("snowsword",180);
who->set_skill("whip",180);
who->set_skill("jueqingbian",180);
who->map_skill("spells", "moonshentong");
who->map_skill("force", "moonforce");
message_vision("С��������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
who->set("yudian/skills","got");
return 1;
}
  int call_fangcun()
 {
    object who=this_player();
             if (this_player()->query("yudian/skills")=="got")
   {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
         command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
  }
 who->set_skill("force",180);
 who->set_skill("spells",180);
 who->set_skill("literate",180);
 who->set_skill("dodge",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
 who->set_skill("wuxiangforce",180);
 who->set_skill("dao",180);
 who->set_skill("jindouyun",180);
 who->set_skill("puti-zhi",180);
 who->set_skill("sword",180);
 who->set_skill("liangyi-sword",180);
 who->set_skill("qianjun-bang",180);
 who->set_skill("stick",180);
who->map_skill("force", "wuxiangforce");
 who->map_skill("spells", "dao");
 message_vision("С��������������������!��\n",this_object(),this_player());
          command("say ok�ˣ�");
 who->set("yudian/skills","got");
return 1;
}
int give_gift()
{
object who=this_player();
         if (this_player()->query("jjf/yudian")=="got")
{
          message_vision("$N����$n����һ����\n",this_object(),this_player());
       command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�");
  return 1;
}
message_vision("С��������������������!\n$nͻȻ�о��ޱ�ǿ��\n",this_object(),this_player());
     who->set("jjf/yudian","got");
return 1;
}
    int call_putuo()
   {
     object who=this_player();
              if (this_player()->query("yudian/skills")=="got")
   {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
    }
   who->set_skill("force",180);
   who->set_skill("spells",180);
  who->set_skill("literate",180);
  who->set_skill("dodge",180);
   who->set_skill("parry",180);
  who->set_skill("unarmed",180);
  who->set_skill("jienan-zhi",180);
  who->set_skill("lotusforce",180);
  who->set_skill("buddhism",180);
  who->set_skill("lotusmove",180);
  who->set_skill("staff",180);
  who->set_skill("lunhui-zhang",180);
who->map_skill("spells", "buddhism");
who->map_skill("force", "lotusforce");
   message_vision("С��������������������!��\n",this_object(),this_player());
           command("say ok�ˣ�");
  who->set("yudian/skills","got");
return 1;
}
     int call_longgong()
    {
       object who=this_player();
                if (this_player()->query("yudian/skills")=="got")
    {
             message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
 return 1;
    }
   who->set_skill("force",180);
  who->set_skill("spells",180);
   who->set_skill("literate",180);
  who->set_skill("dodge",180);
   who->set_skill("parry",180);
 who->set_skill("unarmed",180);
   who->set_skill("dragonforce",180);
 who->set_skill("seashentong",180);
 who->set_skill("dragonstep",180);
 who->set_skill("dragonfight",180);
 who->set_skill("fork",180);
 who->set_skill("hammer",180);
 who->set_skill("huntian-hammer",180);
 who->set_skill("fengbo-cha",180);
who->map_skill("force", "dragonforce");
who->map_skill("spells", "seashentong");
     message_vision("С��������������������!��\n",this_object(),this_player());
            command("say ok�ˣ�");
   who->set("yudian/skills","got");
 return 1;
}
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  say(name()+"���ص�˵������Ҫ���������Ұ�����������ֻ��һ�λ���Ŷ����������\n");
}
  int call_wdd()
 {
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
  {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
         command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
 }
 who->set_skill("force",180);
 who->set_skill("spells",180);
  who->set_skill("literate",180);
 who->set_skill("dodge",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
 who->set_skill("huntian-qigong",180);
 who->set_skill("yaofa",180);
 who->set_skill("dao",180);
 who->set_skill("throwing",180);
 who->set_skill("lingfu-steps",180);
 who->set_skill("yinfeng-zhua",180);
 who->set_skill("kugu-blade",180);
 who->set_skill("qixiu-jian",180);
 who->set_skill("sword",180);
 who->set_skill("blade",180);
who->map_skill("spells", "yaofa");
who->map_skill("force", "huntian-qigong");
message_vision("С��������������������!��\n",this_object(),this_player());
        command("say ok�ˣ�");
who->set("yudian/skills","got");
 return 1;
}
  int call_xueshan()
 {
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
  {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
          command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
  return 1;
 }
who->set_skill("force",180);
 who->set_skill("spells",180);
 who->set_skill("dodge",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
 who->set_skill("literate",180);
 who->set_skill("xiaoyaoyou",180);
 who->set_skill("throwing",180);
 who->set_skill("ningxie-force",180);
 who->set_skill("dengxian-dafa",180);
 who->set_skill("cuixin-zhang",180);
 who->set_skill("bainiao-jian",180);
 who->set_skill("sword",180);
 who->set_skill("bingpo-blade",180);
 who->set_skill("blade",180);
who->map_skill("force", "ningxie-force");
who->map_skill("spells", "dengxian-dafa");
 message_vision("С��������������������!��\n",this_object(),this_player());
          command("say ok�ˣ�");
 who->set("yudian/skills","got");
 return 1;
}
  int call_hell()
  {
    object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
  {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
}
 who->set_skill("force",180);
  who->set_skill("spells",180);
  who->set_skill("dodge",180);
  who->set_skill("literate",180);
  who->set_skill("parry",180);
  who->set_skill("unarmed",180);
  who->set_skill("ghost-steps",180);
  who->set_skill("gouhunshu",180);
  who->set_skill("tonsillit",180);
  who->set_skill("kusang-bang",180);
  who->set_skill("hellfire-whip",180);
  who->set_skill("jinghun-zhang",180);
  who->set_skill("zhuihun-sword",180);
  who->set_skill("sword",180);
  who->set_skill("stick",180);
  who->set_skill("whip",180);
who->map_skill("force", "tonsillit");
who->map_skill("spells", "gouhunshu");
message_vision("С��������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
 who->set("yudian/skills","got");
return 1;
}
int call_wzg()
{
  object who=this_player();
           if (this_player()->query("yudian/skills")=="got")
{
           message_vision("$N����$n����һ����\n",this_object(),this_player());
         command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
 return 1;
  }
 who->set_skill("force",180);
who->set_skill("spells",180);
who->set_skill("dodge",180);
who->set_skill("literate",180);
who->set_skill("parry",180);
who->set_skill("unarmed",180);
who->set_skill("baguazhen",180);
who->set_skill("taiyi",180);
who->set_skill("zhenyuan-force",180);
who->set_skill("wuxing-quan",180);
who->set_skill("kaishan-chui",180);
who->set_skill("hammer",180);
who->set_skill("fumo-zhang",180);
who->set_skill("staff",180);
who->set_skill("xiaofeng-sword",180);
who->set_skill("sword",180);
who->set_skill("yange-blade",180);
who->set_skill("blade",180);
who->set_skill("sanqing-jian",180);
who->map_skill("force", "zhenyuan-force");
who->map_skill("spells", "taiyi");
 message_vision("С��������������������!��\n",this_object(),this_player());
          command("say ok�ˣ�");
 who->set("yudian/skills","got");
return 1;
}
  int call_jjf()
  {
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
   {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
 }
 who->set_skill("force",180);
   who->set_skill("spells",180);
   who->set_skill("dodge",180);
   who->set_skill("parry",180);
   who->set_skill("unarmed",180);
   who->set_skill("literate",180);
   who->set_skill("archery",180);
   who->set_skill("bawang-qiang",180);
   who->set_skill("changquan",180);
   who->set_skill("lengquan-force",180);
   who->set_skill("mace",180);
   who->set_skill("spear",180);
   who->set_skill("wusi-mace",180);
   who->set_skill("yanxing-steps",180);
   who->set_skill("baguazhou",180);
who->map_skill("force", "lengquan-force");
who->map_skill("spells", "baguazhou");
 message_vision("С��������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
 who->set("yudian/skills","got");
return 1;
}
int call_shushan()
{
object who=this_player()
 who->set_skill("force",150);
 who->set_skill("shushan-force",150);
who->set_skill("huomoforce",150);
 who->set_skill("spells",150);
 who->set_skill("xianfeng-spells",150);
 who->set_skill("parry",150);
 who->set_skill("literate",150);
 who->set_skill("unarmed",150);
 who->set_skill("moyun-shou",150);
 who->set_skill("fumozhang",150);
 who->set_skill("whip",150);
 who->set_skill("snowwhip",150);
 who->set_skill("hellfire-whip",150);
 who->set_skill("sword",150);
 who->set_skill("liangyi-sword",150);
 who->set_skill("yujianshu",150);
 who->set_skill("songhe-sword",150);
 who->set_skill("zuihun-sowrd",150);
who->set_skill("stick",150);
 who->set_skill("kusang-bang",150);
 who->set_skill("dodge",150);
 who->set_skill("zuixian-steps",150);
 who->set_skill("dali-bang",150);
who->add("daoxing",200000+random(50000));
who->add("combat_exp",200000+random(50000));
    this_player()->add("max_force",100);
    this_player()->add("max_mana",100);
    this_player()->add("deposit",1000000);
 this_player()->add("potential",10000+random(5000));
return;
}
