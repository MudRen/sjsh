inherit NPC;
#include <ansi.h>
  int give_bonnet();
    int give_dan();
    int give_title();
   int accept_object(object who, object ob)
{
                    if( (string)ob->query("id")=="loyal bonnet" )
{
who->set("yudian/bonnet",0);
                    command("say �ý�û����ٽ費�ѡ�");
    return 1;
}
}
void create()
{
                        set_name(HIB"��Ӱ"NOR, ({"sun ying","sun", "sunying"}));
   set ("long", @LONG
  ��˵������յ�ͽ�ܣ����������︺�����ҷ�����(gift)��
  �����ϻ�����ʦ����(bonnet)��!
  �������ȥ����(ask)�����ǵã���ʦ����������Ҫ��Ŷ��
LONG);
         set("gender", "����");
            set("title",HIM"����"HIG"��Ե"NOR);
                 set("age", 20);
        set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("inquiry", ([
            "bonnet":(:give_bonnet:),
           "title":(:give_title:),
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

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
say(name()+"���ص�˵������Ҫ���������Ұ�����������ֻ��һ�λ���Ŷ����������\n"NOR);
}
int give_title()
{
object who=this_player();
 who->set("title",CYN"�о��е���"NOR);
  who->set("name", HIC "��Ϸ����" NOR );
return 1;
}

