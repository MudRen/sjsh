inherit NPC;
int ask_aoyao();
void create()
{
        set_name("ҩ��С��", ({ "yaopu xiaosi","xiaosi"}) );
        set("gender", "����" );
        set("age", 17);
        set("long","���������ݣ����в�ɫ����֪�������ƹ�Ŀ̱���\n");
        set("str", 12);
        set("dex", 20);
        set("con", 13);
        set("combat_exp", 20000);
        set("max_kee", 500);
        set("max_sen", 500);
        set("force", 700);
        set("max_force", 700);

        set("attitude", "friendly");
        set("inquiry", ([
            "��ҩ" : (: ask_aoyao :),
            "��ҩ" : (: ask_aoyao :),
            "��ҩ" : (: ask_aoyao :),
            "��ҩ" : (: ask_aoyao :),
            "ҩ¯" : "���������Լ�����ҩ����",
       ]) );
        setup();
}

int ask_aoyao()
{
	object me = this_player();
	message_vision(query("name")+"��$N���͵���\n",me);
	message_vision("���Ƚ����Ӵ�\[open lip\]��Ȼ����������ҩ��\[add **** in lu\]\n",me);
	message_vision("���ŵ�һЩˮ\[pour water\]������ҩ���յ��ˡ��ٿۺø���\[close lip\]\n",me);
	message_vision("��̿���ȼ\[burn coal\]����¯���������ˡ��Ϳ��԰�ҩ��\[aoyao\]��\n",me);
	message_vision("��ҩʱҪ��ʱ���ƻ�򣬻�Ҫ��ͣ���裬�����˵ġ�ҩ������֮��\n",me);
	message_vision("�ǵ������˻�\[mie huo\]��ȡҩ\[qu yao\]�����ⱻ���ˡ�\n",me);
	return 1;
}
