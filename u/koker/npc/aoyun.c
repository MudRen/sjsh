//����ʾ������
//by koker@sjsh 2002.01

inherit NPC;
int ask_aoyun();
void create()
{
      set_name("��³ɹ�ʹ��", ({"shizhe","shi"}));
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

//��������Ǹ�ʾ�����򡣵�������������һ�Σ������Ҫ������ô��
//��Ҫ��ֹ��һ��û�����������Ҫ���顣

        if (this_player()->query("sss")>1){
message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �������ɹ��ˣ���Ҳ�����ˣ�����ô��Ҫ����С�������㣡\n");
 return 1;
}
        if (this_player()->query("sss")<1){
message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �������ɹ��ˣ� ����Ҳ��Ҫ�ô������콱������С�������㣡\n");
 return 1;
}
        me->add("potential",150000);
        me->add("sss",1);//ÿҪһ������һ��������
        command("say �������ɹ��ˣ����Ҳ��һ�ݹ���,����ЩǱ�ܰ�!\n");
 return 1;
}
