inherit NPC;
#include <ansi.h>
  int call_shushan();
int call_moon();
 int call_wzg();
 int call_putuo();
  int call_fangcun();
int call_xueshan();
int call_huoyundong();
    int call_longgong();
     int call_wdd();
      int call_hell();
        int call_jjf();
int give_gift();
void create()
{
        set_name(HIB"ħ��С����"NOR, ({"jing ling","jing", "ling"}));
   set ("long", @LONG

  һ���ɰ���С���飬�����԰���õ�����Ҫ�Ĺ���Ŷ��
�������ȥ����(ask)����
LONG);
       set("gender", "Ů��");
      set("title",HIM"����"HIG"��Ե"NOR);
               set("age", 9);
        set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("inquiry", ([
              "shushan":(:call_shushan:),
            "moon":(:call_moon:),
                "huoyundong":(:call_huoyundong:),
              "jjf":(:call_jjf:),
              "wzg":(:call_wzg:),
             "xueshan":(:call_xueshan:),
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
  int call_shushan()
  {
    object who=this_player();
             if (this_player()->query("yudian/skills")=="got")
   {
             message_vision("$N����$n����һ����\n",this_object(),this_player());
          command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
  return 1;
  }
  who->set_skill("force",20);
  who->set_skill("dodge",20);
  who->set_skill("literate",20);
  who->set_skill("parry",20);
  who->set_skill("zixia-shengong",20);
  who->set_skill("yujianshu",20);
  who->set_skill("spells",20);
  who->set_skill("sword",20);
  who->set_skill("taoism",20);
  who->set_skill("sevensteps",20);
  who->map_skill("spells", "taoism");
  who->map_skill("force", "zixia-shengong");
  message_vision("С��������������������!��\n",this_object(),this_player());
           command("say ok�ˣ�");
  who->set("yudian/skills","got");
  return 1;
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
who->set_skill("force",20);
who->set_skill("spells",20);
who->set_skill("literate",20);
who->set_skill("dodge",20);
who->set_skill("parry",20);
who->set_skill("unarmed",20);
who->set_skill("moonforce",20);
who->set_skill("moonshentong",20);
who->set_skill("moondance",20);
 who->set_skill("baihua-zhang",20);
who->set_skill("sword",20);
who->set_skill("snowsword",20);
who->set_skill("whip",20);
who->set_skill("jueqingbian",20);
who->map_skill("spells", "moonshentong");
who->map_skill("force", "moonforce");
message_vision("С��������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
who->set("yudian/skills","got");
return 1;
}
    int call_huoyundong()
{
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
  {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
         command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
 return 1;
}
  who->set_skill("force",20);
    who->set_skill("fumozhang",20);
    who->set_skill("spear",20);
      who->set_skill("huoyun-qiang",20);
  who->set_skill("dali-bang",20);
  who->set_skill("dodge",20);
  who->set_skill("huomoforce",20);
    who->set_skill("moyun-shou",20);
  who->set_skill("parry",20);
  who->set_skill("pingtian-dafa",20);
  who->set_skill("spells",20);
  who->set_skill("stick",20);
  who->set_skill("unarmed",20);
  who->set_skill("moshenbu",20);
  who->set_skill("literate",20);
  who->map_skill("spells", "pingtian-dafa");
  who->map_skill("force", "huomoforce");
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
 who->set_skill("force",20);
 who->set_skill("spells",20);
 who->set_skill("literate",20);
 who->set_skill("dodge",20);
 who->set_skill("parry",20);
 who->set_skill("unarmed",20);
 who->set_skill("wuxiangforce",20);
 who->set_skill("dao",20);
 who->set_skill("jindouyun",20);
 who->set_skill("puti-zhi",20);
 who->set_skill("sword",20);
 who->set_skill("liangyi-sword",20);
 who->set_skill("qianjun-bang",20);
 who->set_skill("stick",20);
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
   who->set_skill("force",20);
   who->set_skill("spells",20);
  who->set_skill("literate",20);
  who->set_skill("dodge",20);
   who->set_skill("parry",20);
  who->set_skill("unarmed",20);
  who->set_skill("jienan-zhi",20);
  who->set_skill("lotusforce",20);
  who->set_skill("buddhism",20);
  who->set_skill("lotusmove",20);
  who->set_skill("staff",20);
  who->set_skill("lunhui-zhang",20);
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
   who->set_skill("force",20);
  who->set_skill("spells",20);
   who->set_skill("literate",20);
  who->set_skill("dodge",20);
   who->set_skill("parry",20);
 who->set_skill("unarmed",20);
   who->set_skill("dragonforce",20);
 who->set_skill("seashentong",20);
 who->set_skill("dragonstep",20);
 who->set_skill("dragonfight",20);
 who->set_skill("fork",20);
 who->set_skill("hammer",20);
 who->set_skill("huntian-hammer",20);
 who->set_skill("fengbo-cha",20);
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
 who->set_skill("force",20);
 who->set_skill("spells",20);
  who->set_skill("literate",20);
 who->set_skill("dodge",20);
 who->set_skill("parry",20);
 who->set_skill("unarmed",20);
 who->set_skill("huntian-qigong",20);
 who->set_skill("yaofa",20);
 who->set_skill("dao",20);
 who->set_skill("throwing",20);
 who->set_skill("lingfu-steps",20);
 who->set_skill("yinfeng-zhua",20);
 who->set_skill("kugu-blade",20);
 who->set_skill("qixiu-jian",20);
 who->set_skill("sword",20);
 who->set_skill("blade",20);
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
who->set_skill("force",20);
 who->set_skill("spells",20);
 who->set_skill("dodge",20);
 who->set_skill("parry",20);
 who->set_skill("unarmed",20);
 who->set_skill("literate",20);
 who->set_skill("xiaoyaoyou",20);
 who->set_skill("throwing",20);
 who->set_skill("ningxie-force",20);
 who->set_skill("dengxian-dafa",20);
 who->set_skill("cuixin-zhang",20);
 who->set_skill("bainiao-jian",20);
 who->set_skill("sword",20);
 who->set_skill("bingpo-blade",20);
 who->set_skill("blade",20);
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
 who->set_skill("force",20);
  who->set_skill("spells",20);
  who->set_skill("dodge",20);
  who->set_skill("literate",20);
  who->set_skill("parry",20);
  who->set_skill("unarmed",20);
  who->set_skill("ghost-steps",20);
  who->set_skill("gouhunshu",20);
  who->set_skill("tonsillit",20);
  who->set_skill("kusang-bang",20);
  who->set_skill("hellfire-whip",20);
  who->set_skill("jinghun-zhang",20);
  who->set_skill("zhuihun-sword",20);
  who->set_skill("sword",20);
  who->set_skill("stick",20);
  who->set_skill("whip",20);
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
 who->set_skill("force",20);
who->set_skill("spells",20);
who->set_skill("dodge",20);
who->set_skill("literate",20);
who->set_skill("parry",20);
who->set_skill("unarmed",20);
who->set_skill("baguazhen",20);
who->set_skill("taiyi",20);
who->set_skill("zhenyuan-force",20);
who->set_skill("wuxing-quan",20);
who->set_skill("kaishan-chui",20);
who->set_skill("hammer",20);
who->set_skill("fumo-zhang",20);
who->set_skill("staff",20);
who->set_skill("xiaofeng-sword",20);
who->set_skill("sword",20);
who->set_skill("yange-blade",20);
who->set_skill("blade",20);
who->set_skill("sanqing-jian",20);
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
 who->set_skill("force",20);
   who->set_skill("spells",20);
   who->set_skill("dodge",20);
   who->set_skill("parry",20);
   who->set_skill("unarmed",20);
   who->set_skill("literate",20);
   who->set_skill("archery",20);
   who->set_skill("bawang-qiang",20);
   who->set_skill("changquan",20);
   who->set_skill("lengquan-force",20);
   who->set_skill("mace",20);
   who->set_skill("spear",20);
   who->set_skill("wusi-mace",20);
   who->set_skill("yanxing-steps",20);
   who->set_skill("baguazhou",20);
who->map_skill("force", "lengquan-force");
who->map_skill("spells", "baguazhou");
 message_vision("С��������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
 who->set("yudian/skills","got");
return 1;
}
