// wan.c ��Ѫ����

#include <ansi.h>

inherit ITEM;

string *names = ({
  "�м������",
  "���̻��ʵ�",
  "��ͷ���Ե�",
  "���ʱ���",
  "�߸����˵�",
});

void create()
{
            set_name(HIB"��ң��"NOR, ({ "xiaoyao dan","dan" }) );
        set("long",
HIB"�������ɼ��˾������ҩ�ģ���ʱ�������ƶ��ɵ��鵤����ǿ����֮��Ч.\n"NOR);
        set("unit", "��");
        set("weight", 5);
        set("value", 100);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob,what;
	  int bonus;
        if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");

        ob=this_player();
	what=this_object();
      int i=random(sizeof(names));
      string hoho=names[i];

//	message_vision("$N����һ��$n,"+hoho+"������ȥ...",ob,what);
	  bonus=200+random(300);
	  if (ob->query("family/family_name")=="��ɽ����")
		bonus=bonus*2;
        ob->add("potential",bonus);
write(HIR+"��õ���"+chinese_number(bonus)+"��Ǳ��!\n"NOR,
               environment(ob), ob);
        destruct(this_object());
        return 1;
}
