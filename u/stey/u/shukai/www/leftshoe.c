#include <ansi.h>
#include <armor.h>

inherit BOOTS;


void create()
{
        set_name(HIW"̩ɽ����Ь������"NOR,({ "left shoe", "xie","shoes" }) );
        set_weight(1000);
                set("unit", "ֻ");
                set("value", 0);
                set("material", "cloth");
        set("armor_prop/armor", 10 );
        set("armor_prop/dodge", 15 );
        setup();
}

void init()
{
   add_action("do_he", "he");
}

int do_he()
{
     object me,ob, obj, shoes;
     me = this_player();
     ob = this_object();
     obj = present("right shoe", me);
     if(!objectp(obj))
           return notify_fail("һֻЬ��ô�ϣ�\n");
     if((int)me->query("force") < 500)
                return notify_fail("������������\n");
     me->add("force", -100);
     message_vision(HIY"\n������ϡ�\n"NOR, me);
     destruct(obj);   
     shoes = new("/u/shukai/shoes")->move(me, 1);     
     destruct(ob);
     return 1;
}
