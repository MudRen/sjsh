inherit NPC;

int call_moon();
int call_fangcun();
int call_jjf();
int call_longgong();
int call_wzg();
int call_wdd();
int call_xueshan();
int call_putuo();
int call_hell();
void create()
{
                 set_name("ħ��С����", ({"jing ling","jing", "ling"}));
  set ("long", @LONG

���������С�����ı��¿ɲ�С��
  ���ţ����������(ask)�����ڸ������ɵ����飬
"moon","fangcun","putuo","longgong","jjf",'wzg",
"wdd","xueshan","hell"
  ���Ը������ɿ�������ָ�ư���
LONG);

       set("gender", "Ů��");
      set("title","������Ե");
               set("age", 9);
        set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("inquiry", ([
    "moon":(:call_moon:),
    "fangcun":(:call_fangcun:),
    "longgong":(:call_longgong:),
    "wzg":(:call_wzg:),
      "putuo":(:call_putuo:),
    "jjf":(:call_jjf:),
    "wdd":(:call_wdd:),
    "xueshan":(:call_xueshan:),
    "hell":(:call_hell:),
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
      if (this_player()->query("yudian/skill")=="yudian")
{
    message_vision("$N�ݺݵص���$nһ�ۡ�\n",this_object(),this_player());
    command("say Ҫ�������˻���Ҫ��û�Ŷ���");
return 1;
}
 who->set_skill("dodge",180);
 who->set_skill("force",180);
 who->set_skill("spells",180);
 who->set_skill("literate",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
who->set_skill("moondance",180);
who->set_skill("dodge",180);
who->set_skill("force",180);
who->set_skill("moonforce",180);
who->set_skill("spells",180);
who->set_skill("moonshentong",180);
who->set_skill("parry",180);
who->set_skill("literate",180);
who->set_skill("unarmed",180);
who->set_skill("baihua-zhang",180);
who->set_skill("sword",180);
who->set_skill("snowsword",180);
who->set_skill("whip",180);
who->set_skill("jueqingbian",180);
     message_vision("С��������������������������˵���������ˣ���\n",who);
        who->set("yudian/skill","yudian");
return 1;}
int call_fangcun()
{
      if (this_player()->query("yudian/skill")=="yudian")
{
      message_vision("$N�ݺݵص���$nһ�ۡ�\n",this_object(),this_player());
     command("say Ҫ�������˻���Ҫ��û�Ŷ���");
  return 1;
}
 who->set_skill("dodge",180);
 who->set_skill("force",180);
 who->set_skill("spells",180);
 who->set_skill("literate",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
who->set_skill("unarmed",180);
who->set_skill("puti-zhi",180);
who->set_skill("force",180);
who->set_skill("wuxiangforce",180);
who->set_skill("spells",180);
who->set_skill("dao",180);
who->set_skill("literate",180);
who->set_skill("parry",180);
who->set_skill("stick",180);
who->set_skill("qianjun-bang",180);
who->set_skill("jindouyun",180);
who->set_skill("sword",180);
who->set_skill("liangyi-sword",180);
     message_vision("С��������������������������˵���������ˣ���\n",who);
        who->set("yudian/skill","yudian");
return 1;}
int call_longgong()
{
    object who=this_player();
      if (this_player()->query("yudian/skill")=="yudian")
{
      message_vision("$N�ݺݵص���$nһ�ۡ�\n",this_object(),this_player());
     command("say Ҫ�������˻���Ҫ��û�Ŷ���");
  return 1;
}
 who->set_skill("dodge",180);
 who->set_skill("force",180);
 who->set_skill("spells",180);
 who->set_skill("literate",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
 who->set_skill("unarmed",180);
 who->set_skill("dragonfight",180);
 who->set_skill("dodge",180);
 who->set_skill("dragonstep",180);
 who->set_skill("parry",180);
 who->set_skill("literate",180);
 who->set_skill("force",180);
 who->set_skill("dragonforce",180);
 who->set_skill("spells",180);
 who->set_skill("seashentong",180);
 who->set_skill("fork",180);
 who->set_skill("fengbo-cha",180);
 who->set_skill("hammer",180);
 who->set_skill("huntian-hammer",180);
      message_vision("С��������������������������˵���������ˣ���\n",who);
        who->set("yudian/skill","yudian");
  return 1;}
int call_putuo()
{
object who=this_player();
      if (this_player()->query("yudian/skill")=="yudian")
{
      message_vision("$N�ݺݵص���$nһ�ۡ�\n",this_object(),this_player());
     command("say Ҫ�������˻���Ҫ��û�Ŷ���");
  return 1;
}
 who->set_skill("dodge",180);
 who->set_skill("force",180);
 who->set_skill("spells",180);
 who->set_skill("parry",180);
 who->set_skill("literate",180);
 who->set_skill("unarmed",180);
who->set_skill("unarmed",180);
who->set_skill("buddhism",180);
who->set_skill("spells",180);
who->set_skill("jienan-zhi",180);
who->set_skill("parry",180);
who->set_skill("literate",180);
who->set_skill("force",180);
who->set_skill("staff",180);
who->set_skill("lotusforce",180);
who->set_skill("lotusmove",180);
who->set_skill("lunhui-zhang",180);
who->set_skill("dodge",180);
       message_vision("С��������������������������˵���������ˣ���\n",who);
        who->set("yudian/skill","yudian");
   return 1;}
int call_hell()
{
object who=this_player();
      if (this_player()->query("yudian/skill")=="yudian")
{
        message_vision("$N�ݺݵص���$nһ�ۡ�\n",this_object(),this_player());
      command("say Ҫ�������˻���Ҫ��û�Ŷ���");
  return 1;
}
 who->set_skill("dodge",180);
 who->set_skill("force",180);
 who->set_skill("spells",180);
 who->set_skill("parry",180);
 who->set_skill("literate",180);
 who->set_skill("unarmed",180);
who->set_skill("ghost-steps",180);
who->set_skill("tonsillit",180);
who->set_skill("gouhunshu",180);
who->set_skill("jinghun-zhang",180);
who->set_skill("hellfire-whip",180);
who->set_skill("kusang-bang",180);
who->set_skill("zhuihun-sword",180);
who->set_skill("whip",180);
who->set_skill("stick",180);
who->set_skill("sword",180);
         message_vision("С��������������������������˵���������ˣ���\n",who);
        who->set("yudian/skill","yudian");
     return 1;}
int call_wzg()
{
object who=this_player();
      if (this_player()->query("yudian/skill")=="yudian")
{
        message_vision("$N�ݺݵص���$nһ�ۡ�\n",this_object(),this_player());
      command("say Ҫ�������˻���Ҫ��û�Ŷ���");
return 1;
}
 who->set_skill("spells",180);
 who->set_skill("force",180);
 who->set_skill("dodge",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
 who->set_skill("literate",180);
who->set_skill("baguazhen",180);
who->set_skill("hammer",180);
who->set_skill("kaishan-chui",180);
who->set_skill("taiyi",180);
who->set_skill("wuxing-quan",180);
who->set_skill("zhenyuan-force",180);
who->set_skill("kaishan-chui",180);
who->set_skill("staff",180);
who->set_skill("fumo-zhang",180);
who->set_skill("blade",180);
who->set_skill("yange-blade",180);
who->set_skill("sword",180);
who->set_skill("xiaofeng-sword",180);
who->set_skill("sanqing-jian",180);
          message_vision("С��������������������������˵���������ˣ���\n",who);
        who->set("yudian/skill","yudian");
      return 1;}
int call_xueshan()
{
object who=this_player();
      if (this_player()->query("yudian/skill")=="yudian")
{
        message_vision("$N�ݺݵص���$nһ�ۡ�\n",this_object(),this_player());
      command("say Ҫ�������˻���Ҫ��û�Ŷ���");
return 1;
}
 who->set_skill("literate",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
 who->set_skill("dodge",180);
 who->set_skill("force",180);
 who->set_skill("spells",180);
who->set_skill("bainiao-jian",180);
who->set_skill("sword",180);
who->set_skill("cuixin-zhang",180);
who->set_skill("dengxian-dafa",180);
who->set_skill("ningxie-force",180);
who->set_skill("throwing",180);
who->set_skill("xiaoyaoyou",180);
who->set_skill("bingpo-blade",180);
who->set_skill("blade",180);
who->set_skill("yingzhaogong",180);
message_vision("С��������������������������˵���������ˣ���\n",who);
        who->set("yudian/skill","yudian");
      return 1;}
int call_wdd()
{
object who=this_player();
      if (this_player()->query("yudian/skill")=="yudian")
{
        message_vision("$N�ݺݵص���$nһ�ۡ�\n",this_object(),this_player());
      command("say Ҫ�������˻���Ҫ��û�Ŷ���");
return 1;
}
 who->set_skill("spells",180);
 who->set_skill("force",180);
 who->set_skill("literate",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
 who->set_skill("dodge",180);
 who->set_skill("blade",180);
 who->set_skill("kugu-blade",180);
 who->set_skill("huntian-qigong",180);
 who->set_skill("lingfu-steps",180);
 who->set_skill("qixiu-jian",180);
 who->set_skill("sword",180);
 who->set_skill("throwing",180);
 who->set_skill("yinfeng-zhua",180);
 who->set_skill("dao",180);
message_vision("С��������������������������˵���������ˣ���\n",who);
        who->set("yudian/skill","yudian");
      return 1;}
int call_jjf()
{
object who=this_player();
      if (this_player()->query("yudian/skill")=="yudian")
{
        message_vision("$N�ݺݵص���$nһ�ۡ�\n",this_object(),this_player());
      command("say Ҫ�������˻���Ҫ��û�Ŷ���");
return 1;
}
 who->set_skill("dodge",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
 who->set_skill("force",180);
 who->set_skill("spells",180);
 who->set_skill("literate",180);
who->set_skill("bawang-qiang",180);
who->set_skill("changquan",180);
who->set_skill("lengquan-force",180);
who->set_skill("spear",180);
who->set_skill("yanxing-steps",180);
who->set_skill("archery",180);
who->set_skill("mace",180);
who->set_skill("wusi-mace",180);
who->set_skill("baguazhou",180);
message_vision("С��������������������������˵���������ˣ���\n",who);
         who->set("dntg/bmw","yudian");
      return 1;}
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  say(name()+"���ص�˵������Ҫ���������Ұ�����������ֻ��һ�λ���Ŷ����������\n");
}
