inherit NPC;
int ask_aoyun();
void create()
{
set_name("��³ɹ�ʹ��", ({"shi","shizhe"}));
set ("long", @LONG
���������︺�����ҷ����˽���(aoyun)�ģ�
��ҸϿ�����Ҫ��ask���ɡ�
LONG);
set("inquiry", ([
"aoyun": (: ask_aoyun :),
        ]));
setup();
}
int ask_aoyun()
{
object me=this_player();
int sss;
if (this_player()->query("sss")){
message_vision("$N����$n����һ����\n",this_object(),this_player());
      command("say �������ɹ��ˣ���Ҳ�����ˣ�����ô��Ҫ����С�������㣡\n");
 return 1;
}
me->add("potential",150000);
me->set("sss",1);
command("say �������ɹ��ˣ����Ҳ��һ�ݹ���,����ЩǱ�ܰ�!\n");
return 1;
}
