// announcer.c
//by kissess

inherit NPC;
#include <ansi.h>

string *msg = ({
"��ӭ���١������񻰡�֮--��Ȫ��ʦԺ��վ����\n",
"�������ʲô���⣬post����ջ���߽�������ʦ���\n",
"��࿴��help�����й���MUD�����±仯��\n",
"������ڿ�ջ��¥���ᱦ�������\n",
"�������ǶԱ�վ�к������õĽ��飬��email �ԣϣ�mudfairy@mail.china.com ��\n",
});
void create()
{
set_name(HIC"�񻰴�˵"NOR, ({"shcs"}));
set("gender", "����" );
set("age", 20);
set("title", HIM"���������ŷ���Ա"NOR);
set("long", "һ����ò���ʵ����������������񻰵����ŷ�����\n");
set("combat_exp", 20000);
set("attitude", "friendly");
        set_skill("dodge", 30);
set("per", 25);
set("max_kee", 100000);
set("kee",100000);
set("sen",100000);
set("max_sen", 100000);
setup();
remove_call_out("msg");
call_out("msg",3600);
}
void msg()
{
        command_function("chat  "+NOR+HBMAG+msg[random(sizeof(msg))]+NOR);

        remove_call_out("msg");
call_out("msg",3600);

}
