//BOX.C by koker@sjsh 2002

#include <ansi.h>
inherit ITEM;
#define LAST_PAR "fg2"
#define THIS_PAR "fg1"

void create()
{
	set_name("����", ({ "box" }) );
	set("long",
			"����һ���ں��������ӣ�����Դ���(open box)��\n" );
	set_weight(5000000);
	if( clonep() )
        set_default_object(__FILE__);
    else {
	set("unit", "��");
	set("value", 0);
        set("no_get",1);
     }
}
void init()
{
	add_action("do_get", "pick");
	add_action("do_get", "get");
	add_action("do_open", "open");
}

int do_open(string arg)
{
       object me,obj1,obj2,*inv;
       int i;
       
       me = this_player();
       if( !arg || arg!="box" ) return notify_fail("��Ҫ��ʲô��\n");
       
       if( (int)me->query("level") < 6 )
    return notify_fail(""HIW"���翴�ص��Ǹ�λ�Ĳ�ѧ����ĵȼ���������ô����ʲô��ѧ�ǣ�."NOR"\n");
       if (me->query(THIS_PAR + "_pick")) {
       tell_object(me,CYN "�������򿪹�������Ӱ���\n\n");
       tell_object(me,HIR "���������ʲôҲû���ˣ�\n\n");
       tell_object(me,CYN "��ʧ������������һ�š�\n" NOR);
       return 1;
       }
	i=random(1000000)+3000000;
	me->add("balance", i);
	obj1 = new ("/u/koker/bingtao");
        obj1->move(me);
        obj2 = new("/u/koker/zhitiao");
        obj2->move(me);
      printf(HIM "������ش������ӣ�һ���������������˳���������������ҵ���%d��Ǯ���Ǻǣ����翶���ɣ�\n\n" ,i );
      printf(HIW "�㷭�˷����ӣ��ַ����˸��ñ��������Ӻ�һ��ֽ����\n" NOR);
//ÿ�δ����ӣ������ϴεĲ������������ӱ��δ򿪵Ĳ����� 
       me->delete(LAST_PAR + "_pick");
       me->set(THIS_PAR + "_pick",1);
       return 1;
}

