inherit NPC;
int ask_yue();
void create()
{
set_name("�½���ʹ��", ({"shi","shizhe"}));
set ("long", @LONG
���������︺�����ҷ��½���(yue)�ģ�
��ҸϿ�����Ҫ��ask���ɡ�
LONG);
set("inquiry", ([
"yue": (: ask_yue :),
        ]));
setup();
}
int ask_yue()
{
object me=this_player();
int yyy;
   if (this_player()->query("yyy")){
message_vision("$N����$n����һ����\n",this_object(),this_player());
         command("say �½����Ѿ������ˣ���Ҫ���������ˣ���\n");
 return 1;
}
me->add("daoxing",50000);
me->set("yyy",1);
message_vision("$N����$n˵����ϲ��õ��˽�����\n",this_object(),this_player());
return 1;
}
