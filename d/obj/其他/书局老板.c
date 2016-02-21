// �Ʋ���, bookseller.
// 5-3-97, pickle

inherit F_VENDOR_SALE;

void create()
{
    reload("lanling_tangbohu");
  set_name("�׷���", ({ "tang bohu", "tang", "bohu", "bookseller", "seller", "vendor" }) );
  set("shop_id",({"tangbohu","tang","bohu","bookseller","seller"}));
  set("gender", "����" );
  set("age", 37);
  set("title", "����ϰ�");

set("long",�Ʋ������ǽ����Ĵ����֮һ��\n");
  set("combat_exp", 40000);
  set("daoxing", 20000);

  set_skill("dodge", 120);
  set_skill("literate", 200);
  set("attitude", "friendly");
  set("rank_info/respect", "�Ʋ���");
  set("per",25);
  set("vendor_goods", ([
    "xyjbook": "/d/obj/books-nonskill/xyjbook",
    "san": "/d/obj/book/san",
    "blade-book" : "/d/obj/book/basic_blade",
    "unarmed-book": "/d/obj/book/basic_unarmed",
   ]));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  command("say ��λ" + RANK_D->query_respect(ob) +"��������");
}

mixed buy_object (object who, object item)
{
  object npc = this_object();
  string st;

  st= "total"+(string)item;
  if (npc->query_temp("total_books") < 30)
      {
        if (npc->query_temp(st)<10)
          {
          //  npc->add_temp(st,1);
              // limit needed only for non-skills books
            return ::buy_object(who,item);
          }
        else
          {
            return notify_fail(name()+"˵�����Բ�������Ҫ���������ˣ�������һ�������ɡ�\n");
          }
        //npc->add_temp("total_books", 1);
      }
      else
      {
        return notify_fail(name()+"˵����С�걾С�������Խ���������ˡ����ϵ���һ���ɡ�\n");
      }
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n��Ȼ������������Ѳ�߹ٱ�����$N��һ������ʲô����ɱ��ı��ô��\n\n",me);        
        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}
