inherit NPC;
int give_cola();
void create()
{
                  set_name("С����", ({"xiao ban xian","xian", "banxian"}));
   set ("long", @LONG

һ����������ҽ����˵�ܡ������������أ�
�������ȥ����(ask)����
LONG);
       set("gender", "����");
               set("age", 60);
        set("per", 10);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("inquiry", ([
          "��������":(:give_cola:),
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
int give_cola()
{
object wan;
object who=this_player();
         if (this_player()->query("yudian/cola")=="over")
{
           message_vision("$N����$n̾�˿�����\n",this_object(),this_player());
       command("say �㲡��̫�أ���Ҳ����Ϊ���ˣ�");
 return 1;
}
wan=new("/u/greenwc/wan");
  wan->move(who);
  message_vision("$N��$nһ����Ѫ���衣\n",this_object(),this_player());
       command("say ��ҩ�����ˣ�����˰ɣ�");
     who->set("yudian/cola","over");
return 1;
}
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
say(name()+"˵�������㲡�ò��ᰡ���Ұ������ΰɣ���\n");
}
