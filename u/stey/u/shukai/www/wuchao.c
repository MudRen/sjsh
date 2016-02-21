

inherit NPC;
int give_book ();

string *msgs = ({
"���ơ�Ħڭ���������۶��ľ�����������������������������۶࣬ʱ�ռ����̽Կգ���һ�п��",
"�����ӣ�ɫ����գ��ղ���ɫ��ɫ���ǿգ��ռ���ɫ��������ʶ���ิ���ǡ�",
"�����ӣ�������࣬�������𣬲�������������������"
"�ǹʿ�����ɫ����������ʶ�����۶��������⣬��ɫ����ζ���������۽磬��������ʶ�硣",
"���������������������������������������������޿��������������޵á��������ùʣ��������֡�",
"�����������۶�ʣ����޹Ұ����޹Ұ��ʣ����пֲ���",
"Զ��ߵ����룬����������������������������۶�ʣ��ð���������������ᡣ",
"��֪���������۶࣬�Ǵ����䣬�Ǵ����䣬�������䣬���޵ȵ��䣬�ܳ�һ�п࣬��ʵ���顣",
"��˵���������۶��䣬��˵��Ի�������У����У����޽��У�����ɮ���У���������ڭ����",
});
void create()
{

  set_name("�ڳ���ʦ", ({ "wuchao chanshi", "chanshi", "wuchao" }) );
  set("gender", "����" );
  set("age",55);
  set("attitude", "peaceful");
  set("rank_info/self", "ƶɮ");
  set("class", "bonze");
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 4000);
  set("max_force", 2000);
  set("force_factor", 145);
  set("max_mana", 3000);
  set("mana", 6000);
  set("mana_factor", 150);
  set("combat_exp", 2000000);
  set("daoxing", 10000000);

  set_skill("literate", 150);
  set_skill("spells", 200);
  set_skill("buddhism", 200);
  set_skill("unarmed", 150);
  set_skill("jienan-zhi", 150);
  set_skill("dodge", 180);
  set_skill("lotusmove", 180);
  set_skill("parry", 180);
  set_skill("force", 180);
  set_skill("lotusforce", 180);
  set_skill("staff", 180);
  set_skill("lunhui-zhang", 180);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
          (: cast_spell, "bighammer" :),
    }) );
  set("inquiry", ([
    "book" : (: give_book :),
  ]) );

  setup();
  carry_object("/d/obj/cloth/hufa-jiasha")->wear();
}
int give_book()
{
  object me = this_object();
  object who = this_player();
  object book;

  if (! who->query("obstacle/wuchao"))
  {
    message_vision ("$N��$nҡ��ҡͷ����ħɽ�ľ���ֻ����Ե֮�ˣ����Ǵ��û��Ե�֡�\n",me,who);
    return 1;
  }
  if( (int)who->query("daoxing")<200000 )
{
    message_vision ("$N��$nҡ��ҡͷ����ħɽ�ľ���ֻ����Ե֮�ˣ����Ǵ��û��Ե�֡�\n",me,who);
    return 1;
}
  if (me->query_temp("given_book"))
  {
    message_vision ("$N��$nҡ��ҡͷ����Ҫ̰�����ᡣ\n",me,who);
    return 1;
  }
  book = new ("/d/obj/book/fumo2");
  command ("nod");
  message_vision("$N��$nһ��"+book->query("name")+"��\n",me,who);
  if(!book->move(who)) {
      destruct(book);
  }
  command ("give "+who->query("id")+" book");
  me->set_temp("given_book",1);
  call_out("reset_give",180);
  return 1;
}
void reset_give ()
{
  object me = this_object();
  me->set_temp("given_book",0);
}
	
void init ()
{
  add_action ("do_tingjing", "tingjing");
}

int do_tingjing ()
{
  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query("obstacle/wuchao_tingjing");
  int j;

  if (who->is_busy())
    return notify_fail ("����æ���أ�\n");

  message_vision ("$N��ʼ�������ڳ���ʦ����˵����\n",who);
  if (i >= size)
{
    message_vision ("\n$N�Ѿ������˾��顣\n",who); 
  who->set("obstacle/wuchao",1);
  }  
  else
  {
    j = 180;
    who->start_busy (j,j);
    call_out ("start_tingjing",5,who,i);
    call_out ("finish_tingjing",j,who);
  }
  return 1;
}

void start_tingjing (object who, int i)
{
  message_vision ("\n�ڳ���ʦ�����"+msgs[i]+"\n",who); 
  who->set("obstacle/wuchao_tingjing",i+1);
}

void finish_tingjing (object who)
{
  object where = environment(who);

  who->interrupt_me ();
  message_vision ("\n$N����һ�侭�ģ�ĬĬ�Ļ�����һ�顣\n",who); 
  }






