// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//fo.c
inherit NPC;
inherit F_MASTER;
string expell_me(object me); 
int ask_me(); 
int ask_master();
void create()
{
       set_name("С��̫��", ({"prince zhang", "zhang", "prince"}));
       set("long", "С��̫���Ǵ�ʥ��ʦ�������ĵ�����ӣ�������Ϊ�������־������һ
Ӣ������Ҳ��\n");
       set("gender", "����");
   set("title", "С̫��");
   set("class", "xian");
       set("age", 25);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "̫��");
       set("per", 30);
   set("int", 30);
   set("str", 30);
   set("cps", 30);
       set("max_kee", 1500);
       set("max_gin", 1500);
       set("max_sen", 1200);
       set("force", 1300);
       set("max_force", 1300);
       set("force_factor", 65);
       set("max_mana", 1200);
       set("mana", 2400);
       set("mana_factor", 60);
       set("combat_exp", 800000);

        set("eff_dx", 250000);
        set("nkgain", 400);

       set_skill("literate", 90);
       set_skill("unarmed", 120); 
       set_skill("lianhuan-tui", 120);
       set_skill("tianwei-shi", 120);
       set_skill("dodge", 120);
       set_skill("parry", 120);
       set_skill("halberd", 120); 
          set_skill("buddhism", 120);
          set_skill("lotusforce", 120);
       set_skill("tianlong-halberd", 120);
       set_skill("spells", 120);
       set_skill("force", 120);
       map_skill("unarmed", "lianhuan-tui");
       map_skill("parry", "tianlong-halberd"); 
       map_skill("halberd", "tianlong-halberd");
        map_skill("spells", "buddhism");
          map_skill("force", "lotusforce");
       map_skill("dodge", "tianwei-shi");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: cast_spell, "sword" :),
                (: cast_spell, "sixiang" :)
        }) );

        set("inquiry", ([
     "��ɽ": (: expell_me :),
     "leave": (: expell_me :), 
     "ˮԳ��ʥ": (: ask_me :), 
     "��ʥ��ʦ������": (: ask_master :), 
     "��ʦ������": (: ask_master :),
     "ʦ��": (: ask_master :),
     "master": (: ask_master :),
      ]) );

  create_family("�Ϻ�����ɽ", 2, "����");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/obj/weapon/halberd/chubai")->wield();
}

void attempt_apprentice(object ob)
{
     if ( (string)ob->query("family/family_name")=="�Ϻ�����ɽ") {
   if (((int)ob->query("combat_exp") < 100000 )) {
   command("say ������л����ɣ�" + RANK_D->query_respect(ob) + "������Ŭ�����ǡ�\n");
   return;
   }
        command("smile");
   command("say �ü����ü�����������"  + RANK_D->query_respect(ob) +
"������Ӣ��֮ʿ��ʵ���������ɵ�ϲ�£�\n");
          command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ����Ϊ���Ϻ�����ɽ���Ͱɡ�\n");
       command("recruit " + ob->query("id") );
   return;
   } 
   if (!(string)ob->query("family/family_name"))   {
   command("shake");  
   command("say " + RANK_D->query_respect(ob) + "��ѧ�ղ���Խ����������ȥ������ɮ�˰ɡ�\n");
         return;
    } 
   command("shake"); 
 command("say " + RANK_D->query_respect(ob) + "����������𣿻������˳�����������˵�ɣ�\n");  
        return;
} 
string expell_me(object me)
{       me=this_player();
          if((string)me->query("family/family_name")=="�Ϻ�����ɽ") {
        if (me->query("combat_exp")<200000) return ("����в�����������ɽ��\n");
        if (me->query("jieshu")<50) return ("�����������������ɽ��\n");
                command("say �����ִ����ɽ������үҲ�����㣬�����Ժ�ɲ�Ҫ�������顣");
                me->set_temp("betray", 1);
     command("say ��Ҫ��ɽ������ү��Ҫ���µ㶫��������Ŷ��");
                return ("���Ը��(agree)��");
        }
        return ("��������ʲô�֡�");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N���������Ը�⡣\n\n", this_player());
     this_player()->add("betray/count", 1);
     this_player()->add("jieshu", -50);
     this_player()->add("betray/xuyi", 1);
                command("say ��Ȼ�㲻�����������ɣ��Ǿ��߰ɣ�");
this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����"); 
                this_player()->set_temp("betray",0); 
                this_player()->save();
                command("say ��Ȼ���������ˡ���\n");
                return 1;
                }
        return 0;
} 

int ask_me()
{ 
    object me, ob;
    me = this_player(); 
       if(me->query_temp("kill_yuan")){
       command("thank "+me->query("id"));
       command("say ��л��λ"+RANK_D->query_respect(me)+"����������һ��ͭ�ƣ��������ȥ�ݼ���ʦ����������ա�");
       ob=new("/d/xuyi/obj/tongpai");
       ob->move(me);
     message_vision("С��̫�����ֽ�������������ʿ����$N�͵��˴�ʥ����ǰ��\n",me);
       me->move("/d/xuyi/frontgate");
       me->set_temp("kill_yuan", 0);
       return 1;
       }
    command("say ��λ"+RANK_D->query_respect(me)+"Ը��ȥ����ˮԳ��ʥ����������֮����");
    return 1;
}

int ask_master()
{ 
    object me, ob;
    me = this_player();  

      if (me->query("family/master_name") !="��ʥ��ʦ������"){
    command("say ʦ����ΪˮԳ��ʥ���·��գ���Ҫȥ��������");
       return 1;
       }
    command("nod");
    command("say �Ҳ�������ȥ��");
     message_vision("С��̫�����ֽ�������������ʿ����$N�͵��˴�ʥ����ǰ��\n",me);
       me->move("/d/xuyi/frontgate");
       return 1;
}
