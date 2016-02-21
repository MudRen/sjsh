//mozi-sword, created 17-06-2001 ����Ʈ(piao)


// mozi-jianpu.c
inherit F_UNIQUE;

#include <ansi.h>

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name(BLK"��ī�ӽ��ס�"NOR, ({"mozi jinpu","book","shu","jianpu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
       set("no_get", 1);
       set("no_give", 1);
       set("no_put", 1);
	set("long",
	"һ��ʧ��������书�ؼ������湤����д�š�ī�ӽ��ס���\n");
        set("material", "paper");
        set("value", 0);   
	set("no_sell",1);
              set("no_sell", "" + (string)this_object()->query("name") + "���޼�֮�������ɽ���������\n");
        }
}

void init()
{
  	add_action("do_read", "read");
	add_action("do_read", "study");

	if( (int)this_object()->query("created") != 1 )
	{
		this_object()->set("created", 1);	}
		remove_call_out ("destroy_book");
		call_out ("destroy_book", 9000);//2.5 hours


}

void destroy_book()
{
	message_vision("һ��紵����" + (string)this_object()->query("name") + "ƬƬ���䣬����ȥ�ˡ�\n", environment(this_object()));
	destruct(this_object());
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	
	me=this_player();

    	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("��Ҫ����������\n");



	if( environment(me)->query("no_fight") )
		return notify_fail("��ȫ���ڲ��ܶ��顣\n");



    	if( me->is_busy() )
        		return notify_fail("������æ���أ����п��ܾ����ж�...\n");
   	if( me->is_fighting() )
        		return notify_fail("���ڲ��뵽�����书�ؼ���̫���˰ɣ�\n");
	
	if( (int)me->query_skill("literate",1)<100 )
        return notify_fail("�㿴����ȥ������û�����Ȿ�ؼ���д�Ķ���ɶ��\n");
	if( (int)me->query_skill("mozi-sword",1)>280 )
		return notify_fail("���ī�ӽ����Ѿ����������Ȿ�鲻�����㳤�����١�\n");

	sen_cost = 35 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("mozi-sword", 1)+(int)me->query("int")+1;
	me->improve_skill("mozi-sword", gain);

    	message_vision("$N����" + (string)this_object()->query("name") + "��ϸ�ж�����������̾�������侹����˸���Ī����书��
"HIY"��ġ�ī�ӽ����������ˣ�"NOR"\n", me);
		
	return 1;
}

